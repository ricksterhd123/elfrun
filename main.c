#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <errno.h>

#include "hello.h"

int main()
{
    void *mem = mmap(NULL, hello_bin_len, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem == MAP_FAILED)
    {
        int errsv = errno;
        fprintf(stderr, "mmap %d\n", errsv);
        return 1;
    }

    memcpy(mem, hello_bin, hello_bin_len);

    int (*hello)() = (int (*)())mem;
    int c = hello();

    printf("%d\n", c);

    munmap(mem, hello_bin_len);

    return 0;
}
