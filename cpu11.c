#include "cpu.h"
#include "header.h"

void _P11_I(CPU *cpu) {
  }

void _P11_0(CPU *cpu) {
  }

void _P11_1(CPU *cpu) {
  }

void _P11_2(CPU *cpu) {
  }

void _P11_3(CPU *cpu) {
  }

void _P11_4(CPU *cpu) {
  }

void _P11_5(CPU *cpu) {
  }

void _P11_6(CPU *cpu) {
  }

void _P11_7(CPU *cpu) {
  }

void _P11_8(CPU *cpu) {
  }

void _P11_9(CPU *cpu) {
  }

void _P11_A(CPU *cpu) {
  }

void _P11_B(CPU *cpu) {
  }

void _P11_C(CPU *cpu) {
  }
    
void _P11_D(CPU *cpu) {
  }

void _P11_E(CPU *cpu) {
  }

void _P11_F(CPU *cpu) {
  }

void _P11_10(CPU *cpu) {
  }

void _P11_11(CPU *cpu) {
  }

void _P11_12(CPU *cpu) {
  }

void _P11_13(CPU *cpu) {
  }

void _P11_14(CPU *cpu) {
  }

void _P11_15(CPU *cpu) {
  }

void _P11_16(CPU *cpu) {
  }

void _P11_17(CPU *cpu) {
  }

void _P11_18(CPU *cpu) {
  }

void _P11_19(CPU *cpu) {
  }

void _P11_1A(CPU *cpu) {
  }

void _P11_1B(CPU *cpu) {
  }

void _P11_1C(CPU *cpu) {
  }

void _P11_1D(CPU *cpu) {
  }

void _P11_1E(CPU *cpu) {
  }

void _P11_1F(CPU *cpu) {
  }

void _P11_20(CPU *cpu) {
  }

void _P11_21(CPU *cpu) {
  }

void _P11_22(CPU *cpu) {
  }

void _P11_23(CPU *cpu) {
  }

void _P11_24(CPU *cpu) {
  }

void _P11_25(CPU *cpu) {
  }

void _P11_26(CPU *cpu) {
  }

void _P11_27(CPU *cpu) {
  }

void _P11_28(CPU *cpu) {
  }

void _P11_29(CPU *cpu) {
  }

void _P11_2A(CPU *cpu) {
  }

void _P11_2B(CPU *cpu) {
  }

void _P11_2C(CPU *cpu) {
  }

void _P11_2D(CPU *cpu) {
  }

void _P11_2E(CPU *cpu) {
  }

void _P11_2F(CPU *cpu) {
  }

