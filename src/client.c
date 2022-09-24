/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:17:06 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/22 20:53:45 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int	check_pid(char *pid)
{
	size_t	i;

	i = 0;
	while (pid[i])
	{
		if (ft_isdigit(pid[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	send_message(int pid, char *msg)
{
	pid++;
	ft_printf("%s\n", msg);
}

int main(int argc, char **argv)
{
	if (argc != 3 || !check_pid(argv[1]))
	{
		ft_printf("Only two arguments are valid: A valid PID and a message to the server!\n");
		return (EXIT_FAILURE);
	}
	else
		send_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
