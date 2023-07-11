/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:13:24 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:13:25 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_door_n(int angle, double distance, t_data *data,
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
				/ height, 4);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_door_e(int angle, double distance, t_data *data,
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
				/ height, 4);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_door_w(int angle, double distance, t_data *data,
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
				/ height, 4);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_door_s(int angle, double distance, t_data *data,
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
				/ height, 4);
		ft_my_put_pixel(&data->img, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}