void _P11_30(CPU *cpu) {                         /* BAND */
  byte b;
  byte c;
  byte pb;
  byte *r;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = (b >> s1) & 0x01;
  c = (*r >> s2) * 0x01;
  b &= c;
  *r &= (~(1 << s2));
  *r |= b << s2;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_31(CPU *cpu) {                         /* BIAND */
  byte b;
  byte c;
  byte pb;
  byte *r;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a) ^ 0xff;
  b = (b >> s1) & 0x01;
  c = (*r >> s2) * 0x01;
  b &= c;
  *r &= (~(1 << s2));
  *r |= b << s2;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_32(CPU *cpu) {                         /* BOR */
  byte b;
  byte c;
  byte pb;
  byte *r;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = (b >> s1) & 0x01;
  c = (*r >> s2) * 0x01;
  b |= c;
  *r &= (~(1 << s2));
  *r |= b << s2;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_33(CPU *cpu) {                         /* BIOR */
  byte b;
  byte c;
  byte pb;
  byte *r;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a) ^ 0xff;
  b = (b >> s1) & 0x01;
  c = (*r >> s2) * 0x01;
  b |= c;
  *r &= (~(1 << s2));
  *r |= b << s2;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_34(CPU *cpu) {                         /* BEOR */
  byte b;
  byte c;
  byte pb;
  byte *r;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = (b >> s1) & 0x01;
  c = (*r >> s2) * 0x01;
  b ^= c;
  *r &= (~(1 << s2));
  *r |= b << s2;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_35(CPU *cpu) {                         /* BIEOR */
  byte b;
  byte c;
  byte pb;
  byte *r;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a) ^ 0xff;
  b = (b >> s1) & 0x01;
  c = (*r >> s2) * 0x01;
  b ^= c;
  *r &= (~(1 << s2));
  *r |= b << s2;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_36(CPU *cpu) {                         /* LDBT */
  byte b;
  byte pb;
  byte *r;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  b = (b >> s1) & 0x01;
  *r &= (~(1 << s2));
  *r |= b << s2;
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_37(CPU *cpu) {                         /* STBT */
  byte b;
  byte pb;
  byte *r;
  byte s;
  byte s1,s2;
  word a;
  pb = readMem(ram, cpu->pc++);
  switch (pb & 0xc0) {
    case 0x00: r = &cpu->cc; break;
    case 0x40: r = &cpu->a; break;
    case 0x80: r = &cpu->b; break;
    default: 
         _P11_I(cpu);
         return;
    }
  s1 = (pb >> 3) & 0x7;
  s2 = pb & 0x7;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);

  s = (*r >> s1) & 0x01;
  b &= (~(1 << s2));
  b |= s << s2;
  writeMem(ram, a, b);
  cpu->ts += (cpu->md & 1) ? 7 : 8;
  }

void _P11_38(CPU *cpu) {                         /* TFM +,+ */
  byte b;
  word d;
  word w;
  int  f;
  word *w1,*w2;
  b = readMem(ram, cpu->pc++);
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: _P11_I(cpu); return; break;
    case 0x80: _P11_I(cpu); return; break;
    case 0x90: _P11_I(cpu); return; break;
    case 0xa0: _P11_I(cpu); return; break;
    case 0xb0: _P11_I(cpu); return; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: _P11_I(cpu); return; break;
    case 0x08: _P11_I(cpu); return; break;
    case 0x09: _P11_I(cpu); return; break;
    case 0x0a: _P11_I(cpu); return; break;
    case 0x0b: _P11_I(cpu); return; break;
    }
  w = (cpu->e << 8) | cpu->f;
  f = -1;
  while (f) {
    ram[*w2] = ram[*w1];
    *w1 += 1;
    *w2 += 1;
    w--;
    if (w == 0) f = 0;
    cpu->ts += 3;
    }
  cpu->e = 0;
  cpu->f = 0;
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P11_39(CPU *cpu) {                         /* TFM -,- */
  byte b;
  word d;
  word w;
  int  f;
  word *w1,*w2;
  b = readMem(ram, cpu->pc++);
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: _P11_I(cpu); return; break;
    case 0x80: _P11_I(cpu); return; break;
    case 0x90: _P11_I(cpu); return; break;
    case 0xa0: _P11_I(cpu); return; break;
    case 0xb0: _P11_I(cpu); return; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: _P11_I(cpu); return; break;
    case 0x08: _P11_I(cpu); return; break;
    case 0x09: _P11_I(cpu); return; break;
    case 0x0a: _P11_I(cpu); return; break;
    case 0x0b: _P11_I(cpu); return; break;
    }
  w = (cpu->e << 8) | cpu->f;
  f = -1;
  while (f) {
    ram[*w2] = ram[*w1];
    *w1 -= 1;
    *w2 -= 1;
    w--;
    if (w == 0) f = 0;
    cpu->ts += 3;
    }
  cpu->e = 0;
  cpu->f = 0;
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P11_3A(CPU *cpu) {                         /* TFM +, */
  byte b;
  word d;
  word w;
  int  f;
  word *w1,*w2;
  b = readMem(ram, cpu->pc++);
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: _P11_I(cpu); return; break;
    case 0x80: _P11_I(cpu); return; break;
    case 0x90: _P11_I(cpu); return; break;
    case 0xa0: _P11_I(cpu); return; break;
    case 0xb0: _P11_I(cpu); return; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: _P11_I(cpu); return; break;
    case 0x08: _P11_I(cpu); return; break;
    case 0x09: _P11_I(cpu); return; break;
    case 0x0a: _P11_I(cpu); return; break;
    case 0x0b: _P11_I(cpu); return; break;
    }
  w = (cpu->e << 8) | cpu->f;
  f = -1;
  while (f) {
    ram[*w2] = ram[*w1];
    *w1 += 1;
    w--;
    if (w == 0) f = 0;
    cpu->ts += 3;
    }
  cpu->e = 0;
  cpu->f = 0;
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P11_3B(CPU *cpu) {                         /* TFM ,+ */
  byte b;
  word d;
  word w;
  int  f;
  word *w1,*w2;
  b = readMem(ram, cpu->pc++);
  switch (b & 0xf0) {
    case 0x00: w1 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x10: w1 = &cpu->x; break;
    case 0x20: w1 = &cpu->y; break;
    case 0x30: w1 = &cpu->u; break;
    case 0x40: w1 = &cpu->s; break;
    case 0x50: _P11_I(cpu); return; break;
    case 0x80: _P11_I(cpu); return; break;
    case 0x90: _P11_I(cpu); return; break;
    case 0xa0: _P11_I(cpu); return; break;
    case 0xb0: _P11_I(cpu); return; break;
    }
  switch (b & 0x0f) {
    case 0x00: w2 = &d; d = (cpu->a << 8) | cpu->b; break;
    case 0x01: w2 = &cpu->x; break;
    case 0x02: w2 = &cpu->y; break;
    case 0x03: w2 = &cpu->u; break;
    case 0x04: w2 = &cpu->s; break;
    case 0x05: _P11_I(cpu); return; break;
    case 0x08: _P11_I(cpu); return; break;
    case 0x09: _P11_I(cpu); return; break;
    case 0x0a: _P11_I(cpu); return; break;
    case 0x0b: _P11_I(cpu); return; break;
    }
  w = (cpu->e << 8) | cpu->f;
  f = -1;
  while (f) {
    ram[*w2] = ram[*w1];
    *w2 += 1;
    w--;
    if (w == 0) f = 0;
    cpu->ts += 3;
    }
  cpu->e = 0;
  cpu->f = 0;
  cpu->ts += (cpu->md & 1) ? 6 : 6;
  }

void _P11_3C(CPU *cpu) {                         /* BITMD */
  byte b;
  byte c;
  b = readMem(ram, cpu->pc++);
  c = (b & cpu->md) & 0xc0;
  if (c == 0) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  if (c & 0x80) cpu->md &= 0x7f;
  if (c & 0x40) cpu->md &= 0xbf;
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P11_3D(CPU *cpu) {                         /* LDMD */
  cpu->md = (cpu->md & 0xfc) | (readMem(ram, cpu->pc++) & 0x03);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_3E(CPU *cpu) {
  }

void _P11_3F(CPU *cpu) {                         /* SWI3 */
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
  cpu->pc = readMem(ram, 0xfff2) << 8;
  cpu->pc |= readMem(ram, 0xfff3);
  cpu->ts += (cpu->md & 1) ? 20 : 20;
  }

void _P11_40(CPU *cpu) {
  }

void _P11_41(CPU *cpu) {
  }

void _P11_42(CPU *cpu) {
  }

void _P11_43(CPU *cpu) {                         /* COME */
  cpu->e = _6809_com(cpu, cpu->e);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_44(CPU *cpu) {
  }

void _P11_45(CPU *cpu) {
  }

void _P11_46(CPU *cpu) {
  }

void _P11_47(CPU *cpu) {
  }

void _P11_48(CPU *cpu) {
  }

void _P11_49(CPU *cpu) {
  }

void _P11_4A(CPU *cpu) {                         /* DECE */
  cpu->e = _6809_dec(cpu, cpu->e);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_4B(CPU *cpu) {
  }

void _P11_4C(CPU *cpu) {                         /* INCE */
  cpu->e = _6809_inc(cpu, cpu->e);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_4D(CPU *cpu) {                         /* TSTE */
  if (cpu->e & 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (cpu->e == 0x00) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_4E(CPU *cpu) {
  }

void _P11_4F(CPU *cpu) {                         /* CLRE */
  cpu->e = 0;
  cpu->cc |= FLAG_Z;
  cpu->cc &= ~FLAG_N;
  cpu->cc &= ~FLAG_V;
  cpu->cc &= ~FLAG_C;
  cpu->ts += (cpu->md & 1) ? 2 : 3;

  }

void _P11_50(CPU *cpu) {
  }

void _P11_51(CPU *cpu) {
  }

void _P11_52(CPU *cpu) {
  }

void _P11_53(CPU *cpu) {
  }

void _P11_54(CPU *cpu) {                         /* COMF */
  cpu->f = _6809_com(cpu, cpu->f);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_55(CPU *cpu) {
  }

void _P11_56(CPU *cpu) {
  }

void _P11_57(CPU *cpu) {
  }

void _P11_58(CPU *cpu) {
  }

void _P11_59(CPU *cpu) {
  }

void _P11_5A(CPU *cpu) {                         /* DECF */
  cpu->f = _6809_dec(cpu, cpu->f);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_5B(CPU *cpu) {
  }

void _P11_5C(CPU *cpu) {                         /* INCF */
  cpu->f = _6809_inc(cpu, cpu->f);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_5D(CPU *cpu) {                         /* TSTF */
  if (cpu->f & 0x80) cpu->cc |= FLAG_N;
    else cpu->cc &= (~FLAG_N);
  if (cpu->f == 0x00) cpu->cc |= FLAG_Z;
    else cpu->cc &= (~FLAG_Z);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_5E(CPU *cpu) {
  }

void _P11_5F(CPU *cpu) {                         /* CLRF */
  cpu->f = 0;
  cpu->cc |= FLAG_Z;
  cpu->cc &= ~FLAG_N;
  cpu->cc &= ~FLAG_V;
  cpu->cc &= ~FLAG_C;
  cpu->ts += (cpu->md & 1) ? 2 : 3;
  }

void _P11_60(CPU *cpu) {
  }

void _P11_61(CPU *cpu) {
  }

void _P11_62(CPU *cpu) {
  }

void _P11_63(CPU *cpu) {
  }

void _P11_64(CPU *cpu) {
  }

void _P11_65(CPU *cpu) {
  }

void _P11_66(CPU *cpu) {
  }

void _P11_67(CPU *cpu) {
  }

void _P11_68(CPU *cpu) {
  }

void _P11_69(CPU *cpu) {
  }

void _P11_6A(CPU *cpu) {
  }

void _P11_6B(CPU *cpu) {
  }

void _P11_6C(CPU *cpu) {
  }

void _P11_6D(CPU *cpu) {
  }

void _P11_6E(CPU *cpu) {
  }

void _P11_6F(CPU *cpu) {
  }

void _P11_70(CPU *cpu) {
  }

void _P11_71(CPU *cpu) {
  }

void _P11_72(CPU *cpu) {
  }

void _P11_73(CPU *cpu) {
  }

void _P11_74(CPU *cpu) {
  }

void _P11_75(CPU *cpu) {
  }

void _P11_76(CPU *cpu) {
  }

void _P11_77(CPU *cpu) {
  }

void _P11_78(CPU *cpu) {
  }

void _P11_79(CPU *cpu) {
  }

void _P11_7A(CPU *cpu) {
  }

void _P11_7B(CPU *cpu) {
  }

void _P11_7C(CPU *cpu) {
  }

void _P11_7D(CPU *cpu) {
  }

void _P11_7E(CPU *cpu) {
  }

void _P11_7F(CPU *cpu) {
  }

void _P11_80(CPU *cpu) {                         /* SUBE # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->e = _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_81(CPU *cpu) {                         /* CMPE # */
  byte b;
  b = readMem(ram, cpu->pc++);
  _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_82(CPU *cpu) {
  }

void _P11_83(CPU *cpu) {                         /* CMPU # */
  word b;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  _6809_sub16(cpu, cpu->u, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_84(CPU *cpu) {
  }

void _P11_85(CPU *cpu) {
  }

void _P11_86(CPU *cpu) {                         /* LDE # */
  cpu->e = readMem(ram, cpu->pc++);
  if (cpu->e == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_87(CPU *cpu) {
  }

void _P11_88(CPU *cpu) {
  }

void _P11_89(CPU *cpu) {
  }

void _P11_8A(CPU *cpu) {
  }

void _P11_8B(CPU *cpu) {                         /* ADDE # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->e = _6809_add(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_8C(CPU *cpu) {                         /* CMPS # */
  word b;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  _6809_sub16(cpu, cpu->s, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_8D(CPU *cpu) {                         /* DIVD # */
  byte b;
  b = readMem(ram, cpu->pc++);
  _6809_div(cpu, b);
  }

void _P11_8E(CPU *cpu) {                         /* DIVQ # */
  word b;
  b = readMem(ram, cpu->pc++) << 8;
  b |= readMem(ram, cpu->pc++);
  _6809_div16(cpu, b);
  }

void _P11_8F(CPU *cpu) {                         /* MULD # */
  word d;
  d = readMem(ram, cpu->pc++) << 8;
  d |= readMem(ram, cpu->pc++);
  _6809_mul16(cpu, d);
  cpu->ts += (cpu->md & 1) ? 4 : 4;
  }

void _P11_90(CPU *cpu) {                         /* SUBE */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->e = _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_91(CPU *cpu) {                         /* CMPE < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_92(CPU *cpu) {
  }

void _P11_93(CPU *cpu) {                         /* CMPU < */
  word a;
  word b;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->u, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P11_94(CPU *cpu) {
  }

void _P11_95(CPU *cpu) {
  }

void _P11_96(CPU *cpu) {                         /* LDE < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->e = readMem(ram, a);
  if (cpu->e == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_97(CPU *cpu) {                         /* STE < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->e);
  if (cpu->e == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_98(CPU *cpu) {
  }

void _P11_99(CPU *cpu) {
  }

void _P11_9A(CPU *cpu) {
  }

void _P11_9B(CPU *cpu) {                         /* ADDE < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->e = _6809_add(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_9C(CPU *cpu) {                         /* CMPS < */
  word a;
  word b;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->s, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 7;
  }

void _P11_9D(CPU *cpu) {                         /* DIVD < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_div(cpu, b);
  cpu->ts += 2;
  }

void _P11_9E(CPU *cpu) {                         /* DIVQ < */
  word b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a) << 8;
  b |= readMem(ram, a+1);
  _6809_div16(cpu, b);
  cpu->ts += 2;
  }

void _P11_9F(CPU *cpu) {                         /* MULD < */
  word b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a) << 8;
  b |= readMem(ram, a+1);
  _6809_mul16(cpu, b);
  cpu->ts += (cpu->md & 1) ? 29 : 30;
  }

void _P11_A0(CPU *cpu) {                         /* SUBE , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->e = _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_A1(CPU *cpu) {                         /* CMPE , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_A2(CPU *cpu) {
  }

void _P11_A3(CPU *cpu) {                         /* CMPU , */
  word a;
  word b;
  a = _6809_ea(cpu);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->u, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_A4(CPU *cpu) {
  }

void _P11_A5(CPU *cpu) {
  }

void _P11_A6(CPU *cpu) {                         /* LDE , */
  word a;
  a = _6809_ea(cpu);
  cpu->e = readMem(ram, a);
  if (cpu->e == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_A7(CPU *cpu) {                         /* STE , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a, cpu->e);
  if (cpu->e == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_A8(CPU *cpu) {
  }

void _P11_A9(CPU *cpu) {
  }

void _P11_AA(CPU *cpu) {
  }

void _P11_AB(CPU *cpu) {                         /* ADDE , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->e = _6809_add(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_AC(CPU *cpu) {                         /* CMPS , */
  word a;
  word b;
  a = _6809_ea(cpu);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->s, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 7;
  }

void _P11_AD(CPU *cpu) {                         /* DIVD , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_div(cpu, b);
  cpu->ts += 2;
  }

void _P11_AE(CPU *cpu) {                         /* DIVQ , */
  word b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a) << 8;
  b |= readMem(ram, a+1);
  _6809_div16(cpu, b);
  cpu->ts += 2;
  }

void _P11_AF(CPU *cpu) {                         /* MULD , */
  word b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a) << 8;
  b |= readMem(ram, a+1);
  _6809_mul16(cpu, b);
  cpu->ts += (cpu->md & 1) ? 30 : 30;
  }

void _P11_B0(CPU *cpu) {                         /* SUBE nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->e = _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_B1(CPU *cpu) {                         /* CMPE nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_B2(CPU *cpu) {
  }

void _P11_B3(CPU *cpu) {                         /* CMPU nnnn */
  word a;
  word b;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->u, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P11_B4(CPU *cpu) {
  }

void _P11_B5(CPU *cpu) {
  }

void _P11_B6(CPU *cpu) {                         /* LDE nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->e = readMem(ram, a);
  if (cpu->e == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_B7(CPU *cpu) {                         /* STE nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->e);
  if (cpu->e == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->e & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_B8(CPU *cpu) {
  }

void _P11_B9(CPU *cpu) {
  }

void _P11_BA(CPU *cpu) {
  }

void _P11_BB(CPU *cpu) {                         /* ADDE nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->e = _6809_add(cpu, cpu->e, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_BC(CPU *cpu) {                         /* CMPS nnnn */
  word a;
  word b;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a++) << 8;
  b |= readMem(ram, a);
  _6809_sub16(cpu, cpu->s, b, 0);
  cpu->ts += (cpu->md & 1) ? 6 : 8;
  }

void _P11_BD(CPU *cpu) {                         /* DIVD nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_div(cpu, b);
  cpu->ts += 3;
  }

void _P11_BE(CPU *cpu) {                         /* DIVQ nnnn */
  word b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a) << 8;
  b |= readMem(ram, a+1);
  _6809_div16(cpu, b);
  cpu->ts += 3;
  }

void _P11_BF(CPU *cpu) {                         /* MULD nnnn */
  word b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a) << 8;
  b |= readMem(ram, a+1);
  _6809_mul16(cpu, b);
  cpu->ts += (cpu->md & 1) ? 30 : 31;
  }

void _P11_C0(CPU *cpu) {                         /* SUBF # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->f = _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_C1(CPU *cpu) {                         /* CMPF # */
  byte b;
  b = readMem(ram, cpu->pc++);
  _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_C2(CPU *cpu) {
  }

void _P11_C3(CPU *cpu) {
  }

void _P11_C4(CPU *cpu) {
  }

void _P11_C5(CPU *cpu) {
  }

void _P11_C6(CPU *cpu) {                         /* LDF # */
  cpu->f = readMem(ram, cpu->pc++);
  if (cpu->f == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->f & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_C7(CPU *cpu) {
  }

void _P11_C8(CPU *cpu) {
  }

void _P11_C9(CPU *cpu) {
  }

void _P11_CA(CPU *cpu) {
  }

void _P11_CB(CPU *cpu) {                         /* ADDF # */
  byte b;
  b = readMem(ram, cpu->pc++);
  cpu->f = _6809_add(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 3 : 3;
  }

void _P11_CC(CPU *cpu) {
  }

void _P11_CD(CPU *cpu) {
  }

void _P11_CE(CPU *cpu) {
  }

void _P11_CF(CPU *cpu) {
  }

void _P11_D0(CPU *cpu) {                         /* SUBF < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->f = _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_D1(CPU *cpu) {                         /* CMPF < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_D2(CPU *cpu) {
  }

void _P11_D3(CPU *cpu) {
  }

void _P11_D4(CPU *cpu) {
  }

void _P11_D5(CPU *cpu) {
  }

void _P11_D6(CPU *cpu) {                         /* LDF < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->f = readMem(ram, a);
  if (cpu->f == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->f & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_D7(CPU *cpu) {                         /* STF < */
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->f);
  if (cpu->f == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->f & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_D8(CPU *cpu) {
  }

void _P11_D9(CPU *cpu) {
  }

void _P11_DA(CPU *cpu) {
  }

void _P11_DB(CPU *cpu) {                         /* ADDF < */
  byte b;
  word a;
  a = cpu->dp << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->f = _6809_add(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_DC(CPU *cpu) {
  }

void _P11_DD(CPU *cpu) {
  }

void _P11_DE(CPU *cpu) {
  }

void _P11_DF(CPU *cpu) {
  }

void _P11_E0(CPU *cpu) {                         /* SUBF , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->f = _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_E1(CPU *cpu) {                         /* CMPF , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_E2(CPU *cpu) {
  }

void _P11_E3(CPU *cpu) {
  }

void _P11_E4(CPU *cpu) {
  }

void _P11_E5(CPU *cpu) {
  }

void _P11_E6(CPU *cpu) {                         /* LDF , */
  word a;
  a = _6809_ea(cpu);
  cpu->f = readMem(ram, a);
  if (cpu->f == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->f & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_E7(CPU *cpu) {                         /* STF , */
  word a;
  a = _6809_ea(cpu);
  writeMem(ram, a, cpu->f);
  if (cpu->f == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->f & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_E8(CPU *cpu) {
  }

void _P11_E9(CPU *cpu) {
  }

void _P11_EA(CPU *cpu) {
  }

void _P11_EB(CPU *cpu) {                         /* ADDF , */
  byte b;
  word a;
  a = _6809_ea(cpu);
  b = readMem(ram, a);
  cpu->f = _6809_add(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 5;
  }

void _P11_EC(CPU *cpu) {
  }

void _P11_ED(CPU *cpu) {
  }

void _P11_EE(CPU *cpu) {
  }

void _P11_EF(CPU *cpu) {
  }

void _P11_F0(CPU *cpu) {                         /* SUBF nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->f = _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_F1(CPU *cpu) {                         /* CMPF nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  _6809_sub(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_F2(CPU *cpu) {
  }

void _P11_F3(CPU *cpu) {
  }

void _P11_F4(CPU *cpu) {
  }

void _P11_F5(CPU *cpu) {
  }

void _P11_F6(CPU *cpu) {                         /* LDF nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  cpu->f = readMem(ram, a);
  if (cpu->f == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->f & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_F7(CPU *cpu) {                         /* STF nnnn */
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  writeMem(ram, a, cpu->f);
  if (cpu->f == 0) cpu->cc |= FLAG_Z; else cpu->cc &= (~FLAG_Z);
  if (cpu->f & 0x80) cpu->cc |= FLAG_N; else cpu->cc &= (~FLAG_N);
  cpu->cc &= (~FLAG_V);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_F8(CPU *cpu) {
  }

void _P11_F9(CPU *cpu) {
  }

void _P11_FA(CPU *cpu) {
  }

void _P11_FB(CPU *cpu) {                         /* ADDF nnnn */
  byte b;
  word a;
  a = readMem(ram, cpu->pc++) << 8;
  a |= readMem(ram, cpu->pc++);
  b = readMem(ram, a);
  cpu->f = _6809_add(cpu, cpu->f, b, 0);
  cpu->ts += (cpu->md & 1) ? 5 : 6;
  }

void _P11_FC(CPU *cpu) {
  }

void _P11_FD(CPU *cpu) {
  }

void _P11_FE(CPU *cpu) {
  }

void _P11_FF(CPU *cpu) {
  }

void cpu_prepare_11_6309(CPU* cpu) {
  cpu->Inst11[0x8B]=_P11_8B; cpu->Inst11[0x9B]=_P11_9B; cpu->Inst11[0xAB]=_P11_AB; cpu->Inst11[0xBB]=_P11_BB;
  cpu->Inst11[0xCB]=_P11_CB; cpu->Inst11[0xDB]=_P11_DB; cpu->Inst11[0xEB]=_P11_EB; cpu->Inst11[0xFB]=_P11_FB;
  cpu->Inst11[0x30]=_P11_30;
  cpu->Inst11[0x34]=_P11_34;
  cpu->Inst11[0x31]=_P11_31;
  cpu->Inst11[0x35]=_P11_35;
  cpu->Inst11[0x33]=_P11_33;
  cpu->Inst11[0x3C]=_P11_3C;
  cpu->Inst11[0x32]=_P11_32;
  cpu->Inst11[0x4f]=_P11_4F;
  cpu->Inst11[0x5F]=_P11_5F;
  cpu->Inst11[0x81]=_P11_81; cpu->Inst11[0x91]=_P11_91; cpu->Inst11[0xA1]=_P11_A1; cpu->Inst11[0xB1]=_P11_B1;
  cpu->Inst11[0xC1]=_P11_C1; cpu->Inst11[0xD1]=_P11_D1; cpu->Inst11[0xE1]=_P11_E1; cpu->Inst11[0xF1]=_P11_F1;
  cpu->Inst11[0x43]=_P11_43;
  cpu->Inst11[0x53]=_P11_53;
  cpu->Inst11[0x4a]=_P11_4A;
  cpu->Inst11[0x5a]=_P11_5A;
  cpu->Inst11[0x8D]=_P11_8D;
  cpu->Inst11[0x8D]=_P11_8D; cpu->Inst11[0x9D]=_P11_9D; cpu->Inst11[0xAD]=_P11_AD; cpu->Inst11[0xBD]=_P11_BD;
  cpu->Inst11[0x8E]=_P11_8E; cpu->Inst11[0x9E]=_P11_9E; cpu->Inst11[0xAE]=_P11_AE; cpu->Inst11[0xBE]=_P11_BE;
  cpu->Inst11[0x4C]=_P11_4C;
  cpu->Inst11[0x5C]=_P11_5C;
  cpu->Inst11[0x86]=_P11_86; cpu->Inst11[0x96]=_P11_96; cpu->Inst11[0xA6]=_P11_A6; cpu->Inst11[0xB6]=_P11_B6;
  cpu->Inst11[0xC6]=_P11_C6; cpu->Inst11[0xD6]=_P11_D6; cpu->Inst11[0xE6]=_P11_E6; cpu->Inst11[0xF6]=_P11_F6;
  cpu->Inst11[0x36]=_P11_36;
  cpu->Inst11[0x3D]=_P11_3D;
  cpu->Inst11[0x8F]=_P11_8F; cpu->Inst11[0x9F]=_P11_9F; cpu->Inst11[0xAF]=_P11_AF; cpu->Inst11[0xBF]=_P11_BF;
  cpu->Inst11[0x97]=_P11_97; cpu->Inst11[0xA7]=_P11_A7; cpu->Inst11[0xB7]=_P11_B7;
  cpu->Inst11[0xD7]=_P11_D7; cpu->Inst11[0xE7]=_P11_E7; cpu->Inst11[0xF7]=_P11_F7;
  cpu->Inst11[0x80]=_P11_80; cpu->Inst11[0x90]=_P11_90; cpu->Inst11[0xA0]=_P11_A0; cpu->Inst11[0xB0]=_P11_B0;
  cpu->Inst11[0xC0]=_P11_C0; cpu->Inst11[0xD0]=_P11_D0; cpu->Inst11[0xE0]=_P11_E0; cpu->Inst11[0xF0]=_P11_F0;
  cpu->Inst11[0x38]=_P11_38;
  cpu->Inst11[0x39]=_P11_39;
  cpu->Inst11[0x3A]=_P11_3A;
  cpu->Inst11[0x3B]=_P11_3B;
  cpu->Inst11[0x4D]=_P11_4D;
  cpu->Inst11[0x5D]=_P11_5D;
  cpu->Inst11[0x37]=_P11_37;
  }

void cpu_prepare_11(CPU *cpu) {
  cpu->Inst11[0x00]=_P11_0; cpu->Inst11[0x01]=_P11_1; cpu->Inst11[0x02]=_P11_2; cpu->Inst11[0x03]=_P11_3;
  cpu->Inst11[0x04]=_P11_4; cpu->Inst11[0x05]=_P11_5; cpu->Inst11[0x06]=_P11_6; cpu->Inst11[0x07]=_P11_7;
  cpu->Inst11[0x08]=_P11_8; cpu->Inst11[0x09]=_P11_9; cpu->Inst11[0x0a]=_P11_A; cpu->Inst11[0x0b]=_P11_B;
  cpu->Inst11[0x0c]=_P11_C; cpu->Inst11[0x0d]=_P11_D; cpu->Inst11[0x0e]=_P11_E; cpu->Inst11[0x0f]=_P11_F;

  cpu->Inst11[0x10]=_P11_I;  cpu->Inst11[0x11]=_P11_I;  cpu->Inst11[0x12]=_P11_I;  cpu->Inst11[0x13]=_P11_I; 
  cpu->Inst11[0x14]=_P11_I;  cpu->Inst11[0x15]=_P11_I;  cpu->Inst11[0x16]=_P11_I;  cpu->Inst11[0x17]=_P11_I; 
  cpu->Inst11[0x18]=_P11_I;  cpu->Inst11[0x19]=_P11_I;  cpu->Inst11[0x1a]=_P11_I;  cpu->Inst11[0x1b]=_P11_I; 
  cpu->Inst11[0x1c]=_P11_I;  cpu->Inst11[0x1d]=_P11_I;  cpu->Inst11[0x1e]=_P11_I;  cpu->Inst11[0x1f]=_P11_I; 

  cpu->Inst11[0x20]=_P11_I;  cpu->Inst11[0x21]=_P11_I;  cpu->Inst11[0x22]=_P11_I;  cpu->Inst11[0x23]=_P11_I; 
  cpu->Inst11[0x24]=_P11_I;  cpu->Inst11[0x25]=_P11_I;  cpu->Inst11[0x26]=_P11_I;  cpu->Inst11[0x27]=_P11_I; 
  cpu->Inst11[0x28]=_P11_I;  cpu->Inst11[0x29]=_P11_I;  cpu->Inst11[0x2a]=_P11_I;  cpu->Inst11[0x2b]=_P11_I; 
  cpu->Inst11[0x2c]=_P11_I;  cpu->Inst11[0x2d]=_P11_I;  cpu->Inst11[0x2e]=_P11_I;  cpu->Inst11[0x2f]=_P11_I; 

  cpu->Inst11[0x30]=_P11_I;  cpu->Inst11[0x31]=_P11_I;  cpu->Inst11[0x32]=_P11_I;  cpu->Inst11[0x33]=_P11_I; 
  cpu->Inst11[0x34]=_P11_I;  cpu->Inst11[0x35]=_P11_I;  cpu->Inst11[0x36]=_P11_I;  cpu->Inst11[0x37]=_P11_I; 
  cpu->Inst11[0x38]=_P11_I;  cpu->Inst11[0x39]=_P11_I;  cpu->Inst11[0x3a]=_P11_I;  cpu->Inst11[0x3b]=_P11_I; 
  cpu->Inst11[0x3c]=_P11_I;  cpu->Inst11[0x3d]=_P11_I;  cpu->Inst11[0x3e]=_P11_I;  cpu->Inst11[0x3f]=_P11_3F;

  cpu->Inst11[0x40]=_P11_I;  cpu->Inst11[0x41]=_P11_I;  cpu->Inst11[0x42]=_P11_I;  cpu->Inst11[0x43]=_P11_I; 
  cpu->Inst11[0x44]=_P11_I;  cpu->Inst11[0x45]=_P11_I;  cpu->Inst11[0x46]=_P11_I;  cpu->Inst11[0x47]=_P11_I; 
  cpu->Inst11[0x48]=_P11_I;  cpu->Inst11[0x49]=_P11_I;  cpu->Inst11[0x4a]=_P11_I;  cpu->Inst11[0x4b]=_P11_I; 
  cpu->Inst11[0x4c]=_P11_I;  cpu->Inst11[0x4d]=_P11_I;  cpu->Inst11[0x4e]=_P11_I;  cpu->Inst11[0x4f]=_P11_I; 

  cpu->Inst11[0x50]=_P11_I;  cpu->Inst11[0x51]=_P11_I;  cpu->Inst11[0x52]=_P11_I;  cpu->Inst11[0x53]=_P11_I; 
  cpu->Inst11[0x54]=_P11_I;  cpu->Inst11[0x55]=_P11_I;  cpu->Inst11[0x56]=_P11_I;  cpu->Inst11[0x57]=_P11_I; 
  cpu->Inst11[0x58]=_P11_I;  cpu->Inst11[0x59]=_P11_I;  cpu->Inst11[0x5a]=_P11_I;  cpu->Inst11[0x5b]=_P11_I; 
  cpu->Inst11[0x5c]=_P11_I;  cpu->Inst11[0x5d]=_P11_I;  cpu->Inst11[0x5e]=_P11_I;  cpu->Inst11[0x5f]=_P11_I; 

  cpu->Inst11[0x60]=_P11_I;  cpu->Inst11[0x61]=_P11_I;  cpu->Inst11[0x62]=_P11_I;  cpu->Inst11[0x63]=_P11_I; 
  cpu->Inst11[0x64]=_P11_I;  cpu->Inst11[0x65]=_P11_I;  cpu->Inst11[0x66]=_P11_I;  cpu->Inst11[0x67]=_P11_I; 
  cpu->Inst11[0x68]=_P11_I;  cpu->Inst11[0x69]=_P11_I;  cpu->Inst11[0x6a]=_P11_I;  cpu->Inst11[0x6b]=_P11_I; 
  cpu->Inst11[0x6c]=_P11_I;  cpu->Inst11[0x6d]=_P11_I;  cpu->Inst11[0x6e]=_P11_I;  cpu->Inst11[0x6f]=_P11_I; 

  cpu->Inst11[0x70]=_P11_I;  cpu->Inst11[0x71]=_P11_I;  cpu->Inst11[0x72]=_P11_I;  cpu->Inst11[0x73]=_P11_I; 
  cpu->Inst11[0x74]=_P11_I;  cpu->Inst11[0x75]=_P11_I;  cpu->Inst11[0x76]=_P11_I;  cpu->Inst11[0x77]=_P11_I; 
  cpu->Inst11[0x78]=_P11_I;  cpu->Inst11[0x79]=_P11_I;  cpu->Inst11[0x7a]=_P11_I;  cpu->Inst11[0x7b]=_P11_I; 
  cpu->Inst11[0x7c]=_P11_I;  cpu->Inst11[0x7d]=_P11_I;  cpu->Inst11[0x7e]=_P11_I;  cpu->Inst11[0x7f]=_P11_I; 

  cpu->Inst11[0x80]=_P11_I;  cpu->Inst11[0x81]=_P11_I;  cpu->Inst11[0x82]=_P11_I;  cpu->Inst11[0x83]=_P11_83;
  cpu->Inst11[0x84]=_P11_I;  cpu->Inst11[0x85]=_P11_I;  cpu->Inst11[0x86]=_P11_I;  cpu->Inst11[0x87]=_P11_I; 
  cpu->Inst11[0x88]=_P11_I;  cpu->Inst11[0x89]=_P11_I;  cpu->Inst11[0x8a]=_P11_I;  cpu->Inst11[0x8b]=_P11_I; 
  cpu->Inst11[0x8c]=_P11_8C; cpu->Inst11[0x8d]=_P11_I;  cpu->Inst11[0x8e]=_P11_I;  cpu->Inst11[0x8f]=_P11_I; 

  cpu->Inst11[0x90]=_P11_I;  cpu->Inst11[0x91]=_P11_I;  cpu->Inst11[0x92]=_P11_I;  cpu->Inst11[0x93]=_P11_93;
  cpu->Inst11[0x94]=_P11_I;  cpu->Inst11[0x95]=_P11_I;  cpu->Inst11[0x96]=_P11_I;  cpu->Inst11[0x97]=_P11_I; 
  cpu->Inst11[0x98]=_P11_I;  cpu->Inst11[0x99]=_P11_I;  cpu->Inst11[0x9a]=_P11_I;  cpu->Inst11[0x9b]=_P11_I; 
  cpu->Inst11[0x9c]=_P11_9C; cpu->Inst11[0x9d]=_P11_I;  cpu->Inst11[0x9e]=_P11_I;  cpu->Inst11[0x9f]=_P11_I; 

  cpu->Inst11[0xa0]=_P11_I;  cpu->Inst11[0xa1]=_P11_I;  cpu->Inst11[0xa2]=_P11_I;  cpu->Inst11[0xa3]=_P11_A3;
  cpu->Inst11[0xa4]=_P11_I;  cpu->Inst11[0xa5]=_P11_I;  cpu->Inst11[0xa6]=_P11_I;  cpu->Inst11[0xa7]=_P11_I; 
  cpu->Inst11[0xa8]=_P11_I;  cpu->Inst11[0xa9]=_P11_I;  cpu->Inst11[0xaa]=_P11_I;  cpu->Inst11[0xab]=_P11_I; 
  cpu->Inst11[0xac]=_P11_AC; cpu->Inst11[0xad]=_P11_I;  cpu->Inst11[0xae]=_P11_I;  cpu->Inst11[0xaf]=_P11_I; 

  cpu->Inst11[0xb0]=_P11_I;  cpu->Inst11[0xb1]=_P11_I;  cpu->Inst11[0xb2]=_P11_I;  cpu->Inst11[0xb3]=_P11_B3;
  cpu->Inst11[0xb4]=_P11_I;  cpu->Inst11[0xb5]=_P11_I;  cpu->Inst11[0xb6]=_P11_I;  cpu->Inst11[0xb7]=_P11_I; 
  cpu->Inst11[0xb8]=_P11_I;  cpu->Inst11[0xb9]=_P11_I;  cpu->Inst11[0xba]=_P11_I;  cpu->Inst11[0xbb]=_P11_I; 
  cpu->Inst11[0xbc]=_P11_BC; cpu->Inst11[0xbd]=_P11_I;  cpu->Inst11[0xbe]=_P11_I;  cpu->Inst11[0xbf]=_P11_I; 

  cpu->Inst11[0xc0]=_P11_I;  cpu->Inst11[0xc1]=_P11_I;  cpu->Inst11[0xc2]=_P11_I;  cpu->Inst11[0xc3]=_P11_I; 
  cpu->Inst11[0xc4]=_P11_I;  cpu->Inst11[0xc5]=_P11_I;  cpu->Inst11[0xc6]=_P11_I;  cpu->Inst11[0xc7]=_P11_I; 
  cpu->Inst11[0xc8]=_P11_I;  cpu->Inst11[0xc9]=_P11_I;  cpu->Inst11[0xca]=_P11_I;  cpu->Inst11[0xcb]=_P11_I; 
  cpu->Inst11[0xcc]=_P11_I;  cpu->Inst11[0xcd]=_P11_I;  cpu->Inst11[0xce]=_P11_I;  cpu->Inst11[0xcf]=_P11_I; 

  cpu->Inst11[0xd0]=_P11_I;  cpu->Inst11[0xd1]=_P11_I;  cpu->Inst11[0xd2]=_P11_I;  cpu->Inst11[0xd3]=_P11_I; 
  cpu->Inst11[0xd4]=_P11_I;  cpu->Inst11[0xd5]=_P11_I;  cpu->Inst11[0xd6]=_P11_I;  cpu->Inst11[0xd7]=_P11_I; 
  cpu->Inst11[0xd8]=_P11_I;  cpu->Inst11[0xd9]=_P11_I;  cpu->Inst11[0xda]=_P11_I;  cpu->Inst11[0xdb]=_P11_I; 
  cpu->Inst11[0xdc]=_P11_I;  cpu->Inst11[0xdd]=_P11_I;  cpu->Inst11[0xde]=_P11_I;  cpu->Inst11[0xdf]=_P11_I; 

  cpu->Inst11[0xe0]=_P11_I;  cpu->Inst11[0xe1]=_P11_I;  cpu->Inst11[0xe2]=_P11_I;  cpu->Inst11[0xe3]=_P11_I; 
  cpu->Inst11[0xe4]=_P11_I;  cpu->Inst11[0xe5]=_P11_I;  cpu->Inst11[0xe6]=_P11_I;  cpu->Inst11[0xe7]=_P11_I; 
  cpu->Inst11[0xe8]=_P11_I;  cpu->Inst11[0xe9]=_P11_I;  cpu->Inst11[0xea]=_P11_I;  cpu->Inst11[0xeb]=_P11_I; 
  cpu->Inst11[0xec]=_P11_I;  cpu->Inst11[0xed]=_P11_I;  cpu->Inst11[0xee]=_P11_I;  cpu->Inst11[0xef]=_P11_I; 

  cpu->Inst11[0xf0]=_P11_I;  cpu->Inst11[0xf1]=_P11_I;  cpu->Inst11[0xf2]=_P11_I;  cpu->Inst11[0xf3]=_P11_I; 
  cpu->Inst11[0xf4]=_P11_I;  cpu->Inst11[0xf5]=_P11_I;  cpu->Inst11[0xf6]=_P11_I;  cpu->Inst11[0xf7]=_P11_I; 
  cpu->Inst11[0xf8]=_P11_I;  cpu->Inst11[0xf9]=_P11_I;  cpu->Inst11[0xfa]=_P11_I;  cpu->Inst11[0xfb]=_P11_I; 
  cpu->Inst11[0xfc]=_P11_I;  cpu->Inst11[0xfd]=_P11_I;  cpu->Inst11[0xfe]=_P11_I;  cpu->Inst11[0xff]=_P11_I; 

  if (use6309) cpu_prepare_11_6309(cpu);
  }


