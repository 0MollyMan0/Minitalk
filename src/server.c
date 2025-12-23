/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 07:42:27 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/23 10:48:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minitalk.h>

static void	handler(int sig)
{
	static unsigned char	bits;
	static int 				count;

	if (sig == SIGUSR2)
		bits = bits | 1 << count;
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
}

int main(void)
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	int pid = getpid();
	printf("Here's my PID: %d\n", pid);
	while (1)
		pause();
	return 0;
}
