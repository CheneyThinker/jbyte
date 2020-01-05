#pragma once

#ifndef JBYTE_DEF_H
#define JBYTE_DEF_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

typedef unsigned char  u1;
typedef unsigned short u2;
typedef unsigned int   u4;

#define BIG_ENDIAN
#ifdef BIG_ENDIAN
  #define swap_u2(origin) ((origin << 8 & 0Xff00) | (origin >> 8 & 0X00ff))
  #define swap_u4(origin) ((origin << 24 & 0Xff000000) | (origin <<  8 & 0X00ff0000) | (origin >> 24 & 0X000000ff) | (origin >>  8 & 0X0000ff00))
#else
  #define swap_u2(origin) origin
  #define swap_u4(origin) origin
#endif

#define MAGIC 0xcafebabe

#define CONSTANT_CLASS_TAG                0x07
#define CONSTANT_FIELDREF_TAG             0x09
#define CONSTANT_METHODREF_TAG            0x0a
#define CONSTANT_INTERFACE_METHODREF_TAG  0x0b
#define CONSTANT_STRING_TAG               0x08
#define CONSTANT_INTEGER_TAG              0x03
#define CONSTANT_FLOAT_TAG                0x04
#define CONSTANT_LONG_TAG                 0x05
#define CONSTANT_DOUBLE_TAG               0x06
#define CONSTANT_NAME_AND_TYPE_TAG        0x0c
#define CONSTANT_UTF8_TAG                 0x01
#define CONSTANT_METHOD_HANDLE_TAG        0x0f
#define CONSTANT_METHOD_TYPE_TAG          0x10
#define CONSTANT_DYNAMIC_TAG              0x11
#define CONSTANT_INVOKE_DYNAMIC_TAG       0x12
#define CONSTANT_MODULE_TAG               0x13
#define CONSTANT_PACKAGE_TAG              0x14

#define ACC_PUBLIC      0x0001
#define ACC_PRIVATE     0x0002
#define ACC_PROTECTED   0x0004
#define ACC_STATIC      0x0008
#define ACC_FINAL       0x0010
#define ACC_SUPER       0x0020
#define ACC_VOLATILE    0x0040
#define ACC_TRANSIENT   0x0080
#define ACC_INTERFACE   0x0200
#define ACC_ABSTRACT    0x0400
#define ACC_SYNTHETIC   0x1000
#define ACC_ANNOTATION  0x2000
#define ACC_ENUM        0x4000
#define ACC_MODULE      0x8000

#define JDK1_0_2  0x002d
#define JDK1_1    0x002d
#define JDK1_2    0x002e
#define JDK1_3    0x002f
#define JDK1_4    0x0030
#define JDK5_0    0x0031
#define JDK6      0x0032
#define JDK7      0x0033
#define JDK8      0x0034
#define JDK9      0x0035
#define JDK10     0x0036
#define JDK11     0x0037
#define JDK12     0x0038
#define JDK13     0x0039

#endif
