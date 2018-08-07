#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    rpn_calc without malloc
*/
char    *ft_strchr(char *str, int c)
{
    while (*str++)
    {
        if (*str == c)
            return(str);
    }
    return (NULL);
}

int     do_op(int a, int b, int op)
{
    if (op == '+')
        return (a + b);
    if (op == '-')
        return (b - a);  //REMEMBER THIS
    if (op == '/')
        return (a / b);
    if (op == '%')
        return (a % b);
    if (op == '*')
        return (a * b);
    return (0);
}

int     main(int argc, char **argv)
{
    int total = 0;
    int stack[4096];
    int top = 0;
    char *ptr = argv[1];
    if (argc == 2)
    {   
        stack[top++] = atoi(ptr);
        while(ptr)
        {
            ptr = ft_strchr(ptr, ' ');
            if (ptr == NULL)
                break ;
            if (ptr[1] ==  '+' || ptr[1] == '-' || ptr[1] == '%' || ptr[1] == '/' || ptr[1] == '*')
            {
                //Pop stack twice
                total = do_op(stack[top-1], stack[top - 2], ptr[1]);
                top -= 2;
                //Push answer to stack
                stack[top++] = total; 
            }
            //Push to stack if operand  
            stack[top++] = atoi(ptr);
        }
    }
    if (top != 1 || argc != 2)
        printf("Error\n");
    else
        printf("%d\n", total);
    return (0);
}