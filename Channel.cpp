/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:41:27 by yel-qabl          #+#    #+#             */
/*   Updated: 2023/06/24 00:01:30 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "client_irc.hpp"

Channel::Channel(){
    
}

Channel::~Channel()
{
    
}

Channel::Channel(std::string ch_name, Client_irc *c) : name (ch_name)   
{
    this->owner = c->get_nick();
    this->invite_only = false;
    is_private = false;
    is_secret = false;
    op_topic = false;
    no_msg = false;
    moderated = false;
    user_limit = 256;
    key = "";
    number_of_users = 0;
    this->clients.insert(std::make_pair(c->get_nick(), c));
}

    
Channel &Channel::operator=(const Channel &c)
{
    this->name = c.name;
    return (*this);
}

int Channel::broadcast(std::string message, int sender) // send message to all clients
{
    std::map<std::string, Client_irc*>::iterator it;
    
    for (it = clients.begin(); it != clients.end(); it++)
    {
        if (sender != it->second->fd_client)
            send(it->second->fd_client, message.c_str(), message.length(), 0);
    }
    return (0);
}


int Channel::cmd_invite(std::string nickname)   // invite client to channel
{
    this->invited_users.push_back(nickname);
    return(0);
}

int Channel::set_topic(std::string top) // change channel topic
{
    this->topic = top;
    return (0);
}

bool    Channel::get_invite_only() const    // return invite only status
{
    return (invite_only);
}



bool    Channel::get_op_topic() const     // return topic privacy status
{
    return(op_topic);
}

std::vector<std::string>  Channel::get_invited_user() const // return list of invited users
{
    return (invited_users);
}

std::vector<std::string> Channel::get_operators() const // return list of operators
{
    return (operators);
}


int Channel::add_operator(std::string nick) // add operator to channel
{
    this->operators.push_back(nick);
    return (0);
}

int Channel::remove_operator(std::string nick) // remove operator from channel
{
    std::vector<std::string>::iterator it = std::find(operators.begin(), operators.end(), nick);
    if (it != operators.end())
        operators.erase(it);
    return (0);
}


int Channel::change_optopic(std::string sign) // change topic privacy
{
    if (sign == "-")
        op_topic = false;
    else if (sign == "+")
        op_topic = true;
    return(0);
}


int		Channel::change_userlimits(std::string sign, std::size_t limit) // change user limit
{
	std::cout<<"change user limits"<<std::endl;
	if (sign == "-")
		user_limit = 256;
	else if (sign == "+")
		user_limit = limit;
	return (0);
}

int		Channel::change_password(std::string sign, std::string password) // change channel password
{
	std::cout<<"change password"<<std::endl;
	if (sign == "-")
		key = "";
	else if (sign == "+")
		key = password;
	return (0);
}

int		Channel::change_invite(std::string sign) // change invite only status
{
	std::cout<<"change invite"<<std::endl;
	if (sign == "-")
		invite_only = false;
	else if (sign == "+")
		invite_only = true;
	return (0);
}


bool Channel::is_operator(std::string nick) // check if user is operator
{
    for (std::vector<std::string>::iterator p  = operators.begin(); p != operators.end(); p++)
    {
        if (nick == *p)
            return (true);
    } 
    if (nick == owner)
        return (true);
    return (false);
}

std::string Channel::get_topic()
{
    return (topic);
}

std::string Channel::get_owner(){
    return (owner);
}

//--
void    Channel::set_key(std::string    k){
    key = k;
}

void    Channel::set_invite_only(bool   valid){
    invite_only = valid;
}
//--
std::string Channel::get_key(){
    return (key);
}

bool    Channel::get_invite_only(){
    return (invite_only);
}