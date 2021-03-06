#include <ft_ls.h>

t_data	*ft_current_dir(char *s, t_flags fl)
{
	DIR		*dirp;
	t_data	*head;

	head = NULL;
	dirp = opendir(s);
	head = ft_readdir(dirp, s, fl);
	closedir(dirp);
	return (head);
}

void	ft_set_time(t_data **head, t_flags fl, char *path)
{
	t_data		*tmp;
	struct stat	buff;
	char		*pt;

	tmp = *head;
	while (tmp)
	{
		if (path == NULL)
			lstat(tmp->name, &buff);
		else
		{
			pt = ft_str_path(path, tmp->name);
			lstat(pt, &buff);
			free(pt);
		}
		if (fl.bits.upper_u == 1)
			tmp->time = buff.st_birthtime;
		else if (fl.bits.u == 1)
			tmp->time = buff.st_atime;
		else
			tmp->time = buff.st_mtime;
		tmp = tmp->next;
	}
}

void	ft_color_dot(char *s)
{
	char	*tmp;

	tmp = ft_strjoin(DIR_COLOR, s);
	ft_putendl(tmp, 0);
	ft_putstr(RESET);
	ft_strdel(&tmp);
}

void	ft_process_current_dir(char *s, t_flags fl)
{
	t_data	*head;

	if (fl.bits.d)
	{
		if (fl.bits.l && !fl.bits.one)
			ft_simple_l(new_file("."), fl);
		else
		{
			if (!fl.bits.upper_g)
				ft_putendl(s, 0);
			else
				ft_color_dot(s);
		}
		return ;
	}
	if (fl.bits.l && !fl.bits.one)
	{
		ft_l(".", fl);
		return ;
	}
	head = ft_current_dir(s, fl);
	ft_output(head, fl, 1, NULL);
}
