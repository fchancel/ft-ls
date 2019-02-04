/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/26 15:09:23 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 13:47:29 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 INCLUDE	                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

# include <dirent.h>
# include <stdio.h>
# include "../libft/include/libft.h"
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 DEFINE FOR FLAG                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

# define AVAILABLE_OPTION "lRartSFf1id"
# define SMALL_L			1
# define LARGE_R			2
# define SMALL_A			4
# define SMALL_R			8
# define SMALL_T			16
# define LARGE_S			32
# define LARGE_F			64
# define ONE				128
# define SMALL_I			256
# define SMALL_D			512
# define SMALL_F			1028

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 OTHER DEFINE	                           ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

# define RIGHT				1
# define LEFT				0
# define NB_DATA			0
# define COL_MAX			1
# define NB_ROW				2
# define ISDIR				1
# define ISFILE				0

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 STRUCTURE                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct		s_data
{
	char			*name;
	char			*path;
	size_t			len_name;
	int				ifdir;
	short int		flag;
	struct s_data	*next;
	struct s_data	*previous;
	struct s_file	*file;
}					t_data;

typedef struct		s_file
{
	mode_t			mode;
	dev_t			st_dev;
	char			*st_nlink;
	ino_t			st_ino;
	int				len_link;
	char			*user_name;
	int				len_user;
	char			*groupe_name;
	int				len_groupe;
	off_t			size;
	dev_t			st_rdev;
	time_t			time;
	blkcnt_t		st_blocks;
}					t_file;

typedef struct		s_sizet_column_data
{
	int				len_link_max;
	int				len_user_max;
	int				len_groupe_max;
	int				len_size_max;
	int				len_major_max;
	int				len_minor_max;
	int				len_name_max;

}					t_size;

typedef struct		s_col
{
	char			**name;
	int				*mode;
	int				*st_ino;
}					t_col;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 display.c                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				display_total(t_data *data);
void				display_color(char *name, int st_mode, short int flag);
void				display_color2(char *name, int st_mode, short int flag);
void				display_one(t_data *data, int type);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 display_error.c                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				display_illegal_opt(char c);
void				display_error(char *str);
void				display_error_exit(char *str);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 display_permit.c                           ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				display_permit(mode_t st_mode, char *path);
char				get_type(mode_t st_mode);
char				get_acl(char *path);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 launcher_display_detail.c                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				launcher_display_detail(t_data *data);
void				launcher_display_detail_file(t_data *data, t_size *size);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 display_detail.c  			               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				display_time(t_file *file);
void				display_size(t_file *file, t_size *size);
void				display_detail(int size, int sizemax, int side, char *str);
void				display_major(t_file *file, t_size *size);
void				display_inoeud(int inoeud, short int flag);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 column.c 		 			               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				init_column(t_data *data, int type);
void				launcher_col(t_col *col_data, int *tab, int s_max,
														short int flag);
void				display_column(char *name, int sizemax, int st_mode,
														short int flag);
t_col				*init_column_data(t_data *data, int type);
void				free_column(t_col *col_data, int nb_data, t_size *size);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 get_size.c 		 			               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_size				*init_size(void);
t_size				*launcher_get_size(t_data *data, t_size *size);
t_size				*get_size_max(t_data *data, t_size *size);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 manage_flag.c 				               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int					check_av(int ac, char **av, int *begin);
int					comp_av_opt(char opt);
int					check_valid_opt(char *av, int *begin);
void				adding_flag1(char opt, short int *flag);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 manage_dir.c 				               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_data				*manage_dir(short int flag, char *name);
t_data				*read_dir(DIR *dir, t_data *data, char *name,
													short int flag);
DIR					*open_dir(char *name);
t_data				*parsing_sort(t_data *data, t_data *new_data,
													short int flag);
/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 ft_linked_list.c 			               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_data				*init_lst(char *path, char *name, short int flag);
t_data				*free_all(t_data *data);
t_file				*init_stat(struct stat file_stat, t_file *file);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 struct_for_col.c 			               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_col				*ft_lst_to_struct(t_data *data, t_col *column_data);
t_col				*ft_file_to_struct(t_data *data, t_col *column_data);
t_col				*init_col_struct(t_data *data, t_col *col_data, int type);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 count.c 					               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int					lst_count_all(t_data *data);
int					lst_count_dir(t_data *data);
int					lst_count_file(t_data *data);
int					count_size_total(t_data *data);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 annex_function.c 			               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_data				*go_to_dir(t_data *data);
char				*get_path(char *b_str, char *e_str);
void				read_link(char *path);
void				display_line(t_data *data,
													short int flag);
char				**sort_str(int *begin, int ac, char **av);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 launcher_ls.c 				               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_data				*get_name(short int flag, int ac, char **av, int *begin);
void				manage_ls(short int flag, char *name);
void				launcher_display_dir(t_data *data, short int flag,
															int *begin);
void				launcher_display_file(t_data *data, short int flag);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 function_sort.c 			               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_data				*sort_ascii(t_data *data, t_data *new_data);
t_data				*sort_time(t_data *data, t_data *new_data);
t_data				*sort_size(t_data *data, t_data *new_data);
t_data				*no_sort(t_data *data, t_data *new_data);
t_data				*reverse_data(t_data *data);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 function_sort_annex.c 		               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_data				*comp_ascii_time(t_data *data, t_data *new_data);
t_data				*comp_ascii_size(t_data *data, t_data *new_data);
t_data				*add_elem(t_data *data, t_data *new_data);
t_data				*switch_elem(t_data *data, t_data *new_data);

#endif
