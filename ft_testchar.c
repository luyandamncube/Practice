#include <stdio.h>
#include <stdlib.h>

unsigned int  ft_isalpha(int c )
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int     main()
{
    int k = -1;
    /*      ft_strrev
    char *test = "this is a test string!";
    printf("len: %d", ft_strlen(test));
    ft_strrev(test);
    */

    /*       ft_print_numbers
    ft_print_numbers();
    */
   /* firstword
    if (ft_iswhitespace(' '))
        printf("yes");
    if (ft_iswhitespace('\t'))
        printf("yes");
    if (ft_iswhitespace('\n'))
        printf("yes");
    if (!ft_iswhitespace('7'))
        printf("no"); 
    */
   while (k < 530)
   {
        if (ft_isalpha(k) == isalpha(k))
            printf("y %d", k);
        k++;
   }

    return (0);
}