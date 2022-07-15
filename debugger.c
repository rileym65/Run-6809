#include "header.h"

word address;
char lines[16][80];
word breakpoints[1000];
int  numBreakpoints;
int  tracing;
byte traps[256];
unsigned int clocks;
char conditions[100][256];
int  numConditions;
char useConditions;


void Cls() {
  printf("\e[H\e[2J");
  }

void GotoXY(int x, int y) {
  printf("\e[%d;%dH",y,x);
  }

int IsHex(char* line) {
  if (*line >= '0' && *line <= '9') return -1;
  if (*line >= 'a' && *line <= 'f') return -1;
  if (*line >= 'A' && *line <= 'F') return -1;
  return 0;
  }

word GetHex(char* line) {
  word ret;
  ret = 0;
  while (IsHex(line)) {
    ret <<= 4;
    if (*line >= '0' && *line <= '9') ret |= (*line - '0');
    if (*line >= 'a' && *line <= 'f') ret |= (*line - 87);
    if (*line >= 'A' && *line <= 'F') ret |= (*line - 55);
    line++;
    }
  return ret;
  }

void DrawScreen() {
  Cls();
  printf("+A-+  +B-+ +------------------------------------------------------------------+\n");
  printf("|--|  |--| |                                                                  |\n");
  printf("+--+  +--+ |                                                                  |\n");
  printf("+-X--++CC+ |                                                                  |\n");
  printf("|----||--| |                                                                  |\n");
  printf("+----++--+ |                                                                  |\n");
  printf("+-Y--++DP+ |                                                                  |\n");
  printf("|----||--| |                                                                  |\n");
  printf("+----++--+ |                                                                  |\n");
  printf("+-U--+     |                                                                  |\n");
  printf("|----|     |                                                                  |\n");
  printf("+----+     |                                                                  |\n");
  printf("+-S--+     |                                                                  |\n");
  printf("|----|     |                                                                  |\n");
  printf("+----+     |                                                                  |\n");
  printf("+-PC-+     |                                                                  |\n");
  printf("|----|     |                                                                  |\n");
  printf("+----+     +------------------------------------------------------------------+\n");
  printf("- - - - - - - -\n");
  printf("\n");
  printf("  -->\n");
  printf("    >");
  }

void UpdateScreen() {
  GotoXY(2,2); printf("%02x",cpu.a);
  GotoXY(8,2); printf("%02x",cpu.b);
  GotoXY(2,5); printf("%04x",cpu.x);
  GotoXY(8,5); printf("%02x",cpu.cc);
  GotoXY(2,8); printf("%04x",cpu.y);
  GotoXY(8,8); printf("%02x",cpu.dp);
  GotoXY(2,11); printf("%04x",cpu.u);
  GotoXY(2,14); printf("%04x",cpu.s);
  GotoXY(2,17); printf("%04x",cpu.pc);
  GotoXY(1,19); if (cpu.cc & FLAG_E) printf("E"); else printf("-");
  GotoXY(3,19); if (cpu.cc & FLAG_F) printf("F"); else printf("-");
  GotoXY(5,19); if (cpu.cc & FLAG_H) printf("H"); else printf("-");
  GotoXY(7,19); if (cpu.cc & FLAG_I) printf("I"); else printf("-");
  GotoXY(9,19); if (cpu.cc & FLAG_N) printf("N"); else printf("-");
  GotoXY(11,19); if (cpu.cc & FLAG_Z) printf("Z"); else printf("-");
  GotoXY(13,19); if (cpu.cc & FLAG_V) printf("V"); else printf("-");
  GotoXY(15,19); if (cpu.cc & FLAG_C) printf("C"); else printf("-");
  }

void Output(char* msg) {
  int i;
  for (i=0; i<15; i++) {
    strcpy(lines[i], lines[i+1]);
    GotoXY(13,i+2); printf("%s", lines[i]);
    }
  strcpy(lines[15], msg);
  while (strlen(lines[15]) < 66) strcat(lines[15]," ");
  lines[15][65] = 0;
  GotoXY(13,17); printf("%s",lines[15]); fflush(stdout);
  }

void debugger_qm(char* line) {
  char l[70];
  char t[6];
  int  stack;
  int  x,y;
  stack = 0;
  if (*line == 'c' || *line == 'C') {
    sprintf(l,"Clocks: %u",clocks);
    Output(l);
    line++;
    if (*line == '-') clocks = 0;
    return;
    }
  if (IsHex(line)) address = GetHex(line);
  else if (*line == 'p' || *line == 'P') address = cpu.pc;
  else if (*line == 's' || *line == 'S') {
    address = cpu.s;
    stack = -1;
    }
  for (y=0; y<16; y++) {
    if (stack) sprintf(l,"%04x:",0x100 + (address & 0xff));
      else sprintf(l,"%04x:",address);
    for (x=0; x<16; x++) {
      if (stack) sprintf(t," %02x",ram[0x100 + ((address++) & 0xff)]);
        else sprintf(t," %02x",ram[address++]);
      strcat(l, t);
      }
    Output(l);
    }
  }

