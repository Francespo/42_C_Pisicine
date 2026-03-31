/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpagano <lpagano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:35:27 by lpagano           #+#    #+#             */
/*   Updated: 2026/03/29 19:52:29 by lpagano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "util.h"

int	check_suffix(char *key)
{
	int	suffix_len;

	suffix_len = -1;
	if (*key++ == '1')
	{
		suffix_len = 0;
		while (*key)
		{
			if (*key++ != '0')
			{
				suffix_len = -1;
				break ;
			}
			suffix_len++;
		}
	}
	return (suffix_len);
}

int	find_longest_suffix(struct s_dict_node *dict, int max_len)
{
	int		suffix_len;
	int		result;

	result = -1;
	while (dict)
	{
		suffix_len = check_suffix(dict->key);
		if (suffix_len > result && suffix_len < max_len)
			result = suffix_len;
		dict = dict->next;
	}
	return (result);
}

void	print_suffix(struct s_dict_node *dict, char *cursor, int len)
{
	int		suffix_len;

	while (dict)
	{
		suffix_len = check_suffix(dict->key);
		if (suffix_len == len)
		{
			write(1, dict->value, ft_strlen(dict->value));
			while (*cursor == '0')
				cursor++;
			if (*cursor != 0)
				write(1, " ", 1);
			return ;
		}
		dict = dict->next;
	}
}

void	print_num_internal(struct s_dict_node *dict, char *cursor, int max_len)
{
	int		suffix_len;
	char	digit[2];

	if (max_len > 2)
	{
		suffix_len = find_longest_suffix(dict, max_len);
		print_num(dict, cursor, max_len - suffix_len);
		print_suffix(dict, cursor + max_len - suffix_len, suffix_len);
		print_num(dict, cursor + max_len - suffix_len, suffix_len);
	}
	else if (max_len == 2)
		print_two_digits(dict, cursor, cursor[2]);
	else if (max_len == 1 && cursor[0] != '0')
	{
		digit[0] = cursor[0];
		digit[1] = '\0';
		ft_print_dict(dict, digit, cursor[1]);
	}
}

void	print_num(struct s_dict_node *dict, char *cursor, int max_len)
{
	int		nb_len;

	while (*cursor && *cursor == '0')
	{
		cursor++;
		max_len--;
	}
	nb_len = ft_strlen(cursor);
	if (max_len >= 0 && nb_len > max_len)
		nb_len = max_len;
	print_num_internal(dict, cursor, nb_len);
}
