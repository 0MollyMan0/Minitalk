/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 07:42:27 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/23 09:37:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_SOURCE
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int sig)
{
	static unsigned char	bits;
	static int 				count;

	if (sig == SIGUSR1)
		bits = bits | 0 << count;
	else if (sig == SIGUSR2)
		bits = bits | 1 << count;
	count++;
	if (count == 8)
	{
		if (bits == 0)
			write(1, "\n", 1);
		else
		{
			write(1, &bits, 1);
			bits = 0;
			count = 0;
		}
			
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
