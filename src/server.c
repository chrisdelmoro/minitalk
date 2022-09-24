/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:22:13 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/24 19:00:29 by ccamargo         ###   ########.fr       */
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

static void	get_bit_0(int sig_num)
{
	fill_str(0);
	(void)sig_num;
}

static void	get_bit_1(int sig_num)
{
	fill_str(1);
	(void)sig_num;
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, get_bit_0);
	signal(SIGUSR2, get_bit_1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
