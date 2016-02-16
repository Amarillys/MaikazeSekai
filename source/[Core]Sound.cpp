//
#include "../header/[Core]Sound.h"

void Finished(int i_channel)
{
	SekaiCheck(to_string(i_channel) + " channel finish one playback!");
	//Unload(i_channel);
}

SoundSys::SoundSys()
{
	Mix_Init(MIX_INIT_FLAC);
	Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 8192);
	Mix_ChannelFinished(&Finished);
	m_bgmvol = m_sevol = m_vcevol = FULLVOL;
	//Init the array of sound
	for (int i = 0; i < SNDS; ++i)
		m_snds[i] = { i, -1, -1, FULLVOL, "blank", nullptr, nullptr};
}

SoundSys::~SoundSys()
{
	//fadeout and Unload
	Stop(ALLSND, 600);
	Mix_CloseAudio();
	for (int i = 0; i < SNDS; ++i)
		Unload(i);
}

void SoundSys::Load(int i_channel, string i_path, int i_loop, int i_fadein)
{
	//detect if it is the same as the former
	if (!i_path.compare(m_snds[i_channel].path))
	{
		Play(i_channel);
		return;
	}
	//if the former exists an music, unload it
	if (m_snds[i_channel].index > -1){
		Stop(i_channel, 200);
		Unload(i_channel);
	}

	//apply for the new sound
	m_snds[i_channel].channel = i_channel;
	m_snds[i_channel].loop = i_loop - 1;
	m_snds[i_channel].path = i_path;
	if (m_filemgr.ReadRW(i_path, &(m_snds[i_channel].rw), m_snds[i_channel].index))
	{
		if (!(m_snds[i_channel].ck = Mix_LoadWAV_RW(m_snds[i_channel].rw, AUTOFREE))){
			SekaiAlert("cannot analyse the music file from " + i_path);
			return;
		}
		SetVol(i_channel, GetVol(i_channel));
		Play(i_channel, i_fadein);
	}
}

void SoundSys::Unload(int i_channel){
	//free the Mix_Chunk and the SDL_RWops, and then init
	if (m_snds[i_channel].ck)
		Mix_FreeChunk(m_snds[i_channel].ck);
	if (m_snds[i_channel].index > -1)
		m_filemgr.FreeRW(m_snds[i_channel].index);
	m_snds[i_channel] = { i_channel, -1, -1, GetVol(i_channel), "blank", nullptr, nullptr };
	SekaiCheck("Unload channel " + to_string(i_channel) + " Finished");
}

void SoundSys::ApplyCfg(int i_channel, int i_vol){
	if (i_vol > -1)	m_snds[i_channel].volumn = i_vol;
}

inline int SoundSys::GetVol(int i_channel){
	if(i_channel > -1 && i_channel < MAXCN)
		return m_snds[i_channel].volumn;
	SekaiAlert("the Channel required is Invalid in GetVol().");
	return 100;
}
