/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArguments.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:08:08 by akadi             #+#    #+#             */
/*   Updated: 2023/06/13 16:11:50 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_irc.hpp"

void    Error(const char *str)
{
    std::cerr << str << std::endl;
    exit(1);
}

void    checkArguments(int ac, char **av)
{
    if (ac != 3)
        Error("Bad input");
    if (!checkPort(av[1]))
        Error("invalid Port");
}

bool checkPort(char *str)
{
    for(int i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return false;
    long n = atoi(str);
    if (n < 0 || n > 65535)
        return (false);
    return true;
}