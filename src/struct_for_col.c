/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_for_col.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 11:47:22 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 14:02:39 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_col			*ft_lst_to_struct(t_data *data, t_col *col_data)
{
	int		i;

	i = 0;
	while (data)
	{
		if (!(col_data->name[i] = ft_strsub(data->name,
						0, ft_strlen(data->name))))
			return (NULL);
		if (!(col_data->mode[i] = data->file->mode))
			return (NULL);
		if (!(col_data->st_ino[i] = data->file->st_ino))
			return (NULL);
		i++;
		data = data->next;
	}
	col_data->name[i] = NULL;
	return (col_data);
}

t_col			*ft_file_to_struct(t_data *data, t_col *col_data)
{
	int		i;

	i = 0;
	while (data)
	{
		if (data->ifdir != 4 && data->ifdir != 0)
		{
			if (!(col_data->name[i] = ft_strsub(data->name,
							0, ft_strlen(data->name))))
				return (NULL);
			if (!(col_data->mode[i] = data->file->mode))
				return (NULL);
			if (!(col_data->st_ino[i] = data->file->st_ino))
				return (NULL);
			i++;
		}
		data = data->next;
	}
	col_data->name[i] = NULL;
	return (col_data);
}

t_col			*init_col_struct(t_data *data, t_col *col_data, int type)
{
	if (type == ISFILE)
	{
		if (!(col_data->name = (char **)malloc(sizeof(char *) *
						(lst_count_file(data) + 1))))
			return (NULL);
		if (!(col_data->mode = (int*)malloc(sizeof(int) *
						(lst_count_file(data)))))
			return (NULL);
		if (!(col_data->st_ino = (int*)malloc(sizeof(int) *
						(lst_count_file(data)))))
			return (NULL);
	}
	else
	{
		if (!(col_data->name = (char **)malloc(sizeof(char *) *
						(lst_count_all(data) + 1))))
			return (NULL);
		if (!(col_data->mode = (int*)malloc(sizeof(int) *
						(lst_count_all(data)))))
			return (NULL);
		if (!(col_data->st_ino = (int*)malloc(sizeof(int) *
						(lst_count_all(data)))))
			return (NULL);
	}
	return (col_data);
}
