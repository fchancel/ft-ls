/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   launcher_display_detail.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/27 14:21:05 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 13:50:24 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	launcher_display_detail_file(t_data *data, t_size *size)
{
	size = launcher_get_size(data, init_size());
	while (data)
	{
		if (data->ifdir != 4 && data->ifdir != 0)
		{
			display_inoeud(data->file->st_ino, data->flag);
			display_permit(data->file->mode, data->path);
			display_detail(data->file->len_link, size->len_link_max,
					RIGHT, data->file->st_nlink);
			ft_putchar(' ');
			display_detail(data->file->len_user, size->len_user_max,
					LEFT, data->file->user_name);
			ft_putstr("  ");
			display_detail(data->file->len_groupe,
					size->len_groupe_max, LEFT, data->file->groupe_name);
			ft_putstr("  ");
			display_size(data->file, size);
			display_color(data->name, data->file->mode, data->flag);
			if (S_ISLNK(data->file->mode))
				read_link(data->path);
			ft_putchar('\n');
		}
		data = data->next;
	}
	free(size);
}

void	launcher_display_detail(t_data *data)
{
	t_size	*size;

	size = launcher_get_size(data, init_size());
	while (data)
	{
		display_inoeud(data->file->st_ino, data->flag);
		display_permit(data->file->mode, data->path);
		display_detail(data->file->len_link, size->len_link_max,
				RIGHT, data->file->st_nlink);
		ft_putchar(' ');
		display_detail(data->file->len_user, size->len_user_max,
				LEFT, data->file->user_name);
		ft_putstr("  ");
		display_detail(data->file->len_groupe,
				size->len_groupe_max, LEFT, data->file->groupe_name);
		ft_putstr("  ");
		display_size(data->file, size);
		display_color(data->name, data->file->mode, data->flag);
		if (S_ISLNK(data->file->mode))
			read_link(data->path);
		data = data->next;
		ft_putchar('\n');
	}
	free(size);
}
