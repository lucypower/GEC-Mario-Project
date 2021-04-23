#pragma once
#ifndef _GAMESCREENMAINMENU_H
#define _GAMESCREENMAINMENU_H
#include "GameScreen.h"
#include "Texture2D.h"
#include <iostream>

class GameScreenMainMenu : public GameScreen
{
public :

	GameScreenMainMenu(SDL_Renderer* renderer);
	~GameScreenMainMenu();

	void Render();
	void Update(float deltaTime, SDL_Event e);

private:

	bool SetUpLevel();

	Texture2D* m_background_texture;

	float m_background_yPos;
};

#endif