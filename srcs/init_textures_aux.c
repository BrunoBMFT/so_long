/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:58:59 by bruno             #+#    #+#             */
/*   Updated: 2024/05/23 00:13:56 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	exit_init(t_vars *vars)
{
	if (!access("./includes/assets/exit.xpm", F_OK))
	{
		vars->map->exit.img = mlx_xpm_file_to_image(vars->mlx,
				"./includes/assets/exit.xpm", &vars->map->exit.width,
				&vars->map->exit.height);
		if (!vars->map->exit.img)
			return (ft_putendl(INV_EXIT), false);
		vars->map->exit.addr = mlx_get_data_addr(vars->map->exit.img,
				&vars->map->exit.bits_per_pixel, &vars->map->exit.line_len,
				&vars->map->exit.endian);
		return (true);
	}
	vars->map->exit.img = NULL;
	return (ft_putendl(INV_EXIT), false);
}

bool	death_init(t_vars *vars)
{
	if (!access("./includes/assets/death.xpm", F_OK))
	{
		vars->map->death.img = mlx_xpm_file_to_image(vars->mlx,
				"./includes/assets/death.xpm", &vars->map->death.width,
				&vars->map->death.height);
		if (!vars->map->death.img)
			return (ft_putendl(INV_DEATH), false);
		vars->map->death.addr = mlx_get_data_addr(vars->map->death.img,
				&vars->map->death.bits_per_pixel, &vars->map->death.line_len,
				&vars->map->death.endian);
		return (true);
	}
	vars->map->death.img = NULL;
	return (ft_putendl(INV_DEATH), false);
}
