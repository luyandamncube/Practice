/*
	PRACTICE FOR LINKED LISTS
		"Produce a linked list which holds the characters h-a-t"
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct          s_list
{
    void				*content;
    size_t				content_size;
    struct s_list		*next;
}						t_list;

t_list		*ft_lstnew(void *content, size_t content_size)
{
    t_list		*new;

    if (NULL == (new = malloc(sizeof(t_list))))
		return (NULL);
	new->content_size = content_size;
	new->next = NULL;
	if (NULL == (new->content = malloc(sizeof(size_t)*content_size)))
		return (NULL);
	new->content = memcpy(new->content, content, content_size);
	return (new);    
}

void    	ft_lstadd(t_list **exist, t_list *new)
{
	if (*exist)
	{
		new->next = *exist;
		*exist = new;
	}
}

void		ft_lstprint(t_list *exist)
{
	int		k;

	k = 1;
	if (exist)
	{
		while (exist)
		{
			printf("element %d : %s\n", k, exist->content);
			exist = exist->next;
			k++;
		}
	}
}

int			main()
{
	//Add the elements h-a-t
	t_list		*head;
	t_list      *first;
	t_list      *second;
	char *t = {"t"};
	char *a = {"af"};	
	char *h = {"h"};		
	//Add links
	head = ft_lstnew(t,1);
	first = ft_lstnew(a,2);
	second = ft_lstnew(h,1);
	ft_lstadd(&head, first);
	ft_lstadd(&head, second);

	//print links
	ft_lstprint(head);

	return(0);
}