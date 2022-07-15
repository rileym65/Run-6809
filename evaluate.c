#include "header.h"

#define OP_MUL     0x61
#define OP_DIV     0x60

#define OP_PLUS    0x51
#define OP_MINUS   0x50

#define OP_AND     0x42
#define OP_OR      0x41
#define OP_XOR     0x40

#define OP_NE      0x35
#define OP_EQ      0x34
#define OP_GE      0x33
#define OP_GT      0x32
#define OP_LE      0x31
#define OP_LT      0x30

#define OP_LAND    0x21
#define OP_LOR     0x20

#define OP_CP      0x11

#define OP_OP      0x01
#define OP_END     0x00

int evaluate(char* expr) {
  word value;
  word nstack[256];
  byte ostack[256];
  int  nsp;
  int  osp;
  byte op;
  nsp = 0;
  osp = 0;
  while (*expr == ' ') expr++;
  op = 0xff;
  while (*expr != 0 && op != OP_END) {

    /* **************************** */
    /* ***** Search for value ***** */
    /* **************************** */

    while (*expr == '(') {
      expr++;
      ostack[osp++] = OP_OP;
      while (*expr == ' ') expr++;
      }

    /* +++++++++++++++++++++++++++++++++++++++ */
    /* +++++ Check for hexadecimal value +++++ */
    /* +++++++++++++++++++++++++++++++++++++++ */
    if (*expr == '$') {
      expr++;
      value = 0;
      while ((*expr >= '0' && *expr <= '9') ||
             (*expr >= 'a' && *expr <= 'f') ||
             (*expr >= 'A' && *expr <= 'F') ||
             *expr == '_') {
        if (*expr >= '0' && *expr <= '9') value = (value << 4) | (*expr - '0');
        else if (*expr >= 'a' && *expr <= 'f') value = (value << 4) | (*expr - 87);
        else if (*expr >= 'A' && *expr <= 'F') value = (value << 4) | (*expr - 55);
        expr++;
        }
      }

    /* ++++++++++++++++++++++++++++++++++ */
    /* +++++ Check for binary value +++++ */
    /* ++++++++++++++++++++++++++++++++++ */
    else if (*expr == '%') {
      expr++;
      value = 0;
      while (*expr >= '0' && *expr <= '1') {
        if (*expr == '0') value <<= 1;
        if (*expr == '1') value = (value << 1) | 1;
        expr++;
        }
      }

    /* +++++++++++++++++++++++++++++++++++ */
    /* +++++ Check for decimal value +++++ */
    /* +++++++++++++++++++++++++++++++++++ */
    else if (*expr >= '0' && *expr <= '9') {
      value = 0;
      while (*expr >= '0' && *expr <= '9') {
        value = (value * 10) + (*expr - '0');
        expr++;
        }
      }

    /* ++++++++++++++++++++++++++++++++++++++ */
    /* +++++ Check for memory reference +++++ */
    /* ++++++++++++++++++++++++++++++++++++++ */
    else if (*expr == '[') {
      expr++;
      if (*expr == '$') {
        expr++;
        value = 0;
        while ((*expr >= '0' && *expr <= '9') ||
               (*expr >= 'a' && *expr <= 'f') ||
               (*expr >= 'A' && *expr <= 'F') ||
               *expr == '_') {
          if (*expr >= '0' && *expr <= '9') value = (value << 4) | (*expr - '0');
          else if (*expr >= 'a' && *expr <= 'f') value = (value << 4) | (*expr - 87);
          else if (*expr >= 'A' && *expr <= 'F') value = (value << 4) | (*expr - 55);
          expr++;
          }
        }
      else if (*expr >= '0' && *expr <= '9') {
        value = 0;
        while (*expr >= '0' && *expr <= '9') {
          value = (value * 10) + (*expr - '0');
          expr++;
          }
        }
      else {
        printf("Invalid memory reference encountered\n");
        return 0;
        }
      if (*expr != ']') {
        printf("Invalid memory reference encountered\n");
        return 0;
        }
      expr++;
      value = readMem(ram, value);
      }

    /* ++++++++++++++++++++++++++++++++++++++ */
    /* +++++ Lastly check for registers +++++ */
    /* ++++++++++++++++++++++++++++++++++++++ */
    else if (strncasecmp(expr, "pc", 2) == 0) {value = cpu.pc; expr += 2; }
    else if (strncasecmp(expr, "cc", 2) == 0) {value = cpu.cc; expr += 2; }
    else if (strncasecmp(expr, "dp", 2) == 0) {value = cpu.dp; expr += 2; }
    else if (*expr == 'a' || *expr == 'A') { value = cpu.a; expr++; }
    else if (*expr == 'b' || *expr == 'B') { value = cpu.b; expr++; }
    else if (*expr == 'x' || *expr == 'X') { value = cpu.x; expr++; }
    else if (*expr == 'y' || *expr == 'Y') { value = cpu.y; expr++; }
    else if (*expr == 's' || *expr == 'S') { value = cpu.s; expr++; }
    else if (*expr == 'u' || *expr == 'U') { value = cpu.u; expr++; }
    else {
      printf("Expected number was not found\n");
      return 0;
      }

    nstack[nsp++] = value;
    while (*expr == ' ') expr++;


    op = OP_CP;
    while (op == OP_CP) {
      /* ******************************* */
      /* ***** Search for operator ***** */
      /* ******************************* */
      if (*expr == '+') { op = OP_PLUS; expr++; }
      else if (*expr == '-') { op = OP_MINUS; expr++; }
      else if (*expr == '*') { op = OP_MUL; expr++; }
      else if (*expr == '/') { op = OP_DIV; expr++; }
      else if (*expr == '&' && *(expr+1) == '&') { op = OP_LAND; expr += 2; }
      else if (*expr == '|' && *(expr+1) == '|') { op = OP_LOR; expr += 2; }
      else if (*expr == '^') { op = OP_XOR; expr++; }
      else if (*expr == '&') { op = OP_AND; expr++; }
      else if (*expr == '|') { op = OP_OR; expr++; }
      else if (*expr == '^') { op = OP_XOR; expr++; }
      else if (*expr == '<' && *(expr+1) == '>') { op = OP_NE; expr += 2; }
      else if (*expr == '<' && *(expr+1) == '=') { op = OP_LE; expr += 2; }
      else if (*expr == '<') { op = OP_LT; expr++; }
      else if (*expr == '>' && *(expr+1) == '=') { op = OP_GE; expr += 2; }
      else if (*expr == '>') { op = OP_GT; expr++; }
      else if (*expr == '=') { op = OP_EQ; expr++; }
      else if (*expr == ')') { op = OP_CP; expr++; }
      else op = OP_END;
      while (osp > 0 && (ostack[osp-1] & 0xf0) >= (op & 0xf0)) {
        switch (ostack[--osp]) {
          case OP_PLUS: nstack[nsp-2] += nstack[nsp-1]; nsp--; break;
          case OP_MINUS: nstack[nsp-2] -= nstack[nsp-1]; nsp--; break;
          case OP_MUL: nstack[nsp-2] *= nstack[nsp-1]; nsp--; break;
          case OP_DIV: nstack[nsp-2] /= nstack[nsp-1]; nsp--; break;
          case OP_AND: nstack[nsp-2] &= nstack[nsp-1]; nsp--; break;
          case OP_OR: nstack[nsp-2] |= nstack[nsp-1]; nsp--; break;
          case OP_XOR: nstack[nsp-2] ^= nstack[nsp-1]; nsp--; break;
          case OP_LAND:
               nstack[nsp-2] = (nstack[nsp-2] && nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          case OP_LOR:
               nstack[nsp-2] = (nstack[nsp-2] || nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          case OP_EQ:
               nstack[nsp-2] = (nstack[nsp-2] == nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          case OP_NE:
               nstack[nsp-2] = (nstack[nsp-2] != nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          case OP_GT:
               nstack[nsp-2] = (nstack[nsp-2] > nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          case OP_GE:
               nstack[nsp-2] = (nstack[nsp-2] >= nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          case OP_LT:
               nstack[nsp-2] = (nstack[nsp-2] < nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          case OP_LE:
               nstack[nsp-2] = (nstack[nsp-2] <= nstack[nsp-1]) ? 0xffff : 0;
               nsp--; break;
          }
        }
      if (op == OP_CP) {
        if (osp == 0 || ostack[osp-1] != OP_OP) {
          printf("Closed parens without an open parens\n");
          return 0;
          }
        osp--;
        }
      }
    if (op != OP_END) ostack[osp++] = op;
    while (*expr == ' ') expr++;
    }
  if (nsp == 0) {
    printf("No return value computed\n");
    return 0;
    }
  return nstack[nsp-1];
  }

