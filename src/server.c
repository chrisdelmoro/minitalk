/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:22:13 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/23 22:52:02 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	fill_str(int bit)
{
	static int	i = 6;
	static char test = 0;

	if (bit)
		test = test | (bit << i);
	i--;
	if (i == -1)
	{
		if (test == '\0')
			write(1, "\n", 1);
		else
			write(1, &test, 1);
		i = 6;
		test = 0;
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

int main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, get_bit_0);
	signal(SIGUSR2, get_bit_1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
