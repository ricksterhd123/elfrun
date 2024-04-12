nasm -f elf hello.s
objcopy -O binary -j .text hello.o hello.bin
xxd -i hello.bin > hello.h
gcc main.c -o hello
rm hello.bin hello.o hello.h

