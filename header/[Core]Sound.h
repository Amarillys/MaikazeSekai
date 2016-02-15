/*
MaikazeSekai Sound System

*/
#ifndef MAIKAZE_SOUND_H
#define MAIKAZE_SOUND_H

#include "SDL_Mixer.h"
#include "[Core]Error.h"
#include "[Core]FileMgr.h"

const int ALLSND = -1;
const int LOOP = 0;
const int BGM = 0;
const int SE = 1;
const int VCE = 2;
const int VCE2 = 3;
const int VCE3 = 4;
const int VCE4 = 5;
const int VCE5 = 6;
const int SNDS = 7;
const int FULLVOL = 100;

struct Sounds{
	int channel;
	int index;
	int loop;
	int volumn;
	string path;
	SDL_RWops * rw;
	Mix_Chunk * ck;
};

class SoundSys
{
public:
	SoundSys();
	~SoundSys();

	void Load(int i_channel, string i_path, int i_loop = LOOP, int i_volumn = 100);
	void Unload(int i_channel);
	void ApplyCfg(int i_bv, int i_sv, int i_vv);

	inline int GetVol(int i_channel);
	inline void Play(int i_channel, int i_fadein = 0) {	Mix_FadeInChannel(i_channel, m_snds[i_channel].ck, m_snds[i_channel].loop, i_fadein);}
	inline void Stop(int i_channel, int i_fadeout = 0) { Mix_FadeOutChannel(i_channel, i_fadeout); }
	inline void Pause(int i_channel) { Mix_Pause(i_channel); }
	inline void Resume(int i_channel) {  Mix_Resume(i_channel); }
	inline void SetVol(int i_channel, int i_volumn = 100){ Mix_Volume(i_channel, i_volumn); }

private:
	Sounds m_snds[SNDS];
	FileMgr m_filemgr;
	int m_bgmvol, m_sevol, m_vcevol;
};

#endif