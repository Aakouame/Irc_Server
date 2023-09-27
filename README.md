# IRC Server in C++ - Readme

This project aims to provide a fully compatible IRC (Internet Relay Chat) server implemented in C++. It allows you to create your own IRC server that can communicate with official IRC clients.

## Features

- **Compatibility**: The server is designed to be fully compatible with the IRC protocol as specified in RFC 1459 (or later versions).
- **Client Communication**: Supports bidirectional communication between the server and IRC clients using TCP/IP sockets.
- **User Management**: Allows clients to register, log in, and manage user information.
- **Channel Management**: Supports the creation, joining, and leaving of channels, as well as managing channel permissions and settings.
- **Message Routing**: Implements message routing to deliver messages between users and channels according to the IRC protocol.
- **Error Handling**: Includes error handling mechanisms to handle exceptions, socket errors, and unexpected behavior.
- **Security**: Provides basic security measures, such as authentication and access control, to ensure secure communication with the server.
- **Event-Driven Design**: Designed with an event-driven architecture to handle multiple client connections simultaneously.

## Requirements

- C++98 compatible compiler
- Standard C++98 libraries

## Getting Started

1. Clone the project repository:

   ```bash
   git clone https://github.com/Aakouame/ft_irc.git
   cd ft_irc
   make

   ```
3. Connect your IRC client to the server:

   Use your preferred IRC client software and connect to the IP address and port on which the server is running (default is `localhost:6667`).

4. Enjoy using your custom IRC server!

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request. Make sure to follow the existing code style and guidelines.

## Acknowledgments

This project was inspired by the IRC protocol specifications and aims to provide a basic IRC server implementation for educational purposes.

## References

- IRC Protocol Specifications: [RFC 1459](https://tools.ietf.org/html/rfc1459)
- punch.wa.us.dal.net
- https://irc.dalexhd.dev/
- ...

## collaboration with KD-ayoub and youssefqabli
