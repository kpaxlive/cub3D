/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:54:07 by dayan             #+#    #+#             */
/*   Updated: 2023/05/12 16:54:08 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_int(t_data *data, int **arr)
{
	int	i;
	int	len_array;

	if (!arr)
		return ;
	len_array = array_len(data->map_data.map);
	i = -1;
	while (++i < len_array)
		free(arr[i]);
	free(arr);
}

int	check_player_exists(t_data *data)
{
	int	i;
	int	j;
	int	exists;

	i = -1;
	exists = 0;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
		{
			if (data->map_data.map[i][j] == 'N' || \
			data->map_data.map[i][j] == 'S' || \
			data->map_data.map[i][j] == 'E' || data->map_data.map[i][j] == 'W')
				exists = 1;
		}
	}
	if (exists == 0)
		return (-1);
	return (0);
}

int	ft_check_rgb_2(char *s)
{
	char	**line;
	int		len;

	s = ft_is_space(s);
	if (!ft_strncmp(&s[0], "1", 1))
		return (0);
	line = ft_split(s, ' ');
	len = ft_strlen(line[0]);
	if (ft_strncmp(line[0], "F", len) && ft_strncmp(line[0], "C", len) \
	&& ft_strncmp(line[0], "NO", len) && ft_strncmp(line[0], "SO", len) \
	&& ft_strncmp(line[0], "EA", len) && ft_strncmp(line[0], "WE", len) \
	&& ft_strncmp(line[0], "DO", len) && ft_strncmp(line[0], "\n", len))
	{
		array_cleaner((void **)line);
		return (-1);
	}
	array_cleaner((void **)line);
	return (0);
}
