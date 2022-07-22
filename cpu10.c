#include "cpu.h"
#include "header.h"

void _P10_I(CPU *cpu) {
  }

void _P10_0(CPU *cpu) {
  }

void _P10_1(CPU *cpu) {
  }

void _P10_2(CPU *cpu) {
  }

void _P10_3(CPU *cpu) {
  }

void _P10_4(CPU *cpu) {
  }

void _P10_5(CPU *cpu) {
  }

void _P10_6(CPU *cpu) {
  }

void _P10_7(CPU *cpu) {
  }

void _P10_8(CPU *cpu) {
  }

void _P10_9(CPU *cpu) {
  }

void _P10_A(CPU *cpu) {
  }

void _P10_B(CPU *cpu) {
  }

void _P10_C(CPU *cpu) {
  }
    
void _P10_D(CPU *cpu) {
  }

void _P10_E(CPU *cpu) {
  }

void _P10_F(CPU *cpu) {
  }

void _P10_10(CPU *cpu) {
  }

void _P10_11(CPU *cpu) {
  }

void _P10_12(CPU *cpu) {
  }

void _P10_13(CPU *cpu) {
  }

void _P10_14(CPU *cpu) {
  }

void _P10_15(CPU *cpu) {
  }

void _P10_16(CPU *cpu) {
  }

void _P10_17(CPU *cpu) {
  }

void _P10_18(CPU *cpu) {
  }

void _P10_19(CPU *cpu) {
  }

void _P10_1A(CPU *cpu) {
  }

void _P10_1B(CPU *cpu) {
  }

void _P10_1C(CPU *cpu) {
  }

void _P10_1D(CPU *cpu) {
  }

void _P10_1E(CPU *cpu) {
  }

void _P10_1F(CPU *cpu) {
  }

