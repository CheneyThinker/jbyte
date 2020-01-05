#include "../include/jbyte_field.h"

void fields(FILE* pReadFile, u1** constant_pool) {
  PRINTF_U2(fields_count)
  if (fields_count > 0) {
    for (u2 fields_count_index = 0; fields_count_index < fields_count; fields_count_index++) {
      PRINTF_U2(access_flags)
      PRINTF_U2(name_index)
      PRINTF_U2(descriptor_index)
      attributes(pReadFile, constant_pool);
    }
  }
}
