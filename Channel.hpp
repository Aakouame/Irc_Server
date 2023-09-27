/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadi <akadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:20:42 by yel-qabl          #+#    #+#             */
/*   Updated: 2023/06/20 19:10:58 by akadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHANNEL_HPP
#define CHANNEL_HPP

// #include <map>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <utility>
// #include <sys/socket.h>
#include "client_irc.hpp"
#include "ft_irc.hpp"

class IrcServer;
class Client_irc;

class Channel {
    private :
        std::string                      name; // channel name
        std::string                      owner; // channel creator
        std::string                      topic;
        // std::map<std::string, Client_irc> clients; // list of clients in channel  
        bool                             invite_only; // if true, only invited users can join
        std::vector<std::string>         invited_users; // list of users invited to channel
        bool                             is_private; // if true, only invited users can join
        bool                             is_secret; // if true, channel is not listed in /list
        bool                             op_topic; // if true, only operator can change topic
        bool                             no_msg; // if true, only operator can send message
        bool                             moderated; // if true, only users in who_speak_on_moderated can speak
        std::string                      key; // password to join channel
        std::vector<std::string>         who_speak_on_moderated; // list of users who can speak on moderated channel
    public:
        Channel();
        Channel(std::string name, Client_irc *c);
        ~Channel();
		
        Channel &operator=(const Channel &c);
		
        std::vector<std::string>         			operators; // list of operators
        std::map<std::string, Client_irc*>			clients; // list of clients in channel  
        std::size_t                                 user_limit; // max number of users in channel
        std::size_t						    		number_of_users; 

        
        int        broadcast(std::string message, int sender); // send message to all Client_ircs
        // int     connect(Client_irc &c); // add Client_irc to channel
        // int     disconnect(Client_irc &c); // remove Client_irc from channel
        // int     disconnect(std::string nickname); // remove Client_irc from channel
        // int     cmd_kick(std::string nickname); // kick Client_irc from channel
        int         cmd_invite(std::string nickname); // invite Client_irc to channel
        int        set_topic(std::string topic); // change channel topic
        // int     cmd_names(Client_irc &sender); // send list of Client_ircs in channel
        // int     cmd_who(Client_irc &sender); // send list of Client_ircs in channel 
        int        add_operator(std::string nick); // add operator to channel
        int        remove_operator(std::string nick); // remove operator from channel
        // int     change_operator(std::string sign, std::string nick); // change operator status
        // int     Client_irc_count(); // return number of Client_ircs in channel 
        // int     list_cmd(Client_irc &sender); // send list of command available in channel
        // int     join_command(std::vector<std::string> const &command, Client_irc &client);
        // int     kick_cmd(std::vector<std::string> const &command, Client_irc &client);
        
        // // setters
        
        // int     change_to_private(std::string sign); // change channel privacy
        // int     change_to_secret(std::string sign);  // change channel privacy
        int        change_optopic(std::string sign); // change topic privacy
        // int     change_nomsg(std::string sign); // change message privacy
        // int     change_moderated(std::string sign);     // change moderated status
        int        change_userlimits(std::string sign, std::size_t limit); // change user limit
        int        change_password(std::string sign, std::string key); // change channel password
        int        change_invite(std::string sign); // change invite only status
        // int     change_who_speaks_on_moderated(std::string sign, std::string user); // change who can speak on moderated channel
        void        set_key(std::string);
        void		set_invite_only(bool valid);
        // //getters

        std::string                     get_topic(); // return channel topic
        // std::string                  get_name() const; // return channel name
        // Client_irc                      *get_channel_operator() const; // return channel operator
        // bool                         is_invited(std::string nick); // check if user is invited
        bool                            is_operator(std::string nickname); // check if user is operator
        // bool                         is_member(Client_irc &c); // check if user is member by Client_irc object 
        // bool                         is_member(std::string nickname); // check if user is member by nickname
        // bool                         can_invite(Client_irc &c); // check by Client_irc object if user can invite
        // int                          can_invite(std::string nickname); // check by nickname if user can invite
        bool                            get_invite_only() const; // check if channel is invite only
        // bool                         get_is_private() const; // check if channel is private
        // bool                         get_is_secret() const; // check if channel is secret
        bool                            get_op_topic() const; // check if only operator can change topic
        // bool                         get_no_msg() const; // check if only operator can send message
        // bool                         get_moderated() const; // check if channel is moderated
        // int                          get_user_limit() const; // return user limit
        // bool                         can_speak_on_channel(std::string nick); // check if user can speak on moderated channel
        // bool                         limit_full(); // check if channel is full
        // std::string                  get_password() const; // return channel password
        // std::vector<std::string>     get_who_speak_on_moderated() const; // return list of users who can speak on moderated channel
        std::vector<std::string>        get_invited_user() const; // return list of invited users
        std::vector<std::string>        get_operators() const; //  return list of operators
        // std::string                  channel_modes();  // return channel modes 
        
        std::string		get_key();
	bool			get_invite_only();
    std::string     get_owner();
};

#endif 