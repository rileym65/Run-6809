#include "cpu.h"
#include "header.h"

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

void _P11_30(CPU *cpu) {
  }

void _P11_31(CPU *cpu) {
  }

void _P11_32(CPU *cpu) {
  }

void _P11_33(CPU *cpu) {
  }

void _P11_34(CPU *cpu) {
  }

void _P11_35(CPU *cpu) {
  }

void _P11_36(CPU *cpu) {
  }

void _P11_37(CPU *cpu) {
  }

void _P11_38(CPU *cpu) {
  }

void _P11_39(CPU *cpu) {
  }

void _P11_3A(CPU *cpu) {
  }

void _P11_3B(CPU *cpu) {
  }

void _P11_3C(CPU *cpu) {
  }

void _P11_3D(CPU *cpu) {
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

void _P11_43(CPU *cpu) {
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

void _P11_4A(CPU *cpu) {
  }

void _P11_4B(CPU *cpu) {
  }

void _P11_4C(CPU *cpu) {
  }

void _P11_4D(CPU *cpu) {
  }

void _P11_4E(CPU *cpu) {
  }

void _P11_4F(CPU *cpu) {
  }

void _P11_50(CPU *cpu) {
  }

void _P11_51(CPU *cpu) {
  }

void _P11_52(CPU *cpu) {
  }

void _P11_53(CPU *cpu) {
  }

void _P11_54(CPU *cpu) {
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

void _P11_5A(CPU *cpu) {
  }

void _P11_5B(CPU *cpu) {
  }

void _P11_5C(CPU *cpu) {
  }

void _P11_5D(CPU *cpu) {
  }

void _P11_5E(CPU *cpu) {
  }

void _P11_5F(CPU *cpu) {
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

void _P11_80(CPU *cpu) {
  }

void _P11_81(CPU *cpu) {
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

void _P11_86(CPU *cpu) {
  }

void _P11_87(CPU *cpu) {
  }

void _P11_88(CPU *cpu) {
  }

void _P11_89(CPU *cpu) {
  }

void _P11_8A(CPU *cpu) {
  }

void _P11_8B(CPU *cpu) {
  }

void _P11_8C(CPU *cpu) {                         /* CMPS # */
  word b;
  b = (readMem(ram, cpu->pc) << 8) + readMem(ram, cpu->pc+1);
  cpu->pc += 2;
  _6809_sub16(cpu, cpu->s, b, 0);
  cpu->ts += (cpu->md & 1) ? 4 : 5;
  }

void _P11_8D(CPU *cpu) {
  }

void _P11_8E(CPU *cpu) {
  }

void _P11_8F(CPU *cpu) {
  }

void _P11_90(CPU *cpu) {
  }

void _P11_91(CPU *cpu) {
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

void _P11_96(CPU *cpu) {
  }

void _P11_97(CPU *cpu) {
  }

void _P11_98(CPU *cpu) {
  }

void _P11_99(CPU *cpu) {
  }

void _P11_9A(CPU *cpu) {
  }

void _P11_9B(CPU *cpu) {
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

void _P11_9D(CPU *cpu) {
  }

void _P11_9E(CPU *cpu) {
  }

void _P11_9F(CPU *cpu) {
  }

void _P11_A0(CPU *cpu) {
  }

void _P11_A1(CPU *cpu) {
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

void _P11_A6(CPU *cpu) {
  }

void _P11_A7(CPU *cpu) {
  }

void _P11_A8(CPU *cpu) {
  }

void _P11_A9(CPU *cpu) {
  }

void _P11_AA(CPU *cpu) {
  }

void _P11_AB(CPU *cpu) {
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

void _P11_AD(CPU *cpu) {
  }

void _P11_AE(CPU *cpu) {
  }

void _P11_AF(CPU *cpu) {
  }

void _P11_B0(CPU *cpu) {
  }

void _P11_B1(CPU *cpu) {
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

void _P11_B6(CPU *cpu) {
  }

void _P11_B7(CPU *cpu) {
  }

void _P11_B8(CPU *cpu) {
  }

void _P11_B9(CPU *cpu) {
  }

void _P11_BA(CPU *cpu) {
  }

void _P11_BB(CPU *cpu) {
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

void _P11_BD(CPU *cpu) {
  }

void _P11_BE(CPU *cpu) {
  }

void _P11_BF(CPU *cpu) {
  }

void _P11_C0(CPU *cpu) {
  }

void _P11_C1(CPU *cpu) {
  }

void _P11_C2(CPU *cpu) {
  }

void _P11_C3(CPU *cpu) {
  }

void _P11_C4(CPU *cpu) {
  }

void _P11_C5(CPU *cpu) {
  }

void _P11_C6(CPU *cpu) {
  }

void _P11_C7(CPU *cpu) {
  }

void _P11_C8(CPU *cpu) {
  }

void _P11_C9(CPU *cpu) {
  }

void _P11_CA(CPU *cpu) {
  }

void _P11_CB(CPU *cpu) {
  }

void _P11_CC(CPU *cpu) {
  }

void _P11_CD(CPU *cpu) {
  }

void _P11_CE(CPU *cpu) {
  }

void _P11_CF(CPU *cpu) {
  }

void _P11_D0(CPU *cpu) {
  }

void _P11_D1(CPU *cpu) {
  }

void _P11_D2(CPU *cpu) {
  }

void _P11_D3(CPU *cpu) {
  }

void _P11_D4(CPU *cpu) {
  }

void _P11_D5(CPU *cpu) {
  }

void _P11_D6(CPU *cpu) {
  }

void _P11_D7(CPU *cpu) {
  }

void _P11_D8(CPU *cpu) {
  }

void _P11_D9(CPU *cpu) {
  }

void _P11_DA(CPU *cpu) {
  }

void _P11_DB(CPU *cpu) {
  }

void _P11_DC(CPU *cpu) {
  }

void _P11_DD(CPU *cpu) {
  }

void _P11_DE(CPU *cpu) {
  }

void _P11_DF(CPU *cpu) {
  }

void _P11_E0(CPU *cpu) {
  }

void _P11_E1(CPU *cpu) {
  }

void _P11_E2(CPU *cpu) {
  }

void _P11_E3(CPU *cpu) {
  }

void _P11_E4(CPU *cpu) {
  }

void _P11_E5(CPU *cpu) {
  }

void _P11_E6(CPU *cpu) {
  }

void _P11_E7(CPU *cpu) {
  }

void _P11_E8(CPU *cpu) {
  }

void _P11_E9(CPU *cpu) {
  }

void _P11_EA(CPU *cpu) {
  }

void _P11_EB(CPU *cpu) {
  }

void _P11_EC(CPU *cpu) {
  }

void _P11_ED(CPU *cpu) {
  }

void _P11_EE(CPU *cpu) {
  }

void _P11_EF(CPU *cpu) {
  }

void _P11_F0(CPU *cpu) {
  }

void _P11_F1(CPU *cpu) {
  }

void _P11_F2(CPU *cpu) {
  }

void _P11_F3(CPU *cpu) {
  }

void _P11_F4(CPU *cpu) {
  }

void _P11_F5(CPU *cpu) {
  }

void _P11_F6(CPU *cpu) {
  }

void _P11_F7(CPU *cpu) {
  }

void _P11_F8(CPU *cpu) {
  }

void _P11_F9(CPU *cpu) {
  }

void _P11_FA(CPU *cpu) {
  }

void _P11_FB(CPU *cpu) {
  }

void _P11_FC(CPU *cpu) {
  }

void _P11_FD(CPU *cpu) {
  }

void _P11_FE(CPU *cpu) {
  }

void _P11_FF(CPU *cpu) {
  }

void cpu_prepare_11(CPU *cpu) {
  cpu->Inst11[0x00]=_P11_0; cpu->Inst11[0x01]=_P11_1; cpu->Inst11[0x02]=_P11_2; cpu->Inst11[0x03]=_P11_3;
  cpu->Inst11[0x04]=_P11_4; cpu->Inst11[0x05]=_P11_5; cpu->Inst11[0x06]=_P11_6; cpu->Inst11[0x07]=_P11_7;
  cpu->Inst11[0x08]=_P11_8; cpu->Inst11[0x09]=_P11_9; cpu->Inst11[0x0a]=_P11_A; cpu->Inst11[0x0b]=_P11_B;
  cpu->Inst11[0x0c]=_P11_C; cpu->Inst11[0x0d]=_P11_D; cpu->Inst11[0x0e]=_P11_E; cpu->Inst11[0x0f]=_P11_F;

  cpu->Inst11[0x10]=_P11_10; cpu->Inst11[0x11]=_P11_11; cpu->Inst11[0x12]=_P11_12; cpu->Inst11[0x13]=_P11_13;
  cpu->Inst11[0x14]=_P11_14; cpu->Inst11[0x15]=_P11_15; cpu->Inst11[0x16]=_P11_16; cpu->Inst11[0x17]=_P11_17;
  cpu->Inst11[0x18]=_P11_18; cpu->Inst11[0x19]=_P11_19; cpu->Inst11[0x1a]=_P11_1A; cpu->Inst11[0x1b]=_P11_1B;
  cpu->Inst11[0x1c]=_P11_1C; cpu->Inst11[0x1d]=_P11_1D; cpu->Inst11[0x1e]=_P11_1E; cpu->Inst11[0x1f]=_P11_1F;

  cpu->Inst11[0x20]=_P11_20; cpu->Inst11[0x21]=_P11_21; cpu->Inst11[0x22]=_P11_22; cpu->Inst11[0x23]=_P11_23;
  cpu->Inst11[0x24]=_P11_24; cpu->Inst11[0x25]=_P11_25; cpu->Inst11[0x26]=_P11_26; cpu->Inst11[0x27]=_P11_27;
  cpu->Inst11[0x28]=_P11_28; cpu->Inst11[0x29]=_P11_29; cpu->Inst11[0x2a]=_P11_2A; cpu->Inst11[0x2b]=_P11_2B;
  cpu->Inst11[0x2c]=_P11_2C; cpu->Inst11[0x2d]=_P11_2D; cpu->Inst11[0x2e]=_P11_2E; cpu->Inst11[0x2f]=_P11_2F;

  cpu->Inst11[0x30]=_P11_30; cpu->Inst11[0x31]=_P11_31; cpu->Inst11[0x32]=_P11_32; cpu->Inst11[0x33]=_P11_33;
  cpu->Inst11[0x34]=_P11_34; cpu->Inst11[0x35]=_P11_35; cpu->Inst11[0x36]=_P11_36; cpu->Inst11[0x37]=_P11_37;
  cpu->Inst11[0x38]=_P11_38; cpu->Inst11[0x39]=_P11_39; cpu->Inst11[0x3a]=_P11_3A; cpu->Inst11[0x3b]=_P11_3B;
  cpu->Inst11[0x3c]=_P11_3C; cpu->Inst11[0x3d]=_P11_3D; cpu->Inst11[0x3e]=_P11_3E; cpu->Inst11[0x3f]=_P11_3F;

  cpu->Inst11[0x40]=_P11_40; cpu->Inst11[0x41]=_P11_41; cpu->Inst11[0x42]=_P11_42; cpu->Inst11[0x43]=_P11_43;
  cpu->Inst11[0x44]=_P11_44; cpu->Inst11[0x45]=_P11_45; cpu->Inst11[0x46]=_P11_46; cpu->Inst11[0x47]=_P11_47;
  cpu->Inst11[0x48]=_P11_48; cpu->Inst11[0x49]=_P11_49; cpu->Inst11[0x4a]=_P11_4A; cpu->Inst11[0x4b]=_P11_4B;
  cpu->Inst11[0x4c]=_P11_4C; cpu->Inst11[0x4d]=_P11_4D; cpu->Inst11[0x4e]=_P11_4E; cpu->Inst11[0x4f]=_P11_4F;

  cpu->Inst11[0x50]=_P11_50; cpu->Inst11[0x51]=_P11_51; cpu->Inst11[0x52]=_P11_52; cpu->Inst11[0x53]=_P11_53;
  cpu->Inst11[0x54]=_P11_54; cpu->Inst11[0x55]=_P11_55; cpu->Inst11[0x56]=_P11_56; cpu->Inst11[0x57]=_P11_57;
  cpu->Inst11[0x58]=_P11_58; cpu->Inst11[0x59]=_P11_59; cpu->Inst11[0x5a]=_P11_5A; cpu->Inst11[0x5b]=_P11_5B;
  cpu->Inst11[0x5c]=_P11_5C; cpu->Inst11[0x5d]=_P11_5D; cpu->Inst11[0x5e]=_P11_5E; cpu->Inst11[0x5f]=_P11_5F;

  cpu->Inst11[0x60]=_P11_60; cpu->Inst11[0x61]=_P11_61; cpu->Inst11[0x62]=_P11_62; cpu->Inst11[0x63]=_P11_63;
  cpu->Inst11[0x64]=_P11_64; cpu->Inst11[0x65]=_P11_65; cpu->Inst11[0x66]=_P11_66; cpu->Inst11[0x67]=_P11_67;
  cpu->Inst11[0x68]=_P11_68; cpu->Inst11[0x69]=_P11_69; cpu->Inst11[0x6a]=_P11_6A; cpu->Inst11[0x6b]=_P11_6B;
  cpu->Inst11[0x6c]=_P11_6C; cpu->Inst11[0x6d]=_P11_6D; cpu->Inst11[0x6e]=_P11_6E; cpu->Inst11[0x6f]=_P11_6F;

  cpu->Inst11[0x70]=_P11_70; cpu->Inst11[0x71]=_P11_71; cpu->Inst11[0x72]=_P11_72; cpu->Inst11[0x73]=_P11_73;
  cpu->Inst11[0x74]=_P11_74; cpu->Inst11[0x75]=_P11_75; cpu->Inst11[0x76]=_P11_76; cpu->Inst11[0x77]=_P11_77;
  cpu->Inst11[0x78]=_P11_78; cpu->Inst11[0x79]=_P11_79; cpu->Inst11[0x7a]=_P11_7A; cpu->Inst11[0x7b]=_P11_7B;
  cpu->Inst11[0x7c]=_P11_7C; cpu->Inst11[0x7d]=_P11_7D; cpu->Inst11[0x7e]=_P11_7E; cpu->Inst11[0x7f]=_P11_7F;

  cpu->Inst11[0x80]=_P11_80; cpu->Inst11[0x81]=_P11_81; cpu->Inst11[0x82]=_P11_82; cpu->Inst11[0x83]=_P11_83;
  cpu->Inst11[0x84]=_P11_84; cpu->Inst11[0x85]=_P11_85; cpu->Inst11[0x86]=_P11_86; cpu->Inst11[0x87]=_P11_87;
  cpu->Inst11[0x88]=_P11_88; cpu->Inst11[0x89]=_P11_89; cpu->Inst11[0x8a]=_P11_8A; cpu->Inst11[0x8b]=_P11_8B;
  cpu->Inst11[0x8c]=_P11_8C; cpu->Inst11[0x8d]=_P11_8D; cpu->Inst11[0x8e]=_P11_8E; cpu->Inst11[0x8f]=_P11_8F;

  cpu->Inst11[0x90]=_P11_90; cpu->Inst11[0x91]=_P11_91; cpu->Inst11[0x92]=_P11_92; cpu->Inst11[0x93]=_P11_93;
  cpu->Inst11[0x94]=_P11_94; cpu->Inst11[0x95]=_P11_95; cpu->Inst11[0x96]=_P11_96; cpu->Inst11[0x97]=_P11_97;
  cpu->Inst11[0x98]=_P11_98; cpu->Inst11[0x99]=_P11_99; cpu->Inst11[0x9a]=_P11_9A; cpu->Inst11[0x9b]=_P11_9B;
  cpu->Inst11[0x9c]=_P11_9C; cpu->Inst11[0x9d]=_P11_9D; cpu->Inst11[0x9e]=_P11_9E; cpu->Inst11[0x9f]=_P11_9F;

  cpu->Inst11[0xa0]=_P11_A0; cpu->Inst11[0xa1]=_P11_A1; cpu->Inst11[0xa2]=_P11_A2; cpu->Inst11[0xa3]=_P11_A3;
  cpu->Inst11[0xa4]=_P11_A4; cpu->Inst11[0xa5]=_P11_A5; cpu->Inst11[0xa6]=_P11_A6; cpu->Inst11[0xa7]=_P11_A7;
  cpu->Inst11[0xa8]=_P11_A8; cpu->Inst11[0xa9]=_P11_A9; cpu->Inst11[0xaa]=_P11_AA; cpu->Inst11[0xab]=_P11_AB;
  cpu->Inst11[0xac]=_P11_AC; cpu->Inst11[0xad]=_P11_AD; cpu->Inst11[0xae]=_P11_AE; cpu->Inst11[0xaf]=_P11_AF;

  cpu->Inst11[0xb0]=_P11_B0; cpu->Inst11[0xb1]=_P11_B1; cpu->Inst11[0xb2]=_P11_B2; cpu->Inst11[0xb3]=_P11_B3;
  cpu->Inst11[0xb4]=_P11_B4; cpu->Inst11[0xb5]=_P11_B5; cpu->Inst11[0xb6]=_P11_B6; cpu->Inst11[0xb7]=_P11_B7;
  cpu->Inst11[0xb8]=_P11_B8; cpu->Inst11[0xb9]=_P11_B9; cpu->Inst11[0xba]=_P11_BA; cpu->Inst11[0xbb]=_P11_BB;
  cpu->Inst11[0xbc]=_P11_BC; cpu->Inst11[0xbd]=_P11_BD; cpu->Inst11[0xbe]=_P11_BE; cpu->Inst11[0xbf]=_P11_BF;

  cpu->Inst11[0xc0]=_P11_C0; cpu->Inst11[0xc1]=_P11_C1; cpu->Inst11[0xc2]=_P11_C2; cpu->Inst11[0xc3]=_P11_C3;
  cpu->Inst11[0xc4]=_P11_C4; cpu->Inst11[0xc5]=_P11_C5; cpu->Inst11[0xc6]=_P11_C6; cpu->Inst11[0xc7]=_P11_C7;
  cpu->Inst11[0xc8]=_P11_C8; cpu->Inst11[0xc9]=_P11_C9; cpu->Inst11[0xca]=_P11_CA; cpu->Inst11[0xcb]=_P11_CB;
  cpu->Inst11[0xcc]=_P11_CC; cpu->Inst11[0xcd]=_P11_CD; cpu->Inst11[0xce]=_P11_CE; cpu->Inst11[0xcf]=_P11_CF;

  cpu->Inst11[0xd0]=_P11_D0; cpu->Inst11[0xd1]=_P11_D1; cpu->Inst11[0xd2]=_P11_D2; cpu->Inst11[0xd3]=_P11_D3;
  cpu->Inst11[0xd4]=_P11_D4; cpu->Inst11[0xd5]=_P11_D5; cpu->Inst11[0xd6]=_P11_D6; cpu->Inst11[0xd7]=_P11_D7;
  cpu->Inst11[0xd8]=_P11_D8; cpu->Inst11[0xd9]=_P11_D9; cpu->Inst11[0xda]=_P11_DA; cpu->Inst11[0xdb]=_P11_DB;
  cpu->Inst11[0xdc]=_P11_DC; cpu->Inst11[0xdd]=_P11_DD; cpu->Inst11[0xde]=_P11_DE; cpu->Inst11[0xdf]=_P11_DF;

  cpu->Inst11[0xe0]=_P11_E0; cpu->Inst11[0xe1]=_P11_E1; cpu->Inst11[0xe2]=_P11_E2; cpu->Inst11[0xe3]=_P11_E3;
  cpu->Inst11[0xe4]=_P11_E4; cpu->Inst11[0xe5]=_P11_E5; cpu->Inst11[0xe6]=_P11_E6; cpu->Inst11[0xe7]=_P11_E7;
  cpu->Inst11[0xe8]=_P11_E8; cpu->Inst11[0xe9]=_P11_E9; cpu->Inst11[0xea]=_P11_EA; cpu->Inst11[0xeb]=_P11_EB;
  cpu->Inst11[0xec]=_P11_EC; cpu->Inst11[0xed]=_P11_ED; cpu->Inst11[0xee]=_P11_EE; cpu->Inst11[0xef]=_P11_EF;

  cpu->Inst11[0xf0]=_P11_F0; cpu->Inst11[0xf1]=_P11_F1; cpu->Inst11[0xf2]=_P11_F2; cpu->Inst11[0xf3]=_P11_F3;
  cpu->Inst11[0xf4]=_P11_F4; cpu->Inst11[0xf5]=_P11_F5; cpu->Inst11[0xf6]=_P11_F6; cpu->Inst11[0xf7]=_P11_F7;
  cpu->Inst11[0xf8]=_P11_F8; cpu->Inst11[0xf9]=_P11_F9; cpu->Inst11[0xfa]=_P11_FA; cpu->Inst11[0xfb]=_P11_FB;
  cpu->Inst11[0xfc]=_P11_FC; cpu->Inst11[0xfd]=_P11_FD; cpu->Inst11[0xfe]=_P11_FE; cpu->Inst11[0xff]=_P11_FF;
  }


