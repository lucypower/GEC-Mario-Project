#pragma once
#ifndef _GAMESCREENLEVEL3_H
#define _GAMESCREENLEVEL3_H
#include "GameScreen.h"
#include "Texture2D.h"
#include "Character.h"
#include "PowBlock.h"
#include <vector>
#include "CharacterGoomba.h"
#include "CharacterCoin.h"
#include "CharacterLuigi.h"
#include "CharacterMario.h"
#include "Collisions.h"
#include "CharacterKoopa.h"

class GameScreenLevel3 : public GameScreen
{
private:

	Texture2D* m_background_texture;
	Character* mario;
	Character* luigi;
	Character* goomba;
	Character* koopa;
	Character* coin;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;
	Mix_Chunk* coinSound;

	bool SetUpLevel();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2D position, FACING direction, float speed);
	void CreateGoomba(Vector2D position, FACING direction, float speed);
	void CreateCoin(Vector2D position, FACING direction, float speed);
	void SetLevelMap();
	void DoScreenShake();

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	float koopaCountdown;
	float goombaCountdown;
	float coinCountdown;

	std::vector<CharacterGoomba*> m_enemies;
	std::vector<CharacterKoopa*> m_enemies2;
	std::vector<CharacterCoin*> m_coins;

public:

	GameScreenLevel3(SDL_Renderer* renderer);
	~GameScreenLevel3();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePowBlock();
};

#endif