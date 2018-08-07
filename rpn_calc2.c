#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
    rpn_calc using malloc
*/
char		**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 256)))
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i += 1;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			split[k][j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i += 1;
		split[k][j] = '\0';
		k += 1;
	}
	split[k] = NULL;
	return (split);
}

int     do_op(int a, int b, int op)
{
    if (op == '+')
        return (a + b);
    if (op == '-')
        return (a - b);
    if (op == '/')
        return (a / b);
    if (op == '%')
        return (a % b);
    if (op == '*')
        return (a * b);
}

int     main(int argc, char **argv)
{
    int total = 0;
    char **q = ft_split(argv[1]);
    if (argc == 2)
    {   
        int stack[4096];
        int temp = 0;
        int top = 0;
        int k = 0;
        while(q[k])
        {
            if (q[k][0] ==  '+' || q[k][0] == '-' || q[k][0] == '%' || q[k][0] == '/' || q[k][0] == '*')
            {
                //Pop stack twice
                temp = do_op(stack[--top], stack[--top], q[k][0]);
                //Push answer to stack
                stack[top++] = temp; 
            }
            else
                //Push to stack if operand
                stack[top++] = atoi(q[k]);
            k++;
    }
    if (top > 1)
        printf("Error");
    else
        printf("%d", temp);
    }
    printf("\n");
    return (0);
}