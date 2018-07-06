#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int             n;
    unsigned char   bit;

    n = 8;
    while (n--)
    {
        //Right shift is division by 2
        //The remainder is printed
        //Therefore right shifting a byte essentially converts it to binary      
        bit = (octet >> n & 1) + '0';
        write(1, &bit, 1);
    }
}

int     main(int argc, char **argv)
{
    //example : 01000001
    if (argc == 2)
    {
        printf("ORIGINAL: %d\n", atoi(argv[1]));                //65 or 'A'
        //printf("CONVERTED: %d\n", print_bits(atoi(argv[1])));    //20
        print_bits(atoi(argv[1]));
    }
    printf("\n");
    return (0);
}


int main(void)
{
    int **a;
    **a = 42;
    Printf(“%i\n”,**a);     // prints “42”
}
