/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:42:16 by cade-oli          #+#    #+#             */
/*   Updated: 2025/06/01 11:38:28 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define _POSIX_C_SOURCE 200809L

#include "../inc/minitalk.h"

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	if (pid == -1)
	{
		ft_printf(RED "Error: Invalid PID. Try again.\n" RESET);
		exit(1);
	}
	print_banner();
	ft_printf("PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
	return (EXIT_SUCCESS);
}
