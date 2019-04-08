/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Entity abstract class definition
*/

#pragma once

#include "EntityType.hpp"
#include "IEntity.hpp"

class Display;

class Entity : public IEntity {
	protected:
		EntityType _type;
		Display *_display;
		bool _isDisplayed;

	public:
		Entity(EntityType type, Display *display);
		virtual ~Entity();
		EntityType getType();
		virtual void display(int x, int y) = 0;
};
