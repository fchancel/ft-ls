/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   column.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 13:39:35 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 13:57:52 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_column(t_data *data, int type)
{
	struct winsize		width;
	int					tab[3];
	t_col				*col_data;
	t_size				*size;

	size = launcher_get_size(data, init_size());
	ioctl(0, TIOCGWINSZ, &width);
	if (size->len_name_max >= width.ws_col)
		display_line(data, data->flag);
	else
	{
		col_data = init_column_data(data, type);
		tab[COL_MAX] = data->flag & SMALL_I ? width.ws_col /
			(size->len_name_max + ft_intlen(data->file->st_ino) + 2) :
			width.ws_col / (size->len_name_max + 1);
		if (type == ISDIR)
			tab[NB_DATA] = lst_count_all(data);
		else
			tab[NB_DATA] = lst_count_file(data);
		tab[NB_ROW] = tab[NB_DATA] / tab[COL_MAX];
		if (tab[NB_DATA] % tab[COL_MAX] != 0)
			tab[NB_ROW] += 1;
		launcher_col(col_data, tab, size->len_name_max, data->flag);
		free_column(col_data, tab[NB_DATA], size);
	}
}

t_col		*init_column_data(t_data *data, int type)
{
	t_col		*col_data;

	if ((col_data = (t_col*)malloc(sizeof(t_col))) == NULL)
		display_error("Launcher_column");
	if (type == ISDIR)
	{
		col_data = init_col_struct(data, col_data, ISDIR);
		col_data = ft_lst_to_struct(data, col_data);
	}
	else
	{
		col_data = init_col_struct(data, col_data, ISFILE);
		col_data = ft_file_to_struct(data, col_data);
	}
	return (col_data);
}

void		launcher_col(t_col *col_data, int *tab, int s_max, short int flag)
{
	int		i;
	int		k;
	int		j;

	j = 0;
	k = 0;
	i = 0;
	while (i < tab[NB_ROW])
	{
		while (k < tab[NB_DATA] && j < tab[COL_MAX])
		{
			display_inoeud(col_data->st_ino[k], flag);
			display_column(col_data->name[k], s_max,
					col_data->mode[k], flag);
			ft_putchar(' ');
			k = k + tab[NB_ROW];
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
		k = i;
	}
}

void		display_column(char *name, int sizemax, int st_mode, short int flag)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(name);
	display_color(name, st_mode, flag);
	while (i < (sizemax - size))
	{
		ft_putchar(' ');
		i++;
	}
}

void		free_column(t_col *col_data, int nb_data, t_size *size)
{
	int		i;

	i = 0;
	free(size);
	free(col_data->mode);
	free(col_data->st_ino);
	while (i < nb_data)
	{
		free(col_data->name[i]);
		i++;
	}
	free(col_data->name);
	free(col_data);
}
