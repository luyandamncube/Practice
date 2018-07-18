#include <stdlib.h>
#include <stdio.h> //REMOVE ME

char    **ft_split(char *str)
{
    char    **split;
    int     k = 0;
    int     m = 0;

    split = (char **)malloc(sizeof(char*)*256);
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    while (*str)
    {
        m = 0;
        split[k] = (char*)malloc(sizeof(char)*4096);
        while (*str != ' ' && *str != '\t' && *str != '\n' && *str)
        {
            split[k][m++] = *str;
            str++; 
        }
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        split[k][m] = '\0';
        k++;
    }
    split[k] = NULL;
    return (split);
}

int     main(int argc, char **argv)
{
    char **split;
    if (argc == 2)
    {
        split = ft_split(argv[1]);
        printf("1: %s\n", split[0]);
        printf("2: %s\n", split[1]);
        printf("3: %s\n", split[2]);
        printf("4: %s\n", split[3]);
        printf("5: %s\n", split[4]);
    }
    printf("\n");
    return (0);
}