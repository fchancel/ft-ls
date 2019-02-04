/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   launcher_ls.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:39:54 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 09:56:46 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		parsing_flag(short int flag, t_data *data)
{
	if (!data)
		return ;
	if (flag & SMALL_R)
		data = reverse_data(data);
	if (flag & SMALL_L)
	{
		display_total(data);
		launcher_display_detail(data);
	}
	else if (flag & ONE)
		display_one(data, ISDIR);
	else
		init_column(data, ISDIR);
	if (flag & LARGE_R)
	{
		while ((data = go_to_dir(data)) != NULL)
		{
			data->ifdir = 8;
			ft_putchar('\n');
			ft_putstr(data->path);
			ft_putstr(":\n");
			manage_ls(flag, data->path);
		}
	}
}

void		manage_ls(short int flag, char *name)
{
	t_data		*data;

	data = manage_dir(flag, name);
	parsing_flag(flag, data);
	if (flag & SMALL_R)
		data = reverse_data(data);
	data = free_all(data);
}

t_data		*get_name(short int flag, int ac, char **av, int *begin)
{
	t_data			*data;
	struct stat		d_stat;
	int				i;

	i = *begin - 1;
	data = NULL;
	if (av[i + 1] == NULL)
		data = parsing_sort(data, init_lst(".", ft_strdup("."), flag), flag);
	while (++i < ac)
	{
		if (stat(av[i], &d_stat) == -1)
			display_error(av[i]);
		else
		{
			if (av[i][0] == '/' || av[i][0] == '~')
				data = parsing_sort(data, init_lst("",
							ft_strdup(av[i]), flag), flag);
			else
				data = parsing_sort(data, init_lst(".",
							ft_strdup(av[i]), flag), flag);
		}
	}
	if (*begin == ac && data->name[0] == '-' && data->name[1] == '-')
		data->name = ft_strdup(".");
	return (data);
}

void		launcher_display_file(t_data *data, short int flag)
{
	t_size		*size;

	size = NULL;
	if (flag & SMALL_L)
		launcher_display_detail_file(data, size);
	else if (flag & ONE)
		display_one(data, ISFILE);
	else
		init_column(data, ISFILE);
}

void		launcher_display_dir(t_data *data, short int flag, int *begin)
{
	int		nb_data;
	int		nb_file;

	nb_file = lst_count_file(data);
	nb_data = lst_count_dir(data);
	if (nb_file > 0 && nb_data > 0)
		ft_putchar('\n');
	while (data)
	{
		if (data->ifdir == 4 || data->ifdir == 0)
		{
			if (nb_data > 1 || nb_file > 0)
			{
				if (*begin > 1)
					ft_putchar('\n');
				ft_putstr(data->name);
				ft_putstr(":\n");
			}
			*begin += 1;
			manage_ls(flag, data->name);
		}
		data = data->next;
	}
}
