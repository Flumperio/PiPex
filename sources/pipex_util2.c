/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:11:05 by jcsantos          #+#    #+#             */
/*   Updated: 2021/09/13 17:18:34 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			cnt;
	unsigned int	ft_len;

	cnt = 0;
	if (s == NULL)
		return (NULL);
	str = ft_calloc(sizeof(*s), (len + 1));
	if (!str)
		return (NULL);
	ft_len = (unsigned int)(ft_strlen(s));
	while (cnt < len && start < ft_len)
	{
		str[cnt] = s[cnt + start];
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}

static	int	count_word(char const *str, char chr)
{
	int		swtch;
	int		cnt;

	swtch = 0;
	cnt = 0;
	while (*str != 0)
	{
		if (swtch == 1 && *str == chr)
			swtch = 0;
		if (swtch == 0 && *str != chr)
		{
			swtch = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

int	cnt_pnt_yes(int *cnt_pnt, const char *s, char c)
{
	int	cnt_tmp;

	cnt_tmp = *cnt_pnt;
	while (s[cnt_tmp] == c && s[cnt_tmp] != 0)
		cnt_tmp++;
	return (cnt_tmp);
}

int	cnt_pnt_no(int *cnt_pnt, const char *s, char c)
{
	int	cnt_tmp;

	cnt_tmp = *cnt_pnt;
	while (s[cnt_tmp] != c && s[cnt_tmp] != 0)
		cnt_tmp++;
	return (cnt_tmp);
}

char	**ft_split(char const *s, char c)
{
	int		split_num;
	char	**split_array;
	int		start;
	int		cnt_pnt;
	int		cnt_array;

	cnt_pnt = 0;
	cnt_array = -1;
	if (!s || !c)
		return (NULL);
	split_num = count_word(s, c);
	split_array = (char **)ft_calloc(sizeof(char *), split_num + 1);
	if (!split_array)
		return (NULL);
	while (++cnt_array < split_num)
	{
		cnt_pnt = cnt_pnt_yes(&cnt_pnt, s, c);
		start = cnt_pnt;
		cnt_pnt = cnt_pnt_no(&cnt_pnt, s, c);
		split_array[cnt_array] = ft_substr(s, start, cnt_pnt - start);
		cnt_pnt++;
	}
	split_array[cnt_array] = 0;
	return (split_array);
}
