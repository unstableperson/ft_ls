/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <kfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:32:11 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/04/26 20:16:58 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_only_files(t_data *head, char *path_name)
{
	struct stat		buff;
	t_data			*tmp;
	char			*path;

	tmp = head;
	while (tmp)
	{
		if (*(tmp->name) == '.')
		{
			tmp = tmp->next;
			continue ;
		}
		path = ft_str_path(path_name, tmp->name);
		stat(path, &buff);
		free(path);
		if (S_ISDIR(buff.st_mode))
			return (0);
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}

void	ft_rec(t_data *tmp, char *pt, t_flags fl)
{
	DIR				*dirp2;
	char			*path;

	while (tmp)
	{
		if (!ft_strcmp(tmp->name, ".") || !ft_strcmp(tmp->name, ".."))
		{
			tmp = tmp->next;
			continue ;
		}
		path = ft_str_path(pt, tmp->name);
		if ((dirp2 = opendir(path)))
		{
			ft_putendl(path, 2);
			ft_recurs(path, dirp2, fl);
			closedir(dirp2);
		}
		tmp = tmp->next;
		free(path);
	}
}

void	ft_recurs(char *path_name, DIR *dirp, t_flags fl)
{
	t_data			*head;
	t_data			*tmp;
	char			*pt;

	head = ft_readdir(dirp, fl);
	ft_balanser_sort(&head, fl, path_name);
	tmp = head;
	pt = ft_strjoin(path_name, "/");
	if (ft_only_files(head, pt))
	{
		ft_output(head, fl, 1, pt);
		free(pt);
		return ;
	}
	head = tmp;
	if (tmp)
		ft_output(tmp, fl, 0, pt);
	//ft_skip_dots(&tmp, fl);
	if (!fl.bits.a && !fl.bits.f)
		ft_remove_dots(&tmp);
	ft_rec(tmp, pt, fl);
	ft_free_list(&head, 0);
	free(pt);
}

void	ft_recursion_flag(char **av, int flag, t_flags fl)
{
	DIR			*dirp;
	int			i;

	i = 0;
	if (flag == 0)
	{
		dirp = opendir(".");
		ft_recurs(".", dirp, fl);
		closedir(dirp);
		return ;
	}
	while (av[i])
	{
		if ((dirp = opendir(av[i])))
		{
			if (flag + i == flag && flag > 1)
				ft_putendl(av[i], 1);
			else if (flag > 1)
				ft_putendl(av[i], 2);
			ft_recurs(av[i], dirp, fl);
			closedir(dirp);
		}
		i++;
	}
}
