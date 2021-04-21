#include "CharacterPeach.h"
#include "constants.h"
#include "Texture2D.h"


CharacterPeach::CharacterPeach(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map) : Character(renderer, imagePath, start_position, map)
{
	m_single_sprite_w = m_texture->GetWidth();
	m_single_sprite_h = m_texture->GetHeight() / 2;
}

CharacterPeach::~CharacterPeach()
{

}

void CharacterPeach::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = true;
			break;
		case SDLK_RIGHT:
			m_moving_right = true;
			break;
		case SDLK_UP:
			if (m_can_jump)
			{
				Jump();
			}
		}
		break;

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = false;
		case SDLK_RIGHT:
			m_moving_right = false;
		}
		break;
	}

	Character::Update(deltaTime, e);
}

void CharacterPeach::Render()
{

}
