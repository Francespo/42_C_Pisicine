/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 00:06:46 by fesposit          #+#    #+#             */
/*   Updated: 2026/03/20 00:19:48 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (src[i] != 0)
		{
			dest[i] = src[i];
			j++;
		}
		i++;
	}
	while (j < n)
	{
		dest[j] = 0;
		j++;
	}
	return (dest);
}
