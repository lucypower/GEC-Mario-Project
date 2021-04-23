#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "LevelMap.h"
#include "PowBlock.h"
#include "Collisions.h"
#include <vector>
#include "CharacterKoopa.h"
#include "CharacterCoin.h"
#include "SoundEffect.h"

class Texture2D; // forward declaration saying we will use this class
class Character;
class PowBlock;

class GameScreenLevel1 : GameScreen // inheriting functionality from GameScreen class
{
private:

	Texture2D* m_background_texture;
	Character* mario;
	Character* luigi;
	Character* koopa;
	Character* coin;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;
	Mix_Chunk* coinSound;

	bool SetUpLevel();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateCoin(Vector2D position, FACING direction, float speed);
	void CreateKoopa(Vector2D position, FACING direction, float speed);
	void SetLevelMap();	
	void DoScreenShake();

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	float koopaCountdown;	
	float coinCountdown;

	std::vector<CharacterKoopa*> m_enemies;
	std::vector<CharacterCoin*> m_coins;

public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePowBlock();
};

#endif // _GAMESCREENLEVEL1_H