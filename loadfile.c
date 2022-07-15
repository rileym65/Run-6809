#include "header.h"

int loadFile(char* filename) {
  word  address;
  word  v;
  FILE *file;
  char  line[1024];
  char  mode;
  char *pchar;
  int   valid;
  file = fopen(filename, "r");
  if (file == NULL) return -1;
  address = 0;
  while (fgets(line, 1023, file) != NULL) {
    mode = 'D';
    v = 0;
    valid = 0;
    pchar = line;
    while (*pchar >= ' ') {
      if (*pchar == '@') {
        if (valid)
          ram[address++] = v;
        valid = 0;
        mode = 'E';
        cpu.pc = 0;
        pchar++;
        }
      if (*pchar == ':') {
        mode = 'A';
        pchar++;
        }
      while ((*pchar >= '0' && *pchar <= '9') ||
             (*pchar >= 'a' && *pchar <= 'f') ||
             (*pchar >= 'A' && *pchar <= 'F')) {
        if (*pchar >= '0' && *pchar <= '9') v = (v << 4) | (*pchar - '0');
        if (*pchar >= 'a' && *pchar <= 'f') v = (v << 4) | (*pchar - 87);
        if (*pchar >= 'A' && *pchar <= 'F') v = (v << 4) | (*pchar - 55);
        valid = -1;
        pchar++;
        }
      if (*pchar <= ' ' && valid) {
        if (mode == 'A') address = v;
        else if (mode == 'E') cpu.pc = v;
        else ram[address++] = (v & 0xff);
        valid = 0;
        mode = 'D';
        pchar++;
        }
      while (*pchar > 0 && *pchar <= ' ') pchar++;
      }
    }
  fclose(file);
  return 0;
  }

