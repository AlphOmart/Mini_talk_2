/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:50:49 by mwubneh           #+#    #+#             */
/*   Updated: 2023/06/01 14:39:26 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putstr(char	*str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

char	*ft_add_char(char *str, char c)
{
	char	*concat_str;
	size_t	i;

	if (!c)
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	concat_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!concat_str)
		return (NULL);
	i = -1;
	while (str[++i])
		concat_str[i] = str[i];
	concat_str[i] = c;
	concat_str[i + 1] = '\0';
	free(str);
	return (concat_str);
}

void	action(int sig, siginfo_t *info, void *context)
{
	static char				*str = NULL;
	static int				i = 0;
	static pid_t			client_id = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_id)
		client_id = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			ft_putstr(str);
			kill(client_id, SIGUSR2);
			client_id = 0;
			return ;
		}
		str = ft_add_char(str, c);
		c = 0;
		kill(client_id, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	client_inf;

	if (argc != 1 && argv[1])
		return (write(1, "\n", 1));
	client_inf.sa_sigaction = action;
	client_inf.sa_flags = SA_SIGINFO;
	ft_putpid(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &client_inf, 0);
	sigaction(SIGUSR2, &client_inf, 0);
	while (42)
	{
		pause();
	}
}
