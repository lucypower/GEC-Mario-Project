#pragma once
#ifndef _CHARACTERLUIGI_H
#define _CHARACTERLUIGI_H
#include "Character.h"
#include "Commons.h"
#include "constants.h""
#include "Texture2D.h"

class CharacterLuigi : public Character
{
public:

	CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterLuigi();

protected:

	virtual void Update(float deltaTime, SDL_Event e);
};

#endif