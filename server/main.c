/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 07:42:27 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/23 08:38:50 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_SOURCE
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int sig)
{
	static char bits;
	static int count;

	if (sig == SIGUSR1)
	{
		bits = bits | 0 << count;
		write(1, "SIGUSR1 received\n", 17);
	}
	else if (sig == SIGUSR2)
	{
		bits = bits | 1 << count;
		write(1, "SIGUSR2 received\n", 17);	
	}
	count++;
	if (count == 8)
	{
		write(1, &bits, 1);
		count = 0;
	}
}

int main(void)
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	int pid = getpid();
	printf("Here's my PID: %d\n", pid);
	while (1)
		pause();
	return 0;
}
