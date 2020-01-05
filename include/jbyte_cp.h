#pragma once

#ifndef JBYTE_CP_H
#define JBYTE_CP_H

#include "jbyte_attribute.h"

void free_constant_pool(u1**, u2);
u1** constant_pool(FILE*, u2*);
void addConstantUtf8(u1*, FILE*);
void addConstantClass(u2, FILE*);
void addConstantString(u2, FILE*);
void addConstantNameAndType(u2, u2, FILE*);
void addConstantFieldref(u2, u2, FILE*);
void addConstantMethodref(u2, u2, FILE*);

#endif
