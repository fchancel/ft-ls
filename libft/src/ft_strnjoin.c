/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 11:46:31 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 01:51:24 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t	l1;
	size_t	l2;
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = ft_strnew(n > l2 ? l1 + l2 : l1 + n)))
		return (NULL);
	l1 = 0;
	while (s1[l1])
		str[i++] = s1[l1++];
	l2 = 0;
	while (s2[l2] && l2 < n)
		str[i++] = s2[l2++];
	return (str);
}