void debugger_dl(char* line) {
  char l[80];
  int  y;
  if (IsHex(line)) address = GetHex(line);
  else if (*line == 'p' || *line == 'P') address = cpu.pc;
  for (y=0; y<16; y++) {
    address = Disassem(address, l);
    Output(l);
    }
  }

void debugger_ex(char*line) {
  word v;
  word addr;
  if (*line == 'P' || *line == 'p') addr = cpu.pc;
  else if (IsHex(line)) {
    addr = GetHex(line);
    while (IsHex(line)) line++;
    while (*line == ' ') line++;
    }
  else return;
  while (IsHex(line)) {
    v = GetHex(line);
    ram[addr++] = v;
    while (IsHex(line)) line++;
    while (*line == ' ') line++;
    }
  }

void debugger_a(char*line) {
  if (*line == '=') {
    line++;
    if (IsHex(line)) {
      cpu.a = GetHex(line);
      UpdateScreen();
      }
    }
  }

void debugger_b(char* line) {
  int  i,j;
  word addr;
  char l[70];
  char t[6];
  if (*line == '?') {
    Output("Breakpoints:");
    i = 0;
    strcpy(l,"  ");
    while (i < numBreakpoints) {
      sprintf(t," %04x", breakpoints[i++]);
      strcat(l, t);
      if (strlen(l) > 62) {
        Output(l);
        strcpy(l,"  ");
        }
      }
    if (strlen(l) > 2) Output(l);
    return;
    }
  if (*line == '=') {
    line++;
    if (IsHex(line)) {
      cpu.b = GetHex(line);
      UpdateScreen();
      }
    }
    return;
  if (*line == '+') {
    line++;
    addr = GetHex(line);
    for (i=0; i<numBreakpoints; i++)
      if (breakpoints[i] == addr) return;
    breakpoints[numBreakpoints++] = addr;
    return;
    }
  if (*line == '-') {
    line++;
    addr = GetHex(line);
    for (i=0; i<numBreakpoints; i++)
      if (breakpoints[i] == addr) {
        for (j=i; j<numBreakpoints-1; j++)
          breakpoints[j] = breakpoints[j+1];
        numBreakpoints--;
        return;
        }
    return;
    }
  if (*line == 'c' || *line == 'C') {
    numBreakpoints = 0;
    return;
    }
  }

void debugger_c(char*line) {
  int i;
  int j;
  char outp[300];
  if (*line == '?') {
    Output("Conditional breakpoints:");
    for (i=0; i<numConditions; i++) {
      sprintf(outp,"%d:%s",i+1,conditions[i]);
      Output(outp);
      }
    return;
    }
  if (*line == 'c' || *line == 'C') {
    line++;
    if (*line == '=') {
      line++;
      if (IsHex(line)) {
        cpu.cc = GetHex(line);
        UpdateScreen();
        }
      return;
      }
    line--;
    }
  if (*line == '+' && *(line+1) == '+') {
    useConditions = 'Y';
    Output("Conditions enabled");
    return;
    }
  if (*line == '-' && *(line+1) == '-') {
    useConditions = 'N';
    Output("Conditions disabled");
    return;
    }
  if (*line == '+') {
    line++;
    strcpy(conditions[numConditions++], line);
    return;
    }
  if (*line == '-') {
    line++;
    j = atoi(line) - 1;
    if (j >= 0 && j < numConditions) {
      for (i=j; i<numConditions-1; i++)
        strcpy(conditions[i], conditions[i+1]);
      numConditions--;
      }
    }
  if (*line == 'c' || *line == 'C') {
    numConditions = 0;
    Output("Conditions cleared");
    return;
    }
  }


void debugger_d(char* line) {
  int  i,j;
  word addr;
  char l[70];
  char t[6];
  if (*line == 'p' || *line == 'P') {
    line++;
    if (*line == '=') {
      line++;
      if (IsHex(line)) {
        cpu.dp = GetHex(line);
        UpdateScreen();
        }
      }
    return;
    }
  }

void debugger_p(char*line) {
  if (*line == 'c' || *line == 'C') {
    line++;
    if (*line == '=') {
      line++;
      if (IsHex(line)) {
        cpu.pc = GetHex(line);
        UpdateScreen();
        }
      }
    return;
    }
  }

void debugger_s(char*line) {
  if (*line == '=') {
    line++;
    if (IsHex(line)) {
      cpu.s = GetHex(line);
      UpdateScreen();
      }
    }
  }

void debugger_u(char*line) {
  if (*line == '=') {
    line++;
    if (IsHex(line)) {
      cpu.u = GetHex(line);
      UpdateScreen();
      }
    }
  }

