#pragma once

#ifndef JBYTE_ATTRIBUTE_H
#define JBYTE_ATTRIBUTE_H

#include "jbyte_base.h"
#include "jbyte_opcode.h"

void generator_attributes(FILE*);
void analyzer_attributes(FILE*, u1**);
void ConstantValue_attribute(FILE*);
void Code_attribute(FILE*, u1**);
void StackMapTable_attribute(FILE*);
void verification_type_info(FILE*);
void Exceptions_attribute(FILE*);
void InnerClasses_attribute(FILE*);
void EnclosingMethod_attribute(FILE*);
void Synthetic_attribute(FILE*);
void Signature_attribute(FILE*);
void SourceFile_attribute(FILE*);
void SourceDebugExtension_attribute(FILE*, u4);
void LineNumberTable_attribute(FILE*);
void LocalVariableTable_attribute(FILE*);
void LocalVariableTypeTable_attribute(FILE*);
void Deprecated_attribute(FILE*);
void RuntimeVisibleAnnotations_attribute(FILE*);
void RuntimeInvisibleAnnotations_attribute(FILE*);
void RuntimeVisibleParameterAnnotations_attribute(FILE*);
void RuntimeInvisibleParameterAnnotations_attribute(FILE*);
void parameter_annotations(FILE*);
void annotations(FILE*);
void RuntimeVisibleTypeAnnotations_attribute(FILE*);
void RuntimeInvisibleTypeAnnotations_attribute(FILE*);
void type_annotation(FILE*);
void AnnotationDefault_attribute(FILE*);
void element_value(FILE*);
void annotation(FILE*);
void BootstrapMethods_attribute(FILE*);
void MethodParameters_attribute(FILE*);
void Module_attribute(FILE*);
void ModulePackages_attribute(FILE*);
void ModuleMainClass_attribute(FILE*);
void NestHost_attribute(FILE*);
void NestMembers_attribute(FILE*);

#endif
