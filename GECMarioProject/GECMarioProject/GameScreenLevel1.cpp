#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "Collisions.h"

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();

	m_level_map = nullptr;
}

GameScreenLevel1::~GameScreenLevel1()
{
	m_background_texture = nullptr;
	delete mario;
	delete luigi;
	mario = nullptr;
	luigi = nullptr;
	delete m_pow_block;
	m_pow_block = nullptr;
}

void GameScreenLevel1::Render()
{
	// draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	mario->Render();
	luigi->Render();
	m_pow_block->Render();
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	// update character
	mario->Update(deltaTime, e);
	luigi->Update(deltaTime, e);

	UpdatePowBlock();

	if (Collisions::Instance()->Circle(mario, luigi))
	{
		std::cout << "Circle hit!" << std::endl;
	}
	if (Collisions::Instance()->Box(mario->GetCollisionsBox(), luigi->GetCollisionsBox()))
	{
		std::cout << "Box hit!" << std::endl;
	}
}

bool GameScreenLevel1::SetUpLevel()
{
	SetLevelMap();
	// load texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	
	m_pow_block = new PowBlock(m_renderer, m_level_map);

	// set up player character
	mario = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map);
	luigi = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(64, 330), m_level_map);	
}

void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
										{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
										{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

	// clear any old maps
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}

	// set the new one
	m_level_map = new LevelMap(map);
}

void GameScreenLevel1::UpdatePowBlock()
{
	if (Collisions::Instance()->Box(mario->GetCollisionsBox(), m_pow_block->GetCollisionBox()))
	{
		if (&PowBlock::IsAvailable)
		{
			// collided while jumping
			if (mario->IsJumping())
			{
				//DoScreenShake();
				m_pow_block->TakeHit();
				mario->CancelJump();
			}
		} 
	}
	return;
}