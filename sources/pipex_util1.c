/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:11:16 by jcsantos          #+#    #+#             */
/*   Updated: 2021/09/09 17:25:18 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*ft_bzero(void *bzero_string, unsigned int num_char)
{
	unsigned char	*temp_pointer;

	temp_pointer = (unsigned char *)bzero_string;
	while (num_char-- > 0)
		*temp_pointer++ = 0;
	return (bzero_string);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*trgt;

	trgt = malloc(num * size);
	if (!trgt)
		return (NULL);
	ft_bzero(trgt, (num * size));
	return (trgt);
}

void	ft_msgerror(char *str, int error)
{
	printf("Error\n%s\n", str);
	exit(error);
}

void	ft_freematrice(char ***matrice)
{
	int		i;

	i = -1;
	while ((*matrice)[++i])
		free((*matrice)[i]);
	free(*matrice);
}

void	ft_free_struct(t_pip *pip)
{
	if (!pip)
		return ;
	free(pip);
	pip = NULL;
}
