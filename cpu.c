#include "cpu.h"
#include "header.h"

byte readMem(byte* ram, word address) {
  return ram[address];
  }

void writeMem(byte* ram, word address, byte value) {
  if (address == 0xf000) {
    printf("%c",value);
    fflush(stdout);
    }
  if (address >= 0xf000) return;
  ram[address] = value;
  }

byte _6809_add(CPU* cpu, byte a, byte b, byte cry) {
  word c;
  if ((b & 0x0f) + (a & 0x0f) > 15) cpu->cc |= FLAG_H;
    else cpu->cc &= (~FLAG_H);
  c = a + b + cry;
  if ((c & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((c & 0xff) == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if (c > 0xff) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  if ((a & 0x80) == (b & 0x80) &&
      (a & 0x80) != (c & 0x80)) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  return c & 0xff;
  }

word _6809_add16(CPU* cpu, word a, word b, byte cry) {
  dword c;
  c = a + b + cry;
  if ((c & 0x8000) == 0x8000) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((c & 0xffff) == 0) cpu->cc |= FLAG_Z;
  if (c > 0xffff) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  if (((c & 0x10) >> 16) != ((c & 0x80) >> 15)) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  return c & 0xffff;
  }

byte _6809_sub(CPU* cpu, byte a, byte b, byte cry) {
  word c;
  word b2;
  b2 = (~b) + 1;
  if (b2 & 0x80) b2 |= 0xff00;
  c = a + b2 + cry;
GotoXY(1,27); printf("%04x\n",c);
  if ((c & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((c & 0xff) == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if (c & 0x100) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  if ((a & 0x80) == (b2 & 0x80) &&
      (a & 0x80) != (c & 0x80)) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  return c & 0xff;
  }

word _6809_sub16(CPU* cpu, word a, word b, byte cry) {
  dword c;
  dword b2;
  b2 = (~b) + 1;
  if (b2 & 0x8000) b2 |= 0xffff0000;
  c = a + b + cry;
  if ((c & 0x8000) == 0x8000) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((c & 0xffff) == 0) cpu->cc |= FLAG_Z;
  if (c > 0xffff) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  if ((a & 0x8000) == (b2 & 0x8000) &&
      (a & 0x8000) != (c & 0x8000)) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  return c & 0xffff;
  }

byte _6809_and(CPU* cpu, byte a, byte b) {
  byte c;
  c = a & b;
  if ((c & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((c & 0xff) == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  return c;
  }

byte _6809_eor(CPU* cpu, byte a, byte b) {
  byte c;
  c = a ^ b;
  if ((c & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((c & 0xff) == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  return c;
  }

byte _6809_or(CPU* cpu, byte a, byte b) {
  byte c;
  c = a ^ b;
  if ((c & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((c & 0xff) == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  return c;
  }

void _6809_tst(CPU* cpu, byte a) {
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  }

byte _6809_asl(CPU* cpu, byte a) {
  if (a & 0x80) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  a <<= 1;
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if ((cpu->cc & 1) != ((a >> 7) & 1)) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  return a;
  }

byte _6809_asr(CPU* cpu, byte a) {
  if (a & 0x01) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  a = (a & 0x80) | ((a >> 1) & 0x7f);
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  return a;
  }

byte _6809_lsl(CPU* cpu, byte a) {
  if (a & 0x80) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  a <<= 1;
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if ((cpu->cc & 1) != ((a >> 7) & 1)) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  return a;
  }

byte _6809_lsr(CPU* cpu, byte a) {
  if (a & 0x01) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  a = ((a >> 1) & 0x7f);
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  return a;
  }

byte _6809_rol(CPU* cpu, byte a) {
  byte c;
  c = (a >> 7) & 0x01;
  if ( ((a >> 7) & 0x01) ^ ((a >> 6) & 0x01) ) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  a = a << 1;
  if (cpu->cc & FLAG_C) a |= 1;
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if (c) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  return a;
  }

byte _6809_ror(CPU* cpu, byte a) {
  byte c;
  c = (a << 7) & 0x80;
  a = a >> 1;
  if (cpu->cc & FLAG_C) a |= 0x80;
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if (c) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  return a;
  }

byte _6809_com(CPU* cpu, byte a) {
  a = a ^ 0xff;
  cpu->cc |= FLAG_C;
  cpu->cc &= (~FLAG_V);
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  return a;
  }

byte _6809_neg(CPU* cpu, byte a) {
  if (a != 0) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  if (a != 0x80) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  a = (a ^ 0xff) + 1;
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  return a;
  }

byte _6809_dec(CPU* cpu, byte a) {
  if (a == 0x80) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  a = a - 1;
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((a & 0xff) == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  return a;
  }

byte _6809_inc(CPU* cpu, byte a) {
  if (a == 0x7f) cpu->cc |= FLAG_V;
    else cpu->cc &= (~FLAG_V);
  a = a + 1;
  if ((a & 0x80) == 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if ((a & 0xff) == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  return a;
  }

void _6809_push(byte* ram, CPU* cpu, byte v) {
  ram[--cpu->s] = v;
  }

void _6809_pushu(byte* ram, CPU* cpu, byte v) {
  ram[--cpu->u] = v;
  }

byte _6809_pop(byte* ram, CPU* cpu) {
  return ram[cpu->s++];
  }

byte _6809_popu(byte* ram, CPU* cpu) {
  return ram[cpu->u++];
  }


word _6809_ea(CPU* cpu) {
  byte i;
  word a;
  word a2;
  word b;
  i = readMem(ram, cpu->pc++);
  switch (i & 0x60) {
    case 0x00: a = cpu->x; break;
    case 0x20: a = cpu->y; break;
    case 0x40: a = cpu->u; break;
    case 0x60: a = cpu->s; break;
    }
  if ((i & 0x80) == 0) {
    b = i & 0x1f;
    if (b & 0x10) b |= 0xfff0;
    cpu->ts++;
    return a+b;
    }
  switch (i & 0x0f) {
    case 0x00:                                   /* ,R+ */
         switch (i & 0x60) {
           case 0x00: cpu->x++; break;
           case 0x20: cpu->y++; break;
           case 0x40: cpu->u++; break;
           case 0x60: cpu->s++; break;
           }
         cpu->ts += 2;
         return a;
         break;
    case 0x01:                                   /* ,R++ */
         switch (i & 0x60) {
           case 0x00: cpu->x += 2; break;
           case 0x20: cpu->y += 2; break;
           case 0x40: cpu->u += 2; break;
           case 0x60: cpu->s += 2; break;
           }
         cpu->ts += 3;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x02:                                   /* ,-R */
         switch (i & 0x60) {
           case 0x00: cpu->x--; a = cpu->x; break;
           case 0x20: cpu->y--; a = cpu->y; break;
           case 0x40: cpu->u--; a = cpu->u; break;
           case 0x60: cpu->s--; a = cpu->s; break;
           }
         cpu->ts += 2;
         return a;
         break;
    case 0x03:                                   /* ,--R */
         switch (i & 0x60) {
           case 0x00: cpu->x -= 2; a = cpu->x; break;
           case 0x20: cpu->y -= 2; a = cpu->y; break;
           case 0x40: cpu->u -= 2; a = cpu->u; break;
           case 0x60: cpu->s -= 2; a = cpu->s; break;
           }
         cpu->ts += 3;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x04:                                   /* ,R */
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x05:                                   /* B,R */
         b = cpu->b;
         if (b & 0x80) b |= 0xff00;
         a += b;
         cpu->ts++;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x06:                                   /* A,R */
         b = cpu->a;
         if (b & 0x80) b |= 0xff00;
         a += b;
         cpu->ts++;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x08:                                   /* nn,R */
         b = readMem(ram, cpu->pc++);
         if (b & 0x80) b |= 0xff00;
         a += b;
         cpu->ts++;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x09:                                   /* nnnn,R */
         b = (readMem(ram, cpu->pc) << 8) | readMem(ram, cpu->pc+1);
         cpu->pc += 2;
         a += b;
         cpu->ts += 4;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x0b:                                   /* D,R */
         b = (cpu->a << 8) | cpu->b;
         a += b;
         cpu->ts += 4;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x0c:                                   /* nn,PC */
         b = readMem(ram, cpu->pc++);
         a = cpu->pc;
         if (b & 0x80) b |= 0xff00;
         a += b;
         cpu->ts++;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x0d:                                   /* nnnn,PC */
         b = (readMem(ram, cpu->pc) << 8) | readMem(ram, cpu->pc+1);
         cpu->pc += 2;
         a = cpu->pc;
         a += b;
         cpu->ts += 5;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    case 0x0f:                                   /* nnnn */
         a = (readMem(ram, cpu->pc) << 8) | readMem(ram, cpu->pc+1);
         cpu->pc += 2;
         cpu->ts += 2;
         if ((i & 0x10) != 0) {
           a2 = (readMem(ram, a) << 8) | readMem(ram, a+1);
           cpu->ts += 3;
           return a2;
           }
         return a;
         break;
    }
  return 0;
  }

void _P0(CPU *cpu) {                             /* NEG < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_neg(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P1(CPU *cpu) {
  }

void _P2(CPU *cpu) {
  }

void _P3(CPU *cpu) {                             /* COM < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_com(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P4(CPU *cpu) {                             /* LSR < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_lsr(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P5(CPU *cpu) {
  }

void _P6(CPU *cpu) {                             /* ROR < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_ror(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P7(CPU *cpu) {                             /* ASR < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_asr(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P8(CPU *cpu) {                             /* ASL < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_asl(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P9(CPU *cpu) {                             /* ROL < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_rol(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _PA(CPU *cpu) {                             /* DEC < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_dec(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _PB(CPU *cpu) {
  }

void _PC(CPU *cpu) {                             /* INC < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_inc(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }
    
void _PD(CPU *cpu) {                             /* TST < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_tst(cpu, b);
  cpu->ts += 4;
  }

void _PE(CPU *cpu) {                             /* JMP < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->pc = a;
  cpu->ts += 1;
  }

void _PF(CPU *cpu) {                             /* CLR < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, 0);
  cpu->cc |= FLAG_Z;
  cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->cc &= (~FLAG_C);
  cpu->ts += 4;
  }

void _P10(CPU *cpu) {
  word a;
  word b;
  byte c;
  word d;
  c = readMem(ram, cpu->pc++);
  switch (c) {
    case 0x20:                                   /* LBRA */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         cpu->pc += d;
         cpu->ts += 3;
         break;
    case 0x21:                                   /* LBRN */
         cpu->pc += 2;
         cpu->ts += 3;
         break;
    case 0x22:                                   /* LBHI */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_C) == 0 && (cpu->cc & FLAG_Z) == 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x23:                                   /* LBLS */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_C) != 0 || (cpu->cc & FLAG_Z) != 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x24:                                   /* LBCC */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_C) == 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x25:                                   /* LBCS */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_C) != 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x26:                                   /* LBNE */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_Z) == 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x27:                                   /* LBEQ */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_Z) != 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x28:                                   /* LBVC */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_V) == 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x29:                                   /* LBVS */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_V) != 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x2a:                                   /* LBPL */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_N) == 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x2b:                                   /* LBMI */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if ((cpu->cc & FLAG_N) != 0) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x2c:                                   /* LBGE */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if (((cpu->cc >> 3) & 0x01) == ((cpu->cc >> 1) & 0x01)) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x2d:                                   /* LBLT */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if (((cpu->cc >> 3) & 0x01) != ((cpu->cc >> 1) & 0x01)) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x2e:                                   /* LBGT */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if (((cpu->cc & FLAG_Z) == 0) &&
             (((cpu->cc >> 3) & 0x01) == ((cpu->cc >> 1) & 0x01))) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x2f:                                   /* LBLE */
         d = readMem(ram, cpu->pc++) << 8;
         d |= readMem(ram, cpu->pc++);
         if (((cpu->cc & FLAG_Z) != 0) ||
             (((cpu->cc >> 3) & 0x01) != ((cpu->cc >> 1) & 0x01))) { cpu->pc += d; cpu->ts++; }
         cpu->ts += 3;
         break;
    case 0x3f:                                   /* SWI2 */
         cpu->cc |= 0x80;
         _6809_push(ram, cpu, cpu->pc & 0xff);
         _6809_push(ram, cpu, cpu->pc >> 8);
         _6809_push(ram, cpu, cpu->u & 0xff);
         _6809_push(ram, cpu, cpu->u >> 8);
         _6809_push(ram, cpu, cpu->y & 0xff);
         _6809_push(ram, cpu, cpu->y >> 8);
         _6809_push(ram, cpu, cpu->x & 0xff);
         _6809_push(ram, cpu, cpu->x >> 8);
         _6809_push(ram, cpu, cpu->dp);
         _6809_push(ram, cpu, cpu->b);
         _6809_push(ram, cpu, cpu->a);
         _6809_push(ram, cpu, cpu->cc);
         cpu->ts += 18;
         cpu->pc = readMem(ram, 0xfff4) << 8;
         cpu->pc |= readMem(ram, 0xfff5);
         break;
    case 0x83:                                   /* CMPD # */
         b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
         cpu->pc += 2;
         d = (cpu->a << 8) | cpu->b;
         _6809_sub16(cpu, d, b, 0);
         cpu->ts += 3;
         break;
    case 0x8c:                                   /* CMPY # */
         b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
         cpu->pc += 2;
         _6809_sub16(cpu, cpu->y, b, 0);
         cpu->ts += 3;
         break;
    case 0x8e:                                   /* LDY # */
         cpu->y = readMem(ram, cpu->pc++) << 8;
         cpu->y |= readMem(ram, cpu->pc++);
         if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 2;
         break;
    case 0x93:                                   /* CMPD < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         d = (cpu->a << 8) | cpu->b;
         _6809_sub16(cpu, d, b, 0);
         cpu->ts += 5;
         break;
    case 0x9c:                                   /* CMPY < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->y, b, 0);
         cpu->ts += 5;
         break;
    case 0x9e:                                   /* LDY < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         cpu->y = readMem(ram, a++) << 8;
         cpu->y |= readMem(ram, a);
         if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0x9f:                                   /* STY < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         writeMem(ram, a++, cpu->y >> 8);
         writeMem(ram, a, cpu->y & 0xff);
         if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0xa3:                                   /* CMPD , */
         a = _6809_ea(cpu);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         d = (cpu->a << 8) | cpu->b;
         _6809_sub16(cpu, d, b, 0);
         cpu->ts += 5;
         break;
    case 0xac:                                   /* CMPY , */
         a = _6809_ea(cpu);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->y, b, 0);
         cpu->ts += 5;
         break;
    case 0xae:                                   /* LDY , */
         a = _6809_ea(cpu);
         cpu->y = readMem(ram, a++) << 8;
         cpu->y |= readMem(ram, a);
         if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0xaf:                                   /* STY , */
         a = _6809_ea(cpu);
         writeMem(ram, a++, cpu->y >> 8);
         writeMem(ram, a, cpu->y & 0xff);
         if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0xb3:                                   /* CMPD nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         d = (cpu->a << 8) | cpu->b;
         _6809_sub16(cpu, d, b, 0);
         cpu->ts += 6;
         break;
    case 0xbc:                                   /* CMPY nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->y, b, 0);
         cpu->ts += 6;
         break;
    case 0xbe:                                   /* LDY nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         cpu->y = readMem(ram, a++) << 8;
         cpu->y |= readMem(ram, a);
         if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 5;
         break;
    case 0xbf:                                   /* STY nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         writeMem(ram, a++, cpu->y >> 8);
         writeMem(ram, a, cpu->y & 0xff);
         if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 5;
         break;
    case 0xce:                                   /* LDS # */
         cpu->s = readMem(ram, cpu->pc++) << 8;
         cpu->s |= readMem(ram, cpu->pc++);
         if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 2;
         break;
    case 0xde:                                   /* LDS < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         cpu->s = readMem(ram, a++) << 8;
         cpu->s |= readMem(ram, a);
         if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0xdf:                                   /* STS < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         writeMem(ram, a++, cpu->s >> 8);
         writeMem(ram, a, cpu->s & 0xff);
         if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0xee:                                   /* LDS , */
         a = _6809_ea(cpu);
         cpu->s = readMem(ram, a++) << 8;
         cpu->s |= readMem(ram, a);
         if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0xef:                                   /* STS , */
         a = _6809_ea(cpu);
         writeMem(ram, a++, cpu->s >> 8);
         writeMem(ram, a, cpu->s & 0xff);
         if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 4;
         break;
    case 0xfe:                                   /* LDS nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         cpu->s = readMem(ram, a++) << 8;
         cpu->s |= readMem(ram, a);
         if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 5;
         break;
    case 0xff:                                   /* STS nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         writeMem(ram, a++, cpu->s >> 8);
         writeMem(ram, a, cpu->s & 0xff);
         if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
         if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
         cpu->cc &= (~FLAG_V);
         cpu->ts += 5;
         break;
    }
  }

void _P11(CPU *cpu) {
  word a;
  word b;
  byte c;
  c = readMem(ram, cpu->pc++);
  switch (c) {
    case 0x3f:                                   /* SWI3 */
         cpu->cc |= 0x80;
         _6809_push(ram, cpu, cpu->pc & 0xff);
         _6809_push(ram, cpu, cpu->pc >> 8);
         _6809_push(ram, cpu, cpu->u & 0xff);
         _6809_push(ram, cpu, cpu->u >> 8);
         _6809_push(ram, cpu, cpu->y & 0xff);
         _6809_push(ram, cpu, cpu->y >> 8);
         _6809_push(ram, cpu, cpu->x & 0xff);
         _6809_push(ram, cpu, cpu->x >> 8);
         _6809_push(ram, cpu, cpu->dp);
         _6809_push(ram, cpu, cpu->b);
         _6809_push(ram, cpu, cpu->a);
         _6809_push(ram, cpu, cpu->cc);
         cpu->ts += 18;
         cpu->pc = readMem(ram, 0xfff2) << 8;
         cpu->pc |= readMem(ram, 0xfff3);
         break;
    case 0x83:                                   /* CMPU # */
         b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
         cpu->pc += 2;
         _6809_sub16(cpu, cpu->u, b, 0);
         cpu->ts += 3;
         break;
    case 0x8c:                                   /* CMPS # */
         b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
         cpu->pc += 2;
         _6809_sub16(cpu, cpu->s, b, 0);
         cpu->ts += 3;
         break;
    case 0x93:                                   /* CMPU < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->u, b, 0);
         cpu->ts += 5;
         break;
    case 0x9c:                                   /* CMPS < */
         a = cpu->dp << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->s, b, 0);
         cpu->ts += 5;
         break;
    case 0xa3:                                   /* CMPU , */
         a = _6809_ea(cpu);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->u, b, 0);
         cpu->ts += 5;
         break;
    case 0xac:                                   /* CMPS , */
         a = _6809_ea(cpu);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->s, b, 0);
         cpu->ts += 5;
         break;
    case 0xb3:                                   /* CMPU nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->u, b, 0);
         cpu->ts += 6;
         break;
    case 0xbc:                                   /* CMPS nnnn */
         a = readMem(ram, cpu->pc++) << 8;
         a |= readMem(ram, cpu->pc++);
         b = readMem(ram, a++) << 8;
         b |= readMem(ram, a);
         _6809_sub16(cpu, cpu->s, b, 0);
         cpu->ts += 6;
         break;
    }
  }

void _P12(CPU *cpu) {
  }

void _P13(CPU *cpu) {
  cpu->halt = 0xff;
  }

void _P14(CPU *cpu) {
  }

void _P15(CPU *cpu) {
  }

void _P16(CPU *cpu) {
  }

void _P17(CPU *cpu) {
  }

void _P18(CPU *cpu) {
  }

void _P19(CPU *cpu) {
  word c;
  word a;
  a = 0;
  c = cpu->a;
  if ( (cpu->cc & FLAG_C) ||
       ((cpu->a & 0xf0) > 0x90) ||
       ((cpu->a & 0xf0) > 0x80 && (cpu->a & 0x0f) > 0x09)) a |= 0x60;
  if ( (cpu->cc & FLAG_H) ||
       ((cpu->a & 0x0f) > 0x09)) a |= 0x06;
  c += a;
  cpu->a = (c & 0xff);
  if (cpu->a == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (c >= 0x100) cpu->cc |= FLAG_C;
    else cpu->cc &= (~FLAG_C);
  }

void _P1A(CPU *cpu) {                            /* ORCC */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->cc |= b;
  }

void _P1B(CPU *cpu) {
  }

void _P1C(CPU *cpu) {                            /* ANDCC */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->cc &= b;
  }

void _P1D(CPU *cpu) {                            /* SEX */
  if (cpu->b & 0x80) cpu->a = 0xff;
    else cpu->a = 0x00;
  }

void _P1E(CPU *cpu) {                            /* EXG */
  word tw;
  byte tb;
  byte b;
  word d;
  word *w1,*w2;
  byte *b1,*b2;
  b = readMem(ram, cpu->pc++);
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    }
  if (((b & 0xf0) < 0x60) && ((b &0x0f) < 0x06)) {
    tw = *w1;
    *w1 = *w2;
    *w2 = tw;
    }
  if (((b & 0xf0) > 0x60) && ((b &0x0f) > 0x06)) {
    tb = *b1;
    *b1 = *b2;
    *b2 = tb;
    }
  if (((b & 0xf0) == 0x00) || ((b & 0x0f) == 0x00)) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  cpu->ts += 6;
  }

void _P1F(CPU *cpu) {                            /* TFR r,r */
  byte b;
  word d;
  word *w1,*w2;
  byte *b1,*b2;
  b = readMem(ram, cpu->pc++);
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    }
  if (((b & 0xf0) < 0x60) && ((b &0x0f) < 0x06)) {
    *w2 = *w1;
    }
  if (((b & 0xf0) > 0x60) && ((b &0x0f) > 0x06)) {
    *b2 = *b1;
    }
  if (((b & 0xf0) == 0x00) || ((b & 0x0f) == 0x00)) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  cpu->ts += 4;
  }

void _P20(CPU *cpu) {                            /* BRA nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  cpu->pc += d;
  cpu->ts++;
  }

void _P21(CPU *cpu) {                            /* BRN nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  cpu->ts++;
  }

void _P22(CPU *cpu) {                            /* BHI nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_C) == 0 && (cpu->cc & FLAG_Z) == 0) cpu->pc += d;
  cpu->ts++;
  }

void _P23(CPU *cpu) {                            /* BLS nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_C) != 0 || (cpu->cc & FLAG_Z) != 0) cpu->pc += d;
  cpu->ts++;
  }

void _P24(CPU *cpu) {                            /* BCC nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_C) == 0) cpu->pc += d;
  cpu->ts++;
  }

void _P25(CPU *cpu) {                            /* BCS nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_C) != 0) cpu->pc += d;
  cpu->ts++;
  }

void _P26(CPU *cpu) {                            /* BNE nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_Z) == 0) cpu->pc += d;
  cpu->ts++;
  }

void _P27(CPU *cpu) {                            /* BEQ nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_Z) != 0) cpu->pc += d;
  cpu->ts++;
  }

void _P28(CPU *cpu) {                            /* BVC nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_V) == 0) cpu->pc += d;
  cpu->ts++;
  }

void _P29(CPU *cpu) {                            /* BVS nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_V) != 0) cpu->pc += d;
  cpu->ts++;
  }

void _P2A(CPU *cpu) {                            /* BPL nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_N) == 0) cpu->pc += d;
  cpu->ts++;
  }

void _P2B(CPU *cpu) {                            /* BMI nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if ((cpu->cc & FLAG_N) != 0) cpu->pc += d;
  cpu->ts++;
  }

void _P2C(CPU *cpu) {                            /* BGE nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if (((cpu->cc >> 3) & 0x01) == ((cpu->cc >> 1) & 0x01)) cpu->pc += d;
  cpu->ts++;
  }

void _P2D(CPU *cpu) {                            /* BLT nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if (((cpu->cc >> 3) & 0x01) != ((cpu->cc >> 1) & 0x01)) cpu->pc += d;
  cpu->ts++;
  }

void _P2E(CPU *cpu) {                            /* BGT nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if (((cpu->cc & FLAG_Z) == 0) &&
      (((cpu->cc >> 3) & 0x01) == ((cpu->cc >> 1) & 0x01))) cpu->pc += d;
  cpu->ts++;
  }

void _P2F(CPU *cpu) {                            /* BLE nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  if (((cpu->cc & FLAG_Z) != 0) ||
      (((cpu->cc >> 3) & 0x01) != ((cpu->cc >> 1) & 0x01))) cpu->pc += d;
  cpu->ts++;
  }

void _P30(CPU *cpu) {                            /* LEAX */
  cpu->x = _6809_ea(cpu);
  cpu->ts += 2;
  }

void _P31(CPU *cpu) {                            /* LEAY */
  cpu->y = _6809_ea(cpu);
  cpu->ts += 2;
  }

void _P32(CPU *cpu) {                            /* LEAS */
  cpu->s = _6809_ea(cpu);
  cpu->ts += 2;
  }

void _P33(CPU *cpu) {                            /* LEAU */
  cpu->u = _6809_ea(cpu);
  cpu->ts += 2;
  }

void _P34(CPU *cpu) {                            /* PSHS */
  byte b;
  b= readMem(ram, cpu->pc++);
  cpu->ts += 3;
  if (b & 0x80) {
    cpu->ts += 2;
    _6809_push(ram, cpu, cpu->pc & 0xff);
    _6809_push(ram, cpu, cpu->pc >> 8);
    }
  if (b & 0x40) {
    cpu->ts += 2;
    _6809_push(ram, cpu, cpu->u & 0xff);
    _6809_push(ram, cpu, cpu->u >> 8);
    }
  if (b & 0x20) {
    cpu->ts += 2;
    _6809_push(ram, cpu, cpu->y & 0xff);
    _6809_push(ram, cpu, cpu->y >> 8);
    }
  if (b & 0x10) {
    cpu->ts += 2;
    _6809_push(ram, cpu, cpu->x & 0xff);
    _6809_push(ram, cpu, cpu->x >> 8);
    }
  if (b & 0x08) {
    cpu->ts += 1;
    _6809_push(ram, cpu, cpu->dp);
    }
  if (b & 0x04) {
    cpu->ts += 1;
    _6809_push(ram, cpu, cpu->b);
    }
  if (b & 0x02) {
    cpu->ts += 1;
    _6809_push(ram, cpu, cpu->a);
    }
  if (b & 0x01) {
    cpu->ts += 1;
    _6809_push(ram, cpu, cpu->cc);
    }
  }

void _P35(CPU *cpu) {                            /* PULS */
  byte b;
  b= readMem(ram, cpu->pc++);
  cpu->ts += 3;
  if (b & 0x01) {
    cpu->ts += 1;
    cpu->cc = _6809_pop(ram, cpu);
    }
  if (b & 0x02) {
    cpu->ts += 1;
    cpu->a = _6809_pop(ram, cpu);
    }
  if (b & 0x04) {
    cpu->ts += 1;
    cpu->b = _6809_pop(ram, cpu);
    }
  if (b & 0x08) {
    cpu->ts += 1;
    cpu->dp = _6809_pop(ram, cpu);
    }
  if (b & 0x10) {
    cpu->ts += 2;
    cpu->x = _6809_pop(ram, cpu) << 8;
    cpu->x |= _6809_pop(ram, cpu);
    }
  if (b & 0x20) {
    cpu->ts += 2;
    cpu->y = _6809_pop(ram, cpu) << 8;
    cpu->y |= _6809_pop(ram, cpu);
    }
  if (b & 0x40) {
    cpu->ts += 2;
    cpu->u = _6809_pop(ram, cpu) << 8;
    cpu->u |= _6809_pop(ram, cpu);
    }
  if (b & 0x40) {
    cpu->ts += 2;
    cpu->pc = _6809_pop(ram, cpu) << 8;
    cpu->pc |= _6809_pop(ram, cpu);
    }
  }

void _P36(CPU *cpu) {                            /* PSHU */
  byte b;
  b= readMem(ram, cpu->pc++);
  cpu->ts += 3;
  if (b & 0x80) {
    cpu->ts += 2;
    _6809_pushu(ram, cpu, cpu->pc & 0xff);
    _6809_pushu(ram, cpu, cpu->pc >> 8);
    }
  if (b & 0x40) {
    cpu->ts += 2;
    _6809_pushu(ram, cpu, cpu->s & 0xff);
    _6809_pushu(ram, cpu, cpu->s >> 8);
    }
  if (b & 0x20) {
    cpu->ts += 2;
    _6809_pushu(ram, cpu, cpu->y & 0xff);
    _6809_pushu(ram, cpu, cpu->y >> 8);
    }
  if (b & 0x10) {
    cpu->ts += 2;
    _6809_pushu(ram, cpu, cpu->x & 0xff);
    _6809_pushu(ram, cpu, cpu->x >> 8);
    }
  if (b & 0x08) {
    cpu->ts += 1;
    _6809_pushu(ram, cpu, cpu->dp);
    }
  if (b & 0x04) {
    cpu->ts += 1;
    _6809_pushu(ram, cpu, cpu->b);
    }
  if (b & 0x02) {
    cpu->ts += 1;
    _6809_pushu(ram, cpu, cpu->a);
    }
  if (b & 0x01) {
    cpu->ts += 1;
    _6809_pushu(ram, cpu, cpu->cc);
    }
  }

void _P37(CPU *cpu) {                            /* PULU */
  byte b;
  b= readMem(ram, cpu->pc++);
  cpu->ts += 3;
  if (b & 0x01) {
    cpu->ts += 1;
    cpu->cc = _6809_popu(ram, cpu);
    }
  if (b & 0x02) {
    cpu->ts += 1;
    cpu->a = _6809_popu(ram, cpu);
    }
  if (b & 0x04) {
    cpu->ts += 1;
    cpu->b = _6809_popu(ram, cpu);
    }
  if (b & 0x08) {
    cpu->ts += 1;
    cpu->dp = _6809_popu(ram, cpu);
    }
  if (b & 0x10) {
    cpu->ts += 2;
    cpu->x = _6809_popu(ram, cpu) << 8;
    cpu->x |= _6809_popu(ram, cpu);
    }
  if (b & 0x20) {
    cpu->ts += 2;
    cpu->y = _6809_popu(ram, cpu) << 8;
    cpu->y |= _6809_popu(ram, cpu);
    }
  if (b & 0x40) {
    cpu->ts += 2;
    cpu->s = _6809_popu(ram, cpu) << 8;
    cpu->s |= _6809_popu(ram, cpu);
    }
  if (b & 0x40) {
    cpu->ts += 2;
    cpu->pc = _6809_popu(ram, cpu) << 8;
    cpu->pc |= _6809_popu(ram, cpu);
    }
  }

void _P38(CPU *cpu) {
  }

void _P39(CPU *cpu) {                            /* RTS */
  cpu->pc = _6809_pop(ram, cpu) << 8;
  cpu->pc |= _6809_pop(ram, cpu);
  cpu->ts += 3;
  }

void _P3A(CPU *cpu) {                            /* ABX */
  cpu->x += cpu->b;
  cpu->ts++;
  }

void _P3B(CPU *cpu) {                            /* RTI */
  cpu->ts += 6;
  cpu->cc = _6809_pop(ram, cpu);
  if (cpu->cc & 0x80) {
    cpu->ts += 9;
    cpu->a = _6809_pop(ram, cpu);
    cpu->b = _6809_pop(ram, cpu);
    cpu->dp = _6809_pop(ram, cpu);
    cpu->x = _6809_pop(ram, cpu) << 8;
    cpu->x |= _6809_pop(ram, cpu);
    cpu->y = _6809_pop(ram, cpu) << 8;
    cpu->y |= _6809_pop(ram, cpu);
    cpu->u = _6809_pop(ram, cpu) << 8;
    cpu->u |= _6809_pop(ram, cpu);
    }
  cpu->pc = _6809_pop(ram, cpu) << 8;
  cpu->pc |= _6809_pop(ram, cpu);
  }

void _P3C(CPU *cpu) {                            /* CWAI #*/
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->cc &= b;
  cpu->halt = 0xff;
  }

void _P3D(CPU *cpu) {                            /* MUL */
  word d;
  d = cpu->a * cpu->b;
  cpu->a = (d >> 8);
  cpu->b = d & 0xff;
  if (d == 0)  cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->ts += 9;
  if (cpu->b && 0x80) cpu->cc |= FLAG_C;
  }

void _P3E(CPU *cpu) {
  }

void _P3F(CPU *cpu) {
  cpu->cc |= 0x80;
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, cpu->pc >> 8);
  _6809_push(ram, cpu, cpu->u & 0xff);
  _6809_push(ram, cpu, cpu->u >> 8);
  _6809_push(ram, cpu, cpu->y & 0xff);
  _6809_push(ram, cpu, cpu->y >> 8);
  _6809_push(ram, cpu, cpu->x & 0xff);
  _6809_push(ram, cpu, cpu->x >> 8);
  _6809_push(ram, cpu, cpu->dp);
  _6809_push(ram, cpu, cpu->b);
  _6809_push(ram, cpu, cpu->a);
  _6809_push(ram, cpu, cpu->cc);
  cpu->cc |= 0x50;
  cpu->ts += 17;
  cpu->pc = readMem(ram, 0xfffa) << 8;
  cpu->pc |= readMem(ram, 0xfffb);
  }

void _P40(CPU *cpu) {                            /* NEGA */
  cpu->a = _6809_neg(cpu, cpu->a);
  }

void _P41(CPU *cpu) {
  }

void _P42(CPU *cpu) {
  }

void _P43(CPU *cpu) {                            /* COMA */
  cpu->a = _6809_com(cpu, cpu->a);
  }

void _P44(CPU *cpu) {                            /* LSRA */
  cpu->a = _6809_lsr(cpu, cpu->a);
  }

void _P45(CPU *cpu) {
  }

void _P46(CPU *cpu) {                            /* RORA */
  cpu->a = _6809_ror(cpu, cpu->a);
  }

void _P47(CPU *cpu) {                            /* ASRA */
  cpu->a = _6809_asr(cpu, cpu->a);
  }

void _P48(CPU *cpu) {                            /* ASLA */
  cpu->a = _6809_asl(cpu, cpu->a);
  }

void _P49(CPU *cpu) {                            /* ROLA */
  cpu->a = _6809_rol(cpu, cpu->a);
  }

void _P4A(CPU *cpu) {                            /* DECA */
  cpu->a = _6809_dec(cpu, cpu->a);
  }

void _P4B(CPU *cpu) {
  }

void _P4C(CPU *cpu) {                            /* INCA */
  cpu->a = _6809_inc(cpu, cpu->a);
  }

void _P4D(CPU *cpu) {                            /* TSTA */
  _6809_tst(cpu, cpu->a);
  }

void _P4E(CPU *cpu) {
  }

void _P4F(CPU *cpu) {                            /* CLRA */
  cpu->a = 0;
  cpu->cc |= FLAG_Z;
  cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->cc &= (~FLAG_C);
  }

void _P50(CPU *cpu) {                            /* NEGB */
  cpu->b = _6809_neg(cpu, cpu->b);
  }

void _P51(CPU *cpu) {
  }

void _P52(CPU *cpu) {
  }

void _P53(CPU *cpu) {                            /* COMB */
  cpu->b = _6809_com(cpu, cpu->b);
  }

void _P54(CPU *cpu) {                            /* LSRB */
  cpu->b = _6809_lsr(cpu, cpu->b);
  }

void _P55(CPU *cpu) {
  }

void _P56(CPU *cpu) {                            /* RORB */
  cpu->b = _6809_ror(cpu, cpu->b);
  }

void _P57(CPU *cpu) {                            /* ASRB */
  cpu->b = _6809_asr(cpu, cpu->b);
  }

void _P58(CPU *cpu) {                            /* ASLB */
  cpu->b = _6809_asl(cpu, cpu->b);
  }

void _P59(CPU *cpu) {                            /* ROLB */
  cpu->b = _6809_rol(cpu, cpu->b);
  }

void _P5A(CPU *cpu) {                            /* DECB */
  cpu->b = _6809_dec(cpu, cpu->b);
  }

void _P5B(CPU *cpu) {
  }

void _P5C(CPU *cpu) {                            /* INCB */
  cpu->b = _6809_inc(cpu, cpu->b);
  }

void _P5D(CPU *cpu) {                            /* TSTB */
  _6809_tst(cpu, cpu->b);
  }

void _P5E(CPU *cpu) {
  }

void _P5F(CPU *cpu) {                            /* CLRB */
  cpu->b = 0;
  cpu->cc |= FLAG_Z;
  cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->cc &= (~FLAG_C);
  }

void _P60(CPU *cpu) {                            /* NEG , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_neg(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P61(CPU *cpu) {
  }

void _P62(CPU *cpu) {
  }

void _P63(CPU *cpu) {                            /* COM , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_com(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P64(CPU *cpu) {                            /* LSR , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_lsr(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P65(CPU *cpu) {
  }

void _P66(CPU *cpu) {                            /* ROR , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_ror(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P67(CPU *cpu) {                            /* ASR , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_asr(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P68(CPU *cpu) {                            /* ASL , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_asl(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P69(CPU *cpu) {                            /* ROL , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_rol(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P6A(CPU *cpu) {                            /* DEC , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_dec(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P6B(CPU *cpu) {
  }

void _P6C(CPU *cpu) {                            /* INC , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  b = _6809_inc(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 4;
  }

void _P6D(CPU *cpu) {                            /* TST , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_tst(cpu, b);
  cpu->ts += 4;
  }

void _P6E(CPU *cpu) {                            /* JMP , */
  cpu->pc = _6809_ea(cpu);
  cpu->ts += 1;
  }

void _P6F(CPU *cpu) {                            /* CLR , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a, 0);
  cpu->ts += 4;
  cpu->cc |= FLAG_Z;
  cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->cc &= (~FLAG_C);
  }

void _P70(CPU *cpu) {                            /* NEG nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_neg(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P71(CPU *cpu) {
  }

void _P72(CPU *cpu) {
  }

void _P73(CPU *cpu) {                            /* COM nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_com(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P74(CPU *cpu) {                            /* LSR nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_lsr(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P75(CPU *cpu) {
  }

void _P76(CPU *cpu) {                            /* ROR nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_ror(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P77(CPU *cpu) {                            /* ASR nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_asr(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P78(CPU *cpu) {                            /* ASL nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_asl(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P79(CPU *cpu) {                            /* ROL nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_rol(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P7A(CPU *cpu) {                            /* DEC nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_dec(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P7B(CPU *cpu) {
  }

void _P7C(CPU *cpu) {                            /* INC nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = _6809_inc(cpu, b);
  writeMem(ram, a, b);
  cpu->ts += 5;
  }

void _P7D(CPU *cpu) {                            /* TST nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_tst(cpu, b);
  cpu->ts += 5;
  }

void _P7E(CPU *cpu) {                            /* JMP nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->pc = a;
  cpu->ts += 2;
  }

void _P7F(CPU *cpu) {                            /* CLR nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, 0);
  cpu->cc |= FLAG_Z;
  cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->cc &= (~FLAG_C);
  cpu->ts += 5;
  }

void _P80(CPU *cpu) {                            /* SUBA # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->a = _6809_sub(cpu, cpu->a, b, 0);
  }

void _P81(CPU *cpu) {                            /* CMPA # */
  byte b;
  b = readMem(ram, cpu->pc++);
  _6809_sub(cpu, cpu->a, b, 0);
  }

void _P82(CPU *cpu) {                            /* SBCA # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->a = _6809_sub(cpu, cpu->a, b, cpu->cc & 0x01);
  }

void _P83(CPU *cpu) {                            /* SUBD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, cpu->b, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 2;
  }

void _P84(CPU *cpu) {                            /* ANDA # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->a = _6809_and(cpu, cpu->a, b);
  }

void _P85(CPU *cpu) {                            /* BITA # */
  byte b;
  b = readMem(ram, cpu->pc++);
  _6809_and(cpu, cpu->a, b);
  }

void _P86(CPU *cpu) {                            /* LDA # */
  cpu->a = readMem(ram, cpu->pc++);
  if (cpu->a == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  }

void _P87(CPU *cpu) {
  }

void _P88(CPU *cpu) {                           /* EOR # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->a = _6809_eor(cpu, cpu->a, b);
  }

void _P89(CPU *cpu) {                            /* ADCA #n */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->a = _6809_add(cpu, cpu->a, b, cpu->cc & 0x01);
  }

void _P8A(CPU *cpu) {                            /* ORA # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->a = _6809_or(cpu, cpu->a, b);
  }

void _P8B(CPU *cpu) {                            /* ADDA # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->a = _6809_add(cpu, cpu->a, b, 0);
  }

void _P8C(CPU *cpu) {                            /* CMPX # */
  word b;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  _6809_sub16(cpu, cpu->x, b, 0);
  cpu->ts += 2;
  }

void _P8D(CPU *cpu) {                            /* BSR nn */
  word d;
  d = readMem(ram, cpu->pc++);
  if (d & 0x80) d |= 0xff00;
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, (cpu->pc >> 8));
  cpu->pc += d;
  cpu->ts += 5;
  }

void _P8E(CPU *cpu) {                            /* LDX # */
  cpu->x = readMem(ram, cpu->pc++) << 8;
  cpu->x |= readMem(ram, cpu->pc++);
  if (cpu->x == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->x & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts++;
  }

void _P8F(CPU *cpu) {
  }

void _P90(CPU *cpu) {                            /* SUBA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_sub(cpu, cpu->a, b, 0);
  cpu->ts += 2;
  }

void _P91(CPU *cpu) {                            /* CMPA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->a, b, 0);
  cpu->ts += 2;
  }

void _P92(CPU *cpu) {                            /* SBCA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_sub(cpu, cpu->a, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _P93(CPU *cpu) {                            /* SUBD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, d, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 4;
  }

void _P94(CPU *cpu) {                            /* ANDA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_and(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _P95(CPU *cpu) {                            /* BITA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_and(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _P96(CPU *cpu) {                            /* LDA < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->a = readMem(ram, a);
  if (cpu->a == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _P97(CPU *cpu) {                            /* STA < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->a);
  if (cpu->a == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _P98(CPU *cpu) {                           /* EORA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_eor(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _P99(CPU *cpu) {                            /* ADCA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_add(cpu, cpu->a, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _P9A(CPU *cpu) {                            /* ORA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_or(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _P9B(CPU *cpu) {                            /* ADDA < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_add(cpu, cpu->a, b, 0);
  cpu->ts += 2;
  }

void _P9C(CPU *cpu) {                            /* CMPX < */
  word a;
  word b;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->x, b, 0);
  cpu->ts += 4;
  }

void _P9D(CPU *cpu) {                            /* JSR < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, (cpu->pc >> 8));
  cpu->pc = a;
  cpu->ts += 5;
  }

void _P9E(CPU *cpu) {                            /* LDX < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->x = readMem(ram, a++) << 8;
  cpu->x |= readMem(ram, a);
  if (cpu->x == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->x & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _P9F(CPU *cpu) {                            /* STX < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->x >> 8);
  writeMem(ram, a, cpu->x & 0xff);
  if (cpu->x == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->x & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PA0(CPU *cpu) {                            /* SUBA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->a = _6809_sub(cpu, cpu->a, b, 0);
  cpu->ts += 2;
  }

void _PA1(CPU *cpu) {                            /* CMPA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->a, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _PA2(CPU *cpu) {                            /* SBCA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->a = _6809_sub(cpu, cpu->a, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _PA3(CPU *cpu) {                            /* SUBD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, d, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 4;
  }

void _PA4(CPU *cpu) {                            /* ANDA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->a = _6809_and(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _PA5(CPU *cpu) {                            /* BITA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_and(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _PA6(CPU *cpu) {                            /* LDA , */
  word a;
  a = _6809_ea(cpu);
  cpu->a = readMem(ram, a);
  if (cpu->a == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _PA7(CPU *cpu) {                            /* STA , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a, cpu->a);
  if (cpu->a == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _PA8(CPU *cpu) {                            /* EORA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->a = _6809_eor(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _PA9(CPU *cpu) {                            /* ADCA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->a = _6809_add(cpu, cpu->a, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _PAA(CPU *cpu) {                            /* ORA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->a = _6809_or(cpu, cpu->a, b);
  cpu->ts += 2;
  }

void _PAB(CPU *cpu) {                            /* ADDA , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->a = _6809_add(cpu, cpu->a, b, 0);
  cpu->ts += 2;
  }

void _PAC(CPU *cpu) {                            /* CMPX , */
  word a;
  word b;
  a = _6809_ea(cpu);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->x, b, 0);
  cpu->ts += 4;
  }

void _PAD(CPU *cpu) {                            /* JSR , */
  word a;
  a = _6809_ea(cpu);
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, (cpu->pc >> 8));
  cpu->pc = a;
  cpu->ts += 5;
  }

void _PAE(CPU *cpu) {                            /* LDX , */
  word a;
  a = _6809_ea(cpu);
  cpu->x = readMem(ram, a++) << 8;
  cpu->x |= readMem(ram, a);
  if (cpu->x == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->x & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PAF(CPU *cpu) {                            /* STX , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a++, cpu->x >> 8);
  writeMem(ram, a, cpu->x & 0xff);
  if (cpu->x == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->x & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PB0(CPU *cpu) {                            /* SUBA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_sub(cpu, cpu->a, b, 0);
  cpu->ts += 3;
  }

void _PB1(CPU *cpu) {                            /* CMPA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->a, b, 0);
  cpu->ts += 3;
  }

void _PB2(CPU *cpu) {                            /* SBCA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_sub(cpu, cpu->a, b, cpu->cc & 0x01);
  cpu->ts += 3;
  }

void _PB3(CPU *cpu) {                            /* SUBD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, d, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 6;
  }

void _PB4(CPU *cpu) {                            /* ANDA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_and(cpu, cpu->a, b);
  cpu->ts += 3;
  }

void _PB5(CPU *cpu) {                            /* BITA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_and(cpu, cpu->a, b);
  cpu->ts += 3;
  }

void _PB6(CPU *cpu) {                            /* LDA nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->a = readMem(ram, a);
  if (cpu->a == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PB7(CPU *cpu) {                            /* STA nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->a);
  if (cpu->a == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PB8(CPU *cpu) {                            /* EORA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_eor(cpu, cpu->a, b);
  cpu->ts += 3;
  }

void _PB9(CPU *cpu) {                            /* ADCA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_add(cpu, cpu->a, b, cpu->cc & 0x01);
  cpu->ts += 3;
  }

void _PBA(CPU *cpu) {                            /* ORA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_or(cpu, cpu->a, b);
  cpu->ts += 3;
  }

void _PBB(CPU *cpu) {                            /* ADDA nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->a = _6809_add(cpu, cpu->a, b, 0);
  cpu->ts += 3;
  }

void _PBC(CPU *cpu) {                            /* CMPX nnnn */
  word a;
  word b;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->x, b, 0);
  cpu->ts += 5;
  }

void _PBD(CPU *cpu) {                            /* JSR nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, (cpu->pc >> 8));
  cpu->pc = a;
  cpu->ts += 6;
  }

void _PBE(CPU *cpu) {                            /* LDX nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->x = readMem(ram, a++) << 8;
  cpu->x |= readMem(ram, a);
  if (cpu->x == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->x & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 4;
  }

void _PBF(CPU *cpu) {                            /* STX nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->x >> 8);
  writeMem(ram, a, cpu->x & 0xff);
  if (cpu->x == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->x & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 4;
  }

void _PC0(CPU *cpu) {                            /* SUBB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->b = _6809_sub(cpu, cpu->b, b, 0);
  }

void _PC1(CPU *cpu) {                            /* CMPB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  _6809_sub(cpu, cpu->b, b, 0);
  }

void _PC2(CPU *cpu) {                            /* SBCB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->b = _6809_sub(cpu, cpu->b, b, cpu->cc & 0x01);
  }

void _PC3(CPU *cpu) {                            /* ADDD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, cpu->b, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 2;
  }

void _PC4(CPU *cpu) {                            /* ANDB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->b = _6809_and(cpu, cpu->b, b);
  }

void _PC5(CPU *cpu) {                            /* BITB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  _6809_and(cpu, cpu->b, b);
  }

void _PC6(CPU *cpu) {                            /* LDB # */
  cpu->b = readMem(ram, cpu->pc++);
  if (cpu->b == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->b & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  }

void _PC7(CPU *cpu) {
  }

void _PC8(CPU *cpu) {                            /* EORB */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->b = _6809_eor(cpu, cpu->b, b);
  }

void _PC9(CPU *cpu) {                            /* ADCB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->b = _6809_add(cpu, cpu->b, b, cpu->cc & 0x01);
  }

void _PCA(CPU *cpu) {                            /* ORB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->b = _6809_or(cpu, cpu->b, b);
  }

void _PCB(CPU *cpu) {                            /* ADDB # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->b = _6809_add(cpu, cpu->b, b, 0);
  }

void _PCC(CPU *cpu) {                            /* LDD # */
  cpu->a = readMem(ram, cpu->pc++);
  cpu->b = readMem(ram, cpu->pc++);
  if ((cpu->b | cpu->a) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts++;
  }

void _PCD(CPU *cpu) {
  }

void _PCE(CPU *cpu) {                            /* LDU # */
  cpu->u = readMem(ram, cpu->pc++) << 8;
  cpu->u |= readMem(ram, cpu->pc++);
  if (cpu->u == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->u & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts++;
  }

void _PCF(CPU *cpu) {
  }

void _PD0(CPU *cpu) {                            /* SUBB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_sub(cpu, cpu->b, b, 0);
  cpu->ts += 2;
  }

void _PD1(CPU *cpu) {                            /* CMPB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->b, b, 0);
  cpu->ts += 2;
  }

void _PD2(CPU *cpu) {                            /* SBCB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_sub(cpu, cpu->b, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _PD3(CPU *cpu) {                            /* ADDD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, d, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 4;
  }

void _PD4(CPU *cpu) {                            /* ANDB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_and(cpu, cpu->b, b);
  cpu->ts += 2;
  }

void _PD5(CPU *cpu) {                            /* BITB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_and(cpu, cpu->b, b);
  cpu->ts += 2;
  }

void _PD6(CPU *cpu) {                            /* LDB < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->b = readMem(ram, a);
  if (cpu->b == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->b & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _PD7(CPU *cpu) {                            /* STB < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->b);
  if (cpu->b == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->b & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _PD8(CPU *cpu) {                            /* EORB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_eor(cpu, cpu->b, b);
  cpu->ts += 2;
  }

void _PD9(CPU *cpu) {                            /* ADCB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_add(cpu, cpu->b, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _PDA(CPU *cpu) {                            /* ORB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_or(cpu, cpu->b, b);
  cpu->ts += 2;
  }

void _PDB(CPU *cpu) {                            /* ADDB < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_add(cpu, cpu->b, b, 0);
  cpu->ts += 2;
  }

void _PDC(CPU *cpu) {                            /* LDD < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->a = readMem(ram, a++);
  cpu->b = readMem(ram, a);
  if ((cpu->a | cpu->b) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PDD(CPU *cpu) {                            /* STD < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->a);
  writeMem(ram, a, cpu->b);
  if ((cpu->a | cpu->b) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PDE(CPU *cpu) {                            /* LDU < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->u = readMem(ram, a++) << 8;
  cpu->u |= readMem(ram, a);
  if (cpu->u == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->u & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PDF(CPU *cpu) {                            /* STU < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->u >> 8);
  writeMem(ram, a, cpu->u & 0xff);
  if (cpu->u == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->u & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PE0(CPU *cpu) {                            /* SUBB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->b = _6809_sub(cpu, cpu->b, b, 0);
  cpu->ts += 2;
  }

void _PE1(CPU *cpu) {                            /* CMPB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->b, b, 0);
  cpu->ts += 2;
  }

void _PE2(CPU *cpu) {                            /* SBCB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->b = _6809_sub(cpu, cpu->b, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _PE3(CPU *cpu) {
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, d, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 4;
  }

void _PE4(CPU *cpu) {                            /* ANDB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->b = _6809_and(cpu, cpu->b, b);
  cpu->ts += 2;
  }

void _PE5(CPU *cpu) {                            /* BITB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_and(cpu, cpu->b, b);
  cpu->ts += 2;
  }

void _PE6(CPU *cpu) {                            /* LDB , */
  word a;
  a = _6809_ea(cpu);
  cpu->b = readMem(ram, a);
  if (cpu->b == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->b & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _PE7(CPU *cpu) {                            /* STB , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a, cpu->b);
  if (cpu->b == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->b & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 2;
  }

void _PE8(CPU *cpu) {                            /* EORB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->b = _6809_eor(cpu, cpu->b, b);
  cpu->ts += 2;
  }

void _PE9(CPU *cpu) {                            /* ADCB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->b = _6809_add(cpu, cpu->b, b, cpu->cc & 0x01);
  cpu->ts += 2;
  }

void _PEA(CPU *cpu) {                            /* ORB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->b = _6809_or(cpu, cpu->b, b);
  cpu->ts += 2;
 }

void _PEB(CPU *cpu) {                            /* ADDB , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->b = _6809_add(cpu, cpu->b, b, 0);
  cpu->ts += 2;
  }

void _PEC(CPU *cpu) {                            /* LDD , */
  word a;
  a = _6809_ea(cpu);
  cpu->a = readMem(ram, a++);
  cpu->b = readMem(ram, a);
  if ((cpu->a | cpu->b) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PED(CPU *cpu) {                            /* STD , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a++, cpu->a);
  writeMem(ram, a, cpu->b);
  if ((cpu->a | cpu->b) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PEE(CPU *cpu) {                            /* LDU , */
  word a;
  a = _6809_ea(cpu);
  cpu->u = readMem(ram, a++) << 8;
  cpu->u |= readMem(ram, a);
  if (cpu->u == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->u & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PEF(CPU *cpu) {                            /* STU , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a++, cpu->u >> 8);
  writeMem(ram, a, cpu->u & 0xff);
  if (cpu->u == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->u & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PF0(CPU *cpu) {                            /* SUBB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_sub(cpu, cpu->b, b, 0);
  cpu->ts += 3;
  }

void _PF1(CPU *cpu) {                            /* CMPB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->b, b, 0);
  cpu->ts += 3;
  }

void _PF2(CPU *cpu) {                            /* SBCB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_sub(cpu, cpu->b, b, cpu->cc & 0x01);
  cpu->ts += 3;
  }

void _PF3(CPU *cpu) {                            /* ADDD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, d, b, 0);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += 6;
  }

void _PF4(CPU *cpu) {                            /* ANDB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_and(cpu, cpu->b, b);
  cpu->ts += 3;
  }

void _PF5(CPU *cpu) {                            /* BITB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_and(cpu, cpu->b, b);
  cpu->ts += 3;
  }

void _PF6(CPU *cpu) {                            /* LDB nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->b = readMem(ram, a);
  if (cpu->b == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->b & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PF7(CPU *cpu) {                            /* STB nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->b);
  if (cpu->b == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->b & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 3;
  }

void _PF8(CPU *cpu) {                            /* EORB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_eor(cpu, cpu->b, b);
  cpu->ts += 3;
  }

void _PF9(CPU *cpu) {                            /* ADCB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_add(cpu, cpu->b, b, cpu->cc & 0x01);
  cpu->ts += 3;
  }

void _PFA(CPU *cpu) {                            /* ORB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_or(cpu, cpu->b, b);
  cpu->ts += 3;
  }

void _PFB(CPU *cpu) {                            /* ADDB nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->b = _6809_add(cpu, cpu->b, b, 0);
  cpu->ts += 3;
  }

void _PFC(CPU *cpu) {                            /* LDD nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->a = readMem(ram, a++);
  cpu->b = readMem(ram, a);
  if ((cpu->a | cpu->b) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 4;
  }

void _PFD(CPU *cpu) {                            /* STD nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->a);
  writeMem(ram, a, cpu->b);
  if ((cpu->a | cpu->b) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 4;
  }

void _PFE(CPU *cpu) {                            /* LDU nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->u = readMem(ram, a++) << 8;
  cpu->u |= readMem(ram, a);
  if (cpu->u == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->u & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 4;
  }

void _PFF(CPU *cpu) {                            /* STU nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->u >> 8);
  writeMem(ram, a, cpu->u & 0xff);
  if (cpu->u == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->u & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += 4;
  }

void cpu_prepare(CPU *cpu) {
  cpu->Inst[0x00]=_P0; cpu->Inst[0x01]=_P1; cpu->Inst[0x02]=_P2; cpu->Inst[0x03]=_P3;
  cpu->Inst[0x04]=_P4; cpu->Inst[0x05]=_P5; cpu->Inst[0x06]=_P6; cpu->Inst[0x07]=_P7;
  cpu->Inst[0x08]=_P8; cpu->Inst[0x09]=_P9; cpu->Inst[0x0a]=_PA; cpu->Inst[0x0b]=_PB;
  cpu->Inst[0x0c]=_PC; cpu->Inst[0x0d]=_PD; cpu->Inst[0x0e]=_PE; cpu->Inst[0x0f]=_PF;

  cpu->Inst[0x10]=_P10; cpu->Inst[0x11]=_P11; cpu->Inst[0x12]=_P12; cpu->Inst[0x13]=_P13;
  cpu->Inst[0x14]=_P14; cpu->Inst[0x15]=_P15; cpu->Inst[0x16]=_P16; cpu->Inst[0x17]=_P17;
  cpu->Inst[0x18]=_P18; cpu->Inst[0x19]=_P19; cpu->Inst[0x1a]=_P1A; cpu->Inst[0x1b]=_P1B;
  cpu->Inst[0x1c]=_P1C; cpu->Inst[0x1d]=_P1D; cpu->Inst[0x1e]=_P1E; cpu->Inst[0x1f]=_P1F;

  cpu->Inst[0x20]=_P20; cpu->Inst[0x21]=_P21; cpu->Inst[0x22]=_P22; cpu->Inst[0x23]=_P23;
  cpu->Inst[0x24]=_P24; cpu->Inst[0x25]=_P25; cpu->Inst[0x26]=_P26; cpu->Inst[0x27]=_P27;
  cpu->Inst[0x28]=_P28; cpu->Inst[0x29]=_P29; cpu->Inst[0x2a]=_P2A; cpu->Inst[0x2b]=_P2B;
  cpu->Inst[0x2c]=_P2C; cpu->Inst[0x2d]=_P2D; cpu->Inst[0x2e]=_P2E; cpu->Inst[0x2f]=_P2F;

  cpu->Inst[0x30]=_P30; cpu->Inst[0x31]=_P31; cpu->Inst[0x32]=_P32; cpu->Inst[0x33]=_P33;
  cpu->Inst[0x34]=_P34; cpu->Inst[0x35]=_P35; cpu->Inst[0x36]=_P36; cpu->Inst[0x37]=_P37;
  cpu->Inst[0x38]=_P38; cpu->Inst[0x39]=_P39; cpu->Inst[0x3a]=_P3A; cpu->Inst[0x3b]=_P3B;
  cpu->Inst[0x3c]=_P3C; cpu->Inst[0x3d]=_P3D; cpu->Inst[0x3e]=_P3E; cpu->Inst[0x3f]=_P3F;

  cpu->Inst[0x40]=_P40; cpu->Inst[0x41]=_P41; cpu->Inst[0x42]=_P42; cpu->Inst[0x43]=_P43;
  cpu->Inst[0x44]=_P44; cpu->Inst[0x45]=_P45; cpu->Inst[0x46]=_P46; cpu->Inst[0x47]=_P47;
  cpu->Inst[0x48]=_P48; cpu->Inst[0x49]=_P49; cpu->Inst[0x4a]=_P4A; cpu->Inst[0x4b]=_P4B;
  cpu->Inst[0x4c]=_P4C; cpu->Inst[0x4d]=_P4D; cpu->Inst[0x4e]=_P4E; cpu->Inst[0x4f]=_P4F;

  cpu->Inst[0x50]=_P50; cpu->Inst[0x51]=_P51; cpu->Inst[0x52]=_P52; cpu->Inst[0x53]=_P53;
  cpu->Inst[0x54]=_P54; cpu->Inst[0x55]=_P55; cpu->Inst[0x56]=_P56; cpu->Inst[0x57]=_P57;
  cpu->Inst[0x58]=_P58; cpu->Inst[0x59]=_P59; cpu->Inst[0x5a]=_P5A; cpu->Inst[0x5b]=_P5B;
  cpu->Inst[0x5c]=_P5C; cpu->Inst[0x5d]=_P5D; cpu->Inst[0x5e]=_P5E; cpu->Inst[0x5f]=_P5F;

  cpu->Inst[0x60]=_P60; cpu->Inst[0x61]=_P61; cpu->Inst[0x62]=_P62; cpu->Inst[0x63]=_P63;
  cpu->Inst[0x64]=_P64; cpu->Inst[0x65]=_P65; cpu->Inst[0x66]=_P66; cpu->Inst[0x67]=_P67;
  cpu->Inst[0x68]=_P68; cpu->Inst[0x69]=_P69; cpu->Inst[0x6a]=_P6A; cpu->Inst[0x6b]=_P6B;
  cpu->Inst[0x6c]=_P6C; cpu->Inst[0x6d]=_P6D; cpu->Inst[0x6e]=_P6E; cpu->Inst[0x6f]=_P6F;

  cpu->Inst[0x70]=_P70; cpu->Inst[0x71]=_P71; cpu->Inst[0x72]=_P72; cpu->Inst[0x73]=_P73;
  cpu->Inst[0x74]=_P74; cpu->Inst[0x75]=_P75; cpu->Inst[0x76]=_P76; cpu->Inst[0x77]=_P77;
  cpu->Inst[0x78]=_P78; cpu->Inst[0x79]=_P79; cpu->Inst[0x7a]=_P7A; cpu->Inst[0x7b]=_P7B;
  cpu->Inst[0x7c]=_P7C; cpu->Inst[0x7d]=_P7D; cpu->Inst[0x7e]=_P7E; cpu->Inst[0x7f]=_P7F;

  cpu->Inst[0x80]=_P80; cpu->Inst[0x81]=_P81; cpu->Inst[0x82]=_P82; cpu->Inst[0x83]=_P83;
  cpu->Inst[0x84]=_P84; cpu->Inst[0x85]=_P85; cpu->Inst[0x86]=_P86; cpu->Inst[0x87]=_P87;
  cpu->Inst[0x88]=_P88; cpu->Inst[0x89]=_P89; cpu->Inst[0x8a]=_P8A; cpu->Inst[0x8b]=_P8B;
  cpu->Inst[0x8c]=_P8C; cpu->Inst[0x8d]=_P8D; cpu->Inst[0x8e]=_P8E; cpu->Inst[0x8f]=_P8F;

  cpu->Inst[0x90]=_P90; cpu->Inst[0x91]=_P91; cpu->Inst[0x92]=_P92; cpu->Inst[0x93]=_P93;
  cpu->Inst[0x94]=_P94; cpu->Inst[0x95]=_P95; cpu->Inst[0x96]=_P96; cpu->Inst[0x97]=_P97;
  cpu->Inst[0x98]=_P98; cpu->Inst[0x99]=_P99; cpu->Inst[0x9a]=_P9A; cpu->Inst[0x9b]=_P9B;
  cpu->Inst[0x9c]=_P9C; cpu->Inst[0x9d]=_P9D; cpu->Inst[0x9e]=_P9E; cpu->Inst[0x9f]=_P9F;

  cpu->Inst[0xa0]=_PA0; cpu->Inst[0xa1]=_PA1; cpu->Inst[0xa2]=_PA2; cpu->Inst[0xa3]=_PA3;
  cpu->Inst[0xa4]=_PA4; cpu->Inst[0xa5]=_PA5; cpu->Inst[0xa6]=_PA6; cpu->Inst[0xa7]=_PA7;
  cpu->Inst[0xa8]=_PA8; cpu->Inst[0xa9]=_PA9; cpu->Inst[0xaa]=_PAA; cpu->Inst[0xab]=_PAB;
  cpu->Inst[0xac]=_PAC; cpu->Inst[0xad]=_PAD; cpu->Inst[0xae]=_PAE; cpu->Inst[0xaf]=_PAF;

  cpu->Inst[0xb0]=_PB0; cpu->Inst[0xb1]=_PB1; cpu->Inst[0xb2]=_PB2; cpu->Inst[0xb3]=_PB3;
  cpu->Inst[0xb4]=_PB4; cpu->Inst[0xb5]=_PB5; cpu->Inst[0xb6]=_PB6; cpu->Inst[0xb7]=_PB7;
  cpu->Inst[0xb8]=_PB8; cpu->Inst[0xb9]=_PB9; cpu->Inst[0xba]=_PBA; cpu->Inst[0xbb]=_PBB;
  cpu->Inst[0xbc]=_PBC; cpu->Inst[0xbd]=_PBD; cpu->Inst[0xbe]=_PBE; cpu->Inst[0xbf]=_PBF;

  cpu->Inst[0xc0]=_PC0; cpu->Inst[0xc1]=_PC1; cpu->Inst[0xc2]=_PC2; cpu->Inst[0xc3]=_PC3;
  cpu->Inst[0xc4]=_PC4; cpu->Inst[0xc5]=_PC5; cpu->Inst[0xc6]=_PC6; cpu->Inst[0xc7]=_PC7;
  cpu->Inst[0xc8]=_PC8; cpu->Inst[0xc9]=_PC9; cpu->Inst[0xca]=_PCA; cpu->Inst[0xcb]=_PCB;
  cpu->Inst[0xcc]=_PCC; cpu->Inst[0xcd]=_PCD; cpu->Inst[0xce]=_PCE; cpu->Inst[0xcf]=_PCF;

  cpu->Inst[0xd0]=_PD0; cpu->Inst[0xd1]=_PD1; cpu->Inst[0xd2]=_PD2; cpu->Inst[0xd3]=_PD3;
  cpu->Inst[0xd4]=_PD4; cpu->Inst[0xd5]=_PD5; cpu->Inst[0xd6]=_PD6; cpu->Inst[0xd7]=_PD7;
  cpu->Inst[0xd8]=_PD8; cpu->Inst[0xd9]=_PD9; cpu->Inst[0xda]=_PDA; cpu->Inst[0xdb]=_PDB;
  cpu->Inst[0xdc]=_PDC; cpu->Inst[0xdd]=_PDD; cpu->Inst[0xde]=_PDE; cpu->Inst[0xdf]=_PDF;

  cpu->Inst[0xe0]=_PE0; cpu->Inst[0xe1]=_PE1; cpu->Inst[0xe2]=_PE2; cpu->Inst[0xe3]=_PE3;
  cpu->Inst[0xe4]=_PE4; cpu->Inst[0xe5]=_PE5; cpu->Inst[0xe6]=_PE6; cpu->Inst[0xe7]=_PE7;
  cpu->Inst[0xe8]=_PE8; cpu->Inst[0xe9]=_PE9; cpu->Inst[0xea]=_PEA; cpu->Inst[0xeb]=_PEB;
  cpu->Inst[0xec]=_PEC; cpu->Inst[0xed]=_PED; cpu->Inst[0xee]=_PEE; cpu->Inst[0xef]=_PEF;

  cpu->Inst[0xf0]=_PF0; cpu->Inst[0xf1]=_PF1; cpu->Inst[0xf2]=_PF2; cpu->Inst[0xf3]=_PF3;
  cpu->Inst[0xf4]=_PF4; cpu->Inst[0xf5]=_PF5; cpu->Inst[0xf6]=_PF6; cpu->Inst[0xf7]=_PF7;
  cpu->Inst[0xf8]=_PF8; cpu->Inst[0xf9]=_PF9; cpu->Inst[0xfa]=_PFA; cpu->Inst[0xfb]=_PFB;
  cpu->Inst[0xfc]=_PFC; cpu->Inst[0xfd]=_PFD; cpu->Inst[0xfe]=_PFE; cpu->Inst[0xff]=_PFF;
  }

void cpu_firq(CPU* cpu) {
  if ((cpu->cc & FLAG_F) != 0) return;
  cpu->cc &= 0x7f;
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, cpu->pc >> 8);
  _6809_push(ram, cpu, cpu->cc);
  cpu->pc = readMem(ram, 0xfff6) << 8;
  cpu->pc |= readMem(ram, 0xfff7);
  cpu->halt = 0;
  }

void cpu_irq(CPU* cpu) {
  if ((cpu->cc & FLAG_I) != 0) return;
  cpu->cc |= 0x80;
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, cpu->pc >> 8);
  _6809_push(ram, cpu, cpu->u & 0xff);
  _6809_push(ram, cpu, cpu->u >> 8);
  _6809_push(ram, cpu, cpu->y & 0xff);
  _6809_push(ram, cpu, cpu->y >> 8);
  _6809_push(ram, cpu, cpu->x & 0xff);
  _6809_push(ram, cpu, cpu->x >> 8);
  _6809_push(ram, cpu, cpu->dp);
  _6809_push(ram, cpu, cpu->b);
  _6809_push(ram, cpu, cpu->a);
  _6809_push(ram, cpu, cpu->cc);
  cpu->pc = readMem(ram, 0xfff8) << 8;
  cpu->pc |= readMem(ram, 0xfff9);
  cpu->halt = 0;
  }

void cpu_nmi(CPU* cpu) {
  cpu->cc |= 0x80;
  _6809_push(ram, cpu, cpu->pc & 0xff);
  _6809_push(ram, cpu, cpu->pc >> 8);
  _6809_push(ram, cpu, cpu->u & 0xff);
  _6809_push(ram, cpu, cpu->u >> 8);
  _6809_push(ram, cpu, cpu->y & 0xff);
  _6809_push(ram, cpu, cpu->y >> 8);
  _6809_push(ram, cpu, cpu->x & 0xff);
  _6809_push(ram, cpu, cpu->x >> 8);
  _6809_push(ram, cpu, cpu->dp);
  _6809_push(ram, cpu, cpu->b);
  _6809_push(ram, cpu, cpu->a);
  _6809_push(ram, cpu, cpu->cc);
  cpu->pc = readMem(ram, 0xfffc) << 8;
  cpu->pc |= readMem(ram, 0xfffd);
  cpu->halt = 0;
  }

void cpu_reset(CPU* cpu) {
  cpu->pc = (readMem(ram, 0xfffe) << 8) | readMem(ram, 0xffff);
  cpu->dp = 0;
  }

void cpu_cycle(CPU* cpu) {
  byte cmd;
  if (cpu->halt != 0) return;
  cmd = readMem(ram, cpu->pc++);
  cpu->ts = 2;
  cpu->Inst[cmd](cpu);
  }

