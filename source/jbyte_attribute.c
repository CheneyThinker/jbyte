#include "../include/jbyte_attribute.h"

/*
attribute_info {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 info[attribute_length];
}
*/
void attributes(FILE* pReadFile, u1** constant_pool) {
  PRINTF_U2(attributes_count)
  if (attributes_count > 0) {
    for (u2 attributes_count_index = 0; attributes_count_index < attributes_count; attributes_count_index++) {
      PRINTF_U2(attribute_name_index)
      PRINTF_U4(attribute_length)
      if (attribute_length > 0) {
        u1* attribute_name = constant_pool[attribute_name_index];
        if (strcmp(attribute_name, "ConstantValue") == 0) {
          ConstantValue_attribute(pReadFile);
        } else if (strcmp(attribute_name, "Code") == 0) {
          Code_attribute(pReadFile, constant_pool);
        } else if (strcmp(attribute_name, "StackMapTable") == 0) {
          StackMapTable_attribute(pReadFile);
        } else if (strcmp(attribute_name, "Exceptions") == 0) {
          Exceptions_attribute(pReadFile);
        } else if (strcmp(attribute_name, "InnerClasses") == 0) {
          InnerClasses_attribute(pReadFile);
        } else if (strcmp(attribute_name, "EnclosingMethod") == 0) {
          EnclosingMethod_attribute(pReadFile);
        } else if (strcmp(attribute_name, "Synthetic") == 0) {
          Synthetic_attribute(pReadFile);
        } else if (strcmp(attribute_name, "Signature") == 0) {
          Signature_attribute(pReadFile);
        } else if (strcmp(attribute_name, "SourceFile") == 0) {
          SourceFile_attribute(pReadFile);
        } else if (strcmp(attribute_name, "SourceDebugExtension") == 0) {
          SourceDebugExtension_attribute(pReadFile, attribute_length);
        } else if (strcmp(attribute_name, "LineNumberTable") == 0) {
          LineNumberTable_attribute(pReadFile);
        } else if (strcmp(attribute_name, "LocalVariableTable") == 0) {
          LocalVariableTable_attribute(pReadFile);
        } else if (strcmp(attribute_name, "LocalVariableTypeTable") == 0) {
          LocalVariableTypeTable_attribute(pReadFile);
        } else if (strcmp(attribute_name, "Deprecated") == 0) {
          Deprecated_attribute(pReadFile);
        } else if (strcmp(attribute_name, "RuntimeVisibleAnnotations") == 0) {
          RuntimeVisibleAnnotations_attribute(pReadFile);
        } else if (strcmp(attribute_name, "RuntimeInvisibleAnnotations") == 0) {
          RuntimeInvisibleAnnotations_attribute(pReadFile);
        } else if (strcmp(attribute_name, "RuntimeVisibleParameterAnnotations") == 0) {
          RuntimeVisibleParameterAnnotations_attribute(pReadFile);
        } else if (strcmp(attribute_name, "RuntimeInvisibleParameterAnnotations") == 0) {
          RuntimeInvisibleParameterAnnotations_attribute(pReadFile);
        } else if (strcmp(attribute_name, "RuntimeVisibleTypeAnnotations") == 0) {
          RuntimeVisibleTypeAnnotations_attribute(pReadFile);
        } else if (strcmp(attribute_name, "RuntimeInvisibleTypeAnnotations") == 0) {
          RuntimeInvisibleTypeAnnotations_attribute(pReadFile);
        } else if (strcmp(attribute_name, "AnnotationDefault") == 0) {
          AnnotationDefault_attribute(pReadFile);
        } else if (strcmp(attribute_name, "BootstrapMethods") == 0) {
          BootstrapMethods_attribute(pReadFile);
        } else if (strcmp(attribute_name, "MethodParameters") == 0) {
          MethodParameters_attribute(pReadFile);
        } else if (strcmp(attribute_name, "Module") == 0) {
          Module_attribute(pReadFile);
        } else if (strcmp(attribute_name, "ModulePackages") == 0) {
          ModulePackages_attribute(pReadFile);
        } else if (strcmp(attribute_name, "ModuleMainClass") == 0) {
          ModuleMainClass_attribute(pReadFile);
        } else if (strcmp(attribute_name, "NestHost") == 0) {
          NestHost_attribute(pReadFile);
        } else if (strcmp(attribute_name, "NestMembers") == 0) {
          NestMembers_attribute(pReadFile);
        } else {
          u1 info[attribute_length];
          printf("info:");
          for (u4 attribute_length_index = 0; attribute_length_index < attribute_length; attribute_length_index++) {
            fread(&info[attribute_length_index], 1, sizeof(u1), pReadFile);
            printf(" %02x", info[attribute_length_index]);
          }
          printf("\n");
        }
      }
    }
  }
}

/*
ConstantValue_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 constantvalue_index;
}
*/
void ConstantValue_attribute(FILE* pReadFile) {
  PRINTF_U2(constantvalue_index)
}

