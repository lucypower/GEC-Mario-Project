#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"
#include <SDL_mixer.h>

class Texture2D;

class Character
{
protected:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

	bool m_moving_left;
	bool m_moving_right;
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;
	float m_collision_radius;
	bool m_alive;
	int marioLives = 3;
	int luigiLives = 3;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);	

private:	

	LevelMap* m_current_level_map;
	Mix_Chunk* jumpSound = Mix_LoadWAV("Music/MarioJump.mp3");

public:

	Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	virtual void AddGravity(float deltaTime);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	void Jump();
	float GetCollisionRadius();
	bool IsJumping() { return m_jumping; }
	void CancelJump() { return; } // returning m_jumping as false
	void SetAlive(bool isAlive);
	bool GetAlive() { return m_alive; }
	void MarioDeath();
	void LuigiDeath();
	Rect2D GetCollisionsBox() {
		return Rect2D(m_position.x, m_position.y,
			m_texture->GetWidth(), m_texture->GetHeight());
	}	

	FACING m_facing_direction;
};

#endif // _CHARACTER_H