void debugger_t(char* line) {
  int  i;
  word addr;
  char l[70];
  char t[6];
  if (*line == 'r' || *line == 'R') {
    line++;
    if (*line == '+') tracing = 0xff;
    if (*line == '-') tracing = 0x00;
    return;
    }
  if (*line == '?') {
    Output("Traps:");
    i = 0;
    strcpy(l,"  ");
    for (i=0; i<256; i++) {
      if (traps[i] != 0) {
        sprintf(t," %02x", i);
        strcat(l, t);
        if (strlen(l) > 62) {
          Output(l);
          strcpy(l,"  ");
          }
        }
      }
    if (strlen(l) > 2) Output(l);
    return;
    }
  if (*line == '+') {
    line++;
    addr = GetHex(line);
    traps[addr & 0xff] = 0xff;
    return;
    }
  if (*line == '-') {
    line++;
    addr = GetHex(line);
    traps[addr & 0xff] = 0x00;
    return;
    }
  if (*line == 'c' || *line == 'C') {
    for (i=0; i<256; i++) traps[i] = 0x00;
    return;
    }
  }

void debugger_x(char*line) {
  if (*line == '=') {
    line++;
    if (IsHex(line)) {
      cpu.x = GetHex(line);
      UpdateScreen();
      }
    }
  }

void debugger_y(char*line) {
  if (*line == '=') {
    line++;
    if (IsHex(line)) {
      cpu.y = GetHex(line);
      UpdateScreen();
      }
    }
  }

void debugger_run(char* line) {
  int i;
  int run;
  char dis[1024];
  run = -1;
  if (IsHex(line)) cpu.pc = GetHex(line);
  while (run) {
    if (tracing) {
      Disassem(cpu.pc, dis);
      Output(dis);
      }
    cpu_cycle(&cpu);
    clocks += cpu.ts;
    if (cpu.halt != 0) run = 0;
    for (i=0; i<numBreakpoints; i++)
      if (cpu.pc == breakpoints[i]) {
        run = 0;
        UpdateScreen();
        }
    if (useConditions == 'Y') {
      for (i=0; i<numConditions; i++)
        if (evaluate(conditions[i]) != 0) {
          run = 0;
          UpdateScreen();
          }
      }
    if (traps[ram[cpu.pc]] != 0) {
      run = 0;
      UpdateScreen();
      }
    }
  UpdateScreen();
  }

void Debugger() {
  int i;
  int flag;
  char line[1024];
  char dis[1024];
  for (i=0; i<15; i++)
    strcpy(lines[i],"                                                                  ");
  for (i=0; i<256; i++) traps[i] = 0;
  address = 0;
  numBreakpoints = 0;
  numConditions = 0;
  useConditions = 'Y';
  tracing = 0;
  clocks = 0;
  DrawScreen();
  UpdateScreen();
  flag = -1;
  while (flag) {
    GotoXY(6, 21); printf("                                                               ");
    GotoXY(6, 22); printf("                                                               ");
    Disassem(cpu.pc, line);
    GotoXY(6, 21); printf("%s",line);
    GotoXY(1, 22); printf("%04x>",cpu.pc);
    fgets(line, 1023, stdin);
    while (strlen(line) > 0 && line[strlen(line)-1] <= ' ')
      line[strlen(line)-1] = 0;
    if (strcmp(line,"/") == 0) flag = 0;
    if (line[0] == '?') debugger_qm(line+1);
    if (line[0] == '$') debugger_dl(line+1);
    if (line[0] == '!') debugger_ex(line+1);
    if (line[0] == 'b' || line[0] == 'B') debugger_b(line+1);
    if (line[0] == 'c' || line[0] == 'C') debugger_c(line+1);
    if (line[0] == 'd' || line[0] == 'D') debugger_d(line+1);
    if (line[0] == 't' || line[0] == 'T') debugger_t(line+1);
    if (line[0] == 'a' || line[0] == 'A') debugger_a(line+1);
    if (line[0] == 's' || line[0] == 'S') debugger_s(line+1);
    if (line[0] == 'u' || line[0] == 'U') debugger_u(line+1);
    if (line[0] == 'x' || line[0] == 'X') debugger_x(line+1);
    if (line[0] == 'y' || line[0] == 'Y') debugger_y(line+1);
    if (line[0] == 'p' || line[0] == 'P') debugger_p(line+1);
    if (line[0] == '@') debugger_run(line+1);
    if (line[0] == 'i' || line[0] == 'I') { cpu_irq(&cpu); UpdateScreen(); }
    if (line[0] == 'f' || line[0] == 'F') { cpu_firq(&cpu); UpdateScreen(); }
    if (line[0] == 'n' || line[0] == 'N') { cpu_nmi(&cpu); UpdateScreen(); }
    if (line[0] == 'r' || line[0] == 'R') {
      cpu_reset(&cpu);
      UpdateScreen();
      }
    if (strlen(line) == 0) {
      if (tracing) {
        Disassem(cpu.pc, dis);
        Output(dis);
        }
      cpu_cycle(&cpu);
      clocks += cpu.ts;
      UpdateScreen();
      }
    }
  }



