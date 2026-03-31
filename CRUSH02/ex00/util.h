/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpagano <lpagano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:23:14 by lpagano           #+#    #+#             */
/*   Updated: 2026/03/29 19:50:53 by lpagano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_dict_node
{
	struct s_dict_node	*next;
	char				*key;
	char				*value;
};

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*read_until(int f1, int f2, char sep, char **result);
char	*ft_trim(char *str);
int		init_dict(const char *path, struct s_dict_node **result);
void	free_dict(struct s_dict_node *head);
void	ft_print_dict(struct s_dict_node *node, char *num, char is_not_last);
void	print_num(struct s_dict_node *dict, char *cursor, int max_len);
void	print_two_digits(struct s_dict_node *node, char *num, char is_not_last);
