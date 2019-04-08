/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IEntity interface definition
*/

#pragma once

class IEntity {
	public:
		virtual EntityType getType() = 0;
};