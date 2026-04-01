/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:06:05 by fesposit          #+#    #+#             */
/*   Updated: 2026/04/01 13:06:11 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sqrt_binary_search(int n)
{
	int				a;
	int				b;
	int				guess;
	unsigned long	square;

	a = 0;
	b = n;
	while (a <= b)
	{
		guess = (a + b) / 2;
		square = (unsigned long)guess * guess;
		if (square < n)
			a = guess + 1;
		else if (square > n)
			b = guess - 1;
		else
			return (guess);
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	return (sqrt_binary_search(nb));
}
