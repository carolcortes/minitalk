/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:54:13 by cade-oli          #+#    #+#             */
/*   Updated: 2025/04/13 17:55:51 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int ac, char **av)
{
	struct sigaction	sa;
	__pid_t				server_pid;

	if (ac != 3)
	{
		handle_error_args(ac);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(server_pid, av[2]);
	return (EXIT_SUCCESS);
}
