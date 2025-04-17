/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:42:18 by cade-oli          #+#    #+#             */
/*   Updated: 2025/04/17 13:58:05 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "../lib/libft/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include "ansii_colors.h"

void	signal_handler(int signum, siginfo_t *info, void *context);
void	print_banner(void);

void	send_message(pid_t pid, char *msg);
void	send_char(pid_t pid, unsigned char c);
void	handle_error_args(int ac);
void	ack_handler(int signum);

#endif
