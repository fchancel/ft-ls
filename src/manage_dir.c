/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_dir.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 11:29:45 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 09:21:33 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*manage_dir(short int flag, char *name)
{
	t_data			*data;
	struct stat		d_stat;
	DIR				*dir;

	data = NULL;
	if (lstat(name, &d_stat) == -1)
	{
		display_error(name);
		return (NULL);
	}
	if ((dir = open_dir(name)) == NULL)
		return (NULL);
	else
		data = read_dir(dir, data, name, flag);
	return (data);
}

DIR		*open_dir(char *name)
{
	DIR			*dir;

	if ((dir = opendir(name)) == NULL)
	{
		display_error(name);
		return (dir);
	}
	else
		return (dir);
}

t_data	*parsing_sort(t_data *data, t_data *new_data, short int flag)
{
	if (flag & LARGE_S)
		data = sort_size(data, new_data);
	else if (flag & SMALL_T)
		data = sort_time(data, new_data);
	else if (flag & SMALL_F)
		data = no_sort(data, new_data);
	else
		data = sort_ascii(data, new_data);
	return (data);
}

t_data	*read_dir(DIR *dir, t_data *data, char *name, short int flag)
{
	struct dirent	*dir_read;
	t_data			*new_data;

	while ((dir_read = readdir(dir)) != NULL)
	{
		if ((flag & SMALL_A) && dir_read->d_name[0] == '.')
		{
			new_data = init_lst(name, ft_strdup(dir_read->d_name), flag);
			data = parsing_sort(data, new_data, flag);
		}
		if (dir_read->d_name[0] != '.')
		{
			new_data = init_lst(name, ft_strdup(dir_read->d_name), flag);
			data = parsing_sort(data, new_data, flag);
		}
	}
	closedir(dir);
	return (data);
}
