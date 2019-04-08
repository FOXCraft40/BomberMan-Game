/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Core class implementation
*/

#include <iostream>
#include <exception>
#include "Indie.hpp"

Core::Core()
{
	_running = false;
	_display = new Display(this);
}

Core::~Core()
{
	delete _display;
}

void Core::start()
{
	_running = true;
	Core::changeState("MainMenu");
	while (_running && _display->getDevice()->run())
		Core::update();
}

void Core::stop()
{
	_running = false;
}

void Core::changeState(std::string const stateName)
{
	if (_state)
		delete _state;
	if (stateName == "MainMenu")
		_state = new MainMenu(this, _display);
	else if (stateName == "Game")
		_state = new Game(this, _display);
}

Display *Core::getDisplay()
{
	return _display;
}

void Core::update()
{
	_display->reset();
	_state->update();
	_state->display();
	_display->draw();
}
