/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:58:59 by bruno             #+#    #+#             */
/*   Updated: 2024/04/24 01:04:17 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	wall_init(t_vars *vars)
{
	vars->map->wall.img = mlx_xpm_file_to_image(vars->mlx,
			"./includes/assets/wall.xpm", &vars->map->wall.width,
			&vars->map->wall.height);
	if (!vars->map->wall.img)
		return (ft_putendl(INV_WALL), false);
	vars->map->wall.addr = mlx_get_data_addr(vars->map->wall.img,
			&vars->map->wall.bits_per_pixel, &vars->map->wall.line_len,
			&vars->map->wall.endian);
	return (true);
}

bool	floor_init(t_vars *vars)
{
	vars->map->floor.img = mlx_xpm_file_to_image(vars->mlx,
			"./includes/assets/floor.xpm", &vars->map->floor.width,
			&vars->map->floor.height);
	if (!vars->map->floor.img)
		return (ft_putendl(INV_FLOOR), false);
	vars->map->floor.addr = mlx_get_data_addr(vars->map->floor.img,
			&vars->map->floor.bits_per_pixel, &vars->map->floor.line_len,
			&vars->map->floor.endian);
	return (true);
}

bool	collectible_init(t_vars *vars)
{
	vars->map->collectible.img = mlx_xpm_file_to_image(vars->mlx,
			"./includes/assets/collectible.xpm", &vars->map->collectible.width,
			&vars->map->collectible.height);
	if (!vars->map->collectible.img)
		return (ft_putendl(INV_COLLECTIBLE), false);
	vars->map->collectible.addr = mlx_get_data_addr(vars->map->collectible.img,
			&vars->map->collectible.bits_per_pixel,
			&vars->map->collectible.line_len,
			&vars->map->collectible.endian);
	return (true);
}

bool	exit_init(t_vars *vars)
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

bool	bomb_init(t_vars *vars)
{
	vars->map->bomb.img = mlx_xpm_file_to_image(vars->mlx,
			"./includes/assets/bomb.xpm", &vars->map->bomb.width,
			&vars->map->bomb.height);
	if (!vars->map->bomb.img)
		return (ft_putendl(INV_BOMB), false);
	vars->map->bomb.addr = mlx_get_data_addr(vars->map->bomb.img,
			&vars->map->bomb.bits_per_pixel, &vars->map->bomb.line_len,
			&vars->map->bomb.endian);
	return (true);
}

bool	death_init(t_vars *vars)
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

bool	map_init(t_vars *vars)
{
	if (!wall_init(vars))
		return (false);
	if (!floor_init(vars))
		return (false);
	if (!collectible_init(vars))
		return (false);
	if (!exit_init(vars))
		return (false);
	if (!bomb_init(vars))
		return (false);
	if (!death_init(vars))
		return (false);
	return (true);
}