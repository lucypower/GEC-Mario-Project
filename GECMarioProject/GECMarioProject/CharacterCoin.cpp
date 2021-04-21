#include "CharacterCoin.h"
#include "constants.h"

CharacterCoin::CharacterCoin(SDL_Renderer* renderer, std::string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed) :
	Character(renderer, imagePath, start_position, map)
{
	m_facing_direction = start_facing;
	m_movement_speed = movement_speed;
	m_position = start_position;

	m_single_sprite_w = m_texture->GetWidth() / 3;
	m_single_sprite_h = m_texture->GetHeight();
}

CharacterCoin::~CharacterCoin()
{

}

void CharacterCoin::Update(float deltaTime, SDL_Event e)
{
	// use the code within base class
	Character::Update(deltaTime, e);

	if ((m_position.x >= SCREEN_WIDTH - 50) or (m_position.x + m_single_sprite_w <= 20))
	{
		if (m_facing_direction == FACING_RIGHT)
		{
			m_facing_direction = FACING_LEFT;
		}
		else if (m_facing_direction == FACING_LEFT)
		{
			m_facing_direction = FACING_RIGHT;
		}
	}

	if (m_facing_direction == FACING_LEFT)
	{
		m_moving_left = true;
		m_moving_right = false;
	}
	else if (m_facing_direction == FACING_RIGHT)
	{
		m_moving_right = true;
		m_moving_left = false;
	}

	m_frame_delay -= deltaTime;
	if (m_frame_delay <= 0.0f)
	{
		// reset frame delay count
		m_frame_delay = ANIMATION_DELAY;

		// move the frame over
		m_current_frame++;

		// loop frame around if it goes beyond the number of frames
		if (m_current_frame > 2)
			m_current_frame = 0;
	}
}

void CharacterCoin::Render()
{
	// get the portion of the sprite sheet you want to draw
	SDL_Rect portion_of_sprite = { m_single_sprite_w * m_current_frame, 0, m_single_sprite_w, m_single_sprite_h };

	// determine where you want it drawn
	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

	// then draw it facing the correct direction
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_HORIZONTAL);
	}
}