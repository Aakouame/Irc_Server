/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:59:19 by akadi             #+#    #+#             */
/*   Updated: 2023/06/24 12:10:02 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

int countCmd(std::string str)
{
    int count = 0;
    for(size_t i = 0; i < str.size(); i++)
        if (str[i] == '\n')
            count++;
    return count;
}

void SplitString(std::string str, std::vector<std::string> &split, int count)
{
    int i = 0;
    size_t pos = 0;
    while(i < count)
    {
        pos = str.find('\n');
        split.push_back(TrimString(str.substr(0, pos)));
        str.erase(0, pos + 1);
        i++;
    }
}

std::string Ltrim(const std::string &str)
{
    size_t start = str.find_first_not_of("\r\n");
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string Rtrim(const std::string &str)
{
    size_t end = str.find_last_not_of("\r\n");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string    TrimString(const std::string str)
{
    return (Rtrim(Ltrim(str)));
}