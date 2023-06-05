# ft_irc
Create your own IRC server in C++, fully compatible with an official client.
---------------------------------------------------------
This project aims to provide a fully compatible IRC (Internet Relay Chat) server implemented in C++. It allows you to create your own IRC server that can communicate with official IRC clients.

#Features
Compatibility: The server is designed to be fully compatible with the IRC protocol as specified in RFC 1459 (or later versions).
Client Communication: Supports bidirectional communication between the server and IRC clients using TCP/IP sockets.
User Management: Allows clients to register, log in, and manage user information.
Channel Management: Supports the creation, joining, and leaving of channels, as well as managing channel permissions and settings.
Message Routing: Implements message routing to deliver messages between users and channels according to the IRC protocol.
Error Handling: Includes error handling mechanisms to handle exceptions, socket errors, and unexpected behavior.
Security: Provides basic security measures, such as authentication and access control, to ensure secure communication with the server.
Event-Driven Design: Designed with an event-driven architecture to handle multiple client connections simultaneously.
Requirements
C++98 compatible compiler (e.g., GCC or Clang)
Standard C++98 libraries
