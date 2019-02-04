/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_sort_annex.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 09:34:54 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 15:54:03 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data			*comp_ascii_time(t_data *data, t_data *new_data)
{
	int		i;

	i = lst_count_all(data);
	while (i-- && data->file->time == new_data->file->time)
	{
		while (data->next != NULL
				&& data->next->file->time == new_data->file->time
				&& ft_strcmp(new_data->name, data->name) > 0)
			data = data->next;
		return (ft_strcmp(new_data->name, data->name) > 0 ?
				add_elem(data, new_data) : switch_elem(data, new_data));
	}
	return (new_data);
}

t_data			*comp_ascii_size(t_data *data, t_data *new_data)
{
	int		i;

	i = lst_count_all(data);
	while (i-- && data->file->size == new_data->file->size)
	{
		while (data->next != NULL
				&& data->next->file->size == new_data->file->size
				&& ft_strcmp(new_data->name, data->name) > 0)
			data = data->next;
		return (ft_strcmp(new_data->name, data->name) > 0 ?
				add_elem(data, new_data) : switch_elem(data, new_data));
	}
	return (new_data);
}

t_data			*add_elem(t_data *data, t_data *new_data)
{
	if (data->next != NULL)
	{
		new_data->next = data->next;
		new_data->next->previous = new_data;
	}
	new_data->previous = data;
	data->next = new_data;
	return (new_data);
}

t_data			*switch_elem(t_data *data, t_data *new_data)
{
	if (data->previous != NULL)
	{
		new_data->previous = data->previous;
		new_data->previous->next = new_data;
	}
	new_data->next = data;
	data->previous = new_data;
	return (new_data);
}
