/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   annex_function.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 04:28:57 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 13:56:24 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data		*go_to_dir(t_data *data)
{
	while (data)
	{
		if (data->ifdir == 4)
			return (data);
		data = data->next;
	}
	return (NULL);
}

char		*get_path(char *b_str, char *e_str)
{
	char	*path;
	char	*tmp;

	path = ft_strjoin(b_str, "/");
	tmp = path;
	path = ft_strjoin(path, e_str);
	free(tmp);
	return (path);
}

void		read_link(char *path)
{
	char	*buf;
	size_t	bufsize;

	bufsize = 256;
	buf = ft_strnew(bufsize);
	readlink(path, buf, bufsize);
	ft_putstr(" -> ");
	ft_putstr(buf);
	free(buf);
}

void		display_line(t_data *data, short int flag)
{
	while (data)
	{
		display_color(data->name, data->file->mode, flag);
		ft_putchar('\n');
		data = data->next;
	}
}

char		**sort_str(int *begin, int ac, char **av)
{
	int		i;
	int		j;
	char	*swap;

	i = *begin + 1;
	while (i < ac)
	{
		j = i;
		while (j > *begin && ft_strcmp(av[j], av[j - 1]) < 0)
		{
			swap = av[j];
			av[j] = av[j - 1];
			av[j - 1] = swap;
			j--;
		}
		i++;
	}
	return (av);
}
