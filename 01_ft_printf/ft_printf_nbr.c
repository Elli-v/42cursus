/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:45:54 by soooh             #+#    #+#             */
/*   Updated: 2021/03/02 21:46:10 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pointer(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int			ft_minus(t_info *info, char **buf)
{
	int		ret;

	ret = 0;
	if ((info->type == 'i' || info->type == 'd') &&
					info->zero == 0 && info->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		ret = 1;
	}
	return (ret);
}

int			ft_minus2(int buf_len, t_info *info, char **buf)
{
	int		ret;

	ret = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			ret = 1;
		}
		else if (buf_len < info->width)
			*buf[0] = '-';
	}
	return (ret);
}

int			ft_prec(unsigned long long nbr, t_info *info, char **buf)
{
	int		buf_len;
	int		ret;
	int		i;

	buf_len = ft_nbrlen(nbr, info);
	ret = (info->prec > buf_len) ? info->prec : buf_len;
	if (!(*buf = (char *)malloc(sizeof(char) * ret + 1)))
		return (0);
	i = 0;
	(*buf)[ret] = '\0';
	while (buf_len + i < ret)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && info->prec != 0)
		(*buf)[ret - i] = '0';
	while (nbr)
	{
		(*buf)[ret - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (buf_len);
}

int			ft_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		ret;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = ft_prec(nbr, info, &buf);
	buf_len += ft_minus(info, &buf);
	if (info->type == 'p')
		buf_len = ft_pointer(&buf);
	ret = ft_width_str(&buf, info);
	ret += ft_minus2(buf_len, info, &buf);
	ft_putstr(buf);
	free(buf);
	return (ret);
}
