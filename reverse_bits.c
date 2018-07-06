#include <stdio.h>

unsigned char   reverse_bits(unsigned char octet)
{
    /*Left shifting a byte from it’s 0 index
      essentially reverses it from right to left 
    */
    return  (((octet >> 0) & 1) << 7) | \
            (((octet >> 1) & 1) << 6) | \
            (((octet >> 2) & 1) << 5) | \
            (((octet >> 3) & 1) << 4) | \
            (((octet >> 4) & 1) << 3) | \
            (((octet >> 5) & 1) << 2) | \
            (((octet >> 6) & 1) << 1) | \
            (((octet >> 7) & 1) << 0);
}

int     main(int argc, char **argv)
{
    //example : 01000001
    if (argc == 2)
    {
        printf("ORIGINAL: %d\n", atoi(argv[1]));                   //65 or 'A'
        printf("CONVERTED: %d\n", reverse_bits(atoi(argv[1])));    //20
    }
    printf("\n");
    return (0);
}