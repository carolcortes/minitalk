/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:42:16 by cade-oli          #+#    #+#             */
/*   Updated: 2025/04/13 17:46:09 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(void)
{
	struct sigaction	sa;
	__pid_t				pid;

	pid = getpid();
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
