@echo off
gcc -c src/*.c
gcc -o jbyte *.o
del *.o
cmd /k
