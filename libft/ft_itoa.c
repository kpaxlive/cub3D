/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:44:51 by fayan             #+#    #+#             */
/*   Updated: 2022/02/06 19:03:49 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static char	*strfill(char *str, int i, long nm, int sign)
{
	str[i] = '\0';
	while (i--)
	{
		str[i] = (nm % 10) + 48;
		nm /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	int			temp;
	long		nm;
	char		*str;
	int			sign;

	sign = 1;
	i = 1;
	nm = (long) n;
	if (nm < 0)
	{
		nm *= -1;
		sign *= -1;
		i++;
	}
	temp = nm;
	while (temp % 10 != temp)
	{
		temp /= 10;
		i++;
	}
	str = (char *) malloc ((i + 1) * sizeof(char));
	if (!str)
		return (0);
	return (strfill(str, i, nm, sign));
}
