#include "SoundEffect.h"
#include <iostream>

SoundEffect::SoundEffect()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 3, 2048) < 0)
	{
		std::cout << "Mixer could not initialise. Error: " << Mix_GetError();
	}
}

SoundEffect::~SoundEffect()
{
	Mix_FreeChunk(m_music);
	m_music = nullptr;
}

void SoundEffect::Play()
{
	Mix_PlayChannel(-1, m_music, 0);
}

void SoundEffect::Load(std::string path)
{
	Mix_LoadWAV(path.c_str());
}