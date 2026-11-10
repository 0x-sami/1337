/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:56:52 by ysalama           #+#    #+#             */
/*   Updated: 2026/11/05 10:57:41 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// ft_printf.c
int	ft_printf(const char *, ...);

// print_utils.c
int	ft_putchar(char c);
int	ft_putstr(char *s);
int ft_putnbr(long n, char flag);

// other_utils.c
int	ft_strlen(const char *s);

#endif
