/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:31:06 by soooh             #+#    #+#             */
/*   Updated: 2021/03/02 00:51:02 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

# define TYPE "csdiupxX%"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			nbr_sign;
}				t_info;

/*
** MAIN FUNCTION
*/

int				ft_printf(const char *format, ...);
int				ft_format(va_list ap, char *format);
void			ft_info(va_list ap, char *format, t_info *info, int i);
void			ft_width_prec(va_list ap, char *format, t_info *info, int i);
int				ft_type(va_list ap, t_info *info);

/*
** PRINT FUNCTION
*/

int				ft_char(int c, t_info *info);
int				ft_char_width(int width, int len, int zero);

int				ft_str(char *str, t_info *info);
int				ft_width_str(char **buf, t_info *info);
char			*ft_buf(char *str, int end, int len);

int				ft_nbr(unsigned long long nbr, t_info *info);
int				ft_prec(unsigned long long nbr, t_info *info, char **buf);
int				ft_minus(t_info *info, char **buf);
int				ft_minus2(int buf_len, t_info *info, char **buf);
int				ft_pointer(char **buf);

/*
** UTILS FUNCTION
*/

void			init_info(t_info *info);
int				ft_nbrlen(unsigned long long nbr, t_info *info);
char			*ft_baseset(char type);

#endif
