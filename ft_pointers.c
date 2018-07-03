/*
	PRACTICE FOR POINTERS
		"Testing output with pointer manipulations"
 */
#include <stdio.h>
#include <stdlib.h>

char    *ft_strchr(const char *s, int c)
{
	/* man page req:
	   -locate char in string
	   -returns a pointer to FIRST occurence of the character in the string
	   -basically returns everything after and including the character
	   HOW TO RETURN A POINTER TO A SPECIFIC LOCATION OF AN ARRAY
	   1 assign a pointer to the array in memory
	   2 increment the pointer to the position you need 
	   */
	int			k;
	int 		m;

	k = 0;
	m = 0;
	while (s[k])
		k++;
	if (s[k] == (char)c)
		return ((char*)&s[k]);					//instead of returning (s) from s++ 
	k++;
	while (m < k)
	{
		if (s[m] == (char)c)
			return ((char*)&s[m]);
		m++;
	}
	return (NULL);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int k;

	k = 0;
	while (src[k])
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	return (dst);
}	

int     main()
{
    char *pos;
    char test[24] = "this is a test string!\n";
    char *buf;

    buf = malloc (50);

		if ((pos = ft_strchr(test, 'i')))
		{
			ft_strcpy(buf, pos + 1);
			*pos = 0;
		}
    printf("OUT: %s", buf);
    return (0);
}


