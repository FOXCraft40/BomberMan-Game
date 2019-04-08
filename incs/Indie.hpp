/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Indie global header
*/

#pragma once

#include <irrlicht.h>

#include "Core.hpp"
#include "IState.hpp"
#include "State.hpp"
#include "Display.hpp"
#include "MainMenu.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "GUI.hpp"
#include "PlayerActions.hpp"
#include "Map.hpp"
#include "MapTile.hpp"

#include "EntityType.hpp"
#include "Entity.hpp"
#include "Bomb.hpp"
#include "Wall.hpp"
#include "PowerUpType.hpp"
#include "PowerUp.hpp"
#include "Direction.hpp"

/* Map size */
#define MAP_WIDTH 17
#define MAP_HEIGHT 15

/* Animations durations */
#define MOVE_TIME 100
#define EXPLOSION_TIME 3000
#define FIRE_TIME 1000

/* PowerUp ranges */
#define LIVES_DEFAULT 2
#define LIVES_MAX 5

#define SPEED_MIN 1
#define SPEED_DEFAULT 3
#define SPEED_MAX 6

#define BOMBS_MIN 1
#define BOMBS_DEFAULT 2
#define BOMBS_MAX 3

#define POWER_MIN 2
#define POWER_DEFAULT 2
#define POWER_MAX 5

/* Map generation */
#define PROP(prop) (100 - prop)

#define PROP_BREAKABLES_ON_UNBREAKABLES 30
#define PROP_BREAKABLES_ON_EMPTY 20

/* Assets */
#define ASSETS_PLAYER_PATH "resources/assets/player/"

#define OBJ_GROUND1 "resources/assets/map/ground.obj"
#define JPG_GROUND1 "resources/assets/map/texture_ground1.jpg"

#define OBJ_GROUND2 "resources/assets/map/ground.obj"
#define JPG_GROUND2 "resources/assets/map/texture_ground2.jpg"

#define OBJ_FIXED_WALL "resources/assets/map/fixed_wall.obj"
#define PNG_FIXED_WALL "resources/assets/map/texture_fixed_wall.png"

#define OBJ_BREAKABLES_WALL "resources/assets/map/breakwable_wall.obj"
#define PNG_BREAKABLES_WALL "resources/assets/map/texture_breakable_wall.png"

#define OBJ_BOMB "resources/assets/map/Bomb.obj"
#define PNG_BOMB "resources/assets/map/texture_bomb.png"

#define OBJ_CONE "resources/assets/map/cone.obj"
#define PNG_CONE "resources/assets/map/texture_lifeup.png"

#define OBJ_LIFE_UP "resources/assets/map/lifeup.obj"
#define PNG_LIFE_UP "resources/assets/map/texture_lifeup.png"

#define OBJ_POWER_UP "resources/assets/map/power_up.obj"
#define PNG_POWER_UP "resources/assets/map/texture_power_up.png"

#define OBJ_POWER_DOWN "resources/assets/map/power_down.obj"
#define PNG_POWER_DOWN "resources/assets/map/texture_power_down.png"

#define OBJ_SPEED_UP "resources/assets/map/speed_up.obj"
#define PNG_SPEED_UP "resources/assets/map/texture_speed_up.png"

#define OBJ_SPEED_DOWN "resources/assets/map/speed_down.obj"
#define PNG_SPEED_DOWN "resources/assets/map/texture_speed_down.png"

#define OBJ_BOMB_UP "resources/assets/map/bomb_up.obj"
#define PNG_BOMB_UP "resources/assets/map/texture_bomb.png"

#define OBJ_BOMB_DOWN "resources/assets/map/bomb_down.obj"
#define PNG_BOMB_DOWN "resources/assets/map/texture_bomb.png"

#define OBJ_WALL_PASS "resources/assets/map/wall_pass.obj"
#define PNG_WALL_PASS "resources/assets/map/"

/* Keymap */
static const irr::EKEY_CODE KEYSMAP[4][5] = {
	{ /* Player 1 */
		irr::EKEY_CODE::KEY_KEY_Z,  /* MOVE_UP */
		irr::EKEY_CODE::KEY_KEY_S,  /* MOVE_DOWN */
		irr::EKEY_CODE::KEY_KEY_Q,  /* MOVE_LEFT */
		irr::EKEY_CODE::KEY_KEY_D,  /* MOVE_RIGHT */
		irr::EKEY_CODE::KEY_SPACE   /* PUT_BOMB */
	},
	{ /* Player 2 */
		irr::EKEY_CODE::KEY_UP,      /* MOVE_UP */
		irr::EKEY_CODE::KEY_DOWN,    /* MOVE_DOWN */
		irr::EKEY_CODE::KEY_LEFT,    /* MOVE_LEFT */
		irr::EKEY_CODE::KEY_RIGHT,   /* MOVE_RIGHT */
		irr::EKEY_CODE::KEY_RCONTROL /* PUT_BOMB */
	},
	{ /* Player 3 */
		irr::EKEY_CODE::KEY_KEY_I,   /* MOVE_UP */
		irr::EKEY_CODE::KEY_KEY_K,   /* MOVE_DOWN */
		irr::EKEY_CODE::KEY_KEY_J,   /* MOVE_LEFT */
		irr::EKEY_CODE::KEY_KEY_L,   /* MOVE_RIGHT */
		irr::EKEY_CODE::KEY_KEY_N    /* PUT_BOMB */
	},
	{ /* Player 4 */
		irr::EKEY_CODE::KEY_F6,    /* MOVE_UP */
		irr::EKEY_CODE::KEY_KEY_6, /* MOVE_DOWN */
		irr::EKEY_CODE::KEY_KEY_5, /* MOVE_LEFT */
		irr::EKEY_CODE::KEY_KEY_7, /* MOVE_RIGHT */
		irr::EKEY_CODE::KEY_KEY_H  /* PUT_BOMB */

	}
};
