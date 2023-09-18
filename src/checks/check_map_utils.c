/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:41:48 by lleiria-          #+#    #+#             */
/*   Updated: 2023/04/26 09:57:31 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	abnormalities(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'N'
				&& map[j][i] != 'S' && map[j][i] != 'W' && map[j][i] != 'E'
				&& map[j][i] != ' ' && map[j][i] != '\t' && map[j][i] != '\n')
				return (1);
			else
				i++;
		}
		j++;
	}
	return (0);
}

int	extreme_lines(char **map, int line)
{
	int	i;

	i = -1;
	while (map[line][++i])
		if (map[line][i] == '0' || map[line][i] == 'N' || map[line][i] == 'S'
			|| map[line][i] == 'E' || map[line][i] == 'W')
			return (1);
	return (0);
}

int	validate(char x, int is_wall)
{
	if (is_wall == 1)
	{
		if (x != '1')
			return (1);
	}
	else
	{
		if (x == '0' || x == '1' || x == 'N' || x == 'S'
			|| x == 'E' || x == 'W')
			return (0);
		else
			return (1);
	}
	return (0);
}

int	not_solo(void)
{
	int	x;
	int	y;
	int	counter;

	y = -1;
	counter = 0;
	while (vars()->map[++y])
	{
		x = -1;
		while (vars()->map[y][++x])
		{
			if (vars()->map[y][x] == 'N' || vars()->map[y][x] == 'S'
				|| vars()->map[y][x] == 'E' || vars()->map[y][x] == 'W')
				counter++;
		}
	}
	if (counter == 1)
		return (0);
	return (1);
}

void	check_file(char *file)
{
	int	end;

	end = ft_strlen(file) - 1;
	if (file[end] != 'b' || file[end - 1] != 'u'
		|| file[end - 2] != 'c' || file[end - 3] != '.')
	{
		printf("\e[1;91mError\nInvalid file type\n\e[0m");
		exit(1);
	}
}
