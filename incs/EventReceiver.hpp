/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** EventReceiver Declaration
*/

#pragma once

#include <irrlicht.h>

class Core;

enum {
    GUI_ID_QUIT_BUTTON,
    GUI_ID_PLAY_BUTTON,
    GUI_ID_LOAD_BUTTON
};

class EventReceiver : public irr::IEventReceiver {
	private:
		bool keys[irr::KEY_KEY_CODES_COUNT];
		irr::IrrlichtDevice *_device;
		Core *_core;
	public:
		EventReceiver();
		~EventReceiver();
		bool getKey(irr::EKEY_CODE);
		bool OnEvent(const irr::SEvent& event);
		void setDevice(irr::IrrlichtDevice *device);
		void setCore(Core *core);
};