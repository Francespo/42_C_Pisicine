/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpagano <lpagano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:17:19 by lpagano           #+#    #+#             */
/*   Updated: 2026/03/29 20:08:29 by lpagano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "util.h"

char	*read_dict_until(int f1, int f2, char sep)
{
	char	*buf;
	int		i;

	read_until(f1, f2, sep, &buf);
	if (!buf)
		return (NULL);
	if (sep == ':')
	{
		i = 0;
		if (buf[i] < '0' || buf[i] > '9')
			return (NULL);
		while (buf[i] >= '0' && buf[i] <= '9')
			i++;
		while (buf[i])
			if (buf[i++] != ' ')
				return (NULL);
	}
	return (ft_trim(buf));
}

int	create_dict_node(int f1, int f2, struct s_dict_node **result)
{
	struct s_dict_node	*node;

	*result = NULL;
	node = malloc(sizeof(struct s_dict_node));
	node->key = read_dict_until(f1, f2, ':');
	node->value = read_dict_until(f1, f2, '\n');
	node->next = NULL;
	if (!node->key || !node->value)
		return (0);
	*result = node;
	create_dict_node(f1, f2, &node->next);
	return (1);
}

int	init_dict(const char *path, struct s_dict_node **result)
{
	struct s_dict_node	*head;
	int					f1;
	int					f2;

	f1 = open(path, O_RDONLY);
	f2 = open(path, O_RDONLY);
	if (f1 < 0 || f2 < 0 || !create_dict_node(f1, f2, &head))
		return (0);
	*result = head;
	return (1);
}

void	free_dict(struct s_dict_node *head)
{
	struct s_dict_node	*next;

	while (head)
	{
		next = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = next;
	}
}
