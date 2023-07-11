/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:49:59 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/05/06 16:13:43 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_wall_n_img(int angle, double distance, t_data *data,
	t_ray ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.x
						- floor(ray_data.for_wall.x)) * 64), ((i - start) * 64)
				/ height, 0);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_wall_e_img(int angle, double distance, t_data *data,
		t_ray ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.y
						- floor(ray_data.for_wall.y)) * 64), ((i - start) * 64)
				/ height, 1);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_wall_w_img(int angle, double distance, t_data *data,
		t_ray ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.y
						- floor(ray_data.for_wall.y)) * 64), ((i - start) * 64)
				/ height, 2);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_wall_s_img(int angle, double distance, t_data *data,
		t_ray ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.x
						- floor(ray_data.for_wall.x)) * 64), ((i - start) * 64)
				/ height, 3);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_walls(t_data *data, t_ray *ray_data, double dist)
{
	t_location	last_loc;
	t_location	wall_loc;

	last_loc = ray_data[data->dray].last_location;
	if (last_loc.x == wall_loc.x + 1 && last_loc.y == wall_loc.y)
		return (draw_walls_forwarded(data, ray_data, dist, 'e'));
	else if (last_loc.x == wall_loc.x && last_loc.y + 1 == wall_loc.y)
		return (draw_walls_forwarded(data, ray_data, dist, 'n'));
	else if (last_loc.x + 1 == wall_loc.x && last_loc.y == wall_loc.y)
		return (draw_walls_forwarded(data, ray_data, dist, 'w'));
	else if (last_loc.x == wall_loc.x && last_loc.y == wall_loc.y + 1)
		return (draw_walls_forwarded(data, ray_data, dist, 's'));
	return (1);
}
