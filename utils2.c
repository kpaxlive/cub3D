/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:15:39 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:15:39 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(int ret)
{
	printf("Error\n");
	return (ret);
}

void	free_func(t_data *data, int control_data)
{
	if (control_data & xpm)
		ft_xpm_cleaner(data);
	if (control_data & int_map)
		free_int(data, data->map_data.int_map);
	if (control_data & map)
		array_cleaner((void **)data->map_data.map);
}

int	array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	check_wall_xpm(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (i < 5)
	{
		fd = open(data->map_data.xpm_dir[i], O_RDONLY);
		if (fd == -1)
			return (xpm);
		close(fd);
		i++;
	}
	return (0);
}

t_control	ft_recontrol(t_control control)
{
	t_control	ret;

	ret = (t_control){
		.read_file = control.read_file * (control.read_file != -1),
		.check_wall = control.check_wall * (control.check_wall != -1),
		.get_map = control.get_map * (control.get_map != -1),
		.set_map = control.set_map * (control.set_map != -1),
		.player_pos = control.player_pos};
	return (ret);
}
