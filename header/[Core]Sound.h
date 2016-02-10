/*
MaikazeSekai Sound System

*/
#ifndef MAIKAZE_SOUND_H
#define MAIKAZE_SOUND_H

#define BGMCHANNEL 1

#include "SDL_Mixer.h"
#include "[Core]Error.h"
#include "[Core]FileMgr.h"

struct Sounds{
	int channel;
	int index;
	int loop;
	int volumn;
	SDL_RWops * rw;
	Mix_Chunk * ck;
};

class SoundSys
{
public:
	SoundSys(){
		Init();
	}
	~SoundSys(){

	}
	void Init();
	void LoadAudio(int i_channel, string i_path, int i_volumn, const int i_loop = -1);
	void PlayAudio(Sounds i_sound);
	void PauseAudio();
	void SetVolumn(int i_channel, const int i_volumn = 100);
	void ExitAudio();
	void Exit();

private:
	vector<Sounds> m_sounds;
	FileMgr m_filemgr;
};

#endif