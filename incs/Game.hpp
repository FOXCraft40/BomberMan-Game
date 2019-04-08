/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Game class definition
*/

#pragma once

#include <chrono>

class Core;
class Player;
class Display;
class Map;
class GUI;

class Game : public State {
	private:
		Player *_players[4];
		Map *_map;
		GUI *_gui;
		static std::chrono::system_clock::time_point _time;

	public:
		Game(Core *core, Display *display);
		~Game();
		void playerActions();
		void enable();
		void disable();
		void update();
		void display();
		static void setTime();
		static std::chrono::system_clock::time_point getTime();
};
