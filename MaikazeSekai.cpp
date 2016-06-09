/*
the main Running Activities
MaikazeSekai
*/

#include "header/UI.h"

FileMgr file;
Config cfg;
SoundSys snd;
Images img;

SDL_Window * win;
SDL_Renderer * ren;
SDL_Texture * blk;

int win_w = 1280, win_h = 720;

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
	SDL_RenderSetLogicalSize(ren, 1280, 720);
	blk = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, win_w, win_h);
		//sent the renderer to Class Image as a stage and init them with the FileMgr
	img.Init(ren, &file);
	snd.Init(&file);

    
    auto *rw = SDL_RWFromFile("z:/star.png", "r");
    auto sur = IMG_Load_RW(rw, AUTOFREE);
    auto tex = SDL_CreateTextureFromSurface(ren, sur);
    SDL_FreeSurface(sur);
    SDL_Rect rt = { 0, 0, 2362, 7087 };
    SDL_RenderCopy(ren, tex, NULL, &rt);
    SDL_RenderPresent(ren);
    SDL_DestroyTexture(tex);

    auto *rw2 = SDL_RWFromFile("z:/1.png", "r");
    auto sur2 = IMG_Load_RW(rw2, AUTOFREE);
    auto tex2 = SDL_CreateTextureFromSurface(ren, sur2);
    SDL_FreeSurface(sur2);
    SDL_Rect rt2 = { 0, 0, 800, 900 };
    SDL_RenderCopy(ren, tex2, NULL, &rt2);
    SDL_RenderPresent(ren);
    //SDL_DestroyTexture(tex);
    
	
	//
	BGM("yui.wav", 1, 0);
	BG("sample.png");
	img.OnDraw();

	//Refresh the textures on renderer
	SDL_RenderPresent(ren);
    UnLoadBG();
    //SDL_DestroyTexture()
	//Logo();
	//Title();
	SDL_Quit();
	return 0;
}
