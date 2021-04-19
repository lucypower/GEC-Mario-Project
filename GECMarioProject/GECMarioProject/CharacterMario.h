#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H
#include "Character.h"
#include "Commons.h"

class CharacterMario : public Character
{
public:

	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterMario();

protected:

	void Update(float deltaTime, SDL_Event e) override;
};

#endif