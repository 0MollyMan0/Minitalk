/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:52:49 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/23 09:54:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int	server_PID;
	int j;
	int	i;
	unsigned char bit;

	if (ac != 3)
	{
		printf("%s", "Wrong parameters");
		return (1);
	}
	server_PID = atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		j = 0;
		while (j < 8)
		{
			bit = (av[2][i] >> j) & 1;
			if (bit)
				kill(server_PID, SIGUSR2);
			else
				kill(server_PID, SIGUSR1);
			usleep(2000);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(server_PID, SIGUSR1);
		usleep(2000);
		j++;
	}
	return 0;
}
 