/*
the main Running Activities
MaikazeSekai
*/

#include "SDL.h"
#include <iostream>

#include "header\[Core]Sound.h"
#include "header\[Core]Data.h"
#include "header\Bg.h"
#include "header\Chara.h"
#include "header\Item.h"
#include "header\Npc.h"
#include "header\Ui.h"

#define bgm BGM
#define se SE
#define vce VCE
#define WINWIDTH 4
#define WINHEIGHT 5
#define BG 1

Config cfg;
SoundSys snd;
Images img;

SDL_Window * win;
SDL_Renderer * ren;

inline void LoadIMG(int i_id, string i_path, int i_x = 0, int i_y = 0, int i_mtime = 0, int i_a = 255, int i_atime = 0);

int main(int argc, char * argv[])
{
	//Init
	SDL_Init(SDL_INIT_EVENTS);
	//Load the config and apply
	int win_w = 1280 , win_h = 720;
	win_w = cfg.Load(WINWIDTH);
	win_h = cfg.Load(WINHEIGHT);
	snd.ApplyCfg(cfg.Load(BGM), cfg.Load(SE), cfg.Load(VCE));

	win = SDL_CreateWindow("MaikazeSekai", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, SDL_WINDOW_OPENGL);
	ren = SDL_CreateRenderer(win, -1, 0);
	img.Init(ren);
	int i;
	snd.Load(bgm, "yui.wav", 2);
	LoadIMG(BG, "sample.png");
	img.OnDraw();
	cin >> i;
	return 0;
}

inline void LoadIMG(int i_id, string i_path, int i_x, int i_y, int i_mtime, int i_a, int i_atime){
	img.Load(i_id, i_path, i_x, i_y, i_mtime, i_a, i_atime);
}