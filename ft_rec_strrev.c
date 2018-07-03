#include <unistd.h>
#include <stdio.h>

void    ft_putchar(int c)
{
    write(1, &c, 1);
}

unsigned int    ft_strlen(char *str)
{
    int k = 0;
    while (*str++)
        k++;
    return (k);
}

void    ft_strrev(char *str)
{
    int k = ft_strlen(str);
    printf("len: %d", k);
    while (k > -1)
    {
        ft_putchar(str[k]);
        k--;
    }
}