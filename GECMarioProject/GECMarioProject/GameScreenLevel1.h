#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "LevelMap.h"
#include "PowBlock.h"
#include "Collisions.h"

class Texture2D; // forward declaration saying we will use this class
class Character;
class PowBlock;

class GameScreenLevel1 : GameScreen // inheriting functionality from GameScreen class
{
private:

	Texture2D* m_background_texture;
	Character* mario;
	Character* luigi;
	LevelMap* m_level_map;

	bool SetUpLevel();

	void SetLevelMap();

	PowBlock* m_pow_block;

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;

	void DoScreenShake();

public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePowBlock();

};

#endif // _GAMESCREENLEVEL1_H