#include "header.h"

void DisassemIndexedBytes(word addr, char* dest) {
  byte i;
  i = ram[addr+1];
  if ((i & 0x80) == 0) {
    sprintf(dest, "%02x       ",ram[addr+1]);
    return;
    }
  switch (i & 0x0f) {
    case 0x00:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x01:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x02:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x03:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x04:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x05:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x06:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x08:
         sprintf(dest, "%02x %02x   ",ram[addr+1],ram[addr+2]);
         return;
         break;
    case 0x09:
         sprintf(dest, "%02x %02x %02x ",ram[addr+1],ram[addr+2],ram[addr+3]);
         return;
         break;
    case 0x0b:
         sprintf(dest, "%02x       ",ram[addr+1]);
         return;
         break;
    case 0x0c:
         sprintf(dest, "%02x %02x   ",ram[addr+1],ram[addr+2]);
         return;
         break;
    case 0x0d:
         sprintf(dest, "%02x %02x %02x ",ram[addr+1],ram[addr+2],ram[addr+3]);
         return;
         break;
    case 0x0f:
         sprintf(dest, "%02x %02x %02x ",ram[addr+1],ram[addr+2],ram[addr+3]);
         return;
         break;
    }
  }

word DisassemIndexed(word addr, char* dest) {
  byte i;
  byte b;
  char reg[3];
  char tmp[16];
  i = ram[addr+1];
  switch(i & 0x60) {
    case 0x00: strcpy(reg,"X"); break;
    case 0x20: strcpy(reg,"Y"); break;
    case 0x40: strcpy(reg,"U"); break;
    case 0x60: strcpy(reg,"S"); break;
    }
  if ((i & 0x80) == 0) {
    b = i & 0x0f;
    if ((i & 0x10) == 0) {
      sprintf(tmp,"+%d,%s",b,reg);
      }
    else {
      b = ((b ^ 0xff) + 1) & 0xf;
      sprintf(tmp,"-%d,%s",b,reg);
      }
    strcat(dest, tmp);
    return 2;
    }
  switch (i & 0x1f) {
    case 0x00:
         sprintf(tmp,",%s+",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x01:
         sprintf(tmp,",%s++",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x02:
         sprintf(tmp,",-%s",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x03:
         sprintf(tmp,",--%s",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x04:
         sprintf(tmp,",%s",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x05:
         sprintf(tmp,"B,%s",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x06:
         sprintf(tmp,"A,%s",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x08:
         sprintf(tmp,"%02x,%s",ram[addr+2],reg);
         strcat(dest, tmp);
         return 3;
         break;
    case 0x09:
         sprintf(tmp,"%02x%02x,%s",ram[addr+2],ram[addr+3],reg);
         strcat(dest, tmp);
         return 4;
         break;
    case 0x0b:
         sprintf(tmp,"D,%s",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x0c:
         sprintf(tmp,"%02x,PC",ram[addr+2]);
         strcat(dest, tmp);
         return 3;
         break;
    case 0x0d:
         sprintf(tmp,"%02x%02x,PC",ram[addr+2],ram[addr+3]);
         strcat(dest, tmp);
         return 4;
         break;
    case 0x11:
         sprintf(tmp,"[,%s++]",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x13:
         sprintf(tmp,"[,--%s]",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x14:
         sprintf(tmp,"[,%s]",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x15:
         sprintf(tmp,"[B,%s]",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x16:
         sprintf(tmp,"[A,%s]",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x18:
         sprintf(tmp,"[%02x,%s]",ram[addr+2],reg);
         strcat(dest, tmp);
         return 3;
         break;
    case 0x19:
         sprintf(tmp,"[%02x%02x,%s]",ram[addr+2],ram[addr+3],reg);
         strcat(dest, tmp);
         return 4;
         break;
    case 0x1b:
         sprintf(tmp,"[D,%s]",reg);
         strcat(dest, tmp);
         return 2;
         break;
    case 0x1c:
         sprintf(tmp,"[%02x,PC]",ram[addr+2]);
         strcat(dest, tmp);
         return 3;
         break;
    case 0x1d:
         sprintf(tmp,"[%02x%02x,PC]",ram[addr+2],ram[addr+3]);
         strcat(dest, tmp);
         return 4;
         break;
    case 0x1f:
         sprintf(tmp,"[%02x%02x]",ram[addr+2],ram[addr+3]);
         strcat(dest, tmp);
         return 4;
         break;
    }

  return 2;
  }


word Disassem(word addr, char* dest) {
  word d;
  char tmp[80];
  char ind[80];
  sprintf(dest,"%04x: %02x ", addr, ram[addr]);
  switch (ram[addr]) {
    case 0x00:
         sprintf(tmp,"%02x           NEG    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x03:
         sprintf(tmp,"%02x           COM    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x04:
         sprintf(tmp,"%02x           LSR    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x06:
         sprintf(tmp,"%02x           ROR    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x07:
         sprintf(tmp,"%02x           ASR    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x08:
         sprintf(tmp,"%02x           ASL    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x09:
         sprintf(tmp,"%02x           ROL    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x0a:
         sprintf(tmp,"%02x           DEC    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x0c:
         sprintf(tmp,"%02x           INC    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x0d:
         sprintf(tmp,"%02x           TST    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x0e:
         sprintf(tmp,"%02x           JMP    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x0f:
         sprintf(tmp,"%02x           CLR    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x10:
         switch (ram[addr+1]) {
           case 0x20:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBRA   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x21:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBRN",ram[addr+2],ram[addr+3]);
                addr += 4;
                break;
           case 0x22:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBHI   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x23:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBLS   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x24:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBCC   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x25:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBCS   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x26:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBNE   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x27:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBEQ   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x28:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBVC   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x29:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBVS   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x2a:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBPL   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x2b:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBMI   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x2c:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBGE   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x2d:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBLT   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x2e:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x     LBGT   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x2f:
                d = (ram[addr+2] << 8) | ram[addr+3];
                d = addr + 4 + d;
                sprintf(tmp,"20 %02x %02x      LBLE   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x3f:
                sprintf(tmp,"3f           SWI2");
                addr += 2;
                break;
           case 0x83:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"83 %02x %02x     CMPD   #$%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x8c:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"8c %02x %02x     CMPY   #$%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x8e:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"8e %02x %02x     LDY    #$%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x93:
                sprintf(tmp,"93 %02x        CMPD   <$%02x",ram[addr+2],ram[addr+2]);
                addr += 3;
                break;
           case 0x9c:
                sprintf(tmp,"9c %02x        CMPY   <$%02x",ram[addr+2],ram[addr+2]);
                addr += 3;
                break;
           case 0x9e:
                sprintf(tmp,"9e %02x        LDY    <$%02x",ram[addr+2],ram[addr+2]);
                addr += 3;
                break;
           case 0x9f:
                sprintf(tmp,"9f %02x        STY    <$%02x",ram[addr+2],ram[addr+2]);
                addr += 3;
                break;
           case 0xa3:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"a3 ");
                strcat(tmp, ind);
                strcat(tmp," CMPD   ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xac:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"ac ");
                strcat(tmp, ind);
                strcat(tmp," CMPY   ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xae:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"ae ");
                strcat(tmp, ind);
                strcat(tmp," LDY    ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xaf:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"af ");
                strcat(tmp, ind);
                strcat(tmp," STY    ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xb3:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"b3 %02x %02x     CMPD   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0xbc:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"b3 %02x %02x     CMPY   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0xbe:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"be %02x %02x     LDY    $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0xbf:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"bf %02x %02x     STY    $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0xce:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"ce %02x %02x     LDS    #$%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0xde:
                sprintf(tmp,"de %02x        LDS    <$%02x",ram[addr+2],ram[addr+2]);
                addr += 3;
                break;
           case 0xee:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"ee ");
                strcat(tmp, ind);
                strcat(tmp," LDS    ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xef:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"ef ");
                strcat(tmp, ind);
                strcat(tmp," STS    ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xfe:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"fe %02x %02x     LDS    $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0xff:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"ff %02x %02x     STS    $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           }
         break;
    case 0x11:
         switch (ram[addr+1]) {
           case 0x3f:
                sprintf(tmp,"3f           SWI3");
                addr += 2;
                break;
           case 0x83:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"83 %02x %02x     CMPU   #$%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x8c:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"8c %02x %02x     CMPS   #$%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0x93:
                sprintf(tmp,"93 %02x        CMPU   <$%02x",ram[addr+2],ram[addr+2]);
                addr += 3;
                break;
           case 0x9c:
                sprintf(tmp,"9c %02x        CMPS   <$%02x",ram[addr+2],ram[addr+2]);
                addr += 3;
                break;
           case 0xa3:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"a3 ");
                strcat(tmp, ind);
                strcat(tmp," CMPU   ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xac:
                addr++;
                DisassemIndexedBytes(addr, ind);
                sprintf(tmp,"ac ");
                strcat(tmp, ind);
                strcat(tmp," CMPS   ");
                addr += DisassemIndexed(addr, tmp);
                break;
           case 0xb3:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"b3 %02x %02x     CMPU   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           case 0xbc:
                d = (ram[addr+2] << 8) | ram[addr+3];
                sprintf(tmp,"b3 %02x %02x     CMPS   $%04x",ram[addr+2],ram[addr+3],d);
                addr += 4;
                break;
           }
         break;
    case 0x12:
         sprintf(tmp,"             NOP");
         addr += 1; break;
    case 0x13:
         sprintf(tmp,"             SYNC");
         addr += 1; break;
    case 0x19:
         sprintf(tmp,"             DAA");
         addr += 1; break;
    case 0x1a:
         sprintf(tmp,"%02x           ORCC   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x1c:
         sprintf(tmp,"%02x           ANDCC  #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x1d:
         sprintf(tmp,"             SEX");
         addr += 1; break;
    case 0x1e:
         sprintf(tmp,"%02x           EXG    ",ram[addr+1]);
         switch(ram[addr+1] & 0xf0) {
           case 0x00: strcat(tmp,"D,"); break;
           case 0x10: strcat(tmp,"X,"); break;
           case 0x20: strcat(tmp,"Y,"); break;
           case 0x30: strcat(tmp,"U,"); break;
           case 0x40: strcat(tmp,"S,"); break;
           case 0x50: strcat(tmp,"PC,"); break;
           case 0x80: strcat(tmp,"A,"); break;
           case 0x90: strcat(tmp,"B,"); break;
           case 0xa0: strcat(tmp,"CC,"); break;
           case 0xb0: strcat(tmp,"DP,"); break;
           }
         switch(ram[addr+1] & 0x0f) {
           case 0x00: strcat(tmp,"D"); break;
           case 0x01: strcat(tmp,"X"); break;
           case 0x02: strcat(tmp,"Y"); break;
           case 0x03: strcat(tmp,"U"); break;
           case 0x04: strcat(tmp,"S"); break;
           case 0x05: strcat(tmp,"PC"); break;
           case 0x08: strcat(tmp,"A"); break;
           case 0x09: strcat(tmp,"B"); break;
           case 0x0a: strcat(tmp,"CC"); break;
           case 0x0b: strcat(tmp,"DP"); break;
           }
         addr += 2; break;
    case 0x1f:
         sprintf(tmp,"%02x           TFR    ",ram[addr+1]);
         switch(ram[addr+1] & 0xf0) {
           case 0x00: strcat(tmp,"D,"); break;
           case 0x10: strcat(tmp,"X,"); break;
           case 0x20: strcat(tmp,"Y,"); break;
           case 0x30: strcat(tmp,"U,"); break;
           case 0x40: strcat(tmp,"S,"); break;
           case 0x50: strcat(tmp,"PC,"); break;
           case 0x80: strcat(tmp,"A,"); break;
           case 0x90: strcat(tmp,"B,"); break;
           case 0xa0: strcat(tmp,"CC,"); break;
           case 0xb0: strcat(tmp,"DP,"); break;
           }
         switch(ram[addr+1] & 0x0f) {
           case 0x00: strcat(tmp,"D"); break;
           case 0x01: strcat(tmp,"X"); break;
           case 0x02: strcat(tmp,"Y"); break;
           case 0x03: strcat(tmp,"U"); break;
           case 0x04: strcat(tmp,"S"); break;
           case 0x05: strcat(tmp,"PC"); break;
           case 0x08: strcat(tmp,"A"); break;
           case 0x09: strcat(tmp,"B"); break;
           case 0x0a: strcat(tmp,"CC"); break;
           case 0x0b: strcat(tmp,"DP"); break;
           }
         addr += 2; break;
    case 0x20:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BRA    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x21:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BRN    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x22:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BHI    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x23:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BLS    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x24:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BCC    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x25:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BCS    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x26:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BNS    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x27:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BEQ    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x28:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BVC    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x29:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BVS    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x2a:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BPL    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x2b:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BMI    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x2c:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BGE    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x2d:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BLT    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x2e:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BGT    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x2f:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BLE    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x30:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LEAX   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x31:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LEAY   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x32:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LEAS   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x33:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LEAU   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x34:
         sprintf(tmp,"%02x           PSHS   $%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x35:
         sprintf(tmp,"%02x           PULS   $%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x36:
         sprintf(tmp,"%02x           PSHU   $%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x37:
         sprintf(tmp,"%02x           PULU   $%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x39:
         sprintf(tmp,"             RTS");
         addr += 1; break;
    case 0x3a:
         sprintf(tmp,"             ABX");
         addr += 1; break;
    case 0x3b:
         sprintf(tmp,"             RTI");
         addr += 1; break;
    case 0x3c:
         sprintf(tmp,"%02x           CWAI   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x3d:
         sprintf(tmp,"             MUL");
         addr += 1; break;
    case 0x3f:
         sprintf(tmp,"             SWI");
         addr += 1; break;
    case 0x40:
         sprintf(tmp,"             NEGA");
         addr += 1; break;
    case 0x43:
         sprintf(tmp,"             COMA");
         addr += 1; break;
    case 0x44:
         sprintf(tmp,"             LSRA");
         addr += 1; break;
    case 0x46:
         sprintf(tmp,"             RORA");
         addr += 1; break;
    case 0x47:
         sprintf(tmp,"             ASRA");
         addr += 1; break;
    case 0x48:
         sprintf(tmp,"             ASLA");
         addr += 1; break;
    case 0x49:
         sprintf(tmp,"             ROLA");
         addr += 1; break;
    case 0x4a:
         sprintf(tmp,"             DECA");
         addr += 1; break;
    case 0x4c:
         sprintf(tmp,"             INCA");
         addr += 1; break;
    case 0x4d:
         sprintf(tmp,"             TSTA");
         addr += 1; break;
    case 0x4f:
         sprintf(tmp,"             CLRA");
         addr += 1; break;
    case 0x50:
         sprintf(tmp,"             NEGB");
         addr += 1; break;
    case 0x53:
         sprintf(tmp,"             COMB");
         addr += 1; break;
    case 0x54:
         sprintf(tmp,"             LSRB");
         addr += 1; break;
    case 0x56:
         sprintf(tmp,"             RORB");
         addr += 1; break;
    case 0x57:
         sprintf(tmp,"             ASRB");
         addr += 1; break;
    case 0x58:
         sprintf(tmp,"             ASLB");
         addr += 1; break;
    case 0x59:
         sprintf(tmp,"             ROLB");
         addr += 1; break;
    case 0x5a:
         sprintf(tmp,"             DECB");
         addr += 1; break;
    case 0x5c:
         sprintf(tmp,"             INCB");
         addr += 1; break;
    case 0x5d:
         sprintf(tmp,"             TSTB");
         addr += 1; break;
    case 0x5f:
         sprintf(tmp,"             CLRB");
         addr += 1; break;
    case 0x60:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    NEG    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x63:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    COM    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x64:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LSR    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x66:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ROR    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x67:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ASR    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x68:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ASL    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x69:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ROL    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x6a:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    DEC    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x6c:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    INC    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x6d:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    TST    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x6e:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    JMP    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x6f:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    CLR    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0x70:
         sprintf(tmp,"%02x %02x        NEG    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x73:
         sprintf(tmp,"%02x %02x        COM    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x74:
         sprintf(tmp,"%02x %02x        LSR    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x76:
         sprintf(tmp,"%02x %02x        ROR    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x77:
         sprintf(tmp,"%02x %02x        ASR    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x78:
         sprintf(tmp,"%02x %02x        ASL    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x79:
         sprintf(tmp,"%02x %02x        ROL    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x7a:
         sprintf(tmp,"%02x %02x        DEC    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x7c:
         sprintf(tmp,"%02x %02x        INC    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x7d:
         sprintf(tmp,"%02x %02x        TST    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x7e:
         sprintf(tmp,"%02x %02x        JMP    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x7f:
         sprintf(tmp,"%02x %02x        CLR    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x80:
         sprintf(tmp,"%02x           SUBA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x81:
         sprintf(tmp,"%02x           CMPA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x82:
         sprintf(tmp,"%02x           SBCA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x83:
         sprintf(tmp,"%02x           SUBD   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x84:
         sprintf(tmp,"%02x           ANDA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x85:
         sprintf(tmp,"%02x           BITA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x86:
         sprintf(tmp,"%02x           LDA    #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x88:
         sprintf(tmp,"%02x           EORA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x89:
         sprintf(tmp,"%02x           ADCA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x8a:
         sprintf(tmp,"%02x           ORA    #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x8b:
         sprintf(tmp,"%02x           ADDA   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x8c:
         sprintf(tmp,"%02x %02x        CMPX   #$%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x8d:
         d = ram[addr+1];
         if (d & 0x80) d |= 0xff00;
         d = addr + 2 + d;
         sprintf(tmp,"%02x           BSR    $%04x",ram[addr+1],d);
         addr += 2;
         break;
    case 0x8e:
         sprintf(tmp,"%02x %02x        LDX    #$%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0x90:
         sprintf(tmp,"%02x           SUBA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x91:
         sprintf(tmp,"%02x           CMPA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x92:
         sprintf(tmp,"%02x           SBCA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x93:
         sprintf(tmp,"%02x           SUBD   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x94:
         sprintf(tmp,"%02x           ANDA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x95:
         sprintf(tmp,"%02x           BITA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x96:
         sprintf(tmp,"%02x           LDA    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x97:
         sprintf(tmp,"%02x           STA    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x98:
         sprintf(tmp,"%02x           EORA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x99:
         sprintf(tmp,"%02x           ADCA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x9a:
         sprintf(tmp,"%02x           ORA    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x9b:
         sprintf(tmp,"%02x           ADDA   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x9c:
         sprintf(tmp,"%02x           CMPX   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x9d:
         sprintf(tmp,"%02x           JSR    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x9e:
         sprintf(tmp,"%02x           LDX    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0x9f:
         sprintf(tmp,"%02x           STX    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xa0:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    SUBA   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa1:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    CMPA   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa2:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    SBCA   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa3:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    SUBD   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa4:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ANDA   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa5:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    BITA   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa6:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LDA    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa7:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    STA    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa8:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    EORA   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xa9:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ADCA   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xaa:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ORA    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xab:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ADCD   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xac:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    CMPX   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xad:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    JSR    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xae:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LDX    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xaf:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    STX    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xb0:
         sprintf(tmp,"%02x %02x        SUBA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb1:
         sprintf(tmp,"%02x %02x        CMPA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb2:
         sprintf(tmp,"%02x %02x        SBCA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb3:
         sprintf(tmp,"%02x %02x        SUBD   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb4:
         sprintf(tmp,"%02x %02x        ANDA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb5:
         sprintf(tmp,"%02x %02x        BITA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb6:
         sprintf(tmp,"%02x %02x        LDA    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb7:
         sprintf(tmp,"%02x %02x        STA    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb8:
         sprintf(tmp,"%02x %02x        EORA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xb9:
         sprintf(tmp,"%02x %02x        ADCA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xba:
         sprintf(tmp,"%02x %02x        ORA    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xbb:
         sprintf(tmp,"%02x %02x        ADDA   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xbc:
         sprintf(tmp,"%02x %02x        CMPX   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xbd:
         sprintf(tmp,"%02x %02x        JSR    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xbe:
         sprintf(tmp,"%02x %02x        LDX    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xbf:
         sprintf(tmp,"%02x %02x        STX    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xc0:
         sprintf(tmp,"%02x           SUBB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xc1:
         sprintf(tmp,"%02x           CMPB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xc2:
         sprintf(tmp,"%02x           SBCB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xc3:
         sprintf(tmp,"%02x %02x       ADDD   #$%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xc4:
         sprintf(tmp,"%02x           ANDB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xc5:
         sprintf(tmp,"%02x           BITB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xc6:
         sprintf(tmp,"%02x           LDB    #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xc8:
         sprintf(tmp,"%02x           EORB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xc9:
         sprintf(tmp,"%02x           ADCB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xca:
         sprintf(tmp,"%02x           ORB    #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xcb:
         sprintf(tmp,"%02x           ADDB   #$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xcc:
         sprintf(tmp,"%02x %02x       LDD    #$%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xce:
         sprintf(tmp,"%02x %02x       LDU    #$%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xd0:
         sprintf(tmp,"%02x           SUBB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd1:
         sprintf(tmp,"%02x           CMPB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd2:
         sprintf(tmp,"%02x           SBCB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd3:
         sprintf(tmp,"%02x           ADDD   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd4:
         sprintf(tmp,"%02x           ANDB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd5:
         sprintf(tmp,"%02x           BITB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd6:
         sprintf(tmp,"%02x           LDB    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd7:
         sprintf(tmp,"%02x           STB    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd8:
         sprintf(tmp,"%02x           EORB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xd9:
         sprintf(tmp,"%02x           ADCB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xda:
         sprintf(tmp,"%02x           ORB    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xdb:
         sprintf(tmp,"%02x           ADDB   <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xdc:
         sprintf(tmp,"%02x           LDD    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xdd:
         sprintf(tmp,"%02x           STD    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xde:
         sprintf(tmp,"%02x           LDU    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xdf:
         sprintf(tmp,"%02x           STU    <$%02x",ram[addr+1],ram[addr+1]);
         addr += 2; break;
    case 0xe0:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    SUBB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe1:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    CMPB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe2:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    SBCB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe3:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ADDD   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe4:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ANDB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe5:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    BITB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe6:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LDB    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe7:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    STB    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe8:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    EORB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xe9:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ADCB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xea:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ORB    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xeb:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    ADDB   ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xec:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LDD    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xed:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    STD    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xee:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    LDU    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xef:
         DisassemIndexedBytes(addr, tmp);
         strcat(tmp,"    STU    ");
         addr += DisassemIndexed(addr, tmp);
         break;
    case 0xf0:
         sprintf(tmp,"%02x %02x        SUBB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf1:
         sprintf(tmp,"%02x %02x        CMPB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf2:
         sprintf(tmp,"%02x %02x        SBCB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf3:
         sprintf(tmp,"%02x %02x        ADDD   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf4:
         sprintf(tmp,"%02x %02x        ANDB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf5:
         sprintf(tmp,"%02x %02x        BITB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf6:
         sprintf(tmp,"%02x %02x        LDB    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf7:
         sprintf(tmp,"%02x %02x        STB    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf8:
         sprintf(tmp,"%02x %02x        EORB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xf9:
         sprintf(tmp,"%02x %02x        ADCB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xfa:
         sprintf(tmp,"%02x %02x        ORB    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xfb:
         sprintf(tmp,"%02x %02x        ADDB   $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xfc:
         sprintf(tmp,"%02x %02x        LDD    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xfd:
         sprintf(tmp,"%02x %02x        STD    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xfe:
         sprintf(tmp,"%02x %02x        LDU    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    case 0xff:
         sprintf(tmp,"%02x %02x        STU    $%02x%02x",ram[addr+1],ram[addr+2],ram[addr+1],ram[addr+2]);
         addr += 3; break;
    default: 
         sprintf(tmp,"              DB   %02x",ram[addr]); addr++; break;
    }
  strcat(dest, tmp);
  return addr;
  }

