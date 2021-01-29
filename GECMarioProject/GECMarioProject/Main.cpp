#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include "Texture2D.h"
#include "Commons.h"
#include <iostream>
#include <string>
#include <filesystem>

// globals
SDL_Window* g_window = nullptr; // null pointer
SDL_Renderer* g_renderer = nullptr;
Texture2D* g_texture = nullptr;

// function prototypes
bool InitSDL();
void CloseSDL();
bool Update();

void Render();

int main(int argc, char* args[])
{
	// check if sdl was setup correctly
	if (InitSDL())
	{
		// flag to check if we wish to quit
		bool quit = false;

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
		// load the background texture

		g_texture = new Texture2D(g_renderer);
		if (!g_texture->LoadFromFile("Images/test.bmp"))
		{
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

	g_texture->Render(Vector2D(), SDL_FLIP_NONE);

	// set where to render the texture
	//SDL_Rect renderLocation = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	Render();
	// render to screen
	//SDL_RenderCopyEx(g_renderer, g_texture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);

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

	// release the texture
	delete g_texture;
	g_texture = nullptr;
}

bool Update()
{
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
	return false;
}
