/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:22:13 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/25 22:40:32 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	fill_str(int bit)
{
	static int				i = 7;
	static unsigned char	c = 0;

	if (bit)
		c = c | (bit << i);
	i--;
	if (i == -1)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

static void	got_bit(int sig_num)
{
	if (sig_num == SIGUSR1)
		fill_str(0);
	else if (sig_num == SIGUSR2)
		fill_str(1);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = got_bit;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
