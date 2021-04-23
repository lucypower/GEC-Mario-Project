#pragma once
#ifndef _SOUNDEFFECT_H
#define _SOUNDEFFECT_H
#include <string>
#include <SDL_mixer.h>
#include <iostream>

class SoundEffect
{
public:

	SoundEffect();
	~SoundEffect();

	void Play();
	void Load(std::string path);

private:

	Mix_Chunk* m_music;
};

#endif