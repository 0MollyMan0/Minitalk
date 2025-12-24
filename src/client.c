/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:52:49 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/24 06:22:42 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	send_byte(unsigned char c, int server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (g_ack_received == 0)
			;
		bit++;
	}
}

static void	send_string(char *s, int server_pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_byte((unsigned char)s[i], server_pid);
		i++;
	}
	send_byte(0, server_pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					server_pid;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac != 3 || !ft_verif_max(av[1]) || !ft_verif_pid(av[1]))
		return (1);
	server_pid = atoi(av[1]);
	send_string(av[2], server_pid);
	return (0);
}
