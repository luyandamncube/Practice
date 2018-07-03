#include <unistd.h>

unsigned int  ft_islower(int c )
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

unsigned int  ft_isupper(int c )
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

void    ft_putchar(int c)
{
    write(1, &c, 1);
}

int     main(int argc, char **argv)
{
    int k = 0;
    int n;
    if (argc == 2)
    {
        while (argv[1][k])
        {
            if (ft_isupper(argv[1][k]))
            {
                n = argv[1][k] - 'A' - 1;
                while (n > 0)
                {
                    ft_putchar(argv[1][k]);
                    n--;
                }
            }
            else if (ft_islower(argv[1][k]))
            {
                n = argv[1][k] - 'a' - 1;
                while (n > 0)
                {
                    ft_putchar(argv[1][k]);
                    n--;
                }
            }
            else 
                ft_putchar(argv[1][k]);
        }
    }
    ft_putchar('\n');
    return (0);
}