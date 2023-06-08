/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:26:21 by akouame           #+#    #+#             */
/*   Updated: 2023/06/08 16:52:21 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

Server::Server(){
    // std::cout << "Server, default constructor called !" << std::endl;   
}

Server::Server(int port): _port(port){
    // std::cout << "Server, parameter constructor called !" << std::endl;   
}

Server::~Server(){
    // std::cout << "Server, default destructor called !" << std::endl;   
}
//--
void	Server::set_port(int port){
	_port = port;
}

int	Server::get_port(){
	return (_port);
}
//--
void	Server::run_server()
{
	socket_srv = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_srv == -1)
	{
		std::cerr << "Cannot create socket !" << std::endl;
		exit (1);
	}
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(get_port());
	srv_addr.sin_addr.s_addr = INADDR_ANY;
	memset(srv_addr.sin_zero, '\0', sizeof(srv_addr.sin_zero));
	if(bind(socket_srv, (sockaddr *)&srv_addr, sizeof(srv_addr)) == -1)
	{
		std::cerr << "Cannot bind socket !" << std::endl;
		exit (1);
	}
	if (listen(socket_srv, 20)) // backlog = 20
	{
		std::cerr << "Can't listen !" << std::endl;
		exit (1);
	}
	sockaddr_in	client_addr;
	socklen_t	size_clientAddr = sizeof(client_addr);
	int	socket_client = accept(socket_srv, (sockaddr *)&client_addr, &size_clientAddr);
	if (socket_client == -1)
	{
		std::cerr << "Cannot accept connection !" << std::endl;
		exit (1);
	}
	else
		std::cout << "dakchi nadi canadi\n";
	close(socket_client);
	close(socket_srv);
}