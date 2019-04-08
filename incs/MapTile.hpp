/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** MapTile struct definition
*/

#pragma once

#include <memory>
#include <chrono>
#include "EntityType.hpp"

class Entity;

typedef struct MapTile_s {
	EntityType type;
	Entity *entity;
	unsigned int x;
	unsigned int y;
	bool fire;
	bool player;
	irr::scene::ISceneNode *fireVisual;
	std::chrono::system_clock::time_point fireEnd;
} MapTile;
