/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map class implementation
*/

#include <irrlicht.h>
#include <exception>
#include <iostream>
#include <random>
#include "Indie.hpp"

Map::Map(Game *game, Display *display, unsigned int width, unsigned int height)
	: _game(game)
	, _display(display)
	, _width(width)
	, _height(height)
{
	_map = std::vector<MapTile>(height * width);
	Map::fill();
	Map::generate();
	Map::displayGround();
	Map::displayEntity();
}

Map::~Map()
{
	for (int i = _cubes.size()-1; i != -1; i--)
		_cubes.at(i)->remove();
	for (int i = 0; i != _width; i++) {
		for (int x = 0; x != _height; x++) {
			if (getTile(i, x).type != EMPTY
				&& getTile(i, x).entity != NULL) {
				delete getTile(i, x).entity;
			}
		}
	}
}

MapTile &Map::getTile(unsigned int x, unsigned int y)
{
	if (x >= _width && y >= _height)
		throw std::invalid_argument("No enought tiles on map");
	return _map[y * _width + x];
}

bool Map::canMove(int x, int y, bool wall_pass)
{
	MapTile *tile;

	if ((x < 0) || (y < 0) ||
		(x > MAP_WIDTH - 1) || (y > MAP_HEIGHT - 1))
		return false;
	tile = &getTile(x, y);
	if (tile->player)
		return false;
	if (wall_pass)
		return true;
	else if ((tile->type == BOMB) || (tile->type == WALL))
		return false;
	else
		return true;
}

bool Map::isThereBomb(int x, int y)
{
	if (getTile(x, y).type == BOMB)
		return true;
	return false;
}

bool Map::isThereFire(int x, int y)
{
	if (getTile(x, y).fire)
		return true;
	return false;
}

void Map::update(void)
{
	for (int i = 0; i != _width; i++) {
		for (int x = 0; x != _height; x++) {
			MapTile *tile = &getTile(i ,x);
			if (tile->type == BOMB) {
				Bomb *bomb = (Bomb *) tile->entity;
				bomb->update(this, tile);
			} else if (tile->fire){
				if (tile->fireEnd < Game::getTime()) {
					tile->fire = false;
					tile->fireVisual->remove();
				}
			}
		}
	}
}

void Map::display(void)
{
	Map::displayEntity();
}

void Map::generate()
{
	Map::generateWallCircles();
	Map::breakCircles();
	Map::randomiseBreakables();
	Map::removeVertex();
	Map::removeTemporary();
}

unsigned int Map::getWidth(void)
{
	return _width;
}

unsigned int Map::getHeight(void)
{
	return _height;
}

void Map::displayGround(void)
{
	bool on = true;

	for (int i = 0; i != _width ; i++) {
		for (int x = 0; x != _height; x++) {
			if (on)
				displayCube(i, x, OBJ_GROUND1, JPG_GROUND1);
			else
				displayCube(i, x, OBJ_GROUND2, JPG_GROUND2);
			on = !on;
		}
	}
}

void Map::displayCube(int i, int x, std::string const obj,
	std::string const png)
{
	irr::scene::ISceneNode *cube =
		_display->getSmgr()->addAnimatedMeshSceneNode(
		_display->getSmgr()->getMesh(obj.c_str()));
	cube->setPosition(irr::core::vector3df(0.0f + x, -1.0f, 0.0f + i));
	cube->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	cube->setMaterialTexture(0, _display->getDriver()->getTexture(
		png.c_str()));
	_cubes.push_back(cube);
}

void Map::displayEntity()
{
	MapTile *tile;

	for (int i = 0; i != _width; i++) {
		for (int x = 0; x != _height; x++) {
			tile = &getTile(i, x);
			if (tile->type != EMPTY
				&& tile->entity != NULL) {
				tile->entity->display(i, x);
			}
		}
	}
}

void Map::fill()
{
	MapTile *tile;

	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			tile = &Map::getTile(x, y);
			tile->x = x;
			tile->y = y;
			tile->fire = false;
			tile->player = false;
			tile->fireEnd = Game::getTime();
			tile->type = EMPTY;
			tile->entity = NULL;
		}
	}
}

