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

- C++98 compatible compiler (e.g., GCC or Clang)
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

## Configuration

The server configuration can be modified in the `config.txt` file. The following parameters can be adjusted:

- `PORT`: The port number on which the server listens for incoming connections.
- `MAX_CLIENTS`: The maximum number of simultaneous client connections the server can handle.
- `MAX_CHANNELS`: The maximum number of channels the server can manage.
- `MAX_USERS`: The maximum number of registered users the server can handle.

Feel free to modify these parameters to suit your needs.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request. Make sure to follow the existing code style and guidelines.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). You are free to modify, distribute, and use the code for personal or commercial purposes.

## Acknowledgments

This project was inspired by the IRC protocol specifications and aims to provide a basic IRC server implementation for educational purposes.

## References

- IRC Protocol Specifications: [RFC 1459](https://tools.ietf.org/html/rfc1459)