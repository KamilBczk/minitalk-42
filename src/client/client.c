/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbiczyk <kbiczyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:29:34 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2022/03/08 15:47:30 by kbiczyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void error(char *s)
{
    printf("%s", s);
    exit(EXIT_FAILURE);
}

void    send_message(int pid, char *message)
{
    int shift;
 
    while (*message != '\0')
    {
        shift = -1;
        while (++shift < 8)
        {
            if (((int) *message >> shift) & 1) {
                if(kill(pid, SIGUSR2) == -1)
                    error("wrong PID");
            }
            else {
                if(kill(pid, SIGUSR1) == -1)
                    error("wrong PID");
            }
            usleep(300);
        }
        message++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
        error("Error:\t./client [SERVER-PID] [MESSAGE]");
    send_message(atoi(argv[1]), argv[2]);
    
}