void Map::generateWallCircles()
{
	MapTile *tile;

	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			tile = &Map::getTile(x, y);
			if (x % 2 == 0 || y % 2 == 0)
				tile->type = TEMPORARY_UNBREAKABLE;
		}
	}
}

void Map::breakCircles()
{
	MapTile *tile;
	std::default_random_engine generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, 4);
	int randomised = 0;

	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			tile = &Map::getTile(x, y);
			if (tile->type == EMPTY) {
				randomised = distribution(generator);
				Map::breakCircle(tile, randomised);
				randomised = distribution(generator);
				Map::breakCircle(tile, randomised);
			}
		}
	}
}

void Map::breakCircle(MapTile *tile, int randomised)
{
	int newX = tile->x;
	int newY = tile->y;

	switch (randomised) {
		case 0:
			newX -= 1;
		case 1:
			newY -= 1;
		case 2:
			newX += 1;
		case 3:
			newY += 1;
	}
	if (Map::getTile(newX, newY).type == TEMPORARY_EMPTY) {
		randomised = randomised + 1 >= 4 ? 0 : randomised + 1;
		Map::breakCircle(tile, randomised);
	} else
		Map::getTile(newX, newY).type = TEMPORARY_EMPTY;
}

void Map::randomiseBreakables()
{
	MapTile *tile;
	std::default_random_engine generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, 100);

	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			tile = &Map::getTile(x, y);
			if (tile->type == TEMPORARY_EMPTY)
				tile->type = EMPTY;
			if (tile->type == EMPTY && distribution(generator) >=
				PROP(PROP_BREAKABLES_ON_EMPTY))
				tile->type = TEMPORARY_BREAKABLE;
			if (tile->type == TEMPORARY_UNBREAKABLE &&
				distribution(generator) >
				PROP(PROP_BREAKABLES_ON_UNBREAKABLES))
				tile->type = TEMPORARY_BREAKABLE;
		}
	}
}

void Map::removeVertex()
{
	Map::getTile(0, 0).type = EMPTY;
	Map::getTile(1, 0).type = EMPTY;
	Map::getTile(0, 1).type = EMPTY;
	Map::getTile(_width - 1, 0).type = EMPTY;
	Map::getTile(_width - 1, 1).type = EMPTY;
	Map::getTile(_width - 2, 0).type = EMPTY;
	Map::getTile(0, _height - 1).type = EMPTY;
	Map::getTile(1, _height - 1).type = EMPTY;
	Map::getTile(0, _height - 2).type = EMPTY;
	Map::getTile(_width - 1, _height - 1).type = EMPTY;
	Map::getTile(_width - 1, _height - 2).type = EMPTY;
	Map::getTile(_width - 2, _height - 1).type = EMPTY;
}

PowerUpType Map::pickPowerUpType(int i)
{
	switch (i) {
		case 1:
			return SPEED_UP;
			break;
		case 2:
			return SPEED_DOWN;
			break;
		case 3:
			return BOMB_UP;
			break;
		case 4:
			return BOMB_DOWN;
			break;
		case 5:
			return POWER_UP;
			break;
		case 6:
			return POWER_DOWN;
			break;
	}
	return LIFE_UP;
}

PowerUp *Map::randomPowerUp()
{
	PowerUp *powerUp;
	std::default_random_engine generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(1,6);

	powerUp = new PowerUp(_display,
		pickPowerUpType(distribution(generator)));
	std::uniform_int_distribution<int> wallPass(0, 42);
	if (wallPass(generator) == 0)
		powerUp = new PowerUp(_display, WALL_PASS);
	return (powerUp);
}

void Map::removeTemporary()
{
	MapTile *tile;

	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			tile = &Map::getTile(x, y);
			if (tile->type == TEMPORARY_UNBREAKABLE) {
				tile->entity = new Wall(_display, false, NULL);
				tile->type = WALL;
			} else if (tile->type == TEMPORARY_BREAKABLE) {
				tile->entity = new Wall(_display, true, randomPowerUp());
				tile->type = WALL;
			}
		}
	}
}
