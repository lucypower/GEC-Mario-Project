#pragma once
#ifndef _CHARACTERCOIN_H
#define _CHARACTERCOIN_H
#include "Character.h"
#include "constants.h"

class CharacterCoin : public Character
{
private:

	float m_single_sprite_w;
	float m_single_sprite_h;
	float m_movement_speed;
	float m_frame_delay;
	float m_current_frame;

public:

	CharacterCoin(SDL_Renderer* renderer, std::string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed);
	~CharacterCoin();

	void TakeDamage();
	void Update(float deltaTime, SDL_Event e) override;
	void Render() override;
};

#endif