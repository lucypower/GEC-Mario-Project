#include "GameScreenMainMenu.h"

GameScreenMainMenu::GameScreenMainMenu(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

GameScreenMainMenu::~GameScreenMainMenu()
{
	m_background_texture = nullptr;
}

void GameScreenMainMenu::Render()
{
	m_background_texture->Render(Vector2D(0, m_background_yPos), SDL_FLIP_NONE);
}

void GameScreenMainMenu::Update(float deltaTime, SDL_Event e)
{

}

bool GameScreenMainMenu::SetUpLevel()
{
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/MenuScreen.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
}