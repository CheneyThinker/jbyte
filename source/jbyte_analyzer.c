#include "../include/jbyte_analyzer.h"

int jbyte_analyzer(int argc, char** argv)
{
  FILE* pReadFile = fopen(argv[2], "r");
  if (pReadFile != NULL) {
    PRINTF_U4(magic)
    PRINTF_U2(minor_version)
    PRINTF_U2(major_version)
    u2 constant_pool_count = 0x0000;
    u1** cp = constant_pool(pReadFile, &constant_pool_count);
    PRINTF_U2(access_flags)
    PRINTF_U2(this_class)
    PRINTF_U2(super_class)
    PRINTF_U2(interfaces_count)
    PRINTF_U2_ARRAY(interfaces_count, interfaces)
    fields(pReadFile, cp);
    methods(pReadFile, cp);
    attributes(pReadFile, cp);
    free_constant_pool(cp, constant_pool_count);
  }
  fclose(pReadFile);
  return 0;
}

