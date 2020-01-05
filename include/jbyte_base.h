#pragma once

#ifndef JBYTE_BASE_H
#define JBYTE_BASE_H

#include "jbyte_def.h"

#define PRINTF_U1(declared)                          \
          u1 declared;                               \
          fread(&declared, 1, sizeof(u1), pReadFile);\
          printf(#declared": %02x\n", declared);

#define PRINTF_U2(declared)                          \
          u2 declared;                               \
          fread(&declared, 1, sizeof(u2), pReadFile);\
          declared = swap_u2(declared);              \
          printf(#declared": %04x\n", declared);

#define PRINTF_U4(declared)                          \
          u4 declared;                               \
          fread(&declared, 1, sizeof(u4), pReadFile);\
          declared = swap_u4(declared);              \
          printf(#declared": %08x\n", declared);

#define PRINTF_U2_ARRAY(count, declared)                                              \
          if (count > 0) {                                                            \
            u2 declared[count];                                                       \
            for (u2 count##_index = 0; count##_index < count; count##_index++) {      \
              fread(&declared[count##_index], 1, sizeof(u2), pReadFile);              \
              declared[count##_index] = swap_u2(declared[count##_index]);             \
              printf(#declared"[%d]: %04x\n", count##_index, declared[count##_index]);\
            }                                                                         \
          }

#define PRINTF_U4_ARRAY(count, declared)                                              \
          if (count > 0) {                                                            \
            u4 declared[count];                                                       \
            for (u4 count##_index = 0; count##_index < count; count##_index++) {      \
              fread(&declared[count##_index], 1, sizeof(u4), pReadFile);              \
              declared[count##_index] = swap_u4(declared[count##_index]);             \
              printf(#declared"[%d]: %08x\n", count##_index, declared[count##_index]);\
            }                                                                         \
          }

#define PUT_U1(declared, value)                 \
          {                                     \
            u1 declared = value;                \
            fwrite(&declared, 1, 1, pWriteFile);\
          }

#define PUT_U2(declared, value)                 \
          {                                     \
            u2 declared = value;                \
            declared = swap_u2(declared);       \
            fwrite(&declared, 2, 1, pWriteFile);\
          }

#define PUT_U4(declared, value)                 \
          {                                     \
            u4 declared = value;                \
            declared = swap_u4(declared);       \
            fwrite(&declared, 4, 1, pWriteFile);\
          }

#endif
