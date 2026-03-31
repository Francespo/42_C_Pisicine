/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:05:34 by fesposit          #+#    #+#             */
/*   Updated: 2026/03/31 17:05:39 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns the position in which the character appears in the base.
// returns -1 if it's not in the base.
int	position_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_alpha_num(char c)
{
	int	is_lcalpha;
	int	is_ucalpha;
	int	is_number;

	is_lcalpha = c >= 'a' && c <= 'z';
	is_ucalpha = c >= 'A' && c <= 'Z';
	is_number = c >= '0' && c <= '9';
	return (is_lcalpha || is_ucalpha || is_number);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
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

int	ft_atoi_base(char *str, char *base)
{
	int				num;
	int				sign;
	unsigned int	base_len;
	int				i;
	int				pos_in_base;

	num = 0;
	sign = 1;
	base_len = check_base(base);
	i = 0;
	if (!base_len)
		return (0);
	while (str[i] == ' ')
		i++;
	while (is_sign(str[i]))
		if (str[i++] == '-')
			sign *= -1;
	pos_in_base = position_in_base(str[i], base);
	while (pos_in_base != -1)
	{
		num *= base_len;
		num += pos_in_base;
		pos_in_base = position_in_base(str[++i], base);
	}
	return (num * sign);
}
