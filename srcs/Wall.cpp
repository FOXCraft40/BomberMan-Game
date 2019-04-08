/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall class implementation
*/

#include <irrlicht.h>
#include "Indie.hpp"

Wall::Wall(Display *display, bool breakable, PowerUp *powerUp)
	: Entity::Entity(WALL, display)
	, _breakable(breakable)
	, _powerUp(powerUp)
{
	_isDisplayed = false;
}

Wall::~Wall()
{
	_wall->remove();
}

void Wall::explode(Map *map, MapTile *tile)
{
	if (Wall::isBreakable()) {
		if (Wall::containsPowerUp()) {
			tile->type = POWERUP;
			tile->entity = Wall::getPowerUp();
		} else {
			tile->type = EMPTY;
			tile->entity = NULL;
		}
		delete this;
	}
}

void Wall::display(int x, int y)
{
	if (_isDisplayed)
		return;
	_isDisplayed = true;
	if (_breakable) {
		_wall = _display->getSmgr()->addAnimatedMeshSceneNode(
			_display->getSmgr()->getMesh(OBJ_BREAKABLES_WALL));
		_wall->setMaterialTexture(0,
			_display->getDriver()->getTexture(PNG_BREAKABLES_WALL));
	}
	else {
		_wall = _display->getSmgr()->addAnimatedMeshSceneNode(
			_display->getSmgr()->getMesh(OBJ_FIXED_WALL));
		_wall->setMaterialTexture(0,
			_display->getDriver()->getTexture(PNG_FIXED_WALL));
	}
	_wall->setPosition(irr::core::vector3df(y, 0.0f, x));
}

bool Wall::isBreakable()
{
	return _breakable;
}

bool Wall::containsPowerUp()
{
	return (bool) _powerUp;
}

PowerUp *Wall::getPowerUp()
{
	return _powerUp;
}
