/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_linked_list.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 13:37:20 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 09:22:04 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data			*init_lst(char *path, char *name, short int flag)
{
	t_data			*new_data;
	t_file			*file;
	struct stat		file_stat;

	if ((new_data = (t_data*)malloc(sizeof(t_data))) == NULL)
		display_error_exit(name);
	if ((file = (t_file *)malloc(sizeof(t_file))) == NULL)
		display_error_exit(name);
	new_data->file = file;
	new_data->name = name;
	new_data->len_name = ft_strlen(name);
	new_data->path = get_path(path, name);
	new_data->next = NULL;
	new_data->previous = NULL;
	new_data->ifdir = 8;
	new_data->flag = flag;
	lstat(new_data->path, &file_stat);
	new_data->file = init_stat(file_stat, new_data->file);
	if (ft_strcmp(".", new_data->name) == 0
			|| ft_strcmp("..", new_data->name) == 0)
		new_data->ifdir = flag & SMALL_D ? 8 : 0;
	else if (S_ISDIR(new_data->file->mode))
		new_data->ifdir = flag & SMALL_D ? 8 : 4;
	return (new_data);
}

t_file			*init_stat(struct stat file_stat, t_file *file)
{
	struct group	*getgid;
	struct passwd	*getuid;

	file->mode = file_stat.st_mode;
	file->st_dev = file_stat.st_dev;
	file->st_nlink = ft_itoa(file_stat.st_nlink);
	file->st_ino = file_stat.st_ino;
	file->len_link = ft_strlen(file->st_nlink);
	getuid = getpwuid(file_stat.st_uid);
	file->user_name = ft_strdup(getuid->pw_name);
	file->len_user = ft_strlen(file->user_name);
	getgid = getgrgid(file_stat.st_gid);
	file->groupe_name = ft_strdup(getgid->gr_name);
	file->len_groupe = ft_strlen(file->groupe_name);
	file->size = file_stat.st_size;
	file->st_rdev = file_stat.st_rdev;
	file->time = file_stat.st_mtime;
	file->st_blocks = file_stat.st_blocks;
	return (file);
}

t_data			*free_all(t_data *data)
{
	t_data	*pdata;

	if (!data)
		return (NULL);
	else
	{
		while (data)
		{
			pdata = data->next;
			free(data->name);
			free(data->path);
			free(data->file->st_nlink);
			free(data->file->user_name);
			free(data->file->groupe_name);
			free(data->file);
			free(data);
			data = pdata;
		}
		return (NULL);
	}
}
