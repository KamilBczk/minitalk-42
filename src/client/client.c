/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbiczyk <kbiczyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:29:34 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2022/03/08 13:05:30 by kbiczyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void error(char *s)
{
    printf("%s", s);
    exit(EXIT_FAILURE);
}

char *format_number(int c)
{
    return (0);
}

void    send_message(int pid, char *message)
{
    int i;
 
    i = 0;
    while (message[i] != '\0')
    {
        printf("%d\n", message[i]);
        i++;
    }
    
    printf("PID : %d", pid);
    printf("\nMESSAGE : %s car : %d", message, *message);

    
}

int main(int argc, char **argv)
{
    if (argc != 3)
        error("Error:\t./client [SERVER-PID] [MESSAGE]");
    send_message(atoi(argv[1]), argv[2]);
    
}