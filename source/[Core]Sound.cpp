//
#include "../header/[Core]Sound.h"

void Finished(int channel)
{

}

void SoundSys::Init()
{
	Mix_Init(MIX_INIT_OGG | MIX_INIT_FLAC |  MIX_INIT_MP3);
	Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 8192);
	Mix_ChannelFinished(&Finished);
}

void SoundSys::LoadAudio(int i_channel, string i_path, int i_volumn, int i_loop)
{
	Sounds newSnd;
	newSnd.channel = i_channel;
	newSnd.volumn = i_volumn;
	newSnd.loop = i_loop;
	if (m_filemgr.ReadRW(i_path, &newSnd.rw, newSnd.index))
	{
		newSnd.ck = Mix_LoadWAV_RW(newSnd.rw, 1048576);
		m_sounds.push_back(newSnd);
		PlayAudio(newSnd);
	}
}

void SoundSys::PlayAudio(Sounds i_sound)
{
	Mix_PlayChannel(i_sound.channel, i_sound.ck, i_sound.loop);
}

void SoundSys::SetVolumn(int i_channel, int i_volumn)
{

}