/*
Code_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1 code[code_length];
    u2 exception_table_length;
    {   u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;
    } exception_table[exception_table_length];
    u2 attributes_count;
    attribute_info attributes[attributes_count];
}
*/
void Code_attribute(FILE* pReadFile, u1** constant_pool) {
  PRINTF_U2(max_stack)
  PRINTF_U2(max_locals)
  PRINTF_U4(code_length)
  u1 code[code_length];
  for (u4 code_length_index = 0; code_length_index < code_length; code_length_index++) {
    fread(&code[code_length_index], 1, sizeof(u1), pReadFile);
    u1 opcode = code[code_length_index];
    switch (opcode) {
      case NOP:
        {
          printf("nop\n");
        }
        break;
      case ACONST_NULL:
        {
          printf("aconst_null\n");
        }
        break;
      case ICONST_M1:
        {
          printf("iconst_m1\n");
        }
        break;
      case ICONST_0:
        {
          printf("iconst_0\n");
        }
        break;
      case ICONST_1:
        {
          printf("iconst_1\n");
        }
        break;
      case ICONST_2:
        {
          printf("iconst_2\n");
        }
        break;
      case ICONST_3:
        {
          printf("iconst_3\n");
        }
        break;
      case ICONST_4:
        {
          printf("iconst_4\n");
        }
        break;
      case ICONST_5:
        {
          printf("iconst_5\n");
        }
        break;
      case LCONST_0:
        {
          printf("lconst_0\n");
        }
        break;
      case LCONST_1:
        {
          printf("lconst_1\n");
        }
        break;
      case FCONST_0:
        {
          printf("fconst_0\n");
        }
        break;
      case FCONST_1:
        {
          printf("fconst_1\n");
        }
        break;
      case FCONST_2:
        {
          printf("fconst_2\n");
        }
        break;
      case DCONST_0:
        {
          printf("dconst_0\n");
        }
        break;
      case DCONST_1:
        {
          printf("dconst_1\n");
        }
        break;
      case BIPUSH:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 byte = code[code_length_index];
          printf("bipush byte[%02x]\n", byte);
        }
        break;
      case SIPUSH:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 byte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 byte2 = code[code_length_index];
          printf("sipush byte1[%02x] byte2[%02x] short[%04x]\n", byte1, byte2, (byte1 << 8) | byte2);
        }
        break;
      case LDC:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("ldc index[%02x]\n", index);
        }
        break;
      case LDC_W:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("ldc_w indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case LDC2_W:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("ldc2_w indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case ILOAD:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("iload index[%02x]\n", index);
        }
        break;
      case LLOAD:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("lload index[%02x]\n", index);
        }
        break;
      case FLOAD:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("fload index[%02x]\n", index);
        }
        break;
      case DLOAD:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("dload index[%02x]\n", index);
        }
        break;
      case ALOAD:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("aload index[%02x]\n", index);
        }
        break;
      case ILOAD_0:
        {
          printf("iload_0\n");
        }
        break;
      case ILOAD_1:
        {
          printf("iload_1\n");
        }
        break;
      case ILOAD_2:
        {
          printf("iload_2\n");
        }
        break;
      case ILOAD_3:
        {
          printf("iload_3\n");
        }
        break;
      case LLOAD_0:
        {
          printf("lload_0\n");
        }
        break;
      case LLOAD_1:
        {
          printf("lload_1\n");
        }
        break;
      case LLOAD_2:
        {
          printf("lload_2\n");
        }
        break;
      case LLOAD_3:
        {
          printf("lload_3\n");
        }
        break;
      case FLOAD_0:
        {
          printf("fload_0\n");
        }
        break;
      case FLOAD_1:
        {
          printf("fload_1\n");
        }
        break;
      case FLOAD_2:
        {
          printf("fload_2\n");
        }
        break;
      case FLOAD_3:
        {
          printf("fload_3\n");
        }
        break;
      case DLOAD_0:
        {
          printf("dload_0\n");
        }
        break;
      case DLOAD_1:
        {
          printf("dload_1\n");
        }
        break;
      case DLOAD_2:
        {
          printf("dload_2\n");
        }
        break;
      case DLOAD_3:
        {
          printf("dload_3\n");
        }
        break;
      case ALOAD_0:
        {
          printf("aload_0\n");
        }
        break;
      case ALOAD_1:
        {
          printf("aload_1\n");
        }
        break;
      case ALOAD_2:
        {
          printf("aload_2\n");
        }
        break;
      case ALOAD_3:
        {
          printf("aload_3\n");
        }
        break;
      case IALOAD:
        {
          printf("iaload\n");
        }
        break;
      case LALOAD:
        {
          printf("laload\n");
        }
        break;
      case FALOAD:
        {
          printf("faload\n");
        }
        break;
      case DALOAD:
        {
          printf("daload\n");
        }
        break;
      case AALOAD:
        {
          printf("aaload\n");
        }
        break;
      case BALOAD:
        {
          printf("baload\n");
        }
        break;
      case CALOAD:
        {
          printf("caload\n");
        }
        break;
      case SALOAD:
        {
          printf("saload\n");
        }
        break;
      case ISTORE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("istore index[%02x]\n", index);
        }
        break;
      case LSTORE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("lstore index[%02x]\n", index);
        }
        break;
      case FSTORE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("fstore index[%02x]\n", index);
        }
        break;
      case DSTORE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("dstore index[%02x]\n", index);
        }
        break;
      case ASTORE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("astore index[%02x]\n", index);
        }
        break;
      case ISTORE_0:
        {
          printf("istore_0\n");
        }
        break;
      case ISTORE_1:
        {
          printf("istore_1\n");
        }
        break;
      case ISTORE_2:
        {
          printf("istore_2\n");
        }
        break;
      case ISTORE_3:
        {
          printf("istore_3\n");
        }
        break;
      case LSTORE_0:
        {
          printf("lstore_0\n");
        }
        break;
      case LSTORE_1:
        {
          printf("lstore_1\n");
        }
        break;
      case LSTORE_2:
        {
          printf("lstore_2\n");
        }
        break;
      case LSTORE_3:
        {
          printf("lstore_3\n");
        }
        break;
      case FSTORE_0:
        {
          printf("fstore_0\n");
        }
        break;
      case FSTORE_1:
        {
          printf("fstore_1\n");
        }
        break;
      case FSTORE_2:
        {
          printf("fstore_2\n");
        }
        break;
      case FSTORE_3:
        {
          printf("fstore_3\n");
        }
        break;
      case DSTORE_0:
        {
          printf("dstore_0\n");
        }
        break;
      case DSTORE_1:
        {
          printf("dstore_1\n");
        }
        break;
      case DSTORE_2:
        {
          printf("dstore_2\n");
        }
        break;
      case DSTORE_3:
        {
          printf("dstore_3\n");
        }
        break;
      case ASTORE_0:
        {
          printf("astore_0\n");
        }
        break;
      case ASTORE_1:
        {
          printf("astore_1\n");
        }
        break;
      case ASTORE_2:
        {
          printf("astore_2\n");
        }
        break;
      case ASTORE_3:
        {
          printf("astore_3\n");
        }
        break;
      case IASTORE:
        {
          printf("iastore\n");
        }
        break;
      case LASTORE:
        {
          printf("lastore\n");
        }
        break;
      case FASTORE:
        {
          printf("fastore\n");
        }
        break;
      case DASTORE:
        {
          printf("dastore\n");
        }
        break;
      case AASTORE:
        {
          printf("aastore\n");
        }
        break;
      case BASTORE:
        {
          printf("bastore\n");
        }
        break;
      case CASTORE:
        {
          printf("castore\n");
        }
        break;
      case SASTORE:
        {
          printf("sastore\n");
        }
        break;
      case POP:
        {
          printf("pop\n");
        }
        break;
      case POP2:
        {
          printf("pop2\n");
        }
        break;
      case DUP:
        {
          printf("dup\n");
        }
        break;
      case DUP_X1:
        {
          printf("dup_x1\n");
        }
        break;
      case DUP_X2:
        {
          printf("dup_x2\n");
        }
        break;
      case DUP2:
        {
          printf("dup2\n");
        }
        break;
      case DUP2_X1:
        {
          printf("dup2_x1\n");
        }
        break;
      case DUP2_X2:
        {
          printf("dup2_x2\n");
        }
        break;
      case SWAP:
        {
          printf("swap\n");
        }
        break;
      case IADD:
        {
          printf("iadd\n");
        }
        break;
      case LADD:
        {
          printf("ladd\n");
        }
        break;
      case FADD:
        {
          printf("fadd\n");
        }
        break;
      case DADD:
        {
          printf("dadd\n");
        }
        break;
      case ISUB:
        {
          printf("isub\n");
        }
        break;
      case LSUB:
        {
          printf("lsub\n");
        }
        break;
      case FSUB:
        {
          printf("fsub\n");
        }
        break;
      case DSUB:
        {
          printf("dsub\n");
        }
        break;
      case IMUL:
        {
          printf("imul\n");
        }
        break;
      case LMUL:
        {
          printf("lmul\n");
        }
        break;
      case FMUL:
        {
          printf("fmul\n");
        }
        break;
      case DMUL:
        {
          printf("dmul\n");
        }
        break;
      case IDIV:
        {
          printf("idiv\n");
        }
        break;
      case LDIV:
        {
          printf("ldiv\n");
        }
        break;
      case FDIV:
        {
          printf("fdiv\n");
        }
        break;
      case DDIV:
        {
          printf("ddiv\n");
        }
        break;
      case IREM:
        {
          printf("irem\n");
        }
        break;
      case LREM:
        {
          printf("lrem\n");
        }
        break;
      case FREM:
        {
          printf("frem\n");
        }
        break;
      case DREM:
        {
          printf("drem\n");
        }
        break;
      case INEG:
        {
          printf("ineg\n");
        }
        break;
      case LNEG:
        {
          printf("lneg\n");
        }
        break;
      case FNEG:
        {
          printf("fneg\n");
        }
        break;
      case DNEG:
        {
          printf("dneg\n");
        }
        break;
      case ISHL:
        {
          printf("ishl\n");
        }
        break;
      case LSHL:
        {
          printf("lshl\n");
        }
        break;
      case ISHR:
        {
          printf("ishr\n");
        }
        break;
      case LSHR:
        {
          printf("lshr\n");
        }
        break;
      case IUSHR:
        {
          printf("iushr\n");
        }
        break;
      case LUSHR:
        {
          printf("lushr\n");
        }
        break;
      case IAND:
        {
          printf("iand\n");
        }
        break;
      case LAND:
        {
          printf("land\n");
        }
        break;
      case IOR:
        {
          printf("ior\n");
        }
        break;
      case LOR:
        {
          printf("lor\n");
        }
        break;
      case IXOR:
        {
          printf("ixor\n");
        }
        break;
      case LXOR:
        {
          printf("lxor\n");
        }
        break;
      case IINC:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 const_ = code[code_length_index];
          printf("iinc index[%02x] const[%02x]\n", index, const_);
        }
        break;
      case I2L:
        {
          printf("i2l\n");
        }
        break;
      case I2F:
        {
          printf("i2f\n");
        }
        break;
      case I2D:
        {
          printf("i2d\n");
        }
        break;
      case L2I:
        {
          printf("l2i\n");
        }
        break;
      case L2F:
        {
          printf("l2f\n");
        }
        break;
      case L2D:
        {
          printf("l2d\n");
        }
        break;
      case F2I:
        {
          printf("f2i\n");
        }
        break;
      case F2L:
        {
          printf("f2l\n");
        }
        break;
      case F2D:
        {
          printf("f2d\n");
        }
        break;
      case D2I:
        {
          printf("d2i\n");
        }
        break;
      case D2L:
        {
          printf("d2l\n");
        }
        break;
      case D2F:
        {
          printf("d2f\n");
        }
        break;
      case I2B:
        {
          printf("i2b\n");
        }
        break;
      case I2C:
        {
          printf("i2c\n");
        }
        break;
      case I2S:
        {
          printf("i2s\n");
        }
        break;
      case LCMP:
        {
          printf("lcmp\n");
        }
        break;
      case FCMPL:
        {
          printf("fcmpl\n");
        }
        break;
      case FCMPG:
        {
          printf("fcmpg\n");
        }
        break;
      case DCMPL:
        {
          printf("dcmpl\n");
        }
        break;
      case DCMPG:
        {
          printf("dcmpg\n");
        }
        break;
      case IFEQ:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("ifeq branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IFNE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("ifne branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IFLT:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("iflt branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IFGE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("ifge branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IFGT:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("ifgt branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IFLE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("ifle branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ICMPEQ:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_icmpeq branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ICMPNE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_icmpne branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ICMPLT:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_icmplt branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ICMPGE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_icmpge branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ICMPGT:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_icmpgt branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ICMPLE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_icmple branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ACMPEQ:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_acmpeq branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IF_ACMPNE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("if_acmpne branchbyte1[%02x] branchbyte2[%02x] branchOffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case GOTO:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("goto branchbyte1[%02x] branchbyte2[%02x] branchoffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case JSR:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("jsr branchbyte1[%02x] branchbyte2[%02x] branchoffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case RET:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 index = code[code_length_index];
          printf("ret index[%02x]\n", index);
        }
        break;
      case TABLESWITCH:
        {
          printf("tableswitch\n");
          u1 defaultbyte1 = 0x00;
          u1 defaultbyte2 = 0x00;
          u1 defaultbyte3 = 0x00;
          u1 defaultbyte4 = 0x00;
          u1 times        = 0x00;
          u4 defaultValue = 0x00000000;
          do {
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte1 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte2 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte3 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte4 = code[code_length_index];
            defaultValue = (defaultbyte1 << 24) | (defaultbyte2 << 16) | (defaultbyte3 << 8) | defaultbyte4;
            if (defaultValue == 0x00000000) {
              if (times == 0x00) {
                printf("\t   byte_pad:");
              }
              times = times + 0x01;
              printf(" [%02x]", defaultbyte1);
              fseek(pReadFile, -3, SEEK_CUR);
              code_length_index = code_length_index - 3;
            }
          } while (defaultValue == 0x00000000 && times <= 0x03);
          if (times) {
            printf("\n");
          }
          printf("\t   defaultbyte1[%02x]\tdefaultbyte2[%02x]\tdefaultbyte3[%02x]\tdefaultbyte4[%02x]\tdefault[%08x]\n", defaultbyte1, defaultbyte2, defaultbyte3, defaultbyte4, defaultValue);
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 lowbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 lowbyte2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 lowbyte3 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 lowbyte4 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 highbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 highbyte2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 highbyte3 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 highbyte4 = code[code_length_index];
          printf("\t   lowbyte1[%02x]\t\tlowbyte2[%02x]\t\tlowbyte3[%02x]\t\tlowbyte4[%02x]\t\tlowbyte[%08x]\n", lowbyte1, lowbyte2, lowbyte3, lowbyte4, (lowbyte1 << 24) | (lowbyte2 << 16) | (lowbyte3 << 8) | lowbyte4);
          printf("\t   highbyte1[%02x]\thighbyte2[%02x]\t\thighbyte3[%02x]\t\thighbyte4[%02x]\t\thighbyte[%08x]\n", highbyte1, highbyte2, highbyte3, highbyte4, (highbyte1 << 24) | (highbyte2 << 16) | (highbyte3 << 8) | highbyte4);
          u4 case_count = ((highbyte1 << 24) | (highbyte2 << 16) | (highbyte3 << 8) | highbyte4) - ((lowbyte1 << 24) | (lowbyte2 << 16) | (lowbyte3 << 8) | lowbyte4);
          for (u4 case_count_index = 0; case_count_index <= case_count; case_count_index++) {
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte1 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte2 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte3 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte4 = code[code_length_index];
            printf("\t   jump offsets\n");
            printf("\t\t\toffsetbyte1[%02x] offsetbyte2[%02x] offsetbyte3[%02x] offsetbyte4[%02x] offset[%08x]\n", offsetbyte1, offsetbyte2, offsetbyte3, offsetbyte4, (offsetbyte1 << 24) | (offsetbyte2 << 16) | (offsetbyte3 << 8) | offsetbyte4);
          }
          //jump offset + goto offset + code_length_index
        }
        break;
      case LOOKUPSWITCH:
        {
          printf("lookupswitch\n");
          u1 defaultbyte1 = 0x00;
          u1 defaultbyte2 = 0x00;
          u1 defaultbyte3 = 0x00;
          u1 defaultbyte4 = 0x00;
          u1 times        = 0x00;
          u4 defaultValue = 0x00000000;
          do {
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte1 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte2 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte3 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            defaultbyte4 = code[code_length_index];
            defaultValue = (defaultbyte1 << 24) | (defaultbyte2 << 16) | (defaultbyte3 << 8) | defaultbyte4;
            if (defaultValue == 0x00000000) {
              if (times == 0x00) {
                printf("\t    byte_pad:");
              }
              times = times + 0x01;
              printf(" [%02x]", defaultbyte1);
              fseek(pReadFile, -3, SEEK_CUR);
              code_length_index = code_length_index - 3;
            }
          } while (defaultValue == 0x00000000 && times <= 0x03);
          if (times) {
            printf("\n");
          }
          printf("\t    defaultbyte1[%02x]\tdefaultbyte2[%02x]\tdefaultbyte3[%02x]\tdefaultbyte4[%02x]\tdefault[%08x]\n", defaultbyte1, defaultbyte2, defaultbyte3, defaultbyte4, defaultValue);
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 case_count1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 case_count2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 case_count3 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 case_count4 = code[code_length_index];
          u4 case_count = (case_count1 << 24) | (case_count2 << 16) | (case_count3 << 8) | case_count4;
          for (u4 case_count_index = 0; case_count_index < case_count; case_count_index++) {
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 npairs1 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 npairs2 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 npairs3 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 npairs4 = code[code_length_index];
            u4 npairs = (npairs1 << 24) | (npairs2 << 16) | (npairs3 << 8) | npairs4;
            printf("\t    npairs1[%02x]\tnpairs2[%02x]\tnpairs3[%02x]\tnpairs4[%02x]\tnpairs[%08x]\n", npairs1, npairs2, npairs3, npairs4, (npairs1 << 24) | (npairs2 << 16) | (npairs3 << 8) | npairs4);
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte1 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte2 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte3 = code[code_length_index];
            fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
            u1 offsetbyte4 = code[code_length_index];
            printf("\t    match-offset pairs\n");
            printf("\t\t\toffsetbyte1[%02x] offsetbyte2[%02x] offsetbyte3[%02x] offsetbyte4[%02x] offset[%08x]\n", offsetbyte1, offsetbyte2, offsetbyte3, offsetbyte4, (offsetbyte1 << 24) | (offsetbyte2 << 16) | (offsetbyte3 << 8) | offsetbyte4);
          }
          //match-offset pairs + goto offset + code_length_index
        }
        break;
      case IRETURN:
        {
          printf("ireturn\n");
        }
        break;
      case LRETURN:
        {
          printf("lreturn\n");
        }
        break;
      case FRETURN:
        {
          printf("freturn\n");
        }
        break;
      case DRETURN:
        {
          printf("dreturn\n");
        }
        break;
      case ARETURN:
        {
          printf("areturn\n");
        }
        break;
      case RETURN:
        {
          printf("return\n");
        }
        break;
      case GETSTATIC:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("getstatic indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case PUTSTATIC:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("putstatic indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case GETFIELD:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("getfield indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case PUTFIELD:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("putfield indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case INVOKEVIRTUAL:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("invokevirtual indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case INVOKESPECIAL:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("invokespecial indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case INVOKESTATIC:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("invokestatic indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case INVOKEINTERFACE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 zero1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 zero2 = code[code_length_index];
          printf("invokeinterface indexbyte1[%02x] indexbyte2[%02x] index[%04x] zero1[%02x] zero2[%02x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2, zero1, zero2);
        }
        break;
      case INVOKEDYNAMIC:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 zero1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 zero2 = code[code_length_index];
          printf("invokedynamic indexbyte1[%02x] indexbyte2[%02x] index[%04x] zero1[%02x] zero2[%02x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2, zero1, zero2);
        }
        break;
      case NEW:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("new indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case NEWARRAY:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 atype = code[code_length_index];
          u1* arrayType;
          switch (atype) {
            case 0x04:
              arrayType = "T_BOOLEAN";
              break;
            case 0x05:
              arrayType = "T_CHAR";
              break;
            case 0x06:
              arrayType = "T_FLOAT";
              break;
            case 0x07:
              arrayType = "T_DOUBLE";
              break;
            case 0x08:
              arrayType = "T_BYTE";
              break;
            case 0x09:
              arrayType = "T_SHORT";
              break;
            case 0x0a:
              arrayType = "T_INT";
              break;
            case 0x0b:
              arrayType = "T_LONG";
              break;
          }
          printf("newarray atype[%02x] %s\n", atype, arrayType);
        }
        break;
      case ANEWARRAY:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("anewarray indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case ARRAYLENGTH:
        {
          printf("arraylength\n");
        }
        break;
      case ATHROW:
        {
          printf("athrow\n");
        }
        break;
      case CHECKCAST:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("checkcast indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case INSTANCEOF:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          printf("instanceof indexbyte1[%02x] indexbyte2[%02x] index[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2);
        }
        break;
      case MONITORENTER:
        {
          printf("monitorenter\n");
        }
        break;
      case MONITOREXIT:
        {
          printf("monitorexit\n");
        }
        break;
      case WIDE:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          opcode = code[code_length_index];
          switch (opcode) {
            case ILOAD:
              break;
            case FLOAD:
              break;
            case ALOAD:
              break;
            case LLOAD:
              break;
            case DLOAD:
              break;
            case ISTORE:
              break;
            case FSTORE:
              break;
            case ASTORE:
              break;
            case LSTORE:
              break;
            case DSTORE:
              break;
            case RET:
              break;
            case IINC:
              {
                fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
                u1 indexbyte1 = code[code_length_index];
                fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
                u1 indexbyte2 = code[code_length_index];
                fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
                u1 constbyte1 = code[code_length_index];
                fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
                u1 constbyte2 = code[code_length_index];
                printf("wide->iinc indexbyte1[%02x] indexbyte2[%02x] index[%04x] constbyte1[%02x] constbyte2[%02x] constant[%04x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2, constbyte1, constbyte2, (constbyte1 << 8) | constbyte2);
              }
              break;
          }
        }
        break;
      case MULTIANEWARRAY:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 indexbyte2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 dimensions = code[code_length_index];
          printf("multianewarray indexbyte1[%02x] indexbyte2[%02x] index[%04x] dimensions[%02x]\n", indexbyte1, indexbyte2, (indexbyte1 << 8) | indexbyte2, dimensions);
        }
        break;
      case IFNULL:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("ifnull branchbyte1[%02x] branchbyte2[%02x] branchoffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case IFNONNULL:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          printf("ifnonnull branchbyte1[%02x] branchbyte2[%02x] branchoffset[%04x]\n", branchbyte1, branchbyte2, (branchbyte1 << 8) | branchbyte2);
        }
        break;
      case GOTO_W:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte3 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte4 = code[code_length_index];
          printf("goto_w branchbyte1[%02x] branchbyte2[%02x] branchbyte3[%02x] branchbyte4[%02x] branchoffset[%08x]\n", branchbyte1, branchbyte2, branchbyte3, branchbyte4, (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4);
        }
        break;
      case JSR_W:
        {
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte1 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte2 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte3 = code[code_length_index];
          fread(&code[++code_length_index], 1, sizeof(u1), pReadFile);
          u1 branchbyte4 = code[code_length_index];
          printf("jsr_w branchbyte1[%02x] branchbyte2[%02x] branchbyte3[%02x] branchbyte4[%02x] branchoffset[%08x]\n", branchbyte1, branchbyte2, branchbyte3, branchbyte4, (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4);
        }
        break;
      case BREAKPOINT:
      case IMPDEP1:
      case IMPDEP2:
        break;
      default:
        printf("%02x ", code[code_length_index]);
        break;
    }
  }
  PRINTF_U2(exception_table_length)
  if (exception_table_length > 0) {
    for (u2 exception_table_length_index = 0; exception_table_length_index < exception_table_length; exception_table_length_index++) {
      PRINTF_U2(start_pc)
      PRINTF_U2(end_pc)
      PRINTF_U2(handler_pc)
      PRINTF_U2(catch_type)
    }
  }
  attributes(pReadFile, constant_pool);
}

/*
StackMapTable_attribute {
    u2              attribute_name_index;
    u4              attribute_length;
    u2              number_of_entries;
    stack_map_frame entries[number_of_entries];
}
union stack_map_frame {
    same_frame;
    same_locals_1_stack_item_frame;
    same_locals_1_stack_item_frame_extended;
    chop_frame;
    same_frame_extended;
    append_frame;
    full_frame;
}
same_frame {
    u1 frame_type = SAME; //0-63
}
same_locals_1_stack_item_frame {
    u1 frame_type = SAME_LOCALS_1_STACK_ITEM; //64-127
    verification_type_info stack[1];
}
same_locals_1_stack_item_frame_extended {
    u1 frame_type = SAME_LOCALS_1_STACK_ITEM_EXTENDED; //247
    u2 offset_delta;
    verification_type_info stack[1];
}
chop_frame {
    u1 frame_type = CHOP; //248-250
    u2 offset_delta;
}
same_frame_extended {
    u1 frame_type = SAME_FRAME_EXTENDED; //251
    u2 offset_delta;
}
append_frame {
    u1 frame_type = APPEND; //252-254
    u2 offset_delta;
    verification_type_info locals[frame_type - 251];
}
full_frame {
    u1 frame_type = FULL_FRAME; //255
    u2 offset_delta;
    u2 number_of_locals;
    verification_type_info locals[number_of_locals];
    u2 number_of_stack_items;
    verification_type_info stack[number_of_stack_items];
}
*/
void StackMapTable_attribute(FILE* pReadFile) {
  PRINTF_U2(number_of_entries)
  if (number_of_entries > 0) {
    for (u2 number_of_entries_index = 0; number_of_entries_index < number_of_entries; number_of_entries_index++) {
      PRINTF_U1(frame_type)
      if (frame_type >= 0x00 && frame_type <= 0x3f) {
      } else if (frame_type >= 0x40 && frame_type <= 0x7f) {
        verification_type_info(pReadFile);
      } else if (frame_type == 0xf7) {
        PRINTF_U2(offset_delta)
        verification_type_info(pReadFile);
      } else if (frame_type >= 0xf8 && frame_type <= 0xfa) {
        PRINTF_U2(offset_delta)
      } else if (frame_type == 0xfb) {
        PRINTF_U2(offset_delta)
      } else if (frame_type >= 0xfc && frame_type <= 0xfe) {
        PRINTF_U2(offset_delta)
        for (u1 frame_type_index = 0, frame_type_ = frame_type - 251; frame_type_index < frame_type_; frame_type_index++) {
          verification_type_info(pReadFile);
        }
      } else if (frame_type == 0xff) {
        PRINTF_U2(offset_delta)
        PRINTF_U2(number_of_locals)
        for (u2 number_of_locals_index = 0; number_of_locals_index < number_of_locals; number_of_locals_index++) {
          verification_type_info(pReadFile);
        }
        PRINTF_U2(number_of_stack_items)
        for (u2 number_of_stack_items_index = 0; number_of_stack_items_index < number_of_stack_items; number_of_stack_items_index++) {
          verification_type_info(pReadFile);
        }
      }
    }
  }
}

/*
union verification_type_info {
    Top_variable_info;
    Integer_variable_info;
    Float_variable_info;
    Long_variable_info;
    Double_variable_info;
    Null_variable_info;
    UninitializedThis_variable_info;
    Object_variable_info;
    Uninitialized_variable_info;
}
Top_variable_info {
    u1 tag = ITEM_Top; //0
}
Integer_variable_info {
    u1 tag = ITEM_Integer; //1
}
Float_variable_info {
    u1 tag = ITEM_Float; //2
}
Double_variable_info {
    u1 tag = ITEM_Double; //3
}
Long_variable_info {
    u1 tag = ITEM_Long; //4
}
Null_variable_info {
    u1 tag = ITEM_Null; //5
}
UninitializedThis_variable_info {
    u1 tag = ITEM_UninitializedThis; //6
}
Object_variable_info {
    u1 tag = ITEM_Object; //7
    u2 cpool_index;
}
Uninitialized_variable_info {
    u1 tag = ITEM_Uninitialized; //8
    u2 offset;
}
*/
void verification_type_info(FILE* pReadFile) {
  PRINTF_U1(tag)
  switch (tag) {
    case 0x00:
      break;
    case 0x01:
      break;
    case 0x02:
      break;
    case 0x03:
      break;
    case 0x04:
      break;
    case 0x05:
      break;
    case 0x06:
      break;
    case 0x07:
      {
        PRINTF_U2(cpool_index)
      }
      break;
    case 0x08:
      {
        PRINTF_U2(offset)
      }
      break;
  }
}

/*
Exceptions_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_exceptions;
    u2 exception_index_table[number_of_exceptions];
}
*/
void Exceptions_attribute(FILE* pReadFile) {
  PRINTF_U2(number_of_exceptions)
  PRINTF_U2_ARRAY(number_of_exceptions, exception_index_table)
}

/*
InnerClasses_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    {   u2 inner_class_info_index;
        u2 outer_class_info_index;
        u2 inner_name_index;
        u2 inner_class_access_flags;
    } classes[number_of_classes];
}
*/
void InnerClasses_attribute(FILE* pReadFile) {
  PRINTF_U2(number_of_classes)
  if (number_of_classes > 0) {
    for (u2 number_of_classes_index = 0; number_of_classes_index < number_of_classes; number_of_classes_index++) {
      PRINTF_U2(inner_class_info_index)
      PRINTF_U2(outer_class_info_index)
      PRINTF_U2(inner_name_index)
      PRINTF_U2(inner_class_access_flags)
    }
  }
}

/*
EnclosingMethod_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 class_index;
    u2 method_index;
}
*/
void EnclosingMethod_attribute(FILE* pReadFile) {
  PRINTF_U2(class_index)
  PRINTF_U2(method_index)
}

/*
Synthetic_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
}
*/
void Synthetic_attribute(FILE* pReadFile) {
}

/*
Signature_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 signature_index;
}
*/
void Signature_attribute(FILE* pReadFile) {
  PRINTF_U2(signature_index)
}

/*
SourceFile_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 sourcefile_index;
}
*/
void SourceFile_attribute(FILE* pReadFile) {
  PRINTF_U2(sourcefile_index)
}

/*
SourceDebugExtension_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 debug_extension[attribute_length];
}
*/
void SourceDebugExtension_attribute(FILE* pReadFile, u4 attribute_length) {
  u1 debug_extension[attribute_length];
  for (u4 attribute_length_index = 0; attribute_length_index < attribute_length; attribute_length_index++) {
    fread(&debug_extension[attribute_length_index], 1, sizeof(u1), pReadFile);
    printf("debug_extension[%04x]: %02x\n", attribute_length_index, debug_extension[attribute_length_index]);
  }
}

/*
LineNumberTable_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 line_number_table_length;
    {   u2 start_pc;
        u2 line_number;	
    } line_number_table[line_number_table_length];
}
*/
void LineNumberTable_attribute(FILE* pReadFile) {
  PRINTF_U2(line_number_table_length)
  if (line_number_table_length > 0) {
    for (u2 line_number_table_length_index = 0; line_number_table_length_index < line_number_table_length; line_number_table_length_index++) {
      PRINTF_U2(start_pc)
      PRINTF_U2(line_number)
    }
  }
}

/*
LocalVariableTable_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 local_variable_table_length;
    {   u2 start_pc;
        u2 length;
        u2 name_index;
        u2 descriptor_index;
        u2 index;
    } local_variable_table[local_variable_table_length];
}
*/
void LocalVariableTable_attribute(FILE* pReadFile) {
  PRINTF_U2(local_variable_table_length)
  if (local_variable_table_length > 0) {
    for (u2 local_variable_table_length_index = 0; local_variable_table_length_index < local_variable_table_length; local_variable_table_length_index++) {
      PRINTF_U2(start_pc)
      PRINTF_U2(length)
      PRINTF_U2(name_index)
      PRINTF_U2(descriptor_index)
      PRINTF_U2(index)
    }
  }
}

/*
LocalVariableTypeTable_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 local_variable_type_table_length;
    {   u2 start_pc;
        u2 length;
        u2 name_index;
        u2 signature_index;
        u2 index;
    } local_variable_type_table[local_variable_type_table_length];
}
*/
void LocalVariableTypeTable_attribute(FILE* pReadFile) {
  PRINTF_U2(local_variable_type_table_length)
  if (local_variable_type_table_length > 0) {
    for (u2 local_variable_type_table_length_index = 0; local_variable_type_table_length_index < local_variable_type_table_length; local_variable_type_table_length_index++) {
      PRINTF_U2(start_pc)
      PRINTF_U2(length)
      PRINTF_U2(name_index)
      PRINTF_U2(signature_index)
      PRINTF_U2(index)
    }
  }
}

/*
Deprecated_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
}
*/
void Deprecated_attribute(FILE* pReadFile) {
}

/*
RuntimeVisibleAnnotations_attribute {
    u2         attribute_name_index;
    u4         attribute_length;
    u2         num_annotations;
    annotation annotations[num_annotations];
}
annotation {
    u2 type_index;
    u2 num_element_value_pairs;
    {   u2            element_name_index;
        element_value value;
    } element_value_pairs[num_element_value_pairs];
}
element_value {
    u1 tag;
    union {
        u2 const_value_index;

        {   u2 type_name_index;
            u2 const_name_index;
        } enum_const_value;

        u2 class_info_index;

        annotation annotation_value;

        {   u2            num_values;
            element_value values[num_values];
        } array_value;
    } value;
}
*/
void RuntimeVisibleAnnotations_attribute(FILE* pReadFile) {
  annotations(pReadFile);
}

/*
RuntimeInvisibleAnnotations_attribute {
    u2         attribute_name_index;
    u4         attribute_length;
    u2         num_annotations;
    annotation annotations[num_annotations];
}
*/
void RuntimeInvisibleAnnotations_attribute(FILE* pReadFile) {
  annotations(pReadFile);
}

/*
RuntimeVisibleParameterAnnotations_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 num_parameters;
    {   u2         num_annotations;
        annotation annotations[num_annotations];
    } parameter_annotations[num_parameters];
}
*/
void RuntimeVisibleParameterAnnotations_attribute(FILE* pReadFile) {
  parameter_annotations(pReadFile);
}

/*
RuntimeInvisibleParameterAnnotations_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 num_parameters;
    {   u2         num_annotations;
        annotation annotations[num_annotations];
    } parameter_annotations[num_parameters];
}
annotation {
    u2 type_index;
    u2 num_element_value_pairs;
    {   u2            element_name_index;
        element_value value;
    } element_value_pairs[num_element_value_pairs];
}
*/
void RuntimeInvisibleParameterAnnotations_attribute(FILE* pReadFile) {
  parameter_annotations(pReadFile);
}

void parameter_annotations(FILE* pReadFile) {
  PRINTF_U1(num_parameters)
  if (num_parameters > 0) {
    for (u1 num_parameters_index = 0; num_parameters_index < num_parameters; num_parameters_index++) {
      annotations(pReadFile);
    }
  }
}

void annotations(FILE* pReadFile) {
  PRINTF_U2(num_annotations)
  for (u2 num_annotations_index = 0; num_annotations_index < num_annotations; num_annotations_index++) {
    annotation(pReadFile);
  }
}

/*
RuntimeVisibleTypeAnnotations_attribute {
    u2              attribute_name_index;
    u4              attribute_length;
    u2              num_annotations;
    type_annotation annotations[num_annotations];
}
type_annotation {
    u1 target_type;
    union {
        type_parameter_target;
        supertype_target;
        type_parameter_bound_target;
        empty_target;
        formal_parameter_target;
        throws_target;
        localvar_target;
        catch_target;
        offset_target;
        type_argument_target;
    } target_info;
    type_path target_path;
    u2        type_index;
    u2        num_element_value_pairs;
    {   u2            element_name_index;
        element_value value;
    } element_value_pairs[num_element_value_pairs];
}
*/
void RuntimeVisibleTypeAnnotations_attribute(FILE* pReadFile) {
  type_annotation(pReadFile);
}

/*
RuntimeInvisibleTypeAnnotations_attribute {
    u2              attribute_name_index;
    u4              attribute_length;
    u2              num_annotations;
    type_annotation annotations[num_annotations];
}
type_annotation {
    u1 target_type;
    union {
        type_parameter_target;
        supertype_target;
        type_parameter_bound_target;
        empty_target;
        formal_parameter_target;
        throws_target;
        localvar_target;
        catch_target;
        offset_target;
        type_argument_target;
    } target_info;
    type_path target_path;
    u2        type_index;
    u2        num_element_value_pairs;
    {   u2            element_name_index;
        element_value value;
    } element_value_pairs[num_element_value_pairs];
}
type_path {
    u1 path_length;
    {   u1 type_path_kind;
        u1 type_argument_index;
    } path[path_length];
}
*/
void RuntimeInvisibleTypeAnnotations_attribute(FILE* pReadFile) {
  type_annotation(pReadFile);
}

void type_annotation(FILE* pReadFile) {
  PRINTF_U2(num_annotations)
  if (num_annotations > 0) {
    for (u2 num_annotations_index = 0; num_annotations_index < num_annotations; num_annotations_index++) {
      PRINTF_U1(target_type)
      switch (target_type) {
        case 0x00://type_parameter_target
          {
            PRINTF_U1(type_parameter_index)
          }
          break;
        case 0x01://type_parameter_target
          {
            PRINTF_U1(type_parameter_index)
          }
          break;
        case 0x10://supertype_target
          {
            PRINTF_U2(supertype_index)
          }
          break;
        case 0x11://type_parameter_bound_target
          {
            PRINTF_U1(type_parameter_index)
            PRINTF_U1(bound_index)
          }
          break;
        case 0x12://type_parameter_bound_target
          {
            PRINTF_U1(type_parameter_index)
            PRINTF_U1(bound_index)
          }
          break;
        case 0x13://empty_target
          break;
        case 0x14://empty_target
          break;
        case 0x15://empty_target
          break;
        case 0x16://formal_parameter_target
          {
            PRINTF_U1(formal_parameter_index)
          }
          break;
        case 0x17://throws_target
          {
            PRINTF_U2(throws_type_index)
          }
          break;
        case 0x40://localvar_target
          {
            PRINTF_U2(table_length)
            for (u2 table_length_index = 0; table_length_index < table_length; table_length_index++) {
              PRINTF_U2(start_pc)
              PRINTF_U2(length)
              PRINTF_U2(index)
            }
          }
          break;
        case 0x41://localvar_target
          {
            PRINTF_U2(table_length)
            for (u2 table_length_index = 0; table_length_index < table_length; table_length_index++) {
              PRINTF_U2(start_pc)
              PRINTF_U2(length)
              PRINTF_U2(index)
            }
          }
          break;
        case 0x42://catch_target
          {
            PRINTF_U2(exception_table_index)
          }
          break;
        case 0x43://offset_target
          {
            PRINTF_U2(offset)
          }
          break;
        case 0x44://offset_target
          {
            PRINTF_U2(offset)
          }
          break;
        case 0x45://offset_target
          {
            PRINTF_U2(offset)
          }
          break;
        case 0x46://offset_target
          {
            PRINTF_U2(offset)
          }
          break;
        case 0x47://type_argument_target
          {
            PRINTF_U1(type_parameter_index)
          }
          break;
        case 0x48://type_argument_target
          {
            PRINTF_U1(type_parameter_index)
          }
          break;
        case 0x49://type_argument_target
          {
            PRINTF_U1(type_parameter_index)
          }
          break;
        case 0x4a://type_argument_target
          {
            PRINTF_U1(type_parameter_index)
          }
          break;
        case 0x4b://type_argument_target
          {
            PRINTF_U1(type_parameter_index)
          }
          break;
      }
      PRINTF_U1(path_length)
      for (u2 path_length_index = 0; path_length_index < path_length; path_length_index++) {
        PRINTF_U1(type_path_kind)
        PRINTF_U1(type_argument_index)
      }
      PRINTF_U2(type_index)
      PRINTF_U2(num_element_value_pairs)
      for (u2 num_element_value_pairs_index = 0; num_element_value_pairs_index < num_element_value_pairs; num_element_value_pairs_index++) {
        PRINTF_U2(element_name_index)
        element_value(pReadFile);
      }
    }
  }
}

/*
AnnotationDefault_attribute {
    u2            attribute_name_index;
    u4            attribute_length;
    element_value default_value;
}
element_value {
    u1 tag;
    union {
        u2 const_value_index;

        {   u2 type_name_index;
            u2 const_name_index;
        } enum_const_value;

        u2 class_info_index;

        annotation annotation_value;

        {   u2            num_values;
            element_value values[num_values];
        } array_value;
    } value;
}
annotation {
    u2 type_index;
    u2 num_element_value_pairs;
    {   u2            element_name_index;
        element_value value;
    } element_value_pairs[num_element_value_pairs];
}
*/
void AnnotationDefault_attribute(FILE* pReadFile) {
  element_value(pReadFile);
}

void element_value(FILE* pReadFile) {
  PRINTF_U1(tag)
  switch (tag) {
    case 'B':
    case 'C':
    case 'D':
    case 'F':
    case 'I':
    case 'J':
    case 'S':
    case 'Z':
    case 's':
      {
        PRINTF_U2(const_value_index)
      }
      break;
    case 'e':
      {
        PRINTF_U2(type_name_index)
        PRINTF_U2(const_name_index)
      }
      break;
    case 'c':
      {
        PRINTF_U2(class_info_index)
      }
      break;
    case '@':
      {
        annotation(pReadFile);
      }
      break;
    case '[':
      {
        PRINTF_U2(num_values)
        if (num_values > 0) {
          for (u2 num_values_index = 0; num_values_index < num_values; num_values_index++) {
            element_value(pReadFile);
          }
        }
      }
      break;
  }
}

void annotation(FILE* pReadFile) {
  PRINTF_U2(type_index)
  PRINTF_U2(num_element_value_pairs)
  if (num_element_value_pairs > 0) {
    for (u2 num_element_value_pairs_index = 0; num_element_value_pairs_index < num_element_value_pairs; num_element_value_pairs_index++) {
      PRINTF_U2(element_name_index)
      element_value(pReadFile);
    }
  }
}

/*
BootstrapMethods_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 num_bootstrap_methods;
    {   u2 bootstrap_method_ref;
        u2 num_bootstrap_arguments;
        u2 bootstrap_arguments[num_bootstrap_arguments];
    } bootstrap_methods[num_bootstrap_methods];
}
*/
void BootstrapMethods_attribute(FILE* pReadFile) {
  PRINTF_U2(num_bootstrap_methods)
  if (num_bootstrap_methods > 0) {
    for (u2 num_bootstrap_methods_index = 0; num_bootstrap_methods_index < num_bootstrap_methods; num_bootstrap_methods_index++) {
      PRINTF_U2(bootstrap_method_ref)
      PRINTF_U2(num_bootstrap_arguments)
      PRINTF_U2_ARRAY(num_bootstrap_arguments, bootstrap_arguments)
    }
  }
}

/*
MethodParameters_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 parameters_count;
    {   u2 name_index;
        u2 access_flags;
    } parameters[parameters_count];
}
*/
void MethodParameters_attribute(FILE* pReadFile) {
  PRINTF_U1(parameters_count)
  if (parameters_count > 0) {
    for (u1 parameters_count_index = 0; parameters_count_index < parameters_count; parameters_count_index++) {
      PRINTF_U2(name_index)
      PRINTF_U2(access_flags)
    }
  }
}

/*
Module_attribute {
    u2 attribute_name_index;
    u4 attribute_length;

    u2 module_name_index;
    u2 module_flags;
    u2 module_version_index;

    u2 requires_count;
    {   u2 requires_index;
        u2 requires_flags;
        u2 requires_version_index;
    } requires[requires_count];

    u2 exports_count;
    {   u2 exports_index;
        u2 exports_flags;
        u2 exports_to_count;
        u2 exports_to_index[exports_to_count];
    } exports[exports_count];

    u2 opens_count;
    {   u2 opens_index;
        u2 opens_flags;
        u2 opens_to_count;
        u2 opens_to_index[opens_to_count];
    } opens[opens_count];

    u2 uses_count;
    u2 uses_index[uses_count];

    u2 provides_count;
    {   u2 provides_index;
        u2 provides_with_count;
        u2 provides_with_index[provides_with_count];
    } provides[provides_count];
}
*/
void Module_attribute(FILE* pReadFile) {
  PRINTF_U2(module_name_index)
  PRINTF_U2(module_flags)
  PRINTF_U2(module_version_index)
  PRINTF_U2(requires_count)
  if (requires_count > 0) {
    for (u2 requires_count_index = 0; requires_count_index < requires_count; requires_count_index++) {
      PRINTF_U2(requires_index)
      PRINTF_U2(requires_flags)
      PRINTF_U2(requires_version_index)
    }
  }
  PRINTF_U2(exports_count)
  if (exports_count > 0) {
    for (u2 exports_count_index = 0; exports_count_index < exports_count; exports_count_index++) {
      PRINTF_U2(exports_index)
      PRINTF_U2(exports_flags)
      PRINTF_U2(exports_to_count)
      PRINTF_U2_ARRAY(exports_count, exports_to_index)
    }
  }
  PRINTF_U2(opens_count)
  if (opens_count > 0) {
    for (u2 opens_count_index = 0; opens_count_index < opens_count; opens_count_index++) {
      PRINTF_U2(opens_index)
      PRINTF_U2(opens_flags)
      PRINTF_U2(opens_to_count)
      PRINTF_U2_ARRAY(opens_to_count, opens_to_index)
    }
  }
  PRINTF_U2(uses_count)
  PRINTF_U2_ARRAY(uses_count, uses_index)
  PRINTF_U2(provides_count)
  if (provides_count > 0) {
    for (u2 provides_count_index = 0; provides_count_index < provides_count; provides_count_index++) {
      PRINTF_U2(provides_index)
      PRINTF_U2(provides_with_count)
      PRINTF_U2_ARRAY(provides_with_count, provides_with_index)
    }
  }
}

/*
ModulePackages_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 package_count;
    u2 package_index[package_count];
}
*/
void ModulePackages_attribute(FILE* pReadFile) {
  PRINTF_U2(package_count)
  PRINTF_U2_ARRAY(package_count, package_index)
}

/*
ModuleMainClass_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 main_class_index;
}
*/
void ModuleMainClass_attribute(FILE* pReadFile) {
  PRINTF_U2(main_class_index)
}

/*
NestHost_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 host_class_index;
}
*/
void NestHost_attribute(FILE* pReadFile) {
  PRINTF_U2(host_class_index)
}

/*
NestMembers_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    u2 classes[number_of_classes];
}
*/
void NestMembers_attribute(FILE* pReadFile) {
  PRINTF_U2(number_of_classes)
  PRINTF_U2_ARRAY(number_of_classes, classes)
}
