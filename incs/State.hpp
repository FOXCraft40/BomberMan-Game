/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** State abstract class definition
*/

#pragma once

#include <string>

class Core;
class Display;

class State : public IState {
	protected:
		Core *_core;
		Display *_display;
		std::string _name;
		bool _enabled;

	public:
		State(Core *core, Display *display, std::string name);
		virtual ~State();
		void enable();
		void disable();
		std::string getName();
		bool isEnabled();
		virtual void update() = 0;
		virtual void display() = 0;
};
