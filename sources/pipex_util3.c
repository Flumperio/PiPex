/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:54:30 by jcsantos          #+#    #+#             */
/*   Updated: 2021/09/13 17:18:34 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (*str++ != 0)
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	cnt;

	cnt = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_calloc(sizeof(*s1), (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[cnt] = *s1;
		cnt++;
		s1++;
	}
	while (*s2)
	{
		str[cnt] = *s2;
		cnt++;
		s2++;
	}
	str[cnt] = 0;
	return (str);
}

char	*ft_strjoin_clean(char *s1, char *s2, int clean)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(s1, s2);
	if (clean == 1 || clean == 3)
		free(s1);
	if (clean == 2 || clean == 3)
		free(s2);
	return (tmp);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	cont;
	int				strncmp;

	cont = 0;
	strncmp = 0;
	if (n == 0)
		return (0);
	while ((str1[cont] == str2[cont]) && \
		str1[cont] && str2[cont] && (cont < n - 1))
		cont++;
	strncmp = ((unsigned char)str1[cont]) - ((unsigned char)str2[cont]);
	return (strncmp);
}
