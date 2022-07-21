#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

#ifndef _BYTE
typedef unsigned char byte;
#define _BYTE
#endif

#ifndef _WORD
typedef unsigned short word;
#endif

#ifndef _DWORD
typedef unsigned int dword;
#endif

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

LINK CPU        cpu;
LINK byte       ram[65536];
LINK char       runDebugger;
LINK int        use6309;

extern byte _6809_add(CPU* cpu, byte a, byte b, byte cry);
extern word _6809_add16(CPU* cpu, word a, word b, byte cry);
extern byte _6809_and(CPU* cpu, byte a, byte b);
extern word _6809_and16(CPU* cpu, word a, word b);
extern word _6809_asl16(CPU* cpu, word a);
extern word _6809_asr16(CPU* cpu, word a);
extern byte _6809_com(CPU* cpu, byte a);
extern word _6809_com16(CPU* cpu, word a);
extern byte _6809_dec(CPU* cpu, byte a);
extern word _6809_dec16(CPU* cpu, word a);
extern void _6809_div(CPU* cpu, byte b);
extern void _6809_div16(CPU* cpu, word b);
extern word _6809_ea(CPU* cpu);
extern byte _6809_eor(CPU* cpu, byte a, byte b);
extern word _6809_eor16(CPU* cpu, word a, word b);
extern byte _6809_inc(CPU* cpu, byte a);
extern word _6809_inc16(CPU* cpu, word a);
extern word _6809_lsl16(CPU* cpu, word a);
extern word _6809_lsr16(CPU* cpu, word a);
extern void _6809_mul16(CPU* cpu, word b);
extern word _6809_neg16(CPU* cpu, word a);
extern byte _6809_or(CPU* cpu, byte a, byte b);
extern word _6809_or16(CPU* cpu, word a, word b);
extern byte _6809_pop(byte* ram, CPU* cpu);
extern byte _6809_popu(byte* ram, CPU* cpu);
extern byte _6809_rol(CPU* cpu, byte a);
extern word _6809_rol16(CPU* cpu, word a);
extern byte _6809_ror(CPU* cpu, byte a);
extern word _6809_ror16(CPU* cpu, word a);
extern byte _6809_sub(CPU* cpu, byte a, byte b, byte cry);
extern word _6809_sub16(CPU* cpu, word a, word b, byte cry);
extern void _6809_trap(CPU* cpu);
extern void _6809_push(byte* ram, CPU* cpu, byte v);
extern void _6809_pushu(byte* ram, CPU* cpu, byte v);
extern void cpu_firq(CPU* cpu);
extern void cpu_irq(CPU* cpu);
extern void cpu_nmi(CPU* cpu);
extern void cpu_reset(CPU* cpu);
extern void cpu_cycle(CPU* cpu);
extern void cpu_prepare(CPU *cpu);
extern void cpu_prepare_10(CPU *cpu);
extern void cpu_prepare_11(CPU *cpu);
extern byte readMem(byte* ram, word address);
extern void writeMem(byte* ram, word address, byte value);


extern void Debugger();
extern word Disassem(word addr, char* dest);
extern int evaluate(char* expr);
extern int loadFile(char* filename);
extern void GotoXY(int x, int y);

#endif
