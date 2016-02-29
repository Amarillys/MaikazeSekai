#ifndef MAIKAZE_API_HPP
#define MAIKAZE_API_HPP

#include "SDL.h"
#include "header\[Core]Sound.h"
#include "header\[Core]Image.h"
#include "header\[Core]Data.h"

#include <iostream>

#define KEY_WINWIDTH 4
#define KEY_WINHEIGHT 5
#define BGLAYER 1
#define NONE -1

extern FileMgr file;
extern Config cfg;
extern SoundSys snd;
extern Images img;

extern SDL_Window * win;
extern SDL_Renderer * ren;
extern SDL_Texture * blk;

extern int win_w, win_h;

inline void CleanScreen(){
	SDL_RenderCopy(ren, blk, nullptr, &(SDL_Rect{ 0, 0, win_w, win_h }));
}

inline void BG(string i_path, int i_x = 0, int i_y = 0, int i_mtime = 0, int i_a = 255, int i_atime = 0){
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

#endif