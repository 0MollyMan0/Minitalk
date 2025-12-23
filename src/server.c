/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 07:42:27 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/23 12:57:58 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minitalk.h>

static void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	bits;
	static int 				count;

	(void)context;
	if (sig == SIGUSR2)
		bits = bits | 1 << count;
	else if (sig == SIGUSR1)
		bits = bits | 0 << count;
	count++;
	if (count == 8)
	{
		if (bits == 0)
			write(1, "\n", 1);
		else
			write(1, &bits, 1);
		bits = 0;
		count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;
	char *pid;
	
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	while (1)
	{
		
	}
	return 0;
}
