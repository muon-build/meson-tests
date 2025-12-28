#include <stdio.h>

int main(void)
{
#ifdef _WIN32
	setvbuf(stderr, 0, _IOFBF, 2048);
#endif

    for (int i = 0 ; i < 100000 ; i++)
        fprintf(stderr, "# Iteration %d to stderr\n", i + 1);

    printf("ok 1 - dumper to stderr\n");

    for (int i = 0 ; i < 100000 ; i++)
        fprintf(stdout, "# Iteration %d to stdout\n", i + 1);

    printf("ok 2 - dumper to stdout\n1..2\n");

    return 0;
}

