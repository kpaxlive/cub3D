/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:21:13 by fayan             #+#    #+#             */
/*   Updated: 2022/02/03 18:21:17 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	ondenbak(char *s1, char const *set)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			j++;
			i = -1;
		}
		i++;
	}
	return (j);
}

static int	arkadanbak(char *s1, char const *set)
{
	int		l;
	int		uzunluks1;

	l = 0;
	uzunluks1 = ft_strlen(s1);
	while (set[l])
	{
		if (set[l] == s1[uzunluks1 - 1])
		{
			uzunluks1--;
			l = -1;
		}
		l++;
	}
	return (uzunluks1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		uzunluks1;
	char	*s2;
	char	*s1cpy;

	if (!s1)
		return (0);
	s1cpy = (char *)s1;
	s1cpy += ondenbak(s1cpy, set);
	uzunluks1 = arkadanbak(s1cpy, set);
	if (uzunluks1 < 0)
		return (ft_strdup(""));
	s2 = (char *) malloc (uzunluks1 + 1);
	if (!s2)
		return (0);
	i = 0;
	while (uzunluks1--)
	{	
		s2[i] = s1cpy[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
