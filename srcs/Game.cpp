/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Game class implementation
*/

#include <iostream>
#include <ctime>
#include "Indie.hpp"

std::chrono::system_clock::time_point Game::_time =
	std::chrono::system_clock::now();

Game::Game(Core *core, Display *display)
	: State(core, display, "Game")
{
	_map = new Map(this, _display, MAP_WIDTH, MAP_HEIGHT);
	_players[0] = new Player(this, _display, _map, 0, "Kim", "Kim");
	_players[1] = new Player(this, _display, _map, 1, "Donald", "Donald");
	_players[2] = new Player(this, _display, _map, 2, "Vlad", "Vlad");
	_players[3] = new Player(this, _display, _map, 3, "Bachar", "Bachar");
	_gui = new GUI(_players, _display);
}

Game::~Game()
{
	for (int i = 0; i < 4; i++)
		delete _players[i];
	delete _map;
}

void Game::playerActions()
{
	for (int i = 0; i < 4; i++) {
		for (int y = 0; y < 5; y++) {
			if (_display->getKey(KEYSMAP[i][y])) {
				_players[i]->buffActions(y);
				break;
			}
			_players[i]->buffActions(5);
		}
		if (_display->getKey(KEYSMAP[i][4]))
			_players[i]->buffActions(4);
	}
}

void Game::enable()
{
	State::enable();
}

void Game::disable()
{
	State::disable();
}

void Game::update()
{
	Game::setTime();
	Game::playerActions();
	_map->update();
	for (int i = 0; i < 4; i++)
		_players[i]->update();
	_gui->update();
	if (_display->getKey(irr::KEY_ESCAPE))
		_core->changeState("MainMenu");
}

void Game::display()
{
	_map->display();
	for (int i = 0; i < 4; i++)
		_players[i]->display();
}

void Game::setTime()
{
	Game::_time = std::chrono::system_clock::now();
}

std::chrono::system_clock::time_point Game::getTime() {
	return Game::_time;
}
