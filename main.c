/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:14:46 by dayan             #+#    #+#             */
/*   Updated: 2023/05/06 16:14:47 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_set_map_in(t_data *data, int i, int j)
{
	while (i <= data->map_data.map_end - data->map_data.map_start)
	{
		data->map_data.int_map[i] = (int *)ft_calloc(longest_line(data),
				sizeof(int));
		while (j < longest_line(data) && data->map_data.map[i][j])
		{
			if (data->map_data.map[i][j] == '\n')
				break ;
			if (data->map_data.map[i][j] == 32)
				data->map_data.map[i][j] = '1';
			if (init_direction(data, i, j) == -1)
				return (map | int_map);
			if (data->map_data.map[i][j] == 'D')
				data->map_data.int_map[i][j] = 3;
			else
				data->map_data.int_map[i][j] = data->map_data.map[i][j] - 48;
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	ft_set_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map_data.int_map = (int **)ft_calloc(array_len(data->map_data.map),
			sizeof(int *));
	return (ft_set_map_in(data, i, j));
}

int	ft_exit(t_data *data)
{
	free_func(data, map | xpm);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		init_var(&data, av[1]);
		if (error_check(&data, av[1]) == -1)
			return (error(1));
		init_xpm(&data);
		init_color(&data);
		render_window(&data);
		mlx_hook(data.mlx_win, 2, 1, key_press_func, &data);
		mlx_hook(data.mlx_win, 17, 0, ft_exit, &data);
		mlx_loop(data.mlx);
	}
	else
		return (error(1));
	return (0);
}
