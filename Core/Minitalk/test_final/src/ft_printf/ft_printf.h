/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 18:49:30 by avon-ben      #+#    #+#                 */
/*   Updated: 2022/10/24 18:49:33 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h> 
# include <stdlib.h>

size_t	ft_strlen(const char *string);
int		ft_printf(const char *str, ...);
int		ft_isprint(unsigned int input);
int		ft_putstr_strlen(char *s);
void	ft_putchar(char c);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		printhex(long long n, char c, int i);
int		print_uint(unsigned int n, int i);
int		ft_putchar_ret1(char c);
int		nlen_putn(int n);
int		put_pt(unsigned long long input);
int		printhex_mod(unsigned long n, char c, int i);

#endif