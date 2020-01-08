#include "../include/jbyte_analyzer.h"

int jbyte_analyzer(int argc, char** argv) {
  FILE* pReadFile = fopen(argv[2], "r");
  if (pReadFile != NULL) {
    PRINTF_U4(magic)
    PRINTF_U2(minor_version)
    PRINTF_U2(major_version)
    cp_info cp = { NULL, 0x0000 };
    analyzer_constant_pool(pReadFile, &cp);
    PRINTF_U2(access_flags)
    PRINTF_U2(this_class)
    PRINTF_U2(super_class)
    PRINTF_U2(interfaces_count)
    PRINTF_U2_ARRAY(interfaces_count, interfaces)
    analyzer_fields(pReadFile, cp.constant_pool);
    analyzer_methods(pReadFile, cp.constant_pool);
    analyzer_attributes(pReadFile, cp.constant_pool);
    free_constant_pool(&cp);
  }
  fclose(pReadFile);
  return 0;
}

