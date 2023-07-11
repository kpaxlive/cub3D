/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:14:41 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:14:41 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_func(int keycode, t_data *data)
{
	if (keycode == Key_W || keycode == Key_A || keycode == Key_S
		|| keycode == Key_D)
		ft_move(keycode, data);
	if (keycode == key_rt)
		data->player.direction += 10;
	if (keycode == key_lt)
		data->player.direction -= 10;
	if (data->player.direction >= 360)
		data->player.direction = abs((int)data->player.direction % 360);
	if (data->player.direction < 0)
		data->player.direction = 359;
	if (keycode == Key_ESC)
		ft_exit(data);
	render_window(data);
	return (0);
}
