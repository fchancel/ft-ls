/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   count.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 13:45:58 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 15:42:20 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			lst_count_dir(t_data *data)
{
	int		count;

	count = 0;
	while (data)
	{
		if (data->ifdir == 4 || data->ifdir == 0)
			count++;
		data = data->next;
	}
	return (count);
}

int			lst_count_all(t_data *data)
{
	int		i;

	i = 0;
	while (data)
	{
		i++;
		data = data->next;
	}
	return (i);
}

int			lst_count_file(t_data *data)
{
	int		count;

	count = 0;
	while (data)
	{
		if (data->ifdir != 4 && data->ifdir != 0)
			count++;
		data = data->next;
	}
	return (count);
}

int			count_size_total(t_data *data)
{
	int total;

	total = 0;
	while (data)
	{
		total = total + data->file->st_blocks;
		data = data->next;
	}
	return (total);
}
