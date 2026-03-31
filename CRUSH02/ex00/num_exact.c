/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_exact.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpagano <lpagano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:41:31 by lpagano           #+#    #+#             */
/*   Updated: 2026/03/29 19:44:51 by lpagano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "util.h"

void	ft_print_dict(struct s_dict_node *node, char *num, char is_not_last)
{
	int	i;

	i = 0;
	if (!ft_strcmp(num, node->key))
	{
		while (node->value[i] != '\0')
			write(1, &node->value[i++], 1);
		if (is_not_last)
			write(1, " ", 1);
	}
	else
	{
		if (node->next != NULL)
			ft_print_dict(node->next, num, is_not_last);
		else
			write(1, "Dict Error\n", 11);
	}
}

void	print_two_digits(struct s_dict_node *node, char *num, char is_not_last)
{
	char	second_digit[2];
	char	str_num[3];

	if (num[0] == '0' && num[1] == '0')
		return ;
	second_digit[0] = '0';
	second_digit[1] = '\0';
	str_num[0] = num[0];
	str_num[1] = num[1];
	str_num[2] = '\0';
	if (str_num[0] != '1' && str_num[1])
	{
		second_digit[0] = str_num[1];
		str_num[1] = '0';
	}
	if (str_num[0] != '0')
	{
		if (!is_not_last)
			ft_print_dict(node, str_num, second_digit[0] != '0');
		else
			ft_print_dict(node, str_num, 1);
	}
	if (second_digit[0] != '0')
		ft_print_dict(node, second_digit, is_not_last);
}
