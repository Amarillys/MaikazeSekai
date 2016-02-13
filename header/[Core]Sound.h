/*
MaikazeSekai Sound System

*/
#ifndef MAIKAZE_SOUND_H
#define MAIKAZE_SOUND_H

#include "SDL_Mixer.h"
#include "[Core]Error.h"
#include "[Core]FileMgr.h"

const int BGM = 1;
const int SE = 2;
const int VCE = 3;
const int VCE2 = 4;

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
	void Load(int i_channel, string i_path, int i_volumn = 100, const int i_loop = -1);

	inline void Play(Sounds i_sound){
		Mix_PlayChannel(i_sound.channel, i_sound.ck, i_sound.loop);
	}

	inline void Pause(){
		Mix_PauseMusic();
	}

	inline void Resume(){
		Mix_ResumeMusic();
	}

	void SetVolumn(int i_channel, const int i_volumn = 100);
	void ExitAudio();
	void Exit();

private:
	vector<Sounds> m_sounds;
	FileMgr m_filemgr;
};

#endif