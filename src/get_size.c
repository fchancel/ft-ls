/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_size.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 16:34:32 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 13:37:29 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_size		*init_size(void)
{
	t_size		*size;

	if ((size = (t_size*)malloc(sizeof(t_size))) == NULL)
		display_error_exit("init size");
	size->len_link_max = 0;
	size->len_user_max = 0;
	size->len_groupe_max = 0;
	size->len_size_max = 0;
	size->len_major_max = 0;
	size->len_minor_max = 0;
	size->len_name_max = 0;
	return (size);
}

t_size		*launcher_get_size(t_data *data, t_size *size)
{
	while (data)
	{
		size = get_size_max(data, size);
		data = data->next;
	}
	return (size);
}

t_size		*get_size_max(t_data *data, t_size *size)
{
	int		major;
	int		minor;

	if (S_ISCHR(data->file->mode) ||
			S_ISBLK(data->file->mode) || S_ISSOCK(data->file->mode))
	{
		major = ((int32_t)(((u_int32_t)(data->file->st_rdev) >> 24) & 0xff));
		minor = ((int32_t)((data->file->st_rdev) & 0xffffff));
		if (ft_intlen(major) > size->len_major_max)
			size->len_major_max = ft_intlen(major);
		if (ft_intlen(minor) > size->len_minor_max)
			size->len_minor_max = ft_intlen(minor);
	}
	else if (ft_intlen(data->file->size) > size->len_size_max)
		size->len_size_max = ft_intlen(data->file->size);
	if (data->file->len_link > size->len_link_max)
		size->len_link_max = data->file->len_link;
	if (data->file->len_user > size->len_user_max)
		size->len_user_max = data->file->len_user;
	if (data->file->len_groupe > size->len_groupe_max)
		size->len_groupe_max = data->file->len_groupe;
	if (data->len_name > (size_t)size->len_name_max)
		size->len_name_max = data->len_name;
	return (size);
}
