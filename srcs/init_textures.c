/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:58:59 by bruno             #+#    #+#             */
/*   Updated: 2024/05/24 17:24:03 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	map_init(t_vars *vars)
{
	vars->map->bomb.img = NULL;
	vars->map->collectible.img = NULL;
	vars->map->death.img = NULL;
	vars->map->exit.img = NULL;
	vars->map->floor.img = NULL;
	vars->map->wall.img = NULL;
	if (!player_init(vars))
		return (false);
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

bool	wall_init(t_vars *vars)
{
	if (!access("./includes/assets/wall.xpm", F_OK))
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
	vars->map->wall.img = NULL;
	return (ft_putendl(INV_WALL), false);
}

bool	floor_init(t_vars *vars)
{
	if (!access("./includes/assets/floor.xpm", F_OK))
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
	vars->map->floor.img = NULL;
	return (ft_putendl(INV_FLOOR), false);
}

bool	collectible_init(t_vars *vars)
{
	if (!access("./includes/assets/collectible.xpm", F_OK))
	{
		vars->map->collectible.img = mlx_xpm_file_to_image(vars->mlx,
				"./includes/assets/collectible.xpm",
				&vars->map->collectible.width,
				&vars->map->collectible.height);
		if (!vars->map->collectible.img)
			return (ft_putendl(INV_COLLECTIBLE), false);
		vars->map->collectible.addr = mlx_get_data_addr(
				vars->map->collectible.img,
				&vars->map->collectible.bits_per_pixel,
				&vars->map->collectible.line_len,
				&vars->map->collectible.endian);
		return (true);
	}
	vars->map->collectible.img = NULL;
	return (ft_putendl(INV_COLLECTIBLE), false);
}

bool	bomb_init(t_vars *vars)
{
	if (!access("./includes/assets/bomb.xpm", F_OK))
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
	vars->map->bomb.img = NULL;
	return (ft_putendl(INV_BOMB), false);
}
