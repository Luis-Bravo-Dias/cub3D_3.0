/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:03:46 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/14 11:53:23 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_array(char *str)
{
	if (str && *str)
		free(str);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free_array(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

int	msg_error(char *message)
{
	ft_putendl_fd(message, 2);
	return (1);
}
