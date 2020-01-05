#include "../include/jbyte_generator.h"

int jbyte_generator(int argc, char** argv) {
  FILE* pWriteFile = fopen(argv[2], "w+b");
  if (pWriteFile != NULL) {

    PUT_U4(magic, MAGIC)
    PUT_U2(minor_version, 0x0000)
    PUT_U2(major_version, JDK13)

    PUT_U2(constant_pool_count, 0x001d)
    addConstantUtf8("Cheseny.java", pWriteFile);
    addConstantUtf8("test/Cheseny", pWriteFile);
    addConstantUtf8("java/lang/Object", pWriteFile);
    addConstantUtf8("<init>", pWriteFile);
    addConstantUtf8("()V", pWriteFile);
    addConstantUtf8("main", pWriteFile);
    addConstantUtf8("([Ljava/lang/String;)V", pWriteFile);
    addConstantUtf8("java/lang/System", pWriteFile);
    addConstantUtf8("out", pWriteFile);
    addConstantUtf8("Ljava/io/PrintStream;", pWriteFile);
    addConstantUtf8("java/io/PrintStream", pWriteFile);
    addConstantUtf8("println", pWriteFile);
    addConstantUtf8("(Ljava/lang/String;)V", pWriteFile);
    addConstantUtf8("Welcome Cheseny, I love you WangYi!", pWriteFile);
    addConstantUtf8("Code", pWriteFile);
    addConstantUtf8("LineNumberTable", pWriteFile);
    addConstantUtf8("SourceFile", pWriteFile);
    addConstantClass(0x0002, pWriteFile);
    addConstantClass(0x0003, pWriteFile);
    addConstantClass(0x0008, pWriteFile);
    addConstantClass(0x000b, pWriteFile);
    addConstantString(0x000e, pWriteFile);
    addConstantNameAndType(0x0004, 0x0005, pWriteFile);
    addConstantNameAndType(0x0009, 0x000a, pWriteFile);
    addConstantNameAndType(0x000c, 0x000d, pWriteFile);
    addConstantFieldref(0x0014, 0x0018, pWriteFile);
    addConstantMethodref(0x0013, 0x0017, pWriteFile);
    addConstantMethodref(0x0015, 0x0019, pWriteFile);
    PUT_U2(access_flags, ACC_PUBLIC | ACC_SUPER)
    PUT_U2(this_class, 0x0012)
    PUT_U2(super_class, 0x0013)
    u2 interfaces_count_value = 0x0000;
    PUT_U2(interfaces_count, interfaces_count_value)
    for (u2 interfaces_count_index = 0; interfaces_count_index < interfaces_count_value; interfaces_count_index++) {
      //PUT_U2(interfaces, )
    }
    u2 fields_count_value = 0;
    PUT_U2(fields_count, fields_count_value)
    for (u2 fields_count_index = 0; fields_count_index < fields_count_value; fields_count_index++) {
      //PUT_U2(access_flags)
      //PUT_U2(name_index)
      //PUT_U2(descriptor_index)
      //attributes(pReadFile, constant_pool);
    }
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

    PUT_U2(attributes_count, 0x0001)
    PUT_U2(attribute_name_index, 0x0011)
    PUT_U4(attribute_length, 0x00000002)
    PUT_U2(sourcefile_index, 0x0001)
  }
  fclose(pWriteFile);
  return 0;
}

