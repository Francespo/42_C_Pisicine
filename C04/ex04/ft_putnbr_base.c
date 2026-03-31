/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:26:41 by fesposit          #+#    #+#             */
/*   Updated: 2026/03/31 10:22:13 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha_num(char c)
{
	int	is_lcalpha;
	int	is_ucalpha;
	int	is_num;

	is_lcalpha = c >= 'a' && c <= 'z';
	is_ucalpha = c >= 'A' && c <= 'Z';
	is_num = c >= '0' && c <= '9';
	return (is_lcalpha || is_ucalpha || is_num);
}

// returns 0 if the base is invalid, the len of the base otherwise
unsigned int	check_base(char *base)
{
	unsigned int	len;
	unsigned char	i;
	char			chars[127];

	len = 0;
	i = 0;
	while (i < 127)
	{
		chars[i] = 0;
		i++;
	}
	while (base[len])
	{
		if (chars[(unsigned char)base[len]] == 1)
			return (0);
		if (!is_alpha_num(base[len]))
			return (0);
		chars[(unsigned char)base[len]] = 1;
		len++;
	}
	if (len < 2)
		return (0);
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char			tw;
	unsigned int	base_len;
	unsigned int	unbr;

	base_len = check_base(base);
	if (!base_len)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		unbr = (unsigned int)(-1 * nbr);
	}
	else
		unbr = nbr;
	if (unbr < base_len)
		tw = base[unbr];
	else
	{
		ft_putnbr_base(unbr / base_len, base);
		tw = base[unbr % base_len];
	}
	write(1, &tw, 1);
}
