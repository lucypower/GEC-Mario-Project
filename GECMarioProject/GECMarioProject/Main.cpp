#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include "Texture2D.h"
#include "Commons.h"
#include "GameScreenManager.h"
#include <iostream>
#include <string>
#include <filesystem>

// globals
SDL_Window* g_window = nullptr; // null pointer
SDL_Renderer* g_renderer = nullptr;
GameScreenManager* game_screen_manager;
Uint32 g_old_time;
Mix_Music* g_music = nullptr;

// function prototypes
bool InitSDL();
void CloseSDL();
bool Update();
void LoadMusic(std::string path);
void Render();

int main(int argc, char* args[])
{
	// check if sdl was setup correctly
	if (InitSDL())
	{
		LoadMusic("Music/Mario.mp3");
		if (Mix_PlayingMusic() == 0)
		{
			Mix_PlayMusic(g_music, -1);
		}

		// flag to check if we wish to quit
		bool quit = false;
		game_screen_manager = new GameScreenManager(g_renderer, SCREEN_LEVEL1);
		// set the time
		g_old_time = SDL_GetTicks();

		// game loop
		while (!quit)
		{
			Render();
			quit = Update();
		}		
	}

	CloseSDL();

	return 0;
}

// setup SDL
bool InitSDL()
{
	// initialise the music mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Mixer could not initialise. Error: " << Mix_GetError();
		return false;
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		// setup passed so window is created
		g_window = SDL_CreateWindow ("Games Engine Creation",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		// did the window get cerated?
		if (g_window == nullptr)
		{
			// window failed
			std::cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}
	}
	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
	if (g_renderer != nullptr)
	{
		// init PNG loading
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags))
		{
			std::cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
			return false;
		}
	}
	else
	{
		std::cout << "Renderer could not initialise. Error: " << SDL_GetError();
		return false;
	}

	return true;
}

void Render()
{
	// sets a colour for the renderer and clears the window
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	game_screen_manager->Render();

	// update the screen
	SDL_RenderPresent(g_renderer);
}

void CloseSDL()
{
	// release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	// quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	// release the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	// destroy the game screen manager
	delete game_screen_manager;
	game_screen_manager = nullptr;

	// clear up music
	Mix_FreeMusic(g_music);
	g_music = nullptr;
}

bool Update()
{
	Uint32 new_time = SDL_GetTicks();

	// event handler
	SDL_Event e;

	// get events
	SDL_PollEvent(&e); // e passed by reference so it can be adjusted

	// handle the events
	switch (e.type)
	{
		// click the 'X' to quit
	case SDL_QUIT:
		return true;
		break;
	}
	switch (e.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		return true;
		break;
	}

	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;

	return false;
}

void LoadMusic(std::string path)
{
	g_music = Mix_LoadMUS(path.c_str());
	if (g_music == nullptr)
	{
		std::cout << "Failed to load music. Error: " << Mix_GetError() << std::endl;
	}
}