/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@42.fr>                    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:09:57 by fesposit          #+#    #+#             */
/*   Updated: 2026/03/15 17:27:18 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	put_correct_char(int x_pos, int y_pos, int x_max, int y_max)
{
	if ((x_pos == 0 && y_pos == 0) || (x_pos == x_max && y_pos == y_max))
		ft_putchar('/');
	else if ((x_pos == 0 && y_pos == y_max) || (x_pos == x_max && y_pos == 0))
		ft_putchar('\\');
	else if (x_pos > 0 && x_pos < x_max && (y_pos == 0 || y_pos == y_max))
		ft_putchar('*');
	else if (y_pos > 0 && y_pos < y_max && (x_pos == 0 || x_pos == x_max))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	xp;
	int	yp;

	yp = 0;
	while (yp < y)
	{
		xp = 0;
		while (xp < x)
		{
			put_correct_char(xp, yp, x - 1, y - 1);
			xp++;
		}
		ft_putchar('\n');
		yp++;
	}
}
