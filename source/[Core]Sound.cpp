//
#include "../header/[Core]Sound.h"

void Finished(int channel)
{

}

void SoundSys::Init()
{
	Mix_Init(MIX_INIT_FLAC);
	Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 8192);
	Mix_ChannelFinished(&Finished);
}

void SoundSys::Load(int i_channel, string i_path, int i_volumn, int i_loop)
{
	Sounds newSnd;
	newSnd.channel = i_channel;
	newSnd.volumn = i_volumn;
	newSnd.loop = i_loop;
	if (m_filemgr.ReadRW(i_path, &newSnd.rw, newSnd.index))
	{
		if (!(newSnd.ck = Mix_LoadWAV_RW(newSnd.rw, 1)))
			SekaiAlert("cannot analyse the music file from " + i_path);
		m_sounds.push_back(newSnd);
		Play(newSnd);
	}
}

void SoundSys::SetVolumn(int i_channel, int i_volumn)
{

}
