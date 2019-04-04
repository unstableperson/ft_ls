/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:24:54 by koparker          #+#    #+#             */
/*   Updated: 2019/04/04 15:54:12 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t	ft_max_namlen(t_data *data)
{
	t_data	*tmp;
	size_t	max;

	if (data == NULL)
		return (0);
	tmp = data;
	max = tmp->len;
	while (tmp)
	{
		if (max < tmp->len)
			max = tmp->len;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_output_spaces(char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
}
