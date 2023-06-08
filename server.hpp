/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:43 by akouame           #+#    #+#             */
/*   Updated: 2023/06/08 16:42:39 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class   Server
{
	int _port;
	
	public:
		struct sockaddr_in	srv_addr;
		int	socket_srv;
		Server();
		Server(int port);
		~Server();
		void	run_server();
		int	get_port();
		void	set_port(int port);
};

#endif