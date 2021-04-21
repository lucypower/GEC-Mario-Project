#pragma once
#ifndef _GAMESCREENLEVEL2_H
#define _GAMESCREENLEVEL2_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "LevelMap.h"
#include "PowBlock.h"
#include "Collisions.h"
#include <vector>
#include "CharacterGoomba.h"

class Texture2D; // forward declaration saying we will use this class
class Character;
class PowBlock;

class GameScreenLevel2 : public GameScreen
{
private:

	Texture2D* m_background_texture;
	Character* peach;
	Character* luigi;
	Character* goomba;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;

	bool SetUpLevel();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateGoomba(Vector2D position, FACING direction, float speed);
	void SetLevelMap();
	void DoScreenShake();

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;

	std::vector<CharacterGoomba*> m_enemies;

public:

	GameScreenLevel2(SDL_Renderer* renderer);
	~GameScreenLevel2();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePowBlock();
};

#endif