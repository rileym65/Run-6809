#ifndef _CPU_H
#define _CPU_H

#ifndef _BYTE
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;
#define _BYTE
#endif

#define FLAG_C     1
#define FLAG_V     2
#define FLAG_Z     4
#define FLAG_N     8
#define FLAG_I    16
#define FLAG_H    32
#define FLAG_F    64
#define FLAG_E   128

typedef struct _CPU {
  word pc;
  word u;
  word s;
  word x;
  word y;
  byte a;
  byte b;
  byte dp;
  byte cc;
  byte ts;
  byte halt;
  void (*Inst[256])(struct _CPU *cpu);
  void (*Inst10[256])(struct _CPU *cpu);
  void (*Inst11[256])(struct _CPU *cpu);
  } CPU;

#endif

