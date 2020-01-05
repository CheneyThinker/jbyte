#include "../include/jbyte_generator.h"

int jbyte_generator(int argc, char** argv) {
  FILE* pWriteFile = fopen(argv[2], "w+b");
  if (pWriteFile != NULL) {
    PUT_U4(magic, MAGIC)
    PUT_U2(minor_version, 0x0000)
    PUT_U2(major_version, JDK13)
    generator_constant_pool(pWriteFile);
    PUT_U2(access_flags, ACC_PUBLIC | ACC_SUPER)
    PUT_U2(this_class, 0x0012)
    PUT_U2(super_class, 0x0013)
    u2 interfaces_count_value = 0x0000;
    PUT_U2(interfaces_count, interfaces_count_value)
    for (u2 interfaces_count_index = 0; interfaces_count_index < interfaces_count_value; interfaces_count_index++) {
      //PUT_U2(interfaces, )
    }
    generator_fields(pWriteFile);
    generator_methods(pWriteFile);
    generator_attributes(pWriteFile);
  }
  fclose(pWriteFile);
  return 0;
}

