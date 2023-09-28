/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ironesto <ironesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:55:56 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/28 04:04:49 by ironesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putnbr(int i, char *base);
int		ft_putnbr_hexa(unsigned int i, char *base);
int		ft_putnbr_u(unsigned int nbr, char *base);
void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putpointer(unsigned long i, char *base);

#endif