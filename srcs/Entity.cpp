/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Entity abstract class implementation
*/

#include "Indie.hpp"

Entity::Entity(EntityType type, Display *display)
	: _type(type)
	, _display(display)
{
}

Entity::~Entity()
{	
}

EntityType Entity::getType()
{
	return _type;
}
