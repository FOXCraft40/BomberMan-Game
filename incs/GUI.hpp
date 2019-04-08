/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GUI class definition
*/

#pragma once

class Display;
class Player;
class Game;

#define ICON_BOMB "resources/assets/GUI/icon_bomb.png"
#define ICON_LIVE "resources/assets/GUI/icon_heart.png"
#define ICON_SPEED "resources/assets/GUI/icon_speed.png"
#define ICON_POWER "resources/assets/GUI/icon_power.png"
#define ICON_GHOST "resources/assets/GUI/icon_ghost.png"

#define LABEL_VLADIMIR "resources/assets/GUI/label_vladimir.png"
#define LABEL_BACHAR "resources/assets/GUI/label_bachar.png"
#define LABEL_KIM "resources/assets/GUI/label_kim.png"
#define LABEL_TRUMP "resources/assets/GUI/label_trump.png"

class GUI {
	protected:
		Display *_display;
		Player **_players;
		irr::core::dimension2du _screenSize;
		irr::gui::IGUIEnvironment *_env;
		irr::video::ITexture *_liveTexture;
		irr::video::ITexture *_bombTexture;
		irr::video::ITexture *_speedTexture;
		irr::video::ITexture *_powerTexture;
		irr::video::ITexture *_ghostTexture;
		irr::video::ITexture *_labelTextures[4];
	private:
	public:
		GUI(Player **players, Display *display);
		~GUI();

		void initGUIEnvironment();
		void loadTextures();
		void initLivesGUI();
		void drawGUI(int playerID, int widthID, int heightID,
			irr::video::ITexture *texture);
		void update();
};
