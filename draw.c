/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:14:02 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:14:03 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_req(t_vector *start, t_data *data,
			t_vector *sin_cos, double angle)
{
	*start = (t_vector){.x = data->player.pos.x * (data->width / MAPWIDTH),
		data->player.pos.y * (data->height / MAPHEIGHT)};
	*sin_cos = (t_vector){.x = cos((angle + data->player.direction \
	- (data->player.fov / 2)) * M_PI / 180), .y = sin((angle \
	+ data->player.direction - (data->player.fov / 2)) * M_PI / 180)};
}

void	draw_ray(t_ray *ray_data, t_vector *ray,
		t_data *data, t_vector sin_cos)
{
	int	wall;

	wall = 0;
	while (!wall)
	{
		(*ray_data).last_location = (*ray_data).wall_location;
		(*ray).y += sin_cos.y;
		(*ray).x += sin_cos.x;
		(*ray_data).wall_location = (t_location){.x = (int)(*ray).x / \
		(data->width / MAPWIDTH), .y = (int)(*ray).y / (data->height / \
		MAPHEIGHT)};
		(*ray_data).for_wall = (t_vector){.x = (*ray).x / \
		(data->width / MAPWIDTH), .y = (*ray).y / (data->width / MAPWIDTH)};
		wall = data->map_data.int_map[(int)floor((*ray_data).wall_location.y)] \
		[(int)floor((*ray_data).wall_location.x)];
	}
}

t_ray	calculate_ray(t_data *data, double angle)
{
	t_ray		ray_data;
	t_vector	ray;
	t_vector	start;
	t_vector	sin_cos;

	init_req(&start, data, &sin_cos, angle);
	ray = (t_vector){.y = start.y, .x = start.x};
	ray_data.wall_location = (t_location){.x = (int)ray.x / (data->width
			/ MAPWIDTH), .y = (int)ray.y / (data->height / MAPHEIGHT)};
	draw_ray(&ray_data, &ray, data, sin_cos);
	ray_data.ray_location = (t_vector){.x = fabs(ray.x - start.x),
		.y = (ray.y - start.y)};
	return (ray_data);
}

void	ft_my_put_pixel(t_imgdata *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_len + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_my_get_pixel(t_data *data, int x, int y, int i)
{
	char	*dst;

	dst = data->xpm[i].img_ptr + (y * data->xpm[i].line_len + x
			* (data->xpm[i].bpp / 8));
	return (*(unsigned int *)dst);
}
