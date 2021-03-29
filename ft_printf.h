/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:21:05 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/29 23:18:49 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct	s_pf
{
	char						buf[BUFFER_SIZE + 1];
	int							buf_count;
	int							ret;
	int							width;
	int							preci;
	int							preci_width;
	int							preci_parse;
	int							conv;
	int							minus;
	int							zero;
	int							plus;
	int							space;
	int							sharp;
	int							len;
	int							sp_len;
	int							is_int;
	int							h_count;
	int							l_count;
	int							true_zero;
	long long int				n;
	unsigned long long int		u;
	int							i;
}				t_pf;

int				ft_printf(const char *format, ...);
void			put_buf(t_pf *lst, char *format, int len);
void			print_buf(t_pf *lst);

void			ft_parse(char *format, va_list arg, t_pf *lst);
size_t			is_signal(char c);

void			ft_conv_s(va_list arg, t_pf *lst);
void			ft_conv_d(va_list arg, t_pf *lst);
void			ft_conv_u(va_list arg, t_pf *lst);
void			ft_conv_x(va_list arg, t_pf *lst);
void			ft_conv_p(va_list arg, t_pf *lst);
void			ft_conv_c(va_list arg, t_pf *lst);
void			ft_conv_n(va_list arg, t_pf *lst);
void			ft_conv_o(va_list arg, t_pf *lst);
void			ft_size_u(va_list arg, t_pf *lst);

char			*ft_print_space(t_pf *lst);
void			ft_join_all(char *format, char *sp, t_pf *lst);
char			*ft_num_preci(char *format, t_pf *lst);
void			check_sign(t_pf *lst);

int				atoi_printf(char *format, int *i);
char			*itoa_printf(long long int n);
char			*ft_strdup_l(char *format, t_pf *lst);
char			*ft_c_to_str(char c);

size_t			u_num_count(unsigned long long int n);
size_t			num_count(long long int n);
char			*ft_uitoa(unsigned long long int n);
char			*ft_itoa_base(unsigned long long int n, char *base);

void			init_lst(t_pf *lst);
void			set_preci(t_pf *lst);
void			reset_flags(t_pf *lst);

#endif
