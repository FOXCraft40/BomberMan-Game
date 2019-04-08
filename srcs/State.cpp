/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** State abstract class implementation
*/

#include "Indie.hpp"


State::State(Core *core, Display *display, std::string name)
	: _core(core)
	, _display(display)
	, _name(name)
{
	_enabled = false;
}

State::~State()
{
}

void State::enable() {
	_enabled = true;
}

void State::disable() {
	_enabled = false;
}

std::string State::getName()
{
	return _name;
}

bool State::isEnabled()
{
	return _enabled;
}
