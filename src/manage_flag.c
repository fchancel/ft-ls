/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_flag.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 09:58:55 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 10:58:40 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_av(int ac, char **av, int *begin)
{
	int			j;
	short int	flag;

	flag = 0;
	j = 1;
	while (*begin < ac)
	{
		if ((check_valid_opt(av[*begin], begin)) == 0)
		{
			while (av[*begin][j])
			{
				if ((comp_av_opt(av[*begin][j])) == 1)
					display_illegal_opt(av[*begin][j]);
				else
					adding_flag1(av[*begin][j], &flag);
				j++;
			}
			j = 1;
		}
		else
			break ;
		*begin += 1;
	}
	return (flag);
}

int			check_valid_opt(char *av, int *begin)
{
	if (av[0] == '-' && av[1] == '-' && !av[2])
	{
		*begin += 1;
		return (1);
	}
	if (av[0] == '-' && !av[1])
		return (1);
	if (av[0] != '-')
		return (1);
	else
		return (0);
}

int			comp_av_opt(char opt)
{
	int		i;

	i = 0;
	while (AVAILABLE_OPTION[i])
	{
		if (opt == AVAILABLE_OPTION[i])
			return (0);
		i++;
	}
	return (1);
}

void		adding_flag1(char opt, short int *flag)
{
	if (opt == 'l')
		*flag |= (short int)1;
	else if (opt == 'R')
		*flag |= (short int)2;
	else if (opt == 'a')
		*flag |= (short int)4;
	else if (opt == 'r')
		*flag |= (short int)8;
	else if (opt == 't')
		*flag |= (short int)16;
	else if (opt == 'S')
		*flag |= (short int)32;
	else if (opt == 'F')
		*flag |= (short int)64;
	else if (opt == '1')
		*flag |= (short int)128;
	else if (opt == 'i')
		*flag |= (short int)256;
	else if (opt == 'd')
		*flag |= (short int)512;
	else if (opt == 'f')
		*flag |= (short int)1028;
}
