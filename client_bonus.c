/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:15:54 by cnamoune          #+#    #+#             */
/*   Updated: 2024/12/21 21:12:39 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_sig_get;

void	sig_get(int signal)
{
	(void)signal;
	g_sig_get = 1;
}

void	ack(int server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			write(1, "Failure to send ACK\n", 20);
			return ;
		}
		while (g_sig_get == 0)
			usleep(100);
		g_sig_get = 0;
	}
}

void	send_data(int server_pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		c = (unsigned char)*str;
		i = 8;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			while (g_sig_get == 0)
				usleep(100);
			g_sig_get = 0;
		}
		str++;
	}
	ack(server_pid);
}

int	main(int argc, char **argv)
{
	char				*str;
	int					server_pid;
	struct sigaction	sa;

	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	sa.sa_handler = sig_get;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		write(1, "Error ; Waiting input : <Server_pid> Message\n", 46);
		return (1);
	}
	send_data(server_pid, str);
	return (0);
}
