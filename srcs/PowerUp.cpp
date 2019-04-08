/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** PowerUp abstract class implementation
*/

#include <iostream>
#include "Indie.hpp"

PowerUp::PowerUp(Display *display, PowerUpType type)
	: Entity::Entity(POWERUP, display)
{
	_PowerUpType = type;
	_isDisplayed = false;
}

PowerUp::~PowerUp()
{
	_powerUp->remove();
}

void PowerUp::applyToPlayer(Player *player, MapTile *tile)
{
	bool 	consume;

	switch (_PowerUpType) {
		case LIFE_UP:
			consume = player->increaseLives();
			break;
		case SPEED_UP:
		 	consume = player->increaseSpeed();
			break;
		case SPEED_DOWN:
		 	consume = player->decreaseSpeed();
			break;
		case BOMB_UP:
		 	consume = player->increaseBombs();
			break;
		case BOMB_DOWN:
		 	consume = player->decreaseBombs();
			break;
		case POWER_UP:
		 	consume = player->increasePower();
			break;
		case POWER_DOWN:
		 	consume = player->decreasePower();
			break;
		case WALL_PASS:
		 	consume = player->enableWallPass();
			break;
	}
	if (consume) {
		tile->type = EMPTY;
		((PowerUp *) tile->entity)->_powerUp->remove();
	}

}

PowerUpType PowerUp::getPowerUpType()
{
	return _PowerUpType;
}

void PowerUp::displayLifeUp(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->addMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_LIFE_UP));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, true);
	_powerUp->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_LIFE_UP));
	_powerUp->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::displaySpeedUp(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->addMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_SPEED_UP));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_powerUp->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_SPEED_UP));
	_powerUp->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::displaySpeedDown(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->
		addMeshSceneNode(_display->getSmgr()->getMesh(OBJ_SPEED_DOWN));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_powerUp->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_SPEED_DOWN));
	_powerUp->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::displayBombUp(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->
		addMeshSceneNode(_display->getSmgr()->getMesh(OBJ_BOMB_UP));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, true);
	_powerUp->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_BOMB_UP));
	_powerUp->setScale(irr::core::vector3df(2.0f, 2.0f, 2.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::displayBombDown(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->addMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_BOMB_DOWN));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, true);
	_powerUp->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_BOMB_DOWN));
	_powerUp->setScale(irr::core::vector3df(2.0f, 2.0f, 2.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::displayPowerUp(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->addMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_POWER_UP));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_powerUp->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_POWER_UP));
	_powerUp->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::displayPowerDown(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->addMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_POWER_DOWN));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_powerUp->setMaterialTexture(0,
		_display->getDriver()->getTexture(PNG_POWER_DOWN));
	_powerUp->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::displayWallPass(int x, int y)
{
	irr::scene::ISceneNodeAnimator* anim;

	_powerUp = _display->getSmgr()->addMeshSceneNode(
		_display->getSmgr()->getMesh(OBJ_WALL_PASS));
	anim = _display->getSmgr()->createRotationAnimator(
		irr::core::vector3df(0, 1, 0));
	_powerUp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_powerUp->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	_powerUp->setPosition(irr::core::vector3df(y, 0.0f, x));
	if (anim) {
		_powerUp->addAnimator(anim);
		anim->drop();
	}
}

void PowerUp::display(int x, int y)
{
	if (_isDisplayed)
		return;
	_isDisplayed = true;
	switch (PowerUp::getPowerUpType()) {
		case LIFE_UP:
			displayLifeUp(x, y);
			break;
		case SPEED_UP:
			displaySpeedUp(x, y);
			break;
		case SPEED_DOWN:
			displaySpeedDown(x, y);
			break;
		case BOMB_UP:
			displayBombUp(x, y);
			break;
		case BOMB_DOWN:
			displayBombDown(x, y);
			break;
		case POWER_UP:
			displayPowerUp(x, y);
			break;
		case POWER_DOWN:
			displayPowerDown(x, y);
			break;
		case WALL_PASS:
			displayWallPass(x, y);
			break;
	}
}
