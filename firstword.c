#include <unistd.h>

void              ft_putchar(int c)
{
    write(1, &c, 1);
}

unsigned int      ft_iswhitespace(int c)
{
    if (c == '\t' || c == ' ' || c == '\n')
        return (1);
    return (0);
}

int     main(int argc, char **argv)
{
    int k = 0;
    if (argc == 2)
    {
        while (!ft_iswhitespace(argv[1][k]))
        {
            ft_putchar(argv[1][k]);
            k++;
        }
    }
    ft_putchar('\n');
    return(0);
}