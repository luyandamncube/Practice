#include <unistd.h>

//ADD TO LIBFT
int     ft_strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return(len);
}

void    ft_putstr(char *str)
{
    int k = 0;

    while (*str)
        write(1, str++, 1);
}

int     ft_iswhitespace(int c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void    ft_replace (char *str)
{
    char *dest = str;
    while (*str)
    {
        while (ft_iswhitespace(*str) && ft_iswhitespace(*(str + 1)))
            *str++;
        *dest++ = *str++;
    }
    *dest = '\0';
}

int     main(int argc, char *argv[])
{
    int     len = ft_strlen(argv[1]); 

    if (argc == 2)
    {
        ft_replace(argv[1]);
        if (ft_iswhitespace(argv[1][len]))
            argv[1][len] = '\0';
        if (ft_iswhitespace(argv[1][0]))
            argv[1] += 1;
             ft_putstr(argv[1]);
    }
    ft_putstr("\n");
    return (0);
}