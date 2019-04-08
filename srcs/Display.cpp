/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Display Implementation
*/

#include <iostream>
#include "Indie.hpp"

Display::Display(Core *core) : _core(core)
{
	_device = irr::createDevice(irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(1920, 1080));
	_driver = _device->getVideoDriver();
	_smgr = _device->getSceneManager();
	_device->setWindowCaption(L"RocketMan");
	_device->setEventReceiver(&_event);
	_smgr->setAmbientLight(irr::video::SColorf(1.0, 1.0, 1.0, 1.0));
	_smgr->addCameraSceneNode(0, irr::core::vector3df(1.0f, 12.0f,
		0.0f + MAP_WIDTH/2),
		irr::core::vector3df(0.0f + MAP_HEIGHT/2 - 2, 0.0f,
		0.0f + MAP_WIDTH/2));
	_device->setResizable(false);
	_event.setDevice(_device);
	_event.setCore(_core);
}

Display::~Display()
{
	_device->drop();
}

void Display::reset(void)
{
	_driver->beginScene(true, true, irr::video::SColor(0, 111, 165, 186));
}

void Display::draw(void)
{
	_smgr->drawAll();
	_driver->endScene();
}

bool Display::getKey(irr::EKEY_CODE key)
{
	return _event.getKey(key);
}

irr::IrrlichtDevice *Display::getDevice(void)
{
	return _device;
}

irr::video::IVideoDriver *Display::getDriver(void)
{
	return _driver;
}

irr::scene::ISceneManager *Display::getSmgr(void)
{
	return _smgr;
}
