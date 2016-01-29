//
// main.cpp for main in /home/plasko_a/projet/gomoku/source/client
//
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
//
// Started on  Mon Jan 25 18:31:24 2016 Antoine Plaskowski
// Last update Wed Jan 27 11:29:33 2016 Antoine Plaskowski
//

#include	<iostream>
#include	<exception>
#include	"Client.hpp"

int	main(void) try
{
    Client	client;

    client.run();
}
catch (std::exception &e)
{
	std::cerr << e.what() << std::endl;
}