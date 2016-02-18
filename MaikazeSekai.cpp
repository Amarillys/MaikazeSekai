/*
the main Running Activities
MaikazeSekai
*/
#include "SDL.h"
#include <iostream>

#include "header\[Core]Sound.h"
#include "header\[Core]Data.h"
#include "header\Chara.h"
#include "header\Item.h"
#include "header\Npc.h"

#define KEY_WINWIDTH 4
#define KEY_WINHEIGHT 5
#define BGLAYER 1
#define NONE -1

FileMgr file;
Config cfg;
SoundSys snd;
Images img;

SDL_Window * win;
SDL_Renderer * ren;
SDL_Texture * blk;

int win_w = 1280, win_h = 720;

void CleanScreen();
inline void BG(string i_path, int i_x = 0, int i_y = 0, int i_mtime = 0, int i_a = 255, int i_atime = 0);
inline void IMG(int i_id, string i_path, int i_x = 0, int i_y = 0, int i_mtime = 0, int i_a = 255, int i_atime = 0);

inline void BGM(string i_path, int i_loop = LOOP, int i_fadein = 0);
inline void BGMVOL(int i_vol);
inline void SEVOL(int i_vol);
inline void VCEVOL(int i_vol);

struct button{
	int index;
	SDL_Rect rect;
	void (* event)();
};

class UI{
public:
	void Dis();
	void Add();
	void OnNext();
	
private:
	vector<button> m_btns;
};

int main(int argc, char * argv[])
{
	//Load the config and apply
		//Load the configs of screen
	win_w = cfg.Load(KEY_WINWIDTH);
	win_h = cfg.Load(KEY_WINHEIGHT);
		//Load the volumn and apply
	snd.ApplyCfg(BGMCN, cfg.Load(BGMCN));
	snd.ApplyCfg(SECN,  cfg.Load(SECN));
	snd.ApplyCfg(VCECN, cfg.Load(VCECN));

	//Init
	SDL_Init(SDL_INIT_EVENTS);
	win = SDL_CreateWindow("MaikazeSekai", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, SDL_WINDOW_OPENGL);
	ren = SDL_CreateRenderer(win, -1, 0);
	blk = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, win_w, win_h);
		//sent the renderer to Class Image as a stage and init them with the FileMgr
	img.Init(ren, &file);
	snd.Init(&file);
	
	//
	BGM("yui.wav", 1, 0);
	BG("sample.png");
	img.OnDraw();
	//Refresh the textures on renderer
	SDL_RenderPresent(ren);
	getchar();
	return 0;
}

void CleanScreen(){
	SDL_RenderCopy(ren, blk, nullptr, &(SDL_Rect{ 0, 0, win_w, win_h }));
}

inline void BG(string i_path, int i_x, int i_y, int i_mtime, int i_a, int i_atime){
	img.Load(BGLAYER, i_path, i_x, i_y, i_mtime, i_a, i_atime);
}

inline void BGM(string i_path, int i_loop, int i_fadein){
	snd.Load(BGMCN, i_path, i_loop, i_fadein);
}

inline void BGMVOL(int i_vol){
	snd.ApplyCfg(BGMCN, i_vol);
}

inline void SEVOL(int i_vol){
	snd.ApplyCfg(SECN, i_vol);
}

inline void VCEVOL(int i_vol){
	snd.ApplyCfg(VCECN, i_vol);
}
