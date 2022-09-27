/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:22:13 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/26 21:02:04 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	fill_str(char c)
{
	char		*c_dup;
	static char	*msg = "";
	char		*tmp;

	tmp = msg;
	c_dup = ft_calloc(2, sizeof(char));
	c_dup[0] = c;
	msg = ft_strjoin(msg, c_dup);
	ft_freethis(&c_dup, NULL);
	if (c == '\0')
	{
		ft_printf("%s\n", msg);
		ft_freethis(&msg, "");
	}
	if (ft_strlen(tmp))
		ft_freethis(&tmp, NULL);
}

static void	encode_byte(int bit)
{
	static int	i = 7;
	static char	c = 0;

	if (bit)
		c = c | (bit << i);
	i--;
	if (i == -1)
	{
		fill_str(c);
		i = 7;
		c = 0;
	}
}

static void	got_bit(int sig_num)
{
	if (sig_num == SIGUSR1)
		encode_byte(0);
	else if (sig_num == SIGUSR2)
		encode_byte(1);
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
