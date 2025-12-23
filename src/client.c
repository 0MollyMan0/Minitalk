/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:52:49 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/23 10:52:13 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void end_of_string(int server_PID)
{
	int	j;
	
	j = 0;
	while (j < 8)
	{
		kill(server_PID, SIGUSR1);
		usleep(2000);
		j++;
	}
}

static void send_string(char *s, int server_PID)
{
	int j;
	int	i;
	unsigned char bit;
	
	i = 0;
	while (s[i])
	{
		j = 0;
		while (j < 8)
		{
			bit = (s[i] >> j) & 1;
			if (bit)
				kill(server_PID, SIGUSR2);
			else
				kill(server_PID, SIGUSR1);
			usleep(500);
			j++;
		}
		i++;
	}
	end_of_string(server_PID);
}

int main(int ac, char **av)
{
	int	server_PID;

	if (ac != 3 || !ft_verif_max(av[1]) || !ft_verif_pid(av[1]))
	{
		printf("%s", "Wrong parameters");
		return (1);
	}
	server_PID = atoi(av[1]);
	send_string(av[2], server_PID);
	return 0;
}
 