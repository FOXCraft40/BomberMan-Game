/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IState interface definition
*/

#pragma once

class IState {
	public:
		virtual void enable() = 0;
		virtual void disable() = 0;
		virtual void update() = 0;
		virtual void display() = 0;
};
