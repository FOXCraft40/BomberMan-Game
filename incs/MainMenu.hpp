/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** MainMenu class definition
*/

#pragma once

#include <irrlicht.h>

class Core;
class Display;

#define MAIN_MENU_BACKGROUND "resources/assets/mainMenu/background_mushroom.png"
#define LOGO "resources/assets/mainMenu/logo.png"
#define PLAY_BUTTON "resources/assets/mainMenu/button_play.png"
#define EXIT_BUTTON "resources/assets/mainMenu/button_exit.png"
#define LOAD_BUTTON "resources/assets/mainMenu/button_load.png"

class MainMenu : public State {
	private:
		irr::gui::IGUIEnvironment *_env;
		irr::video::ITexture *_background;
		irr::video::ITexture *_logo;
		irr::video::ITexture *_playTexture;
		irr::video::ITexture *_exitTexture;
		irr::video::ITexture *_loadTexture;
		irr::gui::IGUIButton *_playButton;
		irr::gui::IGUIButton *_exitButton;
		irr::gui::IGUIButton *_loadButton;
		irr::gui::IGUISkin *_skin;
		irr::core::dimension2du _screenSize;
	public:
		MainMenu(Core *core, Display *display);
		~MainMenu();
		void enable();
		void disable();
		void update();
		void display();
		void initMainMenu();
		void displayLogo();
		void drawNavButtons();
		void drawLoadButton();
};
