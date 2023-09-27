/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_irc.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:55:05 by akouame           #+#    #+#             */
/*   Updated: 2023/06/24 00:01:45 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_irc.hpp"

void	Client_irc::set_msg_error()
{
	error_msg.ERR_NORECIPIENT = ":" + getMachineHost() + " 411 * :No recipient given "+cmd+"\r\n";
	error_msg.ERR_UNKNOWNCOMMAND = ":" + getMachineHost() + " 421 * "  + " :" +cmd+ " Unknown command\r\n";
	error_msg.ERR_NICKNAMEINUSE = ":" + getMachineHost() + " 433 * " + " :"+_nick+" Nickname is already in use\r\n";
	error_msg.ERR_NICKCOLLISION = ":" + getMachineHost() + " 436 * " +  " :"+_nick+" Nickname collision KILL\r\n";
	error_msg.ERR_NEEDMOREPARAMS = ":" + getMachineHost() + " 461 * " + " :"+cmd+" Not enough parameters\r\n";
	error_msg.ERR_NOTEXTTOSEND = ":" + getMachineHost() + " 412 * :No text to send\r\n";
	error_msg.ERR_NONICKNAMEGIVEN = ":" + getMachineHost() + " 431 * :No nickname given\r\n";
	error_msg.ERR_NOTREGISTERED = ":" + getMachineHost() + " 451 * :You have not registered\r\n";
	error_msg.ERR_ALREADYREGISTRED = ":" + getMachineHost() + " 462 * :You may not reregister\r\n";
	error_msg.ERR_PASSWDMISMATCH = ":" + getMachineHost() + " 464 * :Password incorrect\r\n";
}

Client_irc::Client_irc(){
	registered = false;
	_user.valid = false;
	set_msg_error();
	
}
Client_irc::Client_irc(int fd_clt): fd_client(fd_clt){
	registered = false;
	_user.valid = false;
	set_msg_error();
}
Client_irc::~Client_irc(){
	
}
//--
void	Client_irc::set_pass(std::string	pwd){
	_pass = pwd;
}
void	Client_irc::set_nick(std::string	nck){
	_nick = nck;
}
void	Client_irc::set_user(User_parameters	usr){
	_user.username = usr.username;
	_user.hostname = usr.hostname;
	_user.servername = usr.servername;
	_user.realname = usr.realname;
	_user.valid = usr.valid;
}
void	Client_irc::set_stringtoappend(std::string str){
	_stringtoappend = str;
}
void	Client_irc::set_commands(const std::vector<std::string> &cmd){
	_commands = cmd;
}

void	Client_irc::set_registered(bool valid){
	registered = valid;
}
void	Client_irc::set_operator(bool op){
	_operator = op;
}
//--
std::string	Client_irc::get_pass(){
	return (_pass);
}
std::string	Client_irc::get_nick(){
	return (_nick);
}
User_parameters	Client_irc::get_user(){
	return (_user);
}
bool	Client_irc::get_registered(){
	return (registered);
}
std::string Client_irc::get_stringtoappend(){
	return (_stringtoappend);
}
std::vector<std::string>	&Client_irc::get_commands(){
	return(_commands);
}
int	Client_irc::get_size_cmds(){
	return (_commands.size());
}
bool Client_irc::get_operator(){
	return (_operator);
}
//--
std::string	Client_irc::check_pass_cmd(char *buf, std::string pwd)
{
    std::string pass_cmd;

    if (strlen(buf) < 6)
	{
		msg = error_msg.ERR_PASSWDMISMATCH;
		send_msg_to_client();
        return ("");
	}
    int i = 4;
    while (buf[++i])
        pass_cmd += buf[i];
	if (pass_cmd.empty())
	{
		msg = error_msg.ERR_PASSWDMISMATCH;
		send_msg_to_client();
		return ("");
	}
    if (pass_cmd != pwd)
    {
		msg = error_msg.ERR_PASSWDMISMATCH;
        send_msg_to_client();
        return ("");
    }
    return (pass_cmd);
}
std::string	Client_irc::check_nick_cmd(char *buf, std::map<int, Client_irc>  &map_clients)
{
    std::string nick_cmd;
	
    if (strlen(buf) < 6)
	{
		msg = getMachineHost() + " ERROR :No nickname given\r\n";
		send_msg_to_client();
        return ("");
	}
    int i = 4;
    while (buf[++i])
        nick_cmd += buf[i];
	for(std::map<int, Client_irc>::iterator it = map_clients.begin(); it != map_clients.end(); it++)
	{
		if (it->second.get_nick() == nick_cmd)
		{
			msg = getMachineHost() + " 433 :" + nick_cmd + " is already in use\r\n";
			send_msg_to_client();
			return ("");
		}
	}
    return (nick_cmd);
}
//--
void    Client_irc::setup_user()
{
    std::string user_cmd;
	std::vector<std::string>	user_splited;
	
	user_cmd = _commands[2];
    
	user_splited = split_string(user_cmd, ' ');
	user_splited[4].insert(0, 1, ':');
	_commands[2].clear();
	for (size_t i = 0; i < user_splited.size(); i++)
	{
		user_splited[i] += " ";
		_commands[2] += user_splited[i];
	}
}
//--
bool	Client_irc::check_user_cmd(char *buf)
{    
    std::string user_cmd;
	std::vector<std::string>	user_splited;
	
    int i = 4;
    while (buf[++i])
        user_cmd += buf[i];
	user_splited = split_string(user_cmd, ' ');
	if (user_splited.size() < 4)
	{
		msg = getMachineHost() + " ERROR :USER :Not enough parameters\r\n";
		send_msg_to_client();
		return(false);
	}
	_user.username = user_splited[0];
	_user.hostname = user_splited[1];
	_user.servername = user_splited[2];
	for (size_t i = 3; i < user_splited.size(); i++)
		_user.realname += user_splited[i];
    return (true);
}
//--
bool	Client_irc::parse_registration(char *buf, std::string pwd, std::map<int, Client_irc> &map_clients)
{
    if (registered)
    {
		msg = error_msg.ERR_ALREADYREGISTRED;
		send_msg_to_client();
        return (true);
    }
	cmd.clear();
	for (int i = 0; i < 5; i++)
		cmd += buf[i];
	if (cmd == "PASS ")
	{
		_pass = check_pass_cmd(buf, pwd);
		if (_pass.empty())
			return (false);
		msg = getMachineHost() +" :--PASS added succesfully--\r\n";
		send_msg_to_client();
	}
	else if (cmd == "NICK ")
	{
		if (_pass.empty())
		{
			msg = getMachineHost() +" ERROR :You must add PASS before !\r\n";
			send_msg_to_client();
			return (false);
		}
		_nick = check_nick_cmd(buf, map_clients);
		if (_nick.empty())
			return (false);
		msg = getMachineHost() +" :--NICK added succesfully--\r\n";
		send_msg_to_client();
	}
	else if (cmd == "USER ")
	{
		if (_nick.empty() || _pass.empty())
		{
			msg = getMachineHost() + " Error :You must add PASS && NICK before !\r\n";
			send_msg_to_client();
			return (false);	
		}
		if (check_user_cmd(buf) == false)
			return (false);
		_user.valid = true;
		msg = getMachineHost() +" :--USER added succesfully--\r\n";
		send_msg_to_client();
	}
	else
	{
		msg = error_msg.ERR_UNKNOWNCOMMAND;
		send_msg_to_client();
	}
    if (!_pass.empty() && !_nick.empty() && _user.valid == true)
		registered = true;
	if (registered == false)
		return (false);
	return (true);
}
//--
void	Client_irc::send_msg_to_client()
{
	if (send(fd_client, msg.c_str(), msg.length(),0) == -1)
			std::perror("send");
}
