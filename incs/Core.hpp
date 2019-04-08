/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Core class definition
*/

#pragma once

#include <vector>
#include <string>
#include "Indie.hpp"

class Display;
class State;

class Core {
	private:
		bool _running;
		Display *_display;
		std::vector<State *> _states;
		State *_state;
		void update();

	public:
		Core();
		~Core();
		void start();
		void stop();
		void changeState(std::string const stateName);
		Display *getDisplay();
};