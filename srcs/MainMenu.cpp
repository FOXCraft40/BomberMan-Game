/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** MainMenu class implementation
*/

#include <iostream>
#include "Indie.hpp"

MainMenu::MainMenu(Core *core, Display *display)
    : State(core, display, "MainMenu")
{
	MainMenu::initMainMenu();
}

MainMenu::~MainMenu()
{
	_env->clear();
}

void MainMenu::initMainMenu()
{
	_screenSize = _display->getDriver()->getScreenSize();
	_env = _display->getDevice()->getGUIEnvironment();
	_background = _display->getDriver()->getTexture(MAIN_MENU_BACKGROUND);
	_logo = _display->getDriver()->getTexture(LOGO);
	_playTexture = _display->getDriver()->getTexture(PLAY_BUTTON);
	_exitTexture = _display->getDriver()->getTexture(EXIT_BUTTON);
	_loadTexture = _display->getDriver()->getTexture(LOAD_BUTTON);
	MainMenu::displayLogo();
	MainMenu::drawNavButtons();
	//MainMenu::drawLoadButton();
}

void MainMenu::enable()
{
	State::enable();
}

void MainMenu::disable()
{
	State::disable();
}

void MainMenu::update()
{
}

void MainMenu::display()
{
	_display->getDriver()->beginScene(true, true,
            irr::video::SColor (0,120,120,120));
	_display->getDriver()->draw2DImage(_background,
		irr::core::position2d<irr::s32>(0,0),
                irr::core::rect<irr::s32>(0,0,1920,1080), 0,
                irr::video::SColor(255,255,255,255), true);
	_env->drawAll();
	_display->getDriver()->endScene();
}

void MainMenu::displayLogo()
{
	irr::core::dimension2d<irr::u32> textureSize =
		_logo->getOriginalSize();
	int height = _screenSize.Height;
	int width = _screenSize.Width;
	int textureHeight = textureSize.Height;
	int textureWidth = textureSize.Width;

	_display->getDriver()->makeColorKeyTexture (_logo,
        	irr::core::position2d<irr::s32> (0,0));
	_display->getDriver()->draw2DImage(_logo,
		irr::core::position2d<irr::s32>(20,(width / 2) -
			(textureWidth / 2)),
                irr::core::rect<irr::s32>(0, 0, textureWidth, textureHeight), 0,
                irr::video::SColor(255,255,255,255), true);
}

void MainMenu::drawNavButtons()
{
	irr::core::dimension2d<irr::u32> textureSize =
		_playTexture->getSize();
	int height = _screenSize.Height;
	int width = _screenSize.Width;
	int textureHeight = textureSize.Height;
	int textureWidth = textureSize.Width;

	_playButton = _env->addButton(irr::core::rect<irr::s32>(0, 0,
		textureWidth, textureHeight), 0, GUI_ID_PLAY_BUTTON);
	_playButton->setDrawBorder(0);
	_playButton->setImage(_playTexture);
	_playButton->setUseAlphaChannel(true);
	_playButton->setRelativePosition(irr::core::position2d<irr::s32>(
			width - 400 - textureWidth, height * 0.8));
	_exitButton = _env->addButton(irr::core::rect<irr::s32>(0, 0,
		textureWidth, textureHeight), 0, GUI_ID_QUIT_BUTTON);
	_exitButton->setDrawBorder(0);
	_exitButton->setImage(_exitTexture);
	_exitButton->setUseAlphaChannel(true);
	_exitButton->setRelativePosition(irr::core::position2d<irr::s32>(400,
		height * 0.8));
}

void MainMenu::drawLoadButton()
{
	irr::core::dimension2d<irr::u32> textureSize =
		_loadTexture->getSize();
	int height = _screenSize.Height;
	int width = _screenSize.Width;
	int textureHeight = textureSize.Height;
	int textureWidth = textureSize.Width;

	_loadButton = _env->addButton(irr::core::rect<irr::s32>(0, 0,
		textureWidth, textureHeight), 0, GUI_ID_LOAD_BUTTON);
	_loadButton->setDrawBorder(0);
	_loadButton->setImage(_loadTexture);
	_loadButton->setUseAlphaChannel(true);
	_loadButton->setRelativePosition(irr::core::position2d<irr::s32>(
			59, height * 0.05));
}