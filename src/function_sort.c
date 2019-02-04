/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_sort.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 05:22:08 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 10:59:06 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data			*sort_ascii(t_data *data, t_data *new_data)
{
	t_data	*tmp;
	int		i;

	i = lst_count_all(data);
	tmp = data;
	if (data == NULL)
		return (new_data);
	while (i--)
	{
		if (ft_strcmp(tmp->name, new_data->name) > 0)
		{
			new_data = switch_elem(tmp, new_data);
			if (new_data->previous == NULL)
				return (new_data);
			break ;
		}
		if (tmp->next == NULL)
			new_data = add_elem(tmp, new_data);
		tmp = tmp->next;
	}
	return (data);
}

t_data			*sort_time(t_data *data, t_data *new_data)
{
	t_data	*tmp;
	int		i;

	i = lst_count_all(data);
	tmp = data;
	if (data == NULL)
		return (new_data);
	while (i--)
	{
		if (tmp->file->time < new_data->file->time)
		{
			new_data = switch_elem(tmp, new_data);
			return (new_data->previous == NULL ? new_data : data);
		}
		if (tmp->file->time == new_data->file->time)
		{
			new_data = comp_ascii_time(tmp, new_data);
			return (new_data->previous == NULL ? new_data : data);
		}
		if (tmp->next == NULL)
			new_data = add_elem(tmp, new_data);
		tmp = tmp->next;
	}
	return (data);
}

t_data			*sort_size(t_data *data, t_data *new_data)
{
	t_data	*tmp;
	int		i;

	i = lst_count_all(data);
	tmp = data;
	if (data == NULL)
		return (new_data);
	while (i--)
	{
		if (tmp->file->size < new_data->file->size)
		{
			new_data = switch_elem(tmp, new_data);
			return (new_data->previous == NULL ? new_data : data);
		}
		if (tmp->file->size == new_data->file->size)
		{
			new_data = comp_ascii_size(tmp, new_data);
			return (new_data->previous == NULL ? new_data : data);
		}
		if (tmp->next == NULL)
			new_data = add_elem(tmp, new_data);
		tmp = tmp->next;
	}
	return (data);
}

t_data			*reverse_data(t_data *data)
{
	t_data	*tmp;
	t_data	*start;

	start = data;
	tmp = data;
	if (!data)
		return (data);
	while (data->next != NULL)
		data = data->next;
	start = data;
	while (data)
	{
		tmp = data->next;
		data->next = data->previous;
		data->previous = tmp;
		data = data->next;
	}
	return (start);
}

t_data			*no_sort(t_data *data, t_data *new_data)
{
	t_data	*tmp;

	tmp = data;
	if (data == NULL)
		return (new_data);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_data = add_elem(tmp, new_data);
	return (data);
}
