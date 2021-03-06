#include <ft_ls.h>

void	ft_balanser_sort(t_data **head, t_flags fl, char *path)
{
	if (!*head)
		return ;
	if (fl.bits.f)
		return ;
	if ((fl.bits.t && (*head)->time == 0) ||
		(fl.bits.t && !path && (*head)->time == 0))
	{
		if (fl.bits.upper_u)
			ft_set_time(head, fl, path);
		else if (fl.bits.u)
			ft_set_time(head, fl, path);
		else
			ft_set_time(head, fl, path);
		ft_ascii_sort(head);
		ft_time_sort(head);
	}
	else if (fl.bits.t && fl.bits.l && (*head)->time != 0)
	{
		ft_ascii_sort(head);
		ft_time_sort(head);
	}
	else
		ft_ascii_sort(head);
	if (fl.bits.r)
		ft_rev_list(head);
}

void	ft_output(t_data *head, t_flags fl, int to_free, char *path)
{
	ft_balanser_sort(&head, fl, path);
	if (!fl.bits.upper_r)
	{
		if (fl.bits.d)
		{
			if (fl.bits.l && !fl.bits.one)
				ft_simple_l(head, fl);
			else if (!fl.bits.one)
				ft_print(head, fl, path);
			else
				ft_print_simple(head, fl);
			ft_free_list(&head, 0);
			return ;
		}
	}
	if (fl.bits.l && !fl.bits.one)
		ft_l(path, fl);
	else if (!fl.bits.one)
		ft_print(head, fl, path);
	else
		ft_print_simple(head, fl);
	if (to_free == 1)
		ft_free_list(&head, 0);
}

void	ft_output_files(t_data *head, t_flags fl, int to_free,
						char *path)
{
	ft_balanser_sort(&head, fl, NULL);
	if (fl.bits.l && !fl.bits.one)
		ft_l(path, fl);
	else if (!fl.bits.one)
		ft_print(head, fl, NULL);
	else
		ft_print_simple(head, fl);
	if (to_free)
		ft_free_list(&head, 0);
}
