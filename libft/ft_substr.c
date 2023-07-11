/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:21:29 by fayan             #+#    #+#             */
/*   Updated: 2022/02/03 18:22:06 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	int		lenght;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	lenght = 0;
	if (len > ft_strlen(s) - start)
		lenght = (ft_strlen(s) - start);
	else if (len <= ft_strlen(s) - start)
		lenght = len;
	sub = (char *) malloc ((lenght + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i] && i < lenght)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
