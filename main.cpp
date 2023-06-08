/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:31 by akouame           #+#    #+#             */
/*   Updated: 2023/06/08 16:48:25 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cerr << "You must have 2 arguments {port, password} !" << std::endl;
        return (1);
    }
    else
    {
        int i = -1;
        while (av[1][++i])
        {
            if (!isdigit(av[1][i]))
            {
                std::cerr << "Error: Bad input !" << std ::endl;
                return (1);
            }
        }
        long port = atoi(av[1]);
        if (port < 0 || port > 65535)
        {
            std::cerr << "Error: Bad port !" << std::endl;
            return (1);
        }
        Server  srv(port);
        
        srv.run_server();
    }
}