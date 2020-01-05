#pragma once

#ifndef JBYTE_CP_H
#define JBYTE_CP_H

#include "jbyte_base.h"
#include "jbyte_opcode.h"

void addConstantUtf8(u1*, FILE*);
void addConstantClass(u2, FILE*);
void addConstantString(u2, FILE*);
void addConstantNameAndType(u2, u2, FILE*);
void addConstantFieldref(u2, u2, FILE*);
void addConstantMethodref(u2, u2, FILE*);

#endif
