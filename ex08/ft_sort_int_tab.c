/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 23:26:27 by fesposit          #+#    #+#             */
/*   Updated: 2026/03/19 23:48:04 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	ccp;

	i = 0;
	ccp = 0;
	while (ccp < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab [i + 1];
				tab[i + 1] = temp;
				ccp = 0;
			}
			else
				ccp++;
			i++;
		}
	}
}
