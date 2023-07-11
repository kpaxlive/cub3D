/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:15:44 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:15:45 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	top_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_data.map[0][i])
	{
		if (data->map_data.map[0][i] != '1' && data->map_data.map[0][i] != '\n' \
		&& data->map_data.map[0][i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	bottom_wall(t_data *data)
{
	int	i;
	int	last_letter;

	i = -1;
	last_letter = ft_strlen(data->map_data.map[array_len(data->map_data.map) \
	- 1]) - 1;
	while (++i < last_letter)
	{
		if (data->map_data.map[array_len(data->map_data.map) - 1][i] != '1' \
		&& data->map_data.map[array_len(data->map_data.map) - 1][i] != '\n' \
		&& data->map_data.map[array_len(data->map_data.map) - 1][i] != '\0' \
		&& data->map_data.map[array_len(data->map_data.map) - 1][i] != ' ')
			return (-1);
	}
	return (0);
}

int	left_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_data.map[i])
	{
		if (data->map_data.map[i][0] == '0')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_multi_map(t_data *data, char **lines)
{
	int		flag;
	int		i;
	char	*tmp;

	i = 0;
	flag = 0;
	while (lines[i])
	{
		tmp = ft_strdup(ft_is_space(lines[i]));
		flag = control(tmp, flag, data, i);
		if (flag == 3)
			return (-1);
		free(tmp);
		i++;
	}
	if (flag == 1)
	{
		data->map_data.map_end = i -1;
	}
	return (0);
}

void	forward_func(double distance, t_data *data,
		t_ray ray_data, char c)
{
	t_location	wall_loc;

	wall_loc = ray_data.wall_location;
	if (data->map_data.map[wall_loc.y][wall_loc.x] == 'D')
	{
		if (c == 'e')
			draw_door_e(data->dray, distance, data, ray_data);
		else if (c == 'n')
			draw_door_n(data->dray, distance, data, ray_data);
		else if (c == 'w')
			draw_door_w(data->dray, distance, data, ray_data);
		else if (c == 's')
			draw_door_s(data->dray, distance, data, ray_data);
	}
	else
	{
		if (c == 'e')
			draw_wall_e_img(data->dray, distance, data, ray_data);
		else if (c == 'n')
			draw_wall_n_img(data->dray, distance, data, ray_data);
		else if (c == 'w')
			draw_wall_w_img(data->dray, distance, data, ray_data);
		else if (c == 's')
			draw_wall_s_img(data->dray, distance, data, ray_data);
	}
}
