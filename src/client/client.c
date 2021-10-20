/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:29:34 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/10/20 22:46:39 by kamilbiczyk      ###   ########.fr       */
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
    int     i;
    char    *formated_number;

    formated_number = malloc(sizeof(char) * (3 + 1));
    i = 0;
    if (c < 100)
        formated_number[i] = '0';
    else
        formated_number[i] = c/100 + 48;
    i++;
    if (c < 10)
        formated_number[i] = '0';
    else
        formated_number[i] = (c/10%10) + 48;
    i++;
    formated_number[i] = (c%10) + 48;
    formated_number[i + 1] = '\0';
    return(formated_number);
}

void    to_base_uncode(char *message, char *to_send)
{
    int i;
    int f;
    int nb;

    i = 0;
    f = 0;
    to_send[f++] = '0';
    while(message[i] != '\0')
    {
        nb = message[i] - 48;
        if (nb == 0)
            to_send[f++] = '0';
        else
            while (nb-- != 0)
                to_send[f++] = '1';
        to_send[f++] = '0';
        i++;
    }
    to_send[f] = '\0';
}

void    send_message(char *strpid, char *message)
{
    int pid;
    int i;
    char *to_send;
    char *formated_number;

    pid = atoi(strpid);
    to_send = malloc(sizeof(char) * (23 + 1));
    if (!to_send)
        return ;
    while (*message)
    {
        formated_number = format_number(*message);
        to_base_uncode(formated_number, to_send);
        //printf("%s\n", to_send);
        while(to_send[i] != '\0')
        {
            if (to_send[i] == '0')
                if (kill(pid, SIGUSR1) == -1)
                    error("Wrong PID!");
            if (to_send[i] == '1')
                if (kill(pid, SIGUSR2) == -1)
                    error("Wrong PID!");
            i++;
        }
        i = 0;
        message++;
    }

    // kill(pid, SIGUSR1);
    // kill(pid, SIGUSR2);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        error("Error:\t./client [SERVER-PID] [MESSAGE]");
    send_message(argv[1], argv[2]);
    
}