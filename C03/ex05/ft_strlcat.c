/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesposit <fesposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:30:29 by fesposit          #+#    #+#             */
/*   Updated: 2026/03/29 14:30:31 by fesposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	total_len;

	i = 0;
	total_len = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size > dest_len)
		total_len = dest_len + src_len;
	else
		total_len = src_len + size;
	while (src[i] && size > (dest_len + 1))
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = 0;
	return (total_len);
}
