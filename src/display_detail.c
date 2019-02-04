/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_detail.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:29:53 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 15:53:03 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_detail(int size, int sizemax, int side, char *str)
{
	char	*n_str;

	n_str = ft_strnew(sizemax);
	ft_memset(n_str, ' ', sizemax);
	if (side == RIGHT)
		ft_memcpy(n_str + (sizemax - size), str, size);
	else
		ft_memcpy(n_str, str, size);
	ft_putstr(n_str);
	free(n_str);
}

void	display_major(t_file *file, t_size *size)
{
	char		*minor;
	char		*major;

	ft_putstr(" ");
	major = ft_itoa((int32_t)(((u_int32_t)(file->st_rdev) >> 24) & 0xff));
	minor = ft_itoa((int32_t)((file->st_rdev) & 0xffffff));
	display_detail(ft_strlen(major), size->len_major_max, RIGHT, major);
	ft_putstr(", ");
	display_detail(ft_strlen(minor), size->len_minor_max, RIGHT, minor);
	free(major);
	free(minor);
}

void	display_size(t_file *file, t_size *size)
{
	char	*len_size;

	len_size = ft_itoa(file->size);
	if (S_ISCHR(file->mode) ||
			S_ISBLK(file->mode) || S_ISSOCK(file->mode))
		display_major(file, size);
	else
	{
		if (size->len_major_max != 0)
			ft_putstr("  ");
		display_detail(ft_strlen(len_size),
				(size->len_size_max + size->len_major_max +
				size->len_minor_max), RIGHT, len_size);
	}
	free(len_size);
	ft_putchar(' ');
	display_time(file);
}

void	display_time(t_file *file)
{
	char	*file_time;
	time_t	today;
	char	*tmp;

	today = time(&today);
	file_time = ctime(&(file->time));
	tmp = ft_strsub(file_time, 4, 6);
	ft_putstr(tmp);
	free(tmp);
	ft_putchar(' ');
	if ((today - file->time) > 15778800 || (file->time - today) > 3600)
	{
		ft_putchar(' ');
		tmp = ft_strsub(file_time, 20, 4);
		ft_putstr(tmp);
		free(tmp);
	}
	else
	{
		tmp = ft_strsub(file_time, 11, 5);
		ft_putstr(tmp);
		free(tmp);
	}
	ft_putchar(' ');
}

void	display_inoeud(int inoeud, short int flag)
{
	if (flag & SMALL_I)
	{
		ft_putnbr(inoeud);
		ft_putchar(' ');
	}
}
