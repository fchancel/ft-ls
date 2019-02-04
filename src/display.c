/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 11:07:11 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 13:57:48 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_total(t_data *data)
{
	ft_putstr("total ");
	ft_putnbr(count_size_total(data));
	ft_putchar('\n');
}

void		display_color(char *name, int st_mode, short int flag)
{
	if (S_ISCHR(st_mode))
		ft_putcolor(YELLOW_HIGHT_BLUE, name);
	else if ((S_ISDIR(st_mode)) && (S_IWUSR & st_mode)
			&& (S_IWGRP & st_mode) && (S_IWOTH & st_mode))
	{
		ft_putcolor(YELLOW_HIGHT_BLACK, name);
		if (flag & LARGE_F)
			ft_putchar('/');
	}
	else if (S_ISLNK(st_mode))
	{
		ft_putcolor(MAGENTA, name);
		if (flag & LARGE_F)
			ft_putchar('@');
	}
	else if (S_ISDIR(st_mode))
	{
		ft_putcolor(BOLD_CYAN, name);
		if (flag & LARGE_F)
			ft_putchar('/');
	}
	else if (S_ISBLK(st_mode))
		ft_putcolor(BLUE_HIGHT_BLUE, name);
	else
		display_color2(name, st_mode, flag);
}

void		display_color2(char *name, int st_mode, short int flag)
{
	if (S_ISFIFO(st_mode))
	{
		ft_putcolor(YELLOW, name);
		if (flag & LARGE_F)
			ft_putchar('|');
	}
	else if (S_ISVTX & st_mode || S_ISGID & st_mode ||
			S_ISUID & st_mode)
	{
		ft_putcolor(RED_HIGHT_BLACK, name);
		if (flag & LARGE_F)
			ft_putchar('*');
	}
	else if (S_IXUSR & st_mode)
	{
		ft_putcolor(RED, name);
		if (flag & LARGE_F)
			ft_putchar('*');
	}
	else
		ft_putstr(name);
}

void		display_one(t_data *data, int type)
{
	if (!data)
		return ;
	if (type == ISFILE)
	{
		while (data)
		{
			if (data->ifdir != 4 && data->ifdir != 0)
			{
				display_inoeud(data->file->st_ino, data->flag);
				display_color(data->name, data->file->mode, data->flag);
				ft_putchar('\n');
			}
			data = data->next;
		}
	}
	else
	{
		while (data)
		{
			display_inoeud(data->file->st_ino, data->flag);
			display_color(data->name, data->file->mode, data->flag);
			ft_putchar('\n');
			data = data->next;
		}
	}
}
