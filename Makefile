sourceDir         	= source/
objects			= jbyte_attribute.o jbyte_cp.o jbyte_field.o jbyte_method.o jbyte_analyzer.o jbyte_generator.o jbyte.o
jbyte_attribute		= $(sourceDir)jbyte_attribute.c
jbyte_cp		= $(sourceDir)jbyte_cp.c
jbyte_field		= $(sourceDir)jbyte_field.c
jbyte_method		= $(sourceDir)jbyte_method.c
jbyte_analyzer		= $(sourceDir)jbyte_analyzer.c
jbyte_generator		= $(sourceDir)jbyte_generator.c
jbyte			= $(sourceDir)jbyte.c
jbyte:			$(objects)
			gcc -o jbyte $(objects) -lm
jbyte_attribute.o:	$(jbyte_attribute)
			gcc -c $(jbyte_attribute)
jbyte_cp.o:		$(jbyte_cp)
			gcc -c $(jbyte_cp)
jbyte_field.o:		$(jbyte_field)
			gcc -c $(jbyte_field)
jbyte_method.o:		$(jbyte_method)
			gcc -c $(jbyte_method)
jbyte_analyzer.o:	$(jbyte_analyzer)
			gcc -c $(jbyte_analyzer)
jbyte_generator.o:	$(jbyte_generator)
			gcc -c $(jbyte_generator)
jbyte.o:		$(jbyte)
			gcc -c $(jbyte)
.PHONY:	clean
clean:
			rm -rf *.o jbyte
