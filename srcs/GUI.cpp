/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GUI implementation
*/

#include "Indie.hpp"
#include <iostream>

GUI::GUI(Player **players, Display *display)
	: _display(display), _players(players)
{
	GUI::initGUIEnvironment();
	GUI::loadTextures();
}

GUI::~GUI()
{
	_env->clear();
}

void GUI::initGUIEnvironment()
{
	_env = _display->getDevice()->getGUIEnvironment();
	_screenSize = _display->getDriver()->getScreenSize();
}

void GUI::loadTextures()
{
	_liveTexture = _display->getDriver()->getTexture(ICON_LIVE);
	_bombTexture = _display->getDriver()->getTexture(ICON_BOMB);
	_ghostTexture = _display->getDriver()->getTexture(ICON_GHOST);
	_speedTexture = _display->getDriver()->getTexture(ICON_SPEED);
	_powerTexture = _display->getDriver()->getTexture(ICON_POWER);
	_labelTextures[0] = _display->getDriver()->getTexture(LABEL_KIM);
	_labelTextures[1] = _display->getDriver()->getTexture(LABEL_TRUMP);
	_labelTextures[2] = _display->getDriver()->getTexture(LABEL_VLADIMIR);
	_labelTextures[3] = _display->getDriver()->getTexture(LABEL_BACHAR);
}

void GUI::initLivesGUI()
{
	for (int i = 0; i < 4; i++) {
		GUI::drawGUI(i, 0, 0, _labelTextures[i]);
		if (_players[i]->getLives() != 0) {
			for (int j = 0; j < _players[i]->getLives(); j++)
				GUI::drawGUI(i, j, 1, _liveTexture);
			for (int j = 0; j < _players[i]->getBombsMax(); j++)
				GUI::drawGUI(i, j, 2, _bombTexture);
			for (int j = 0; j < _players[i]->getPower(); j++)
				GUI::drawGUI(i, j, 3, _powerTexture);
			for (int j = 0; j < _players[i]->getSpeed(); j++)
				GUI::drawGUI(i, j, 4, _speedTexture);
			if (_players[i]->getWallPass())
				GUI::drawGUI(i, 0, 5, _ghostTexture);
		}
	}
}

void GUI::drawGUI(int playerID, int widthID,
			int heightID, irr::video::ITexture *texture)
{
	int height = 0;
	int width = 0;
	irr::core::dimension2d<irr::u32> textureSize = texture->getSize();

	switch (playerID) {
		case 0:
			height = _screenSize.Height - (textureSize.Height * (heightID + 1));
			width = _screenSize.Width - (textureSize.Width * (widthID + 1));
			break;
		case 1: width = _screenSize.Width - (textureSize.Width * (widthID + 1));
			height = textureSize.Height * heightID;
			break;
		case 2: height = _screenSize.Height - (textureSize.Height * (heightID + 1));
			width = textureSize.Width * widthID;
			break;
		case 3: width = textureSize.Width * widthID;
			height = textureSize.Height * heightID;
			break;
	}
	_display->getDriver()->draw2DImage(texture,
		irr::core::position2d<irr::s32>(width, height),
                irr::core::rect<irr::s32>(
			0, 0, textureSize.Width, textureSize.Height),
			0, irr::video::SColor(255,255,255,255), true);
}

void GUI::update()
{
	GUI::initLivesGUI();
	_env->drawAll();
}