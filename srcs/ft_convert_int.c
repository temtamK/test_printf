/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:01:56 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/29 19:40:24 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_size_int(va_list arg, t_pf *lst)
{
	if (lst->l_count >= 2)
		lst->n = (long long int)va_arg(arg, long long int);
	else if (lst->l_count == 1)
		lst->n = (long long int)va_arg(arg, long int);
	else if (lst->h_count && ((lst->h_count % 2) == 0))
		lst->n = (long long int)((char)va_arg(arg, int));
	else if (lst->h_count && ((lst->h_count % 2) != 0))
		lst->n = (long long int)((short)va_arg(arg, int));
	else
		lst->n = (long long int)va_arg(arg, int);
}

void	ft_size_u(va_list arg, t_pf *lst)
{
	if (lst->l_count >= 2)
		lst->u = (unsigned long long)va_arg(arg, unsigned long long);
	else if (lst->l_count == 1)
		lst->u = (unsigned long long int)va_arg(arg, unsigned long int);
	else if (lst->h_count && ((lst->h_count % 2) == 0))
		lst->u = (unsigned long long int)((unsigned char)va_arg(arg, int));
	else if (lst->h_count && ((lst->h_count % 2) != 0))
		lst->u = (unsigned long long int)((unsigned short)va_arg(arg, int));
	else
		lst->u = (unsigned long long int)va_arg(arg, unsigned int);
}

void	if_n_zero(t_pf *lst, char *format)
{
	if (lst->n == 0 && lst->preci && lst->preci_width == 0 && !lst->width)
	{
		free(format);
		return ;
	}
	else if (lst->n == 0 && lst->preci && lst->preci_width == 0)
	{
		free(format);
		format = ft_strdup(" ");
	}
	else if (lst->n == 0 && (lst->plus || lst->space))
		lst->len++;
}

void	ft_conv_d(va_list arg, t_pf *lst)
{
	char	*format;
	char	*sp;

	lst->is_int = 1;
	ft_size_int(arg, lst);
	format = itoa_printf(lst->n);
	lst->len = num_count(lst->n);
	format = ft_num_preci(format, lst);
	lst->len = ft_strlen(format);
	(lst->n < 0) ? lst->len++ : 0;
	(lst->n > 0) && (lst->plus || lst->space) ? lst->len++ : 0;
	if_n_zero(lst, format);
	sp = ft_print_space(lst);
	ft_join_all(format, sp, lst);
}

void	ft_conv_u(va_list arg, t_pf *lst)
{
	char	*format;
	char	*sp;

	lst->is_int = 1;
	ft_size_u(arg, lst);
	format = ft_uitoa(lst->u);
	lst->len = ft_strlen(format);
	format = ft_num_preci(format, lst);
	lst->len = ft_strlen(format);
	if (lst->u == 0 && lst->preci && lst->preci_width == 0 && !lst->width)
	{
		free(format);
		return ;
	}
	if (lst->u == 0 && lst->preci && lst->preci_width == 0)
	{
		free(format);
		format = ft_strdup(" ");
	}
	sp = ft_print_space(lst);
	ft_join_all(format, sp, lst);
}
