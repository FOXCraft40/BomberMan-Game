/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Entry point
*/

#include <iostream>
#include <memory>
#include <exception>
#include "Indie.hpp"

int main(int ac, char **av)
{
	std::shared_ptr<Core> core;

	try {
		core = std::shared_ptr<Core>(new Core());
		core.get()->start();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	return 0;
}