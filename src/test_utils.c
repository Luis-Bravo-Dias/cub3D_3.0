/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:11:39 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/02 17:11:40 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	printf("  0123456789abcdefghijklmnopqrstuvwxyz\n");
	while (matrix[i])
	{
		printf("%x:%s\n", i, matrix[i]);
		i++;
	}
}
