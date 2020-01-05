#include "../include/jbyte_analyzer.h"

int jbyte_analyzer(int argc, char** argv)
{
  FILE* pReadFile = fopen(argv[2], "r");
  if (pReadFile != NULL) {

    PRINTF_U4(magic)
    PRINTF_U2(minor_version)
    PRINTF_U2(major_version)
    PRINTF_U2(constant_pool_count)

    u1** constant_pool = (u1**) malloc(constant_pool_count * sizeof(u1*));
    for (u2 constant_pool_count_index = 0; constant_pool_count_index < constant_pool_count; constant_pool_count_index++) {
      constant_pool[constant_pool_count_index] = NULL;
    }
    for (u2 constant_pool_count_index = 1; constant_pool_count_index < constant_pool_count; constant_pool_count_index++) {
      PRINTF_U1(tag)
      switch (tag) {
        case CONSTANT_CLASS_TAG:
          {
            PRINTF_U2(name_index)
          }
          break;
        case CONSTANT_FIELDREF_TAG:
        case CONSTANT_METHODREF_TAG:
        case CONSTANT_INTERFACE_METHODREF_TAG:
          {
            PRINTF_U2(class_index)
            PRINTF_U2(name_and_type_index)
          }
          break;
        case CONSTANT_STRING_TAG:
          {
            PRINTF_U2(string_index)
          }
          break;
        case CONSTANT_INTEGER_TAG:
          {
            PRINTF_U4(bytes)
          }
          break;
        case CONSTANT_FLOAT_TAG:
          {
            PRINTF_U4(bytes)
            if ((bytes >= 0x7f800001 && bytes <= 0x7fffffff) || (bytes >= 0xff800001 && bytes <= 0xffffffff)) {
              printf("\tthe float value is NaN!\n");
            } else {
              int s = ((bytes >> 31) == 0) ? 1 : -1;
              int e = ((bytes >> 23) & 0xff);
              int m = (e == 0) ? (bytes & 0x7fffff) << 1 : (bytes & 0x7fffff) | 0x800000;
              float result = s * m * powf(2, e - 150);
              printf("\t%f\n", result);
            }
          }
          break;
        case CONSTANT_LONG_TAG:
          {
            PRINTF_U4(high_bytes)
            PRINTF_U4(low_bytes)
            long result = ((long) high_bytes << 32) | low_bytes;
            printf("\t%ld\n", result);
            constant_pool_count_index = constant_pool_count_index + 0x01;
          }
          break;
        case CONSTANT_DOUBLE_TAG:
          {
            PRINTF_U4(high_bytes)
            PRINTF_U4(low_bytes)
            long bytes = ((long) high_bytes << 32) | low_bytes;
            if ((bytes >= 0x7ff0000000000001L && bytes <= 0x7fffffffffffffffL) || (bytes >= 0xfff0000000000001L && bytes <= 0xffffffffffffffffL)) {
              printf("\tthe double value is NaN!\n");
            } else {
              int s = ((bytes >> 63) == 0) ? 1 : -1;
              int e = (int) ((bytes >> 52) & 0x7FFL);
              long m = (e == 0) ? (bytes & 0xfffffffffffffL) << 1 : (bytes & 0xfffffffffffffL) | 0x10000000000000L;
              double result = s * m * pow(2, e - 1075);
              printf("\t%lf\n", result);
            }
            constant_pool_count_index = constant_pool_count_index + 0x01;
          }
          break;
        case CONSTANT_NAME_AND_TYPE_TAG:
          {
            PRINTF_U2(name_index)
            PRINTF_U2(descriptor_index)
          }
          break;
        case CONSTANT_UTF8_TAG:
          {
            PRINTF_U2(length)
            if (length > 0) {
              u1 utf8_bytes[length + 1];
              constant_pool[constant_pool_count_index] = (u1*) malloc((length + 1) * sizeof(u1));
              for (u2 utf8_bytes_index = 0; utf8_bytes_index < length; utf8_bytes_index++) {
                fread(&utf8_bytes[utf8_bytes_index], 1, sizeof(u1), pReadFile);
                constant_pool[constant_pool_count_index][utf8_bytes_index] = utf8_bytes[utf8_bytes_index];
              }
              utf8_bytes[length] = '\0';
              constant_pool[constant_pool_count_index][length] = '\0';
              printf("utf8_bytes: %s\n", utf8_bytes);
            }
          }
          break;
        case CONSTANT_METHOD_HANDLE_TAG:
          {
            PRINTF_U1(reference_kind)
            PRINTF_U2(reference_index)
          }
          break;
        case CONSTANT_METHOD_TYPE_TAG:
          {
            PRINTF_U2(descriptor_index)
          }
          break;
        case CONSTANT_DYNAMIC_TAG:
        case CONSTANT_INVOKE_DYNAMIC_TAG:
          {
            PRINTF_U2(bootstrap_method_attr_index)
            PRINTF_U2(name_and_type_index)
          }
          break;
        case CONSTANT_MODULE_TAG:
        case CONSTANT_PACKAGE_TAG:
          {
            PRINTF_U2(name_index)
          }
          break;
      }
    }

    PRINTF_U2(access_flags)
    PRINTF_U2(this_class)
    PRINTF_U2(super_class)
    PRINTF_U2(interfaces_count)
    PRINTF_U2_ARRAY(interfaces_count, interfaces)

    PRINTF_U2(fields_count)
    if (fields_count > 0) {
      for (u2 fields_count_index = 0; fields_count_index < fields_count; fields_count_index++) {
        PRINTF_U2(access_flags)
        PRINTF_U2(name_index)
        PRINTF_U2(descriptor_index)
        attributes(pReadFile, constant_pool);
      }
    }

    PRINTF_U2(methods_count)
    if (methods_count > 0) {
      for (u2 methods_count_index = 0; methods_count_index < methods_count; methods_count_index++) {
        PRINTF_U2(access_flags)
        PRINTF_U2(name_index)
        PRINTF_U2(descriptor_index)
        attributes(pReadFile, constant_pool);
      }
    }
    attributes(pReadFile, constant_pool);
    for (u2 constant_pool_count_index = 0; constant_pool_count_index < constant_pool_count; constant_pool_count_index++) {
      free(constant_pool[constant_pool_count_index]);
    }
    free(constant_pool);
  }
  fclose(pReadFile);
  return 0;
}

