#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char      ft_dostuff(char c )
{
    return (c = c +1);
}

char    *ft_strmap(char const *s, char (*f)(char))
{
    size_t      size;
    size_t      i;
    char        *out;

    if (s)
    {
        size = strlen(s);
        if (NULL == (out = malloc(sizeof(char) * size + 1)))
            return (NULL);
        i = -1;
        while (++i < size)
            out[i] = (*f)(s[i]);
        out[i] = '\0';
        return (out);
    }
    return (NULL);
}

int main()
{
    char (*fp)(char c);

    fp = ft_dostuff;
    char test[22] = "this is a test string!";
    char *buf = malloc(32);
    int k = 0;

    buf = ft_strmap(test, fp);
    printf("TEST: %s", buf);
    return (0);
}