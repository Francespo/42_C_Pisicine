/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpagano <lpagano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:18:35 by lpagano           #+#    #+#             */
/*   Updated: 2026/03/29 19:52:05 by lpagano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "util.h"

int	main(int argc, char **argv)
{
	struct s_dict_node	*dict;

	if (argc < 2 || argc > 3)
	{
		write(1, "Not enough parameters\n", 21);
		return (-1);
	}
	if ((argc == 2 && !init_dict("numbers.dict", &dict))
		|| (argc == 3 && !init_dict(argv[1], &dict)))
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	if (argc == 2)
		print_num(dict, argv[1], -1);
	else
		print_num(dict, argv[2], -1);
	free_dict(dict);
}
