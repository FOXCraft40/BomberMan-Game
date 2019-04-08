/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Player class implementation
*/

#include "Indie.hpp"
#include <fstream>
#include <iostream>

Player::Player(Game *game, Display *display, Map *map,
	unsigned int id, std::string const name, std::string const skin)
	: _game(game)
	, _display(display)
	, _map(map)
	, _id(id)
	, _name(name)
	, _skin(skin)
{
	_x = 0;
	_y = 0;
	_score = 0;
	_lives = LIVES_DEFAULT;
	_speed = SPEED_DEFAULT;
	_bombs = 0;
	_bombMax = BOMBS_DEFAULT;
	_power = POWER_DEFAULT;
	_bufferInput = PlayerActions::NOTHING;
	_wallPass = false;
	Player::init3DPlayer();
	_animation = 1.0;
}

Player::~Player()
{
	_anms->remove();
}

void Player::update()
{
	if (_lives == 0)
		return;
	if (_animation != 1) {
		Player::updateAnimation();
		return;
	}
	getDamage();
	if (_lives == 0)
		return;
	getPowerUp();
	putBomb();
	if (_bufferInput != PlayerActions::NOTHING) {
		doActions(_bufferInput);
		_bufferInput = PlayerActions::NOTHING;
	}
}

std::string &Player::getName()
{
	return _name;
}

std::string &Player::getSkin()
{
	return _skin;
}

int Player::getScore()
{
	return _score;
}

int Player::getX()
{
	return _x;
}

int Player::getY()
{
	return _y;
}

int Player::getSpeed()
{
	return _speed;
}

float Player::getAnimation()
{
	return _animation;
}

int Player::getLives()
{
	return _lives;
}

int Player::getBombsMax()
{
	return _bombMax;
}

bool Player::getWallPass()
{
	return _wallPass;
}

int Player::getPower()
{
	return _power;
}

FaceDirection Player::getDirection()
{
	return _faceDirection;
}

void Player::bombExplode()
{
	_bombs--;
}

void Player::startAnimation()
{
	_beginAnimation = Game::getTime();
	_animation = 0;
}

void Player::updateAnimation()
{
	int moveTime;

	moveTime = (MOVE_TIME / 2) + ((MOVE_TIME / SPEED_MAX) *
		(SPEED_MAX - _speed));
	auto timeAnimated = Game::getTime() - _beginAnimation;
	if (timeAnimated > std::chrono::duration<int, std::milli>(moveTime))
		_animation = 1;
	else {
		_animation = (timeAnimated * 100)/
		std::chrono::duration<int, std::milli>(moveTime);
		_animation = _animation / 100;
	}
}

void Player::buffActions(int action)
{
	switch (action) {
		case 0: _bufferInput = PlayerActions::MOVE_UP;
			break;
		case 1: _bufferInput = PlayerActions::MOVE_DOWN;
			break;
		case 2: _bufferInput = PlayerActions::MOVE_LEFT;
			break;
		case 3: _bufferInput = PlayerActions::MOVE_RIGHT;
			break;
		case 4: _putBomb = true;
			break;
		case 5: _bufferInput = PlayerActions::NOTHING;
			break;
	}
}

void Player::doActions(PlayerActions action)
{
	switch (action) {
		case MOVE_UP: Player::moveUp();
			break;
		case MOVE_DOWN: Player::moveDown();
			break;
		case MOVE_LEFT: Player::moveLeft();
			break;
		case MOVE_RIGHT: Player::moveRight();
			break;
	}
}

void Player::moveUp()
{
	MapTile *tile;

	_faceDirection = FACE_UP;
	if (_map->canMove(_x, _y + 1, _wallPass)) {
		Player::startAnimation();
		tile = &_map->getTile(_x, _y);
		tile->player = false;
		_y += 1;
		tile = &_map->getTile(_x, _y);
		tile->player = true;
	}
}

void Player::moveDown()
{
	MapTile *tile;

	_faceDirection = FACE_DOWN;
	if (_map->canMove(_x , _y - 1, _wallPass)) {
		Player::startAnimation();
		tile = &_map->getTile(_x, _y);
		tile->player = false;
		_y -= 1;
		tile = &_map->getTile(_x, _y);
		tile->player = true;
	}
}

