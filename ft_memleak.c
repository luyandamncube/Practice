/*
	PRACTICE FOR MEMORY LEAKS
		"Read in memory chunks and supress leaks using pointers & realloc"
		- Still have possible leaks from using a buffer & reallocating mem sizes (._."
 */

//#include "C:\Users\shaniceg\Documents\libc\libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		k;

	k = 0;
	while (src[k] && k < n)
	{
		dst[k] = src[k];
		k++;
	}
	while (k < n)
	{
		dst[k] = '\0';
		k++;
	}
	return (dst);
}


void	ft_bzero(void *s, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		*(unsigned char *)(s + k) = 0;
		k++;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		k;
	char		*mem;

	k = 0;
	if (NULL == (mem = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s)
	{
		while (k < len)
		{
			mem[k] = s[start + k];
			k++;
		}
	}
	mem[k] = '\0';
	return (mem);
}
//	return pos of FIRST newline character
int		ft_nlpos(size_t start, char * str)
{
    unsigned int    k;

	k = start;
	if (!str)
		return (!str);
	while (str[k] != '\n' && str[k])
		k++;
	return (k+1);
}

int 	ft_strlen(char * str)
{
	int		k;

	k = 0;
	while (*str++)
		k++;
	return (k);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	k;

	k = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (k < n)
	{
		*(unsigned char *)(dst + k) = *(unsigned char *)(src + k);
		k++;
	}
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void *mem;

	if (NULL == (mem = malloc(size)))
		return (NULL);
	ft_memcpy(mem, ptr, size);
	ft_memdel(&ptr);					//Needs to be ptr address
	return (mem);
}

int		main()
{
	char	test[] = "this is a \ntest string\n";
	char 	*buf;
	int		pos;
	size_t	index = 0;
	int 	bufsize = 32;
	int		k = 0;
	int 	len = ft_strlen(test);

	buf = malloc (bufsize);
	
	while (index < len)
	{
		pos = ft_nlpos(index, test);
		buf = ft_realloc(buf, pos);
		ft_bzero(buf,pos);
		//buf = ft_strsub(test, index, pos);
		buf = ft_strncpy(buf,test+index,pos-1);
		printf("Memory %d content: %s\n", k, buf);
		index += pos;
		k++;
	}
	return (0);
}
