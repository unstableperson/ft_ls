/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:45:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/04/18 14:09:53 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	t_data	*head;
    t_flags flags;
    int		num_of_flags;
	int		flag;

	if (ac == 1)
	{
		ft_without_args(".");
		return (0);
	}
    flags.value = 0;
	num_of_flags = ft_flags(ac, av, &flags);
	flag = ac - num_of_flags - 1;
	head = ft_convert_args(av + num_of_flags + 1);
	if (flags.bits.f == 0)
		ft_sort_params(av + num_of_flags + 1, num_of_flags, flags);
	if (flags.bits.l && flags.bits.upper_r == 0)
		ft_l_flag(head, flag, flags);
	else if (flags.bits.upper_r)
		ft_recursion_flag(av + num_of_flags + 1, flag, flags);
	else
		ft_argv(&head, ac - num_of_flags - 1, flags);
	return (0);
}