void Player::moveLeft()
{
	MapTile *tile;

	_faceDirection = FACE_LEFT;
	if (_map->canMove(_x + 1, _y, _wallPass)) {
		Player::startAnimation();
		tile = &_map->getTile(_x, _y);
		tile->player = false;
		_x += 1;
		tile = &_map->getTile(_x, _y);
		tile->player = true;
	}
}

void Player::moveRight()
{
	MapTile *tile;

	_faceDirection = FACE_RIGHT;
	if (_map->canMove(_x - 1, _y, _wallPass)) {
		Player::startAnimation();
		tile = &_map->getTile(_x, _y);
		tile->player = false;
		_x -= 1;
		tile = &_map->getTile(_x, _y);
		tile->player = true;
	}
}

void Player::putBomb()
{
	MapTile *tile = &_map->getTile(_x, _y);
	Bomb *bomb;

	if (!_putBomb)
		return;
	else if ((_bombs >= _bombMax) || (tile->type == BOMB)
	 	|| (tile->type == WALL)) {
		_putBomb = false;
		return;
	}
	_putBomb = false;
	bomb = new Bomb(_display, _power, this);
	_bombs++;
	tile->type = BOMB;
	tile->entity = bomb;
}

void Player::getDamage()
{
	MapTile *tile;

	tile = &_map->getTile(_x, _y);
	if (tile->fire) {
		tile->fire = false;
		tile->fireVisual->remove();
		_lives--;
	}
	if (_lives == 0)
		die(tile);
}

void Player::getPowerUp()
{
	MapTile *tile;

	tile = &_map->getTile(_x, _y);
	if (tile->type == POWERUP) {
		std::cout << ((PowerUp *)tile->entity)->getPowerUpType();
		((PowerUp *) tile->entity)->applyToPlayer(this, tile);
	}

}

void Player::die(MapTile *tile)
{
	PowerUp *life = new PowerUp(_display, LIFE_UP);

	tile->player = false;
	tile->type = POWERUP;
	tile->entity = life;
}

bool Player::increaseLives()
{
	if (_lives >= LIVES_MAX) {
		_lives = LIVES_MAX;
		return false;
	}
	_lives++;
	return true;
}

bool Player::increaseSpeed()
{
	if (_speed >= SPEED_MAX) {
		_speed = SPEED_MAX;
		return false;
	}
	_speed++;
	return true;
}

bool Player::decreaseSpeed()
{
	if (_speed <= SPEED_MIN) {
		_speed = SPEED_MIN;
		return false;
	}
	_speed--;
	return true;
}

bool Player::increaseBombs()
{
	if (_bombMax >= BOMBS_MAX) {
		_bombMax = BOMBS_MAX;
		return false;
	}
	_bombMax++;
	return true;
}

bool Player::decreaseBombs()
{
	if (_bombMax <= BOMBS_MIN) {
		_bombMax = BOMBS_MIN;
		return false;
	}
	_bombMax--;
	return true;
}

bool Player::increasePower()
{
	if (_power >= POWER_MAX) {
		_power = POWER_MAX;
		return false;
	}
	_power++;
	return true;
}

bool Player::decreasePower()
{
	if (_power <= POWER_MIN) {
		_power = POWER_MIN;
		return false;
	}
	_power--;
	return true;
}

bool Player::enableWallPass()
{
	if (_wallPass)
		return false;
	_wallPass = true;
	return true;
}

void Player::init3DPlayer()
{
	std::string mesh = ASSETS_PLAYER_PATH + Player::getSkin() + ".b3d";
	std::string texture = ASSETS_PLAYER_PATH + Player::getSkin() + ".png";
	irr::scene::ISceneManager *smgr = _display->getSmgr();
	irr::video::IVideoDriver *driver = _display->getDriver();

	if (Player::fexists(mesh) && Player::fexists(texture)) {
		Player::setInitialMeshTexture(mesh, texture, smgr, driver);
		Player::setInitialPosition();
		Player::setInitialAnimation();
		Player::setInitialRotation();
		Player::setInitialScale();
	} else
		std::cout << "ERROR" << std::endl;
}

