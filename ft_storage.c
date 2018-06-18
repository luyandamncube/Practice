/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 08:18:35 by lmncube           #+#    #+#             */
/*   Updated: 2018/06/18 08:58:22 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * STORAGE LOOP:
 * practice for cumalative storage loop (GNL)
 */

#include <stdio.h>

unsigned int	ft_storage(int	haystack)
{
	unsigned int	batch;
	unsigned int sorted;
	int	flag;
	int pos;
	int k;

	sorted = 0;
	flag = 0;
	pos = 16;
	k = 1;

	batch = 32;
	while (flag == 0)
	{
		if (sorted < 97)
		{
			sorted = sorted + batch;
			flag = 0;
		}
		else
		{
			sorted = sorted - batch +  pos;
			flag = 1;
			printf("Loops: %d\n", k);
			return (sorted);
		}
		k++;
	}
	return (0);
}

int		main()
{
	int storage;

	storage = ft_storage(118);
	printf("Cumalative storage: %d\n", storage);
	return (0);
}
