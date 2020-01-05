#pragma once

#ifndef JBYTE_CP_H
#define JBYTE_CP_H

#include "jbyte_attribute.h"

void generator_constant_pool(FILE*);
void addConstantUtf8(u1*, FILE*);
void addConstantClass(u2, FILE*);
void addConstantString(u2, FILE*);
void addConstantNameAndType(u2, u2, FILE*);
void addConstantFieldref(u2, u2, FILE*);
void addConstantMethodref(u2, u2, FILE*);
void analyzer_constant_pool(FILE*, pcp_info);
void free_constant_pool(pcp_info);

#endif
