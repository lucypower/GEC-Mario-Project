#pragma once
#ifndef _CHARACTERPEACH_H
#define _CHARACTERPEACH_H
#include "Character.h"
#include "Commons.h"

class CharacterPeach : public Character
{
public:

	CharacterPeach(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterPeach();

protected:

	void Update(float deltaTime, SDL_Event e) override;
	void Render() override;
};

#endif