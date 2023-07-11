/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:55:39 by fayan             #+#    #+#             */
/*   Updated: 2022/02/03 17:55:42 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*source;
	char		*destination;
	size_t		i;

	destination = (char *)dest;
	source = (char *) src;
	if (!destination && !source)
		return (0);
	i = 0;
	if (source < destination)
	{
		while (n--)
			*(destination + n) = *(source + n);
	}
	else
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
