/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:44:53 by mwubneh           #+#    #+#             */
/*   Updated: 2023/06/01 15:53:30 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static size_t	ft_strlen(char *str);
static void		ft_putnbr(int nbr);
static void		action(int sig);
static void		ft_send_str(pid_t server_id, char *str);


int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		write(1, "Usage : ./client <server_PID> <String to send>\n", 47);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	ft_send_str(ft_atoi(argv[1]), argv[2]);
	while (42)
		pause();
	return (0);
}

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		received += 1;
	else
	{
		write(1, "transmission finished : ", 24);
		ft_putnbr(received);
		write(1, " character sent\n", 16);
		exit(0);
	}
}

static void	ft_send_str(pid_t server_id, char *str)
{
	int		bit;
	int		i;
	char	c;

	i = -1;
	while (str[++i])
	{
		bit = 8;
		c = str[i];
		while (bit--)
		{
			if (c >> bit & 1)
				kill(server_id, SIGUSR2);
			else
				kill(server_id, SIGUSR1);
			usleep(100);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(server_id, SIGUSR1);
		usleep(100);
	}
}
