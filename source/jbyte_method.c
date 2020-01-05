#include "../include/jbyte_method.h"

void methods(FILE* pReadFile, u1** constant_pool) {
  PRINTF_U2(methods_count)
  if (methods_count > 0) {
    for (u2 methods_count_index = 0; methods_count_index < methods_count; methods_count_index++) {
      PRINTF_U2(access_flags)
      PRINTF_U2(name_index)
      PRINTF_U2(descriptor_index)
      attributes(pReadFile, constant_pool);
    }
  }
}
