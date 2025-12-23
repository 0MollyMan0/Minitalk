/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:52:49 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/23 13:02:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	send_char(unsigned char c, int server_PID)
{
	int	j;
	int	bit;

	j = 0;
	while (j < 8)
	{
		g_ack_received = 0;
		bit = (c >> j) & 1;
		if (bit)
			kill(server_PID, SIGUSR2);
		else
			kill(server_PID, SIGUSR1);
		while (g_ack_received == 0)
			;
		j++;
	}
}

static void	send_string(char *s, int server_PID)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_char((unsigned char)s[i], server_PID);
		i++;
	}
	send_char('\0', server_PID);
}

int main(int ac, char **av)
{
	struct sigaction sa;
	int	server_PID;
	
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac != 3 || !ft_verif_max(av[1]) || !ft_verif_pid(av[1]))
		return (1);
	server_PID = atoi(av[1]);
	send_string(av[2], server_PID);
	return 0;
}
 