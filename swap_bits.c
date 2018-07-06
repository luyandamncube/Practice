#include <stdio.h>
#include <stdlib.h>

unsigned char swap_bits(char c)
{
   //c is 1 byte (i.e. 8-bit pattern) 
   //left shift the pattern 4 places using          (c << 4)
   //right shift the pattern 4 places using         (c >> 4)
   //Peform a bitwise OR on the two results using     |
   return ((c << 4) | (c >> 4));
}

int     main(int argc, char **argv)
{
    //example : 01000001
    if (argc == 2)
    {
        printf("ORIGINAL: %d\n", atoi(argv[1]));                //65 or 'A'
        printf("CONVERTED: %d\n", swap_bits(atoi(argv[1])));    //20
    }
    printf("\n");
    return (0);
}