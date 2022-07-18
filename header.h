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

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

LINK CPU        cpu;
LINK byte       ram[65536];
LINK char       runDebugger;
LINK int        use6309;

extern word _6809_ea(CPU* cpu);
extern word _6809_sub16(CPU* cpu, word a, word b, byte cry);
extern void _6809_push(byte* ram, CPU* cpu, byte v);
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
