/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:12:09 by cnamoune          #+#    #+#             */
/*   Updated: 2024/12/21 21:08:01 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, unsigned char c);
void	*ft_memset(void *s, int c, size_t n);
int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);
char	*ft_strdup(char *s1);
#endif