void _P10_20(CPU *cpu) {                         /* LBRA */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  cpu->pc += d;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_21(CPU *cpu) {                         /* LBRN */
  cpu->pc += 2;
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_22(CPU *cpu) {                         /* LBHI */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_C) == 0 && (cpu->cc & FLAG_Z) == 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_23(CPU *cpu) {                         /* LBLS */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_C) != 0 || (cpu->cc & FLAG_Z) != 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_24(CPU *cpu) {                         /* LBCC */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_C) == 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_25(CPU *cpu) {                         /* LBCS */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_C) != 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_26(CPU *cpu) {                         /* LBNE */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_Z) == 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_27(CPU *cpu) {                         /* LBEQ */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_Z) != 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_28(CPU *cpu) {                         /* LBVC */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_V) == 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_29(CPU *cpu) {                         /* LBVS */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_V) != 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_2A(CPU *cpu) {                         /* LBPL */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_N) == 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_2B(CPU *cpu) {                         /* LBMI */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if ((cpu->cc & FLAG_N) != 0) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_2C(CPU *cpu) {                         /* LBGE */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if (((cpu->cc >> 3) & 0x01) == ((cpu->cc >> 1) & 0x01)) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_2D(CPU *cpu) {                         /* LBLT */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if (((cpu->cc >> 3) & 0x01) != ((cpu->cc >> 1) & 0x01)) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_2E(CPU *cpu) {                         /* LBGT */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if (((cpu->cc & FLAG_Z) == 0) &&
     (((cpu->cc >> 3) & 0x01) == ((cpu->cc >> 1) & 0x01))) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_2F(CPU *cpu) {                         /* LBLE */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  if (((cpu->cc & FLAG_Z) != 0) ||
     (((cpu->cc >> 3) & 0x01) != ((cpu->cc >> 1) & 0x01))) { cpu->pc += d; cpu->ts++; }
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_30(CPU *cpu) {                         /* ADDR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    *w2 = _6809_add16(cpu, *w1, *w2, 0);
    }
  if (a1 == 'B' && a2 == 'B') {
    *b2 = _6809_add(cpu, *b1, *b2, 0);
    }
  if (a1 == 'W' && a2 == 'B') {
    *b2 = _6809_add(cpu, (*w1 & 0xff), *b2, 0);
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    *w2 = _6809_add16(cpu, t, *w2, 0);
    }
  if ((b & 0x0f) == 0x00) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  if ((b & 0x0f) == 0x06) {
    cpu->e = (w >> 8);
    cpu->f = w & 0xff;
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_31(CPU *cpu) {                         /* ADCR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    *w2 = _6809_add16(cpu, *w1, *w2, (cpu->cc & 1));
    }
  if (a1 == 'B' && a2 == 'B') {
    *b2 = _6809_add(cpu, *b1, *b2, (cpu->cc & 1));
    }
  if (a1 == 'W' && a2 == 'B') {
    *b2 = _6809_add(cpu, (*w1 & 0xff), *b2, (cpu->cc & 1));
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    *w2 = _6809_add16(cpu, t, *w2, (cpu->cc & 1));
    }
  if ((b & 0x0f) == 0x00) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  if ((b & 0x0f) == 0x06) {
    cpu->e = (w >> 8);
    cpu->f = w & 0xff;
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_32(CPU *cpu) {                         /* SUBR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    *w2 = _6809_sub16(cpu, *w2, *w1, 0);
    }
  if (a1 == 'B' && a2 == 'B') {
    *b2 = _6809_sub(cpu, *b2, *b1, 0);
    }
  if (a1 == 'W' && a2 == 'B') {
    *b2 = _6809_sub(cpu, (*w2 & 0xff), *b1, 0);
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    *w2 = _6809_sub16(cpu, *w2, t, 0);
    }
  if ((b & 0x0f) == 0x00) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  if ((b & 0x0f) == 0x06) {
    cpu->e = (w >> 8);
    cpu->f = w & 0xff;
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_33(CPU *cpu) {                         /* SBCR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    *w2 = _6809_sub16(cpu, *w2, *w1, (cpu->cc & 1));
    }
  if (a1 == 'B' && a2 == 'B') {
    *b2 = _6809_sub(cpu, *b2, *b1, (cpu->cc & 1));
    }
  if (a1 == 'W' && a2 == 'B') {
    *b2 = _6809_sub(cpu, (*w2 & 0xff), *b1, (cpu->cc & 1));
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    *w2 = _6809_sub16(cpu, *w2, t, (cpu->cc & 1));
    }
  if ((b & 0x0f) == 0x00) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  if ((b & 0x0f) == 0x06) {
    cpu->e = (w >> 8);
    cpu->f = w & 0xff;
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_34(CPU *cpu) {                         /* ANDR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    *w2 = _6809_and16(cpu, *w1, *w2);
    }
  if (a1 == 'B' && a2 == 'B') {
    *b2 = _6809_and(cpu, *b1, *b2);
    }
  if (a1 == 'W' && a2 == 'B') {
    *b2 = _6809_and(cpu, (*w1 & 0xff), *b2);
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    *w2 = _6809_and16(cpu, t, *w2);
    }
  if ((b & 0x0f) == 0x00) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  if ((b & 0x0f) == 0x06) {
    cpu->e = (w >> 8);
    cpu->f = w & 0xff;
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_35(CPU *cpu) {                         /* ORR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    *w2 = _6809_or16(cpu, *w1, *w2);
    }
  if (a1 == 'B' && a2 == 'B') {
    *b2 = _6809_or(cpu, *b1, *b2);
    }
  if (a1 == 'W' && a2 == 'B') {
    *b2 = _6809_or(cpu, (*w1 & 0xff), *b2);
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    *w2 = _6809_or16(cpu, t, *w2);
    }
  if ((b & 0x0f) == 0x00) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  if ((b & 0x0f) == 0x06) {
    cpu->e = (w >> 8);
    cpu->f = w & 0xff;
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_36(CPU *cpu) {                         /* EORR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    *w2 = _6809_eor16(cpu, *w1, *w2);
    }
  if (a1 == 'B' && a2 == 'B') {
    *b2 = _6809_eor(cpu, *b1, *b2);
    }
  if (a1 == 'W' && a2 == 'B') {
    *b2 = _6809_eor(cpu, (*w1 & 0xff), *b2);
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    *w2 = _6809_eor16(cpu, t, *w2);
    }
  if ((b & 0x0f) == 0x00) {
    cpu->a = (d >> 8);
    cpu->b = d & 0xff;
    }
  if ((b & 0x0f) == 0x06) {
    cpu->e = (w >> 8);
    cpu->f = w & 0xff;
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_37(CPU *cpu) {                         /* CMPR r,r */
  byte b;
  word d;
  word w;
  word t;
  word *w1,*w2;
  byte *b1,*b2;
  byte zb;
  char a1,a2;
  zb = 0;
  b = readMem(ram, cpu->pc++);
  a1 = ((b & 0xf0) >= 0x80) ? 'B' : 'W';
  a2 = ((b & 0x0f) >= 0x08) ? 'B' : 'W';
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: w1 = &cpu->pc; break;
    case 0x60: w1 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x70: w1 = &cpu->v; break;
    case 0x80: b1 = &cpu->a; break;
    case 0x90: b1 = &cpu->b; break;
    case 0xa0: b1 = &cpu->cc; break;
    case 0xb0: b1 = &cpu->dp; break;
    case 0xc0: b1 = &zb; break;
    case 0xd0: b1 = &zb; break;
    case 0xe0: b1 = &cpu->e; break;
    case 0xf0: b1 = &cpu->f; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: w2 = &cpu->pc; break;
    case 0x06: w2 = &w; w = (cpu->e << 8) | cpu->f; break;
    case 0x07: w2 = &cpu->v; break;
    case 0x08: b2 = &cpu->a; break;
    case 0x09: b2 = &cpu->b; break;
    case 0x0a: b2 = &cpu->cc; break;
    case 0x0b: b2 = &cpu->dp; break;
    case 0x0c: b2 = &zb; break;
    case 0x0d: b2 = &zb; break;
    case 0x0e: b2 = &cpu->e; break;
    case 0x0f: b2 = &cpu->f; break;
    }
  if (a1 == 'W' && a2 == 'W') {
    _6809_sub16(cpu, *w1, *w2, 0);
    }
  if (a1 == 'B' && a2 == 'B') {
    _6809_sub(cpu, *b1, *b2, 0);
    }
  if (a1 == 'W' && a2 == 'B') {
    _6809_sub(cpu, (*w1 & 0xff), *b2, 0);
    }
  if (a1 == 'B' && a2 == 'W') {
    if (((b & 0xf) == 0x08) || ((b & 0xf) == 0x09)) t = (cpu->a << 8) | cpu->b;
    else if (((b & 0xf) == 0x0e) || ((b & 0xf) == 0x0f)) t = (cpu->e << 8) | cpu->f;
    else t = *b1;
    _6809_sub16(cpu, t, *w2, 0);
    }
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_38(CPU *cpu) {                         /* PSHSW */
  _6809_push(ram, cpu, cpu->f);
  _6809_push(ram, cpu, cpu->e);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_39(CPU *cpu) {                         /* PULSW */
  cpu->e = _6809_pop(ram, cpu);
  cpu->f = _6809_pop(ram, cpu);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_3A(CPU *cpu) {                         /* PSHUW */
  _6809_pushu(ram, cpu, cpu->f);
  _6809_pushu(ram, cpu, cpu->e);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_3B(CPU *cpu) {                         /* PULUW */
  cpu->e = _6809_popu(ram, cpu);
  cpu->f = _6809_popu(ram, cpu);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_3C(CPU *cpu) {
  }

void _P10_3D(CPU *cpu) {
  }

void _P10_3E(CPU *cpu) {
  }

void _P10_3F(CPU *cpu) {                         /* SWI2 */
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
  if (use6309 && (cpu->md & 1)) {
    cpu->ts += 2;
    _6809_push(ram, cpu, cpu->f);
    _6809_push(ram, cpu, cpu->e);
    }
  _6809_push(ram, cpu, cpu->b);
  _6809_push(ram, cpu, cpu->a);
  _6809_push(ram, cpu, cpu->cc);
  cpu->ts += (cpu->md & 1) ? 20 : 20;
  cpu->pc = readMem(ram, 0xfff4) << 8;
  cpu->pc |= readMem(ram, 0xfff5);
  }

void _P10_40(CPU *cpu) {                         /* NEGD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_neg16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_41(CPU *cpu) {
  }

void _P10_42(CPU *cpu) {
  }

void _P10_43(CPU *cpu) {                         /* COMD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_com16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_44(CPU *cpu) {                         /* LSRD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_lsr16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_45(CPU *cpu) {
  }

void _P10_46(CPU *cpu) {                         /* RORD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_ror16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_47(CPU *cpu) {                         /* ASRD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_asr16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_48(CPU *cpu) {                         /* ASLD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_asl16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_49(CPU *cpu) {                         /* ROLD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_rol16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_4A(CPU *cpu) {                         /* DECD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_dec16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_4B(CPU *cpu) {
  }

void _P10_4C(CPU *cpu) {                         /* INCD */
  word d;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_inc16(cpu, d);
  cpu->a = (d >> 8);
  cpu->b = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_4D(CPU *cpu) {                         /* TSTD */
  if (cpu->a & 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (cpu->a == 0x00 && cpu->b == 0x00) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_4E(CPU *cpu) {
  }

void _P10_4F(CPU *cpu) {                         /* CLRD */
  cpu->a = 0;
  cpu->b = 0;
  cpu->cc |= FLAG_Z;
  cpu->cc &= ~FLAG_N;
  cpu->cc &= ~FLAG_V;
  cpu->cc &= ~FLAG_C;
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_50(CPU *cpu) {
  }

void _P10_51(CPU *cpu) {
  }

void _P10_52(CPU *cpu) {
  }

void _P10_53(CPU *cpu) {                         /* COMW */
  word d;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_com16(cpu, d);
  cpu->e = (d >> 8);
  cpu->f = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_54(CPU *cpu) {                         /* LSRW */
  word d;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_lsr16(cpu, d);
  cpu->e = (d >> 8);
  cpu->f = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_55(CPU *cpu) {
  }

void _P10_56(CPU *cpu) {                         /* RORW */
  word d;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_ror16(cpu, d);
  cpu->e = (d >> 8);
  cpu->f = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_57(CPU *cpu) {
  }

void _P10_58(CPU *cpu) {
  }

void _P10_59(CPU *cpu) {                         /* ROLW */
  word d;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_rol16(cpu, d);
  cpu->e = (d >> 8);
  cpu->f = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_5A(CPU *cpu) {                         /* DECW */
  word d;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_dec16(cpu, d);
  cpu->e = (d >> 8);
  cpu->f = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_5B(CPU *cpu) {
  }

void _P10_5C(CPU *cpu) {                         /* INCW */
  word d;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_inc16(cpu, d);
  cpu->e = (d >> 8);
  cpu->f = (d & 0xff);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_5D(CPU *cpu) {                         /* TSTW */
  if (cpu->e & 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (cpu->e == 0x00 && cpu->f == 0x00) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_5E(CPU *cpu) {
  }

void _P10_5F(CPU *cpu) {                         /* CLRW */
  cpu->e = 0;
  cpu->f = 0;
  cpu->cc |= FLAG_Z;
  cpu->cc &= ~FLAG_N;
  cpu->cc &= ~FLAG_V;
  cpu->cc &= ~FLAG_C;
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P10_60(CPU *cpu) {
  }

void _P10_61(CPU *cpu) {
  }

void _P10_62(CPU *cpu) {
  }

void _P10_63(CPU *cpu) {
  }

void _P10_64(CPU *cpu) {
  }

void _P10_65(CPU *cpu) {
  }

void _P10_66(CPU *cpu) {
  }

void _P10_67(CPU *cpu) {
  }

void _P10_68(CPU *cpu) {
  }

void _P10_69(CPU *cpu) {
  }

void _P10_6A(CPU *cpu) {
  }

void _P10_6B(CPU *cpu) {
  }

void _P10_6C(CPU *cpu) {
  }

void _P10_6D(CPU *cpu) {
  }

void _P10_6E(CPU *cpu) {
  }

void _P10_6F(CPU *cpu) {
  }

void _P10_70(CPU *cpu) {
  }

void _P10_71(CPU *cpu) {
  }

void _P10_72(CPU *cpu) {
  }

void _P10_73(CPU *cpu) {
  }

void _P10_74(CPU *cpu) {
  }

void _P10_75(CPU *cpu) {
  }

void _P10_76(CPU *cpu) {
  }

void _P10_77(CPU *cpu) {
  }

void _P10_78(CPU *cpu) {
  }

void _P10_79(CPU *cpu) {
  }

void _P10_7A(CPU *cpu) {
  }

void _P10_7B(CPU *cpu) {
  }

void _P10_7C(CPU *cpu) {
  }

void _P10_7D(CPU *cpu) {
  }

void _P10_7E(CPU *cpu) {
  }

void _P10_7F(CPU *cpu) {
  }

void _P10_80(CPU *cpu) {                         /* SUBW # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_sub16(cpu, d, b, 0);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_81(CPU *cpu) {                         /* CMPW # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->e << 8) | cpu->f;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_82(CPU *cpu) {                         /* SBCD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, d, b, (cpu->cc & 1));
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_83(CPU *cpu) {                         /* CMPD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_84(CPU *cpu) {                         /* ANDD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_85(CPU *cpu) {                         /* BITD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_86(CPU *cpu) {                         /* LDW # */
  cpu->e = readMem(ram, cpu->pc++);
  cpu->f = readMem(ram, cpu->pc++);
  if ((cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_87(CPU *cpu) {
  }

void _P10_88(CPU *cpu) {                         /* EORD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_eor16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_89(CPU *cpu) {                         /* ADCD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, d, b, (cpu->cc & 1));
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_8A(CPU *cpu) {                         /* ORD # */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_or16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_8B(CPU *cpu) {                         /* ADD W */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_add16(cpu, d, b, 0);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_8C(CPU *cpu) {                         /* CMPY # */
  word b;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  _6809_sub16(cpu, cpu->y, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P10_8D(CPU *cpu) {
  }

void _P10_8E(CPU *cpu) {                         /* LDY # */
  cpu->y = readMem(ram, cpu->pc++) << 8;
  cpu->y |= readMem(ram, cpu->pc++);
  if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_8F(CPU *cpu) {
  }

void _P10_90(CPU *cpu) {                         /* SUBW < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->e << 8) | cpu->f;
  d = _6809_sub16(cpu, d, b, 0);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_91(CPU *cpu) {                         /* CMPW < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  d = (cpu->e << 8) | cpu->f;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_92(CPU *cpu) {                         /* SBCD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, d, b, cpu->cc & FLAG_C);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_93(CPU *cpu) {                         /* CMPD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  d = (cpu->a << 8) | cpu->b;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_94(CPU *cpu) {                         /* ANDD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_95(CPU *cpu) {                         /* BITD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_96(CPU *cpu) {                         /* LDW < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->e = readMem(ram, a++);
  cpu->f = readMem(ram, a);
  if ((cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P10_97(CPU *cpu) {                         /* STW < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->e);
  writeMem(ram, a, cpu->f);
  if ((cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P10_98(CPU *cpu) {                         /* EORD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_eor16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_99(CPU *cpu) {                         /* ADCD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, d, b, cpu->cc & FLAG_C);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_9A(CPU *cpu) {                         /* ORD < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_or16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_9B(CPU *cpu) {                         /* ADDW < */
  word a;
  word b;
  word d;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->e << 8) | cpu->f;
  d = _6809_add16(cpu, d, b, 0);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_9C(CPU *cpu) {                         /* CMPY < */
  word a;
  word b;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->y, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P10_9D(CPU *cpu) {
  }

void _P10_9E(CPU *cpu) {                         /* LDY < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->y = readMem(ram, a++) << 8;
  cpu->y |= readMem(ram, a);
  if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P10_9F(CPU *cpu) {                         /* STY < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->y >> 8);
  writeMem(ram, a, cpu->y & 0xff);
  if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P10_A0(CPU *cpu) {                         /* SUBW , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->e << 8) | cpu->f;
  d = _6809_sub16(cpu, d, b, 0);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_A1(CPU *cpu) {                         /* CMPW , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  d = (cpu->e << 8) | cpu->f;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_A2(CPU *cpu) {                         /* SBCD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, d, b, cpu->cc & 1);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_A3(CPU *cpu) {                         /* CMPD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  d = (cpu->a << 8) | cpu->b;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_A4(CPU *cpu) {                         /* ANDD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_A5(CPU *cpu) {                         /* BITD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_A6(CPU *cpu) {                         /* LDW , */
  word a;
  a = _6809_ea(cpu);
  cpu->e = readMem(ram, a++);
  cpu->f = readMem(ram, a);
  if ((cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_A7(CPU *cpu) {                         /* STW , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a++, cpu->e);
  writeMem(ram, a, cpu->f);
  if ((cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_A8(CPU *cpu) {                         /* EORD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_eor16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_A9(CPU *cpu) {                         /* ADCD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, d, b, cpu->cc & 1);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_AA(CPU *cpu) {                         /* ORD , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->a << 8) | cpu->b;
  d = _6809_or16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_AB(CPU *cpu) {                         /* ADDW , */
  word a;
  word b;
  word d;
  a = _6809_ea(cpu);
  b = (readMem(ram, a) << 8) + readMem(ram, a+1);
  d = (cpu->e << 8) | cpu->f;
  d = _6809_add16(cpu, d, b, 0);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_AC(CPU *cpu) {                         /* CMPY , */
  word a;
  word b;
  a = _6809_ea(cpu);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->y, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_AD(CPU *cpu) {
  }

void _P10_AE(CPU *cpu) {                         /* LDY , */
  word a;
  a = _6809_ea(cpu);
  cpu->y = readMem(ram, a++) << 8;
  cpu->y |= readMem(ram, a);
  if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_AF(CPU *cpu) {                         /* STY , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a++, cpu->y >> 8);
  writeMem(ram, a, cpu->y & 0xff);
  if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_B0(CPU *cpu) {                         /* SUBW nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_sub16(cpu, d, b, 0);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_B1(CPU *cpu) {                         /* CMPW nnnn */
  word a;
  word b;
  word d;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  d = (cpu->e << 8) | cpu->f;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_B2(CPU *cpu) {                         /* SBCD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_sub16(cpu, d, b, cpu->cc & 1);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_B3(CPU *cpu) {                         /* CMPD nnnn */
  word a;
  word b;
  word d;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  d = (cpu->a << 8) | cpu->b;
  _6809_sub16(cpu, d, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_B4(CPU *cpu) {                         /* ANDD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_B5(CPU *cpu) {                         /* BITD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_and16(cpu, d, b);
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_B6(CPU *cpu) {                         /* LDW nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->e = readMem(ram, a++);
  cpu->f = readMem(ram, a);
  if ((cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_B7(CPU *cpu) {                         /* STW nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->e);
  writeMem(ram, a, cpu->f);
  if ((cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_B8(CPU *cpu) {                         /* EORD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_eor16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_B9(CPU *cpu) {                         /* ADCD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_add16(cpu, d, b, cpu->cc & 1);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_BA(CPU *cpu) {                         /* ORD nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->a << 8) | cpu->b;
  d = _6809_or16(cpu, d, b);
  cpu->a = (d >> 8) & 0xff;
  cpu->b = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_BB(CPU *cpu) {                         /* ADDW nnnn */
  word b;
  word d;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  d = (cpu->e << 8) | cpu->f;
  d = _6809_add16(cpu, d, b, cpu->cc & 1);
  cpu->e = (d >> 8) & 0xff;
  cpu->f = d & 0xff;
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_BC(CPU *cpu) {                         /* CMPY nnnn */
  word a;
  word b;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->y, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P10_BD(CPU *cpu) {
  }

void _P10_BE(CPU *cpu) {                         /* LDY nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->y = readMem(ram, a++) << 8;
  cpu->y |= readMem(ram, a);
  if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_BF(CPU *cpu) {                         /* STY nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->y >> 8);
  writeMem(ram, a, cpu->y & 0xff);
  if (cpu->y == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->y & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_C0(CPU *cpu) {
  }

void _P10_C1(CPU *cpu) {
  }

void _P10_C2(CPU *cpu) {
  }

void _P10_C3(CPU *cpu) {
  }

void _P10_C4(CPU *cpu) {
  }

void _P10_C5(CPU *cpu) {
  }

void _P10_C6(CPU *cpu) {
  }

void _P10_C7(CPU *cpu) {
  }

void _P10_C8(CPU *cpu) {
  }

void _P10_C9(CPU *cpu) {
  }

void _P10_CA(CPU *cpu) {
  }

void _P10_CB(CPU *cpu) {
  }

void _P10_CC(CPU *cpu) {
  }

void _P10_CD(CPU *cpu) {
  }

void _P10_CE(CPU *cpu) {                         /* LDS # */
  cpu->s = readMem(ram, cpu->pc++) << 8;
  cpu->s |= readMem(ram, cpu->pc++);
  if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P10_CF(CPU *cpu) {
  }

void _P10_D0(CPU *cpu) {
  }

void _P10_D1(CPU *cpu) {
  }

void _P10_D2(CPU *cpu) {
  }

void _P10_D3(CPU *cpu) {
  }

void _P10_D4(CPU *cpu) {
  }

void _P10_D5(CPU *cpu) {
  }

void _P10_D6(CPU *cpu) {
  }

void _P10_D7(CPU *cpu) {
  }

void _P10_D8(CPU *cpu) {
  }

void _P10_D9(CPU *cpu) {
  }

void _P10_DA(CPU *cpu) {
  }

void _P10_DB(CPU *cpu) {
  }

void _P10_DC(CPU *cpu) {                         /* LDQ < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->a = readMem(ram, a++);
  cpu->b = readMem(ram, a++);
  cpu->e = readMem(ram, a++);
  cpu->f = readMem(ram, a);
  if ((cpu->a | cpu->b | cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 7 : 8;
  }

void _P10_DD(CPU *cpu) {                         /* STQ < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->a);
  writeMem(ram, a++, cpu->b);
  writeMem(ram, a++, cpu->e);
  writeMem(ram, a, cpu->f);
  if ((cpu->a | cpu->b | cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 7 : 8;
  }

void _P10_DE(CPU *cpu) {                         /* LDS < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->s = readMem(ram, a++) << 8;
  cpu->s |= readMem(ram, a);
  if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P10_DF(CPU *cpu) {                         /* STS < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->s >> 8);
  writeMem(ram, a, cpu->s & 0xff);
  if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P10_E0(CPU *cpu) {
  }

void _P10_E1(CPU *cpu) {
  }

void _P10_E2(CPU *cpu) {
  }

void _P10_E3(CPU *cpu) {
  }

void _P10_E4(CPU *cpu) {
  }

void _P10_E5(CPU *cpu) {
  }

void _P10_E6(CPU *cpu) {
  }

void _P10_E7(CPU *cpu) {
  }

void _P10_E8(CPU *cpu) {
  }

void _P10_E9(CPU *cpu) {
  }

void _P10_EA(CPU *cpu) {
  }

void _P10_EB(CPU *cpu) {
  }

void _P10_EC(CPU *cpu) {                         /* LDQ , */
  word a;
  a = _6809_ea(cpu);
  cpu->a = readMem(ram, a++);
  cpu->b = readMem(ram, a++);
  cpu->e = readMem(ram, a++);
  cpu->f = readMem(ram, a);
  if ((cpu->a | cpu->b | cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P10_ED(CPU *cpu) {                         /* STQ , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a++, cpu->a);
  writeMem(ram, a++, cpu->b);
  writeMem(ram, a++, cpu->e);
  writeMem(ram, a, cpu->f);
  if ((cpu->a | cpu->b | cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 8 : 8;
  }

void _P10_EE(CPU *cpu) {                         /* LDS , */
  word a;
  a = _6809_ea(cpu);
  cpu->s = readMem(ram, a++) << 8;
  cpu->s |= readMem(ram, a);
  if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_EF(CPU *cpu) {                         /* STS , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a++, cpu->s >> 8);
  writeMem(ram, a, cpu->s & 0xff);
  if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P10_F0(CPU *cpu) {
  }

void _P10_F1(CPU *cpu) {
  }

void _P10_F2(CPU *cpu) {
  }

void _P10_F3(CPU *cpu) {
  }

void _P10_F4(CPU *cpu) {
  }

void _P10_F5(CPU *cpu) {
  }

void _P10_F6(CPU *cpu) {
  }

void _P10_F7(CPU *cpu) {
  }

void _P10_F8(CPU *cpu) {
  }

void _P10_F9(CPU *cpu) {
  }

void _P10_FA(CPU *cpu) {
  }

void _P10_FB(CPU *cpu) {
  }

void _P10_FC(CPU *cpu) {                         /* LDQ nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->a = readMem(ram, a++);
  cpu->b = readMem(ram, a++);
  cpu->e = readMem(ram, a++);
  cpu->f = readMem(ram, a);
  if ((cpu->a | cpu->b | cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 8 : 9;
  }

void _P10_FD(CPU *cpu) {                         /* STQ nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->a);
  writeMem(ram, a++, cpu->b);
  writeMem(ram, a++, cpu->e);
  writeMem(ram, a, cpu->f);
  if ((cpu->a | cpu->b | cpu->e | cpu->f) == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->a & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 8 : 9;
  }

void _P10_FE(CPU *cpu) {                         /* LDS nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->s = readMem(ram, a++) << 8;
  cpu->s |= readMem(ram, a);
  if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P10_FF(CPU *cpu) {                         /* STS nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a++, cpu->s >> 8);
  writeMem(ram, a, cpu->s & 0xff);
  if (cpu->s == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->s & 0x8000) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void cpu_prepare_10_6309(CPU* cpu) {
  cpu->Inst10[0x89]=_P10_89; cpu->Inst10[0x99]=_P10_99; cpu->Inst10[0xA9]=_P10_A9; cpu->Inst10[0xB9]=_P10_B9;
  cpu->Inst10[0x31]=_P10_31;
  cpu->Inst10[0x8B]=_P10_8B; cpu->Inst10[0x9B]=_P10_9B; cpu->Inst10[0xAB]=_P10_AB; cpu->Inst10[0xBB]=_P10_BB;
  cpu->Inst10[0x30]=_P10_30;
  cpu->Inst10[0x84]=_P10_84; cpu->Inst10[0x94]=_P10_94; cpu->Inst10[0xA4]=_P10_A4; cpu->Inst10[0xB4]=_P10_B4;
  cpu->Inst10[0x34]=_P10_34;
  cpu->Inst10[0x48]=_P10_48;
  cpu->Inst10[0x47]=_P10_47;
  cpu->Inst10[0x85]=_P10_85; cpu->Inst10[0x95]=_P10_95; cpu->Inst10[0xA5]=_P10_A5; cpu->Inst10[0xB5]=_P10_B5;
  cpu->Inst10[0x4f]=_P10_4F;
  cpu->Inst10[0x5f]=_P10_5F;
  cpu->Inst10[0x81]=_P10_81; cpu->Inst10[0x91]=_P10_91; cpu->Inst10[0xA1]=_P10_A1; cpu->Inst10[0xB1]=_P10_B1;
  cpu->Inst10[0x37]=_P10_37;
  cpu->Inst10[0x43]=_P10_43;
  cpu->Inst10[0x53]=_P10_53;
  cpu->Inst10[0x4A]=_P10_4A;
  cpu->Inst10[0x5A]=_P10_5A;
  cpu->Inst10[0x88]=_P10_88; cpu->Inst10[0x98]=_P10_98; cpu->Inst10[0xA8]=_P10_A8; cpu->Inst10[0xB8]=_P10_B8;
  cpu->Inst10[0x36]=_P10_36;
  cpu->Inst10[0x4C]=_P10_4C;
  cpu->Inst10[0x5C]=_P10_5C;
  cpu->Inst10[0x86]=_P10_86; cpu->Inst10[0x96]=_P10_96; cpu->Inst10[0xA6]=_P10_A6; cpu->Inst10[0xB6]=_P10_B6;
  cpu->Inst10[0xC6]=_P10_C6; cpu->Inst10[0xD6]=_P10_D6; cpu->Inst10[0xE6]=_P10_E6; cpu->Inst10[0xF6]=_P10_F6;
  cpu->Inst10[0xDC]=_P10_DC; cpu->Inst10[0xEC]=_P10_EC; cpu->Inst10[0xFC]=_P10_FC;
  cpu->Inst10[0x44]=_P10_44;
  cpu->Inst10[0x54]=_P10_54;
  cpu->Inst10[0x40]=_P10_40;
  cpu->Inst10[0x8A]=_P10_8A; cpu->Inst10[0x9A]=_P10_9A; cpu->Inst10[0xAA]=_P10_AA; cpu->Inst10[0xBA]=_P10_BA;
  cpu->Inst10[0x35]=_P10_35;
  cpu->Inst10[0x38]=_P10_38;
  cpu->Inst10[0x3A]=_P10_3A;
  cpu->Inst10[0x39]=_P10_39;
  cpu->Inst10[0x3B]=_P10_3B;
  cpu->Inst10[0x46]=_P10_46;
  cpu->Inst10[0x56]=_P10_56;
  cpu->Inst10[0x82]=_P10_82; cpu->Inst10[0x92]=_P10_92; cpu->Inst10[0xA2]=_P10_A2; cpu->Inst10[0xB2]=_P10_B2;
  cpu->Inst10[0x33]=_P10_33;
  cpu->Inst10[0x97]=_P10_97; cpu->Inst10[0xA7]=_P10_A7; cpu->Inst10[0xB7]=_P10_B7;
  cpu->Inst10[0xDD]=_P10_DD; cpu->Inst10[0xED]=_P10_ED; cpu->Inst10[0xFD]=_P10_FD;
  cpu->Inst10[0x80]=_P10_80; cpu->Inst10[0x90]=_P10_90; cpu->Inst10[0xA0]=_P10_A0; cpu->Inst10[0xB0]=_P10_B0;
  cpu->Inst10[0x32]=_P10_32;
  cpu->Inst10[0x4D]=_P10_4D;
  cpu->Inst10[0x5D]=_P10_5D;
  }

void cpu_prepare_10(CPU *cpu) {
  cpu->Inst10[0x00]=_P10_I; cpu->Inst10[0x01]=_P10_I; cpu->Inst10[0x02]=_P10_I; cpu->Inst10[0x03]=_P10_I;
  cpu->Inst10[0x04]=_P10_I; cpu->Inst10[0x05]=_P10_I; cpu->Inst10[0x06]=_P10_I; cpu->Inst10[0x07]=_P10_I;
  cpu->Inst10[0x08]=_P10_I; cpu->Inst10[0x09]=_P10_I; cpu->Inst10[0x0a]=_P10_I; cpu->Inst10[0x0b]=_P10_I;
  cpu->Inst10[0x0c]=_P10_I; cpu->Inst10[0x0d]=_P10_I; cpu->Inst10[0x0e]=_P10_I; cpu->Inst10[0x0f]=_P10_I;

  cpu->Inst10[0x10]=_P10_I;  cpu->Inst10[0x11]=_P10_I;  cpu->Inst10[0x12]=_P10_I;  cpu->Inst10[0x13]=_P10_I; 
  cpu->Inst10[0x14]=_P10_I;  cpu->Inst10[0x15]=_P10_I;  cpu->Inst10[0x16]=_P10_I;  cpu->Inst10[0x17]=_P10_I; 
  cpu->Inst10[0x18]=_P10_I;  cpu->Inst10[0x19]=_P10_I;  cpu->Inst10[0x1a]=_P10_I;  cpu->Inst10[0x1b]=_P10_I; 
  cpu->Inst10[0x1c]=_P10_I;  cpu->Inst10[0x1d]=_P10_I;  cpu->Inst10[0x1e]=_P10_I;  cpu->Inst10[0x1f]=_P10_I; 

  cpu->Inst10[0x20]=_P10_20; cpu->Inst10[0x21]=_P10_21; cpu->Inst10[0x22]=_P10_22; cpu->Inst10[0x23]=_P10_23;
  cpu->Inst10[0x24]=_P10_24; cpu->Inst10[0x25]=_P10_25; cpu->Inst10[0x26]=_P10_26; cpu->Inst10[0x27]=_P10_27;
  cpu->Inst10[0x28]=_P10_28; cpu->Inst10[0x29]=_P10_29; cpu->Inst10[0x2a]=_P10_2A; cpu->Inst10[0x2b]=_P10_2B;
  cpu->Inst10[0x2c]=_P10_2C; cpu->Inst10[0x2d]=_P10_2D; cpu->Inst10[0x2e]=_P10_2E; cpu->Inst10[0x2f]=_P10_2F;

  cpu->Inst10[0x30]=_P10_I;  cpu->Inst10[0x31]=_P10_I;  cpu->Inst10[0x32]=_P10_I;  cpu->Inst10[0x33]=_P10_I; 
  cpu->Inst10[0x34]=_P10_I;  cpu->Inst10[0x35]=_P10_I;  cpu->Inst10[0x36]=_P10_I;  cpu->Inst10[0x37]=_P10_I; 
  cpu->Inst10[0x38]=_P10_I;  cpu->Inst10[0x39]=_P10_I;  cpu->Inst10[0x3a]=_P10_I;  cpu->Inst10[0x3b]=_P10_I; 
  cpu->Inst10[0x3c]=_P10_I;  cpu->Inst10[0x3d]=_P10_I;  cpu->Inst10[0x3e]=_P10_I;  cpu->Inst10[0x3f]=_P10_3F;

  cpu->Inst10[0x40]=_P10_I;  cpu->Inst10[0x41]=_P10_I;  cpu->Inst10[0x42]=_P10_I;  cpu->Inst10[0x43]=_P10_I; 
  cpu->Inst10[0x44]=_P10_I;  cpu->Inst10[0x45]=_P10_I;  cpu->Inst10[0x46]=_P10_I;  cpu->Inst10[0x47]=_P10_I; 
  cpu->Inst10[0x48]=_P10_I;  cpu->Inst10[0x49]=_P10_I;  cpu->Inst10[0x4a]=_P10_I;  cpu->Inst10[0x4b]=_P10_I; 
  cpu->Inst10[0x4c]=_P10_I;  cpu->Inst10[0x4d]=_P10_I;  cpu->Inst10[0x4e]=_P10_I;  cpu->Inst10[0x4f]=_P10_I; 

  cpu->Inst10[0x50]=_P10_I;  cpu->Inst10[0x51]=_P10_I;  cpu->Inst10[0x52]=_P10_I;  cpu->Inst10[0x53]=_P10_I; 
  cpu->Inst10[0x54]=_P10_I;  cpu->Inst10[0x55]=_P10_I;  cpu->Inst10[0x56]=_P10_I;  cpu->Inst10[0x57]=_P10_I; 
  cpu->Inst10[0x58]=_P10_I;  cpu->Inst10[0x59]=_P10_I;  cpu->Inst10[0x5a]=_P10_I;  cpu->Inst10[0x5b]=_P10_I; 
  cpu->Inst10[0x5c]=_P10_I;  cpu->Inst10[0x5d]=_P10_I;  cpu->Inst10[0x5e]=_P10_I;  cpu->Inst10[0x5f]=_P10_I; 

  cpu->Inst10[0x60]=_P10_I;  cpu->Inst10[0x61]=_P10_I;  cpu->Inst10[0x62]=_P10_I;  cpu->Inst10[0x63]=_P10_I; 
  cpu->Inst10[0x64]=_P10_I;  cpu->Inst10[0x65]=_P10_I;  cpu->Inst10[0x66]=_P10_I;  cpu->Inst10[0x67]=_P10_I; 
  cpu->Inst10[0x68]=_P10_I;  cpu->Inst10[0x69]=_P10_I;  cpu->Inst10[0x6a]=_P10_I;  cpu->Inst10[0x6b]=_P10_I; 
  cpu->Inst10[0x6c]=_P10_I;  cpu->Inst10[0x6d]=_P10_I;  cpu->Inst10[0x6e]=_P10_I;  cpu->Inst10[0x6f]=_P10_I; 

  cpu->Inst10[0x70]=_P10_I;  cpu->Inst10[0x71]=_P10_I;  cpu->Inst10[0x72]=_P10_I;  cpu->Inst10[0x73]=_P10_I; 
  cpu->Inst10[0x74]=_P10_I;  cpu->Inst10[0x75]=_P10_I;  cpu->Inst10[0x76]=_P10_I;  cpu->Inst10[0x77]=_P10_I; 
  cpu->Inst10[0x78]=_P10_I;  cpu->Inst10[0x79]=_P10_I;  cpu->Inst10[0x7a]=_P10_I;  cpu->Inst10[0x7b]=_P10_I; 
  cpu->Inst10[0x7c]=_P10_I;  cpu->Inst10[0x7d]=_P10_I;  cpu->Inst10[0x7e]=_P10_I;  cpu->Inst10[0x7f]=_P10_I; 

  cpu->Inst10[0x80]=_P10_I;  cpu->Inst10[0x81]=_P10_I;  cpu->Inst10[0x82]=_P10_I;  cpu->Inst10[0x83]=_P10_83;
  cpu->Inst10[0x84]=_P10_I;  cpu->Inst10[0x85]=_P10_I;  cpu->Inst10[0x86]=_P10_I;  cpu->Inst10[0x87]=_P10_I; 
  cpu->Inst10[0x88]=_P10_I;  cpu->Inst10[0x89]=_P10_I;  cpu->Inst10[0x8a]=_P10_I;  cpu->Inst10[0x8b]=_P10_I; 
  cpu->Inst10[0x8c]=_P10_8C; cpu->Inst10[0x8d]=_P10_I;  cpu->Inst10[0x8e]=_P10_8E; cpu->Inst10[0x8f]=_P10_I; 

  cpu->Inst10[0x90]=_P10_I;  cpu->Inst10[0x91]=_P10_I;  cpu->Inst10[0x92]=_P10_I;  cpu->Inst10[0x93]=_P10_93;
  cpu->Inst10[0x94]=_P10_I;  cpu->Inst10[0x95]=_P10_I;  cpu->Inst10[0x96]=_P10_I;  cpu->Inst10[0x97]=_P10_I; 
  cpu->Inst10[0x98]=_P10_I;  cpu->Inst10[0x99]=_P10_I;  cpu->Inst10[0x9a]=_P10_I;  cpu->Inst10[0x9b]=_P10_I; 
  cpu->Inst10[0x9c]=_P10_9C; cpu->Inst10[0x9d]=_P10_I;  cpu->Inst10[0x9e]=_P10_9E; cpu->Inst10[0x9f]=_P10_9F;

  cpu->Inst10[0xa0]=_P10_I;  cpu->Inst10[0xa1]=_P10_I;  cpu->Inst10[0xa2]=_P10_I;  cpu->Inst10[0xa3]=_P10_A3;
  cpu->Inst10[0xa4]=_P10_I;  cpu->Inst10[0xa5]=_P10_I;  cpu->Inst10[0xa6]=_P10_I;  cpu->Inst10[0xa7]=_P10_I; 
  cpu->Inst10[0xa8]=_P10_I;  cpu->Inst10[0xa9]=_P10_I;  cpu->Inst10[0xaa]=_P10_I;  cpu->Inst10[0xab]=_P10_I; 
  cpu->Inst10[0xac]=_P10_AC; cpu->Inst10[0xad]=_P10_I;  cpu->Inst10[0xae]=_P10_AE; cpu->Inst10[0xaf]=_P10_AF;

  cpu->Inst10[0xb0]=_P10_I;  cpu->Inst10[0xb1]=_P10_I;  cpu->Inst10[0xb2]=_P10_I;  cpu->Inst10[0xb3]=_P10_B3;
  cpu->Inst10[0xb4]=_P10_I;  cpu->Inst10[0xb5]=_P10_I;  cpu->Inst10[0xb6]=_P10_I;  cpu->Inst10[0xb7]=_P10_I; 
  cpu->Inst10[0xb8]=_P10_I;  cpu->Inst10[0xb9]=_P10_I;  cpu->Inst10[0xba]=_P10_I;  cpu->Inst10[0xbb]=_P10_I; 
  cpu->Inst10[0xbc]=_P10_BC; cpu->Inst10[0xbd]=_P10_I;  cpu->Inst10[0xbe]=_P10_BE; cpu->Inst10[0xbf]=_P10_BF;

  cpu->Inst10[0xc0]=_P10_I;  cpu->Inst10[0xc1]=_P10_I;  cpu->Inst10[0xc2]=_P10_I;  cpu->Inst10[0xc3]=_P10_I; 
  cpu->Inst10[0xc4]=_P10_I;  cpu->Inst10[0xc5]=_P10_I;  cpu->Inst10[0xc6]=_P10_I;  cpu->Inst10[0xc7]=_P10_I; 
  cpu->Inst10[0xc8]=_P10_I;  cpu->Inst10[0xc9]=_P10_I;  cpu->Inst10[0xca]=_P10_I;  cpu->Inst10[0xcb]=_P10_I; 
  cpu->Inst10[0xcc]=_P10_I;  cpu->Inst10[0xcd]=_P10_I;  cpu->Inst10[0xce]=_P10_CE; cpu->Inst10[0xcf]=_P10_I; 

  cpu->Inst10[0xd0]=_P10_I;  cpu->Inst10[0xd1]=_P10_I;  cpu->Inst10[0xd2]=_P10_I;  cpu->Inst10[0xd3]=_P10_I; 
  cpu->Inst10[0xd4]=_P10_I;  cpu->Inst10[0xd5]=_P10_I;  cpu->Inst10[0xd6]=_P10_I;  cpu->Inst10[0xd7]=_P10_I; 
  cpu->Inst10[0xd8]=_P10_I;  cpu->Inst10[0xd9]=_P10_I;  cpu->Inst10[0xda]=_P10_I;  cpu->Inst10[0xdb]=_P10_I; 
  cpu->Inst10[0xdc]=_P10_I;  cpu->Inst10[0xdd]=_P10_I;  cpu->Inst10[0xde]=_P10_DE; cpu->Inst10[0xdf]=_P10_DF;

  cpu->Inst10[0xe0]=_P10_I;  cpu->Inst10[0xe1]=_P10_I;  cpu->Inst10[0xe2]=_P10_I;  cpu->Inst10[0xe3]=_P10_I; 
  cpu->Inst10[0xe4]=_P10_I;  cpu->Inst10[0xe5]=_P10_I;  cpu->Inst10[0xe6]=_P10_I;  cpu->Inst10[0xe7]=_P10_I; 
  cpu->Inst10[0xe8]=_P10_I;  cpu->Inst10[0xe9]=_P10_I;  cpu->Inst10[0xea]=_P10_I;  cpu->Inst10[0xeb]=_P10_I; 
  cpu->Inst10[0xec]=_P10_I;  cpu->Inst10[0xed]=_P10_I;  cpu->Inst10[0xee]=_P10_EE; cpu->Inst10[0xef]=_P10_EF;

  cpu->Inst10[0xf0]=_P10_I;  cpu->Inst10[0xf1]=_P10_I;  cpu->Inst10[0xf2]=_P10_I;  cpu->Inst10[0xf3]=_P10_I; 
  cpu->Inst10[0xf4]=_P10_I;  cpu->Inst10[0xf5]=_P10_I;  cpu->Inst10[0xf6]=_P10_I;  cpu->Inst10[0xf7]=_P10_I; 
  cpu->Inst10[0xf8]=_P10_I;  cpu->Inst10[0xf9]=_P10_I;  cpu->Inst10[0xfa]=_P10_I;  cpu->Inst10[0xfb]=_P10_I; 
  cpu->Inst10[0xfc]=_P10_I;  cpu->Inst10[0xfd]=_P10_I;  cpu->Inst10[0xfe]=_P10_FE; cpu->Inst10[0xff]=_P10_FF;

  if (use6309) cpu_prepare_10_6309(cpu);
  }


