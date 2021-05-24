/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:17:00 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 20:39:59 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../cub3d.h"
# include "../../utils/libft/libft.h"
# include "../../utils/get_next_line/get_next_line.h"

enum				e_map_element
{
	IN_EMPTY,
	WALL,
	SPRITE,
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEILING,
	TOTAL_E = 8,
	OUT_EMPTY
};

enum				e_tex_element
{
	E_CEILING,
	E_FLOOR
};

typedef struct		s_element
{
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	int				s;
	int				total;
	int				map_start;

}					t_ele;

typedef struct		s_map
{
	int				col;
	int				row;
	int				dir;
	int				**map;
	char			**cvisited;
	int				map_dir;
	int				x;
	int				y;
	int				sp_total;
}					t_map;

typedef struct		s_parse
{
	t_bundle		bun;
	t_ele			ele;
	t_map			map;
}					t_par;

/*
** cub_utils.c
*/

void				cub_putstr(char *s);
void				cub_error(char *text);
int					cub_space(char i);
void				cub_digit(char **str);
void				cub_free_2fd(char **str);

/*
** cub_parse.c
*/

int					cub_strcmp(const char *str1, const char *str2);
void				cub_check_arg(int argc, char *argv[], int *fd);
void				cub_open_check(int *fd, char *file, int argv);
void				cub_open_texture(t_par *par);
int					parse(t_par *par, int fd);

/*
** cub_utils_texture.c
*/

char				**cub_b_flag_connect(t_bundle *bun, int element);
int					*cub_e_flag_connect(t_ele *ele, int element);
char				*cub_tex_filepath(const char *str);
void				cub_extention(char *temp, char *ext, int cub);
void				cub_ele_total(t_par *par, char **line, int fd);

/*
** cub_utils_rgb.c
*/

void				cub_rgb_error(int *e_flag, char **temp);
void				cub_check_rgb(t_rgb *rgb);
t_rgb				*cub_rgb_flag(t_bundle *bun, int flag);
int					*cub_ele_flag(t_ele *ele, int flag);
void				cub_free_char(int row, char **temp);

/*
** cub_parsing_e.c
*/

void				cub_resolution(char *line, t_ele *ele, t_bundle *bun);
void				cub_texture(char *line, t_ele *ele, t_bundle *bun,
								int element);
void				cub_rgb(char *line, t_ele *ele, t_bundle *bun, int flag);
int					parsing_e_convert(char *line, t_ele *ele, t_bundle *bun);
int					parsing_e(char *line, t_par *par);

/*
** cub_parsing_m.c
*/

int					*cub_map_stack2(t_map *mflag, int ***temp, int i, int pre);
int					**cub_map_stack(char *line, t_map *mflag, int pre);
int					cub_map_check(char *line, t_map *mflag);
void				parsing_m(char *line, t_map *mflag);

/*
** cub_map_convert_utils.c
*/

int					cub_map_convert_dir(t_map *mflag, int dir);
int					cub_map_convert_alpha(char line, t_map *mflag);
int					*cub_map_convert(char *line, t_map *mflag, int len);

/*
** cub_map_utils.c
*/

void				cub_free_map(int **map, int row);
int					cub_blank(char *line);
int					cub_map_element(char e, t_map *mflag);

/*
** cub_map_trim.c
*/

int					cub_map_out_empty(t_map mflag, int *idx);
int					*cub_map_trim2(t_map *mflag, int ***temp, int i, int idx);
void				cub_map_trim(t_map *mflag, int idx);
void				cub_map_missing(t_par *par);

/*
** cub_map_validity.c
*/

int					cub_validity_check(int i, int j, t_map *mflag);
char				**cub_map_malloc(t_map *mflag);
void				cub_map_copy(t_map *mflag);
void				cub_map_validity(t_map *mflag);

/*
** cub_init.c
*/

void				cub_binit(t_bundle *bun);
void				cub_einit(t_ele *ele);
void				cub_map_init(t_map *map);

#endif
