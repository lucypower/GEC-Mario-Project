#pragma once
#ifndef _GAMESCREENLEVEL2_H
#define _GAMESCREENLEVEL2_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "LevelMap.h"
#include "PowBlock.h"
#include "Collisions.h"
#include "CharacterGoomba.h"
#include "CharacterCoin.h"
#include <iostream>
#include <vector>
#include "Texture2D.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"

class Texture2D; // forward declaration saying we will use this class
class Character;
class PowBlock;

class GameScreenLevel2 : public GameScreen
{
private:

	Texture2D* m_background_texture;
	Character* mario;
	Character* luigi;
	Character* goomba;
	Character* coin;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;
	Mix_Chunk* coinSound;

	bool SetUpLevel();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateGoomba(Vector2D position, FACING direction, float speed);
	void CreateCoin(Vector2D position, FACING direction, float speed);
	void SetLevelMap();
	void DoScreenShake();

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	float goombaCountdown;
	float coinCountdown;

	std::vector<CharacterGoomba*> m_enemies;
	std::vector<CharacterCoin*> m_coins;

public:

	GameScreenLevel2(SDL_Renderer* renderer);
	~GameScreenLevel2();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePowBlock();
};

#endif