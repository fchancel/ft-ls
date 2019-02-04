/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:34:25 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 10:07:24 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	short int	flag;
	int			begin;
	t_data		*data;

	begin = 1;
	flag = check_av(ac, av, &begin);
	av = sort_str(&begin, ac, av);
	data = get_name(flag, ac, av, &begin);
	if (flag & SMALL_R)
		data = reverse_data(data);
	if (!data)
		exit(0);
	launcher_display_file(data, flag);
	launcher_display_dir(data, flag, &begin);
	free_all(data);
}
