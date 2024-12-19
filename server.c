/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:49:34 by cnamoune          #+#    #+#             */
/*   Updated: 2024/12/19 19:07:51 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_signal(int signum, siginfo_t *info, void *context)
{
	static int				bit_nb ;
	static unsigned char	signal;
	static char				*buffer = NULL;

	(void)context;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		write(1, "Signal reçu\n", 12);
	}

	signal <<= 1;
	if (signum == SIGUSR2)
		signal |= 1;
	bit_nb++;
	if (bit_nb == 8)
	{
		write(1, "8 bits reçus, caractère complet\n", 32);
		if (signal == '\0')
		{
			if (buffer)
			{
				write(1, "Chaîne reçue complète : ", 24);
				write(1, buffer, ft_strlen(buffer));
				write(1, "\n", 1);
				free(buffer);
				buffer = NULL;
			}
			else
				write(1, "Buffer est vide\n", 16);
		}
		else
			buffer = ft_strjoin(buffer, signal);
		signal = 0;
		bit_nb = 0;
	}
	if (info && info->si_pid > 0)
	{
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	ft_putnbr(getpid());
	sa.sa_sigaction = get_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(1, "Error with SIGUSR1. Closing server now.", 40);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error with SIGUSR1. Closing server now.", 40);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
