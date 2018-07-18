#include <unistd.h>
#include <stdio.h>      //REMOVE ME
#include <stdlib.h>      //REMOVE ME

void    ft_putchar(int c)
{
    write(1, &c, 1);
}

int		is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 2))
	{
		if (!(nb % i))
			return (0);
		else
			i += 1;
	}
	return (1);
}

int     main(int argc, char **argv)
{
    int primes_sum = 0;
    int k = 0;
    if (argc !=2 || argv[1][0] == '-')
    {
        ft_putchar('\n');
    }
    while (k <= atoi(argv[1]))
    {
        if (is_prime(k))
            primes_sum += k;
        k++;
    }
    printf("%d", primes_sum);
    return (0);
}