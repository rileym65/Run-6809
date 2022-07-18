PROJECT=run09
CC=gcc
DEFS=-Wall
INCS=
INCIDR=
LIBS=
LIBDIR=
OBJS=\
	cpu.o \
	cpu10.o \
	cpu11.o \
	debugger.o \
	disassem.o \
	evaluate.o \
	loadfile.o \
	main.o

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(OBJS) $(LIBDIR) $(LIBS) -o $(PROJECT)

.c.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

clean:
	-rm *.o
	-rm $(PROJECT)

cpu.o:       cpu.h header.h cpu.c
cpu10.o:     cpu.h header.h cpu10.c
cpu11.o:     cpu.h header.h cpu11.c
debugger.o:  cpu.h header.h debugger.c
disassem.o:  cpu.h header.h disassem.c
evaluate.o:  cpu.h header.h evaluate.c
loadfile.o:  cpu.h header.h loadfile.c
main.o:      cpu.h header.h main.c

