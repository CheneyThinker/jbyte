#include "../include/jbyte_cp.h"

void addConstantUtf8(u1* utf8_value, FILE* pWriteFile) {
  PUT_U1(tag, CONSTANT_UTF8_TAG)
  u2 utf8_length = (u2) strlen(utf8_value);
  PUT_U2(length, utf8_length)
  for (u2 utf8_length_index = 0; utf8_length_index < utf8_length; utf8_length_index++) {
    PUT_U1(bytes, utf8_value[utf8_length_index])
  }
}

void addConstantClass(u2 name_index_value, FILE* pWriteFile) {
  PUT_U1(tag, CONSTANT_CLASS_TAG)
  PUT_U2(name_index, name_index_value)
}

void addConstantString(u2 string_index_value, FILE* pWriteFile) {
  PUT_U1(tag, CONSTANT_STRING_TAG)
  PUT_U2(string_index, string_index_value)
}

void addConstantNameAndType(u2 name_index_value, u2 descriptor_index_value, FILE* pWriteFile) {
  PUT_U1(tag, CONSTANT_NAME_AND_TYPE_TAG)
  PUT_U2(name_index, name_index_value)
  PUT_U2(descriptor_index, descriptor_index_value)
}

void addConstantFieldref(u2 class_index_value, u2 name_and_type_index_value, FILE* pWriteFile) {
  PUT_U1(tag, CONSTANT_FIELDREF_TAG)
  PUT_U2(class_index, class_index_value)
  PUT_U2(name_and_type_index, name_and_type_index_value)
}

void addConstantMethodref(u2 class_index_value, u2 name_and_type_index_value, FILE* pWriteFile) {
  PUT_U1(tag, CONSTANT_METHODREF_TAG)
  PUT_U2(class_index, class_index_value)
  PUT_U2(name_and_type_index, name_and_type_index_value)
}

