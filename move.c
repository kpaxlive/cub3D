/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:15:05 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:15:05 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_left(t_data *data)
{
	t_vector	w_check;
	t_vector	move;

	move = (t_vector){.y = 0.3 * cos(deg2rad(data->player.direction)),
		.x = 0.3 * sin(deg2rad(data->player.direction))};
	w_check.y = data->player.pos.y - move.y;
	w_check.x = data->player.pos.x + move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1
			|| data->map_data.int_map[(int)(w_check.y
			+ move.y)][(int)(w_check.x - move.x)] == 1)
		return ;
	data->player.pos.y -= move.y;
	data->player.pos.x += move.x;
}

void	ft_right(t_data *data)
{
	t_vector	w_check;
	t_vector	move;

	move = (t_vector){.y = 0.3 * cos(deg2rad(data->player.direction)),
		.x = 0.3 * sin(deg2rad(data->player.direction))};
	w_check.y = data->player.pos.y + move.y;
	w_check.x = data->player.pos.x - move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1
			|| data->map_data.int_map[(int)(w_check.y
			- move.y)][(int)(w_check.x + move.x)] == 1)
		return ;
	data->player.pos.y += move.y;
	data->player.pos.x -= move.x;
}

void	ft_backward(t_data *data)
{
	t_vector	w_check;
	t_vector	move;

	move = (t_vector){0.3 * cos(deg2rad(data->player.direction)), 0.3
		* sin(deg2rad(-data->player.direction))};
	w_check.y = data->player.pos.y + move.y;
	w_check.x = data->player.pos.x - move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1
			|| data->map_data.int_map[(int)(w_check.y
			- move.y)][(int)(w_check.x + move.x)] == 1)
		return ;
	data->player.pos.y += move.y;
	data->player.pos.x -= move.x;
}

void	ft_forward(t_data *data)
{
	t_vector	w_check;
	t_vector	move;

	move = (t_vector){0.3 * cos(deg2rad(data->player.direction)), 0.3
		* sin(deg2rad(-data->player.direction))};
	w_check.y = data->player.pos.y - move.y;
	w_check.x = data->player.pos.x + move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 20
		|| data->map_data.int_map[(int)(w_check.y
			+ move.y)][(int)(w_check.x - move.x)] == 20)
	{
		data->player.pos.y -= move.y;
		data->player.pos.x += move.x;
		return ;
	}
	if ((data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1
		|| data->map_data.int_map[(int)(w_check.y
			+ move.y)][(int)(w_check.x - move.x)] == 1)
			|| (data->dist_l <= 20. && data->dist_r <= 20.))
		return ;
	data->player.pos.y -= move.y;
	data->player.pos.x += move.x;
}

void	ft_move(int keycode, t_data *data)
{
	if (keycode == Key_W)
		ft_forward(data);
	else if (keycode == Key_S)
		ft_backward(data);
	else if (keycode == Key_A)
		ft_left(data);
	else if (keycode == Key_D)
		ft_right(data);
	check_door(data);
}
