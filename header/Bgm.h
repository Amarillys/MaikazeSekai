/*
BGM System

1.MultiBgm Support
2.FadeIn and FadeOut
3.
*/
#include "[Core]Sound.h"
#include "[Core]Error.h"


class BgmMgr
{
public:
	inline void PlayBGM(string i_path, const int i_loop = -1){
		m_soundsys.LoadAudio(BGMCHANNEL, i_path, i_loop);
	}	

	inline void StopBGM(){

	}

private:
	SoundSys m_soundsys;

};