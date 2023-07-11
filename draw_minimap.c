/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:35:53 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:35:55 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_around_door(t_data *data, int x, int y)
{
	if ((x + 1 == (int)data->player.pos.x && y == (int)data->player.pos.y) \
	|| (x == (int)data->player.pos.x && y == (int)data->player.pos.y) \
	|| (x - 1 == (int)data->player.pos.x && y == (int)data->player.pos.y) \
	|| (x + 1 == (int)data->player.pos.x && y + 1 == (int)data->player.pos.y) \
	|| (x + 1 == (int)data->player.pos.x && y + 1 == (int)data->player.pos.y) \
	|| (x + 1 == (int)data->player.pos.x && y - 1 == (int)data->player.pos.y) \
	|| (x == (int)data->player.pos.x && y + 1 == (int)data->player.pos.y) \
	|| (x == (int)data->player.pos.x && y - 1 == (int)data->player.pos.y))
		data->map_data.int_map[y][x] = 0;
	else
		data->map_data.int_map[y][x] = 20;
}

void	check_door(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
			if (data->map_data.map[i][j] == 'D')
				check_around_door(data, j, i);
	}
}

void	draw_square(t_imgdata *img, int x_y[2], int size, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_my_put_pixel(img, x_y[0] + i, x_y[1] + j, color);
	}	
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (data->map_data.map[++x])
	{
		y = -1;
		while (data->map_data.map[x][++y])
		{
			if (data->map_data.map[x][y] == '1')
				draw_square(&data->img, (int [2]){y * 8, x * 8}, 8, 16711680);
			else if (data->map_data.map[x][y] == 'D')
				draw_square(&data->img, (int [2]){y * 8, x * 8}, 8, 32768);
		}
	}
	draw_square(&data->img, (int [2]){data->player.pos.x * 8 - 3,
		data->player.pos.y * 8 - 3}, 6, 3093151);
}

int	draw_walls_forwarded(t_data *data, t_ray *ray_data, double d, char c)
{
	t_location	wall_loc;

	wall_loc = ray_data[data->dray].wall_location;
	if (data->map_data.map[wall_loc.y][wall_loc.x] == 'D')
	{
		if (c == 'e')
			return (draw_door_e(data->dray, d, data, ray_data[data->dray]));
		else if (c == 'n')
			return (draw_door_n(data->dray, d, data, ray_data[data->dray]));
		else if (c == 'w')
			return (draw_door_w(data->dray, d, data, ray_data[data->dray]));
		else
			return (draw_door_s(data->dray, d, data, ray_data[data->dray]));
	}
	else
	{
		if (c == 'e')
			return (draw_wall_e_img(data->dray, d, data, ray_data[data->dray]));
		else if (c == 'n')
			return (draw_wall_n_img(data->dray, d, data, ray_data[data->dray]));
		else if (c == 'w')
			return (draw_wall_w_img(data->dray, d, data, ray_data[data->dray]));
		else
			return (draw_wall_s_img(data->dray, d, data, ray_data[data->dray]));
	}
}