void Player::setInitialMeshTexture(std::string mesh, std::string texture,
					irr::scene::ISceneManager *smgr,
					irr::video::IVideoDriver *driver)
{
	_anms = smgr->addAnimatedMeshSceneNode(smgr->getMesh(mesh.c_str()));
	_anms->setMaterialTexture(0, driver->getTexture(texture.c_str()));
	_anms->setMaterialFlag(irr::video::EMF_LIGHTING, true);
}

void Player::setInitialPosition()
{
	float width = (float)_map->getWidth() - 1.0;
	float height = (float)_map->getHeight() - 1.0;

	switch(_id) {
		case 0:
			_anms->setPosition(irr::core::vector3df(0, 0, 0));
			break;
		case 1:
			_anms->setPosition(irr::core::vector3df(0, 0, width));
			break;
		case 2:
			_anms->setPosition(irr::core::vector3df(height, 0, 0));
			break;
		case 3:
			_anms->setPosition(irr::core::vector3df(
				height, 0, width));
			break;
	}
	Player::saveInitialPosition(width, height);
}

void Player::saveInitialPosition(float width, float height)
{
	switch(_id) {
		case 1:
			_y = height;
			break;
		case 2:
			_x = width;
			break;
		case 3:
			_y = height;
			_x = width;
			break;
		default:
			break;
	}
	_oldPosition = _anms->getPosition();
}

void Player::setInitialRotation()
{
	switch(_id) {
		case 0:
			_anms->setRotation(irr::core::vector3df(0, 225, 0));
			break;
		case 1:
			_anms->setRotation(irr::core::vector3df(0, 90, 0));
			break;
		case 2:
			_anms->setRotation(irr::core::vector3df(0, -35, 0));
			break;
		case 3:
			_anms->setRotation(irr::core::vector3df(0, 45, 0));
			break;
	}
}

void Player::setInitialScale()
{
	_anms->setScale(irr::core::vector3df(7.5f, 7.5f, 7.5f));
}

void Player::setInitialAnimation()
{
	_anms->setFrameLoop(52, 75);
	_anms->setAnimationSpeed(25);
}

void Player::display()
{
	irr::core::vector3df newPosition = _oldPosition;

	Player::setOrientation();
	if (_lives == 0) {
		_oldPosition = {(float)-1000, 0, (float)-1000};
		_anms->setPosition(_oldPosition);
		return;
	}
	if (_animation == 1) {
		_oldPosition = {(float)_y, 0, (float)_x};
		_anms->setPosition(_oldPosition);
		Player::resetAnimation();
	} else {
		Player::computeFrameLoop();
		Player::computeNewPosition(&newPosition);
		_anms->setPosition(newPosition);
	}
}

void Player::computeNewPosition(irr::core::vector3df *newPosition)
{
	if (_oldPosition.Z < _x)
		newPosition->Z = _oldPosition.Z + (_animation);
	else if (_oldPosition.Z > _x)
		newPosition->Z = _oldPosition.Z - (_animation);
	else if (_oldPosition.X < _y)
		newPosition->X = _oldPosition.X + (_animation);
	else
		newPosition->X = _oldPosition.X - (_animation);
}

void Player::setOrientation()
{
	switch (_faceDirection) {
		case FACE_UP :
			_anms->setRotation(irr::core::vector3df(0, -90, 0));
			break;
		case FACE_DOWN :
			_anms->setRotation(irr::core::vector3df(0, 90, 0));
			break;
		case FACE_LEFT :
			_anms->setRotation(irr::core::vector3df(0, 180, 0));
			break;
		case FACE_RIGHT :
			_anms->setRotation(irr::core::vector3df(0, -360, 0));
			break;
	}
}

void Player::computeFrameLoop()
{
	if (_anms->getStartFrame() != 140) {
		_anms->setAnimationSpeed(100);
		_anms->setFrameLoop(140, 189);
	}
}

void Player::resetAnimation()
{
	if (_anms->getStartFrame() != 52) {
		_anms->setFrameLoop(52, 75);
	}
}

bool Player::fexists(const std::string filename)
{
	std::ifstream ifile(filename.c_str());
	return (bool)ifile;
}
