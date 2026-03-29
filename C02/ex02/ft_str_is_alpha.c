/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:41:14 by fesposit          #+#    #+#             */
/*   Updated: 2026/03/20 11:15:53 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	is_lcalpha;
	int	is_ucalpha;

	i = 0;
	while (str[i] != 0)
	{
		is_lcalpha = str[i] >= 'a' && str[i] <= 'z';
		is_ucalpha = str[i] >= 'A' && str[i] <= 'Z';
		if (!is_lcalpha && !is_ucalpha)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
