 /*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Display Declaration
*/

#pragma once

#include <irrlicht.h>
#include "EventReceiver.hpp"

class Core;

class Display {
	private:
		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_driver;
		irr::scene::ISceneManager *_smgr;
		irr::gui::IGUIEnvironment *_gui;
		Core *_core;
		EventReceiver _event;
	public:
		Display(Core *core);
		~Display();
		void reset(void);
		void draw(void);
		bool getKey(irr::EKEY_CODE key);
		irr::IrrlichtDevice *getDevice(void);
		irr::video::IVideoDriver *getDriver(void);
		irr::scene::ISceneManager *getSmgr(void);
};
