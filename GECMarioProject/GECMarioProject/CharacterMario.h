#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H
#include "Character.h"
#include "Commons.h"

class CharacterMario : public Character
{
public:

	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position);
	~CharacterMario();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

protected:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

	bool m_moving_left;
	bool m_moving_right;

	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;

private:

	FACING m_facing_direction;
};

#endif