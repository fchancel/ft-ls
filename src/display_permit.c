/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_all.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 14:58:50 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 09:02:10 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_permit(mode_t st_mode, char *path)
{
	char		permit[12];

	permit[0] = get_type(st_mode);
	permit[1] = (S_IRUSR & st_mode) ? 'r' : '-';
	permit[2] = (S_IWUSR & st_mode) ? 'w' : '-';
	permit[3] = (S_IXUSR & st_mode) ? 'x' : '-';
	if (S_ISUID & st_mode)
		permit[3] = permit[3] == '-' ? 'S' : 's';
	permit[4] = (S_IRGRP & st_mode) ? 'r' : '-';
	permit[5] = (S_IWGRP & st_mode) ? 'w' : '-';
	permit[6] = (S_IXGRP & st_mode) ? 'x' : '-';
	if (S_ISGID & st_mode)
		permit[6] = permit[6] == '-' ? 'S' : 's';
	permit[7] = (S_IROTH & st_mode) ? 'r' : '-';
	permit[8] = (S_IWOTH & st_mode) ? 'w' : '-';
	permit[9] = (S_IXOTH & st_mode) ? 'x' : '-';
	if (S_ISVTX & st_mode)
		permit[9] = permit[9] == '-' ? 'T' : 't';
	permit[10] = get_acl(path);
	permit[11] = '\0';
	ft_putstr(permit);
	ft_putchar(' ');
}

char		get_type(mode_t st_mode)
{
	if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else
		return ('-');
}

char		get_acl(char *path)
{
//	char	buf[100];
//	acl_t	acl;
	char	ret;

	ret = ' ';
	*path = ' ';
//	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
//	{
//		acl_free((void*)acl);
//		ret = '+';
//	}
//	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
//		ret = '@';
	return (ret);
}
