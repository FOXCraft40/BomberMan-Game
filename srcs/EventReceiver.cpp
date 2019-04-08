/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** EventReceiver Implementation
*/

#include <iostream>
#include "Indie.hpp"

EventReceiver::EventReceiver()
{
	for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
		keys[i] = false;
}

EventReceiver::~EventReceiver()
{
}

bool EventReceiver::getKey(irr::EKEY_CODE key)
{
	return keys[key];
}

void EventReceiver::setDevice(irr::IrrlichtDevice *device)
{
	_device = device;
}

void EventReceiver::setCore(Core *core)
{
	_core = core;
}

bool EventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
	{
		keys[event.KeyInput.Key] = event.KeyInput.PressedDown;
		return true;
	}
	else if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		irr::gui::IGUIEnvironment *env =
			_device->getGUIEnvironment();
		switch (event.GUIEvent.EventType) {
			case irr::gui::EGET_BUTTON_CLICKED:
				switch (id) {
					case GUI_ID_QUIT_BUTTON:
						_device->closeDevice();
						return true;
					case GUI_ID_PLAY_BUTTON:
						_core->changeState("Game");
						return true;
					default:
						return false;
				}
				break;
			default:
				break;
		}
	}
	return false;
}
