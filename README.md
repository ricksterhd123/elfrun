# elfrun
proof of concept for upcoming project

How it works

![ELF format (src wikipedia)](elf-layout.png)

1. assembly nasm code into ELF
2. extract .text from ELF (raw machine code)
3. use xxd to load .text bytes into C header file
4. use mmap to allocate page (with read|write|exec perms)
5. copy c header bytes into page
5. grab function pointer to first page
6. run

## Requirements
- GNU/Linux x86-64
- bash, gcc, nasm, xxd, objcopy

## Build
`bash build.sh`
