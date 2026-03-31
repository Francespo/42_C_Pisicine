/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpagano <lpagano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:28:40 by lpagano           #+#    #+#             */
/*   Updated: 2026/03/29 20:12:57 by lpagano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	read_until(int f1, int f2, char sep, char **result)
{
	char	*buf;
	char	c;
	int		len;
	int		ret;

	len = 0;
	c = '0';
	while (c != sep)
	{
		ret = read(f1, &c, 1);
		if (ret <= 0)
			return (0);
		len++;
	}
	if (c != sep)
		return (-1);
	buf = malloc(len);
	ret = read(f2, buf, len);
	buf[ret - 1] = '\0';
	*result = buf;
	return (ret);
}

char	*ft_trim(char *str)
{
	int		i;
	int		spaces_start;
	int		spaces_end;
	char	*result;

	i = -1;
	spaces_start = -1;
	spaces_end = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\n')
		{
			if (spaces_start < 0)
				spaces_start = i;
			spaces_end = i;
		}
	}
	result = malloc(spaces_end - spaces_start + 1);
	i = -1;
	while (++i < (spaces_end - spaces_start + 1))
		result[i] = str[spaces_start + i];
	result[i] = '\0';
	free(str);
	return (result);
}
