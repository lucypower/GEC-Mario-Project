#include "CharacterMario.h"
#include "constants.h"
#include "Texture2D.h"
#include "Character.h"

CharacterMario::CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position) : Character(renderer, imagePath, start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load image" << std::endl;
	}
	m_facing_direction = FACING_RIGHT;
	m_moving_left = false;
	m_moving_right = false;
}

CharacterMario::~CharacterMario()
{
	m_renderer = nullptr;
}

void CharacterMario::Render()
{
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}

void CharacterMario::Update(float deltaTime, SDL_Event e)
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
		}
	case SDLK_UP:
		if (m_can_jump)
		{
			Jump();
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
