/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Player class definition
*/

#pragma once

#include <string>
#include <chrono>
#include <irrlicht.h>
#include "Direction.hpp"
#include "PlayerActions.hpp"
#include "MapTile.hpp"

class Game;
class Display;
class Map;

class Player {
	private:
		Game *_game;
		Display *_display;
		Map *_map;
		unsigned int _id;
		std::string _name;
		std::string _skin;
		int _x;
		int _y;
		int _score;
		int _lives;
		int _speed;
		int _bombs;
		int _bombMax;
		int _power;
		bool _wallPass;
		bool _putBomb;
		float _animation;
		float _oldAnimation;
		irr::core::vector3df _oldPosition;
		std::chrono::system_clock::time_point _beginAnimation;
		PlayerActions _bufferInput;
		FaceDirection _faceDirection;
		irr::scene::IAnimatedMeshSceneNode *_anms;

	protected:
	public:
		Player(Game *game, Display *display, Map *map,
			unsigned int id, std::string const name,
			std::string const skin);
		~Player();
		void update();
		std::string &getName();
		std::string &getSkin();
		int getScore();
		int getX();
		int getY();
		int getSpeed();
		float getAnimation();
		int getLives();
		int getBombsMax();
		bool getWallPass();
		int getPower();
		FaceDirection getDirection();
		void bombExplode();
		void startAnimation();
		void updateAnimation();
		void buffActions(int action);
		void doActions(PlayerActions action);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void putBomb();
		void getDamage();
		void getPowerUp();
		void die(MapTile *tile);
		bool increaseLives();
		bool increaseSpeed();
		bool decreaseSpeed();
		bool increaseBombs();
		bool decreaseBombs();
		bool increasePower();
		bool decreasePower();
		bool enableWallPass();
		void init3DPlayer();
		void setInitialMeshTexture(std::string mesh,
					std::string texture,
					irr::scene::ISceneManager *smgr,
					irr::video::IVideoDriver *driver);
		void setInitialPosition();
		void saveInitialPosition(float width, float height);
		void setInitialRotation();
		void setInitialScale();
		void setInitialAnimation();
		void display();
		void computeNewPosition(irr::core::vector3df *newPosition);
		void setOrientation();
		void computeFrameLoop();
		void resetAnimation();
		static bool fexists(const std::string filename);
};
