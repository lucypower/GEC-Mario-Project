#include "GameScreenManager.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;


	ChangeScreen(startScreen);
}

GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete m_current_screen;
	m_current_screen = nullptr;
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);
	
}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	// clear up the old screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

	GameScreenMainMenu* tempScreen;
	GameScreenLevel1* tempScreen2;
	GameScreenLevel2* tempScreen3;
	GameScreenLevel3* tempScreen4;

	switch (new_screen)
	{
	case SCREEN_LEVEL1:
		tempScreen = new GameScreenMainMenu(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
		break;
	case SCREEN_LEVEL2:
		tempScreen2 = new GameScreenLevel1(m_renderer);
		m_current_screen = (GameScreen*)tempScreen2;
		tempScreen2 = nullptr;
		break;
	case SCREEN_LEVEL3:
		tempScreen3 = new GameScreenLevel2(m_renderer);
		m_current_screen = (GameScreen*)tempScreen3;
		tempScreen3 = nullptr;
		break;
	case SCREEN_LEVEL4:
		tempScreen4 = new GameScreenLevel3(m_renderer);
		m_current_screen = (GameScreen*)tempScreen4;
		tempScreen4 = nullptr;
		break;
	default:;
	}

	


}