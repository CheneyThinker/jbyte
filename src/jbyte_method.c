#include "../include/jbyte_method.h"

void generator_methods(FILE* pWriteFile) {
  u2 methods_count_value = 0x0002;
  PUT_U2(methods_count, methods_count_value)
  PUT_U2(access_flags, ACC_PUBLIC)
  PUT_U2(name_index, 0x0004)
  PUT_U2(descriptor_index, 0x0005)
  PUT_U2(attributes_count, 0x0001)
  PUT_U2(attribute_name_index, 0x000f)
  PUT_U4(attribute_length, 0x0000001d)
  PUT_U2(max_stack, 0x0001)
  PUT_U2(max_locals, 0x0001)
  PUT_U4(code_length, 0x00000005)
  PUT_U1(opcode, ALOAD_0)
  PUT_U1(opcode, INVOKESPECIAL)
  PUT_U1(indexbyte1, 0x00)
  PUT_U1(indexbyte2, 0x1b)
  PUT_U1(opcode, RETURN)
  u2 exception_table_length_value = 0x0000;
  PUT_U2(exception_table_length, exception_table_length_value)
  for (u2 exception_table_length_index = 0; exception_table_length_index < exception_table_length_value; exception_table_length_index++) {
    //PUT_U2(start_pc)
    //PUT_U2(end_pc)
    //PUT_U2(handler_pc)
    //PUT_U2(catch_type)
  }
  PUT_U2(attributes_count, 0x0001)
  PUT_U2(attribute_name_index, 0x0010)
  PUT_U4(attribute_length, 0x00000006)
  PUT_U2(line_number_table_length, 0x0001)
  PUT_U2(start_pc, 0x0000)
  PUT_U2(line_number, 0x0003)

  PUT_U2(access_flags, ACC_PUBLIC | ACC_STATIC)
  PUT_U2(name_index, 0x0006)
  PUT_U2(descriptor_index, 0x0007)
  PUT_U2(attributes_count, 0x0001)
  PUT_U2(attribute_name_index, 0x000f)
  PUT_U4(attribute_length, 0x00000025)
  PUT_U2(max_stack, 0x0002)
  PUT_U2(max_locals, 0x0001)
  PUT_U4(code_length, 0x00000009)
  PUT_U1(opcode, GETSTATIC)
  PUT_U1(indexbyte1, 0x00)
  PUT_U1(indexbyte2, 0x1a)
  PUT_U1(opcode, LDC)
  PUT_U1(index, 0x16)
  PUT_U1(opcode, INVOKEVIRTUAL)
  PUT_U1(indexbyte1, 0x00)
  PUT_U1(indexbyte2, 0x1c)
  PUT_U1(opcode, RETURN)
  exception_table_length_value = 0x0000;
  PUT_U2(exception_table_length, exception_table_length_value)
  for (u2 exception_table_length_index = 0; exception_table_length_index < exception_table_length_value; exception_table_length_index++) {
    //PUT_U2(start_pc)
    //PUT_U2(end_pc)
    //PUT_U2(handler_pc)
    //PUT_U2(catch_type)
  }
  PUT_U2(attributes_count, 0x0001)
  PUT_U2(attribute_name_index, 0x0010)
  PUT_U4(attribute_length, 0x0000000a)
  PUT_U2(line_number_table_length, 0x0002)
  PUT_U2(start_pc, 0x0000)
  PUT_U2(line_number, 0x0005)
  PUT_U2(start_pc, 0x0008)
  PUT_U2(line_number, 0x0006)
}

void analyzer_methods(FILE* pReadFile, u1** constant_pool) {
  PRINTF_U2(methods_count)
  if (methods_count > 0) {
    for (u2 methods_count_index = 0; methods_count_index < methods_count; methods_count_index++) {
      PRINTF_U2(access_flags)
      PRINTF_U2(name_index)
      PRINTF_U2(descriptor_index)
      analyzer_attributes(pReadFile, constant_pool);
    }
  }
}
