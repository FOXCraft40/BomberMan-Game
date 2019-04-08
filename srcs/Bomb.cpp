/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Bomb class implementation
*/

#include <iostream>
#include "Indie.hpp"

Bomb::Bomb(Display *display, unsigned int power, Player * owner)
	: Entity::Entity(BOMB, display)
	, _power(power)
	, _owner(owner)
{
	_end = Game::getTime() +
		std::chrono::duration<int, std::milli>(EXPLOSION_TIME);
	_isDisplayed = false;
}

Bomb::~Bomb()
{
	if (_graphicalObj)
		_graphicalObj->remove();
}

void Bomb::update(Map *map, MapTile *tile)
{
	if (Game::getTime() >= _end)
		Bomb::explode(map, tile);
}

void Bomb::display(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	if (_isDisplayed)
		return;
	_isDisplayed = true;
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 0, 0));
	_graphicalObj = _display->getSmgr()->addAnimatedMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_BOMB));
	_graphicalObj->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_BOMB));
	_graphicalObj->setScale(irr::core::vector3df(2.0f, 2.0f, 2.0f));
	_graphicalObj->setPosition(irr::core::vector3df(y, 0.5f, x));
	if (anim) {
		_graphicalObj->addAnimator(anim);
		anim->drop();
	}
}

unsigned int Bomb::getPower()
{
	return _power;
}

void Bomb::drawFire(MapTile *tile)
{
	tile->fireVisual = _display->getSmgr()->addMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_CONE));
	tile->fireVisual->setPosition(	irr::core::vector3df(tile->y, 0.5f,
		tile->x));
	tile->fireVisual->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_CONE));
	tile->fireVisual->setScale(irr::core::vector3df(0.02f, 0.02f, 0.02f));
}

void Bomb::explode(Map *map, MapTile *tile)
{
	_owner->bombExplode();
	tile->type = EMPTY;
	tile->entity = NULL;
	if (!tile->fire)
		drawFire(tile);
	tile->fire = true;
	tile->fireEnd = Game::getTime() +
		std::chrono::duration<int, std::milli>(FIRE_TIME);
	Bomb::propagateFireXn(map, tile);
	Bomb::propagateFireX(map, tile);
	Bomb::propagateFireYn(map, tile);
	Bomb::propagateFireY(map, tile);
	delete this;
}

void Bomb::propagateFireXn(Map *map, MapTile *tile)
{
	MapTile *nextTile;

	for (int i = 1; i < _power && (int) tile->x - i >= 0; i++) {
		nextTile = &map->getTile(tile->x - i, tile->y);
		if (nextTile->type == WALL) {
			((Wall *) nextTile->entity)->explode(map, nextTile);
			break;
		} else if (nextTile->type == BOMB) {
			break;
		} else {
			if (!nextTile->fire)
				drawFire(nextTile);
			nextTile->fire = true;
			nextTile->fireEnd = tile->fireEnd;
		}
	}
}

void Bomb::propagateFireX(Map *map, MapTile *tile)
{
	MapTile *nextTile;

	for (int i = 1; i < _power && tile->x + i < map->getWidth(); i++) {
		nextTile = &map->getTile(tile->x + i, tile->y);
		if (nextTile->type == WALL) {
			((Wall *) nextTile->entity)->explode(map, nextTile);
			break;
		} else if (nextTile->type == BOMB) {
			break;
		} else {
			if (!nextTile->fire)
				drawFire(nextTile);
			nextTile->fire = true;
			nextTile->fireEnd = tile->fireEnd;
		}
	}
}

void Bomb::propagateFireYn(Map *map, MapTile *tile)
{
	MapTile *nextTile;

	for (int i = 1; i < _power && (int) tile->y - i >= 0; i++) {
		nextTile = &map->getTile(tile->x, tile->y - i);
		if (nextTile->type == WALL) {
			((Wall *) nextTile->entity)->explode(map, nextTile);
			break;
		} else if (nextTile->type == BOMB) {
			break;
		} else {
			if (!nextTile->fire)
				drawFire(nextTile);
			nextTile->fire = true;
			nextTile->fireEnd = tile->fireEnd;
		}
	}
}

void Bomb::propagateFireY(Map *map, MapTile *tile)
{
	MapTile *nextTile;

	for (int i = 1; i < _power && tile->y + i < map->getHeight(); i++) {
		nextTile = &map->getTile(tile->x, tile->y + i);
		if (nextTile->type == WALL) {
			((Wall *) nextTile->entity)->explode(map, nextTile);
			break;
		} else if (nextTile->type == BOMB) {
			break;
		} else {
			if (!nextTile->fire)
				drawFire(nextTile);
			nextTile->fire = true;
			nextTile->fireEnd = tile->fireEnd;
		}
	}
}
