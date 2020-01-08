objects	= jbyte_attribute.o\
          jbyte_cp.o\
          jbyte_field.o\
          jbyte_method.o\
          jbyte_analyzer.o\
          jbyte_generator.o\
          jbyte.o

jbyte:	$(objects)
	gcc -o $@ $(objects) -lm
	rm -rf *.o

%.o:	src/%.c
	gcc -c -o $@ $<

.PHONY:	clean

clean:
	rm -rf *.o jbyte
