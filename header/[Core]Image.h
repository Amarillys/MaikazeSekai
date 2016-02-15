/*
MaikazeSekai Image System
*/
#ifndef MAIKAZE_IMAGE_H
#define MAIKAZE_IMAGE_H

#include "SDL_Image.h"
#include "[Core]FileMgr.h"

struct Image{
	int id;
	int index;
	int a;
	SDL_Rect rect;
	SDL_Surface * sur;
	SDL_Texture * tex;
	SDL_RWops * rw;
	string path;
};

class Images{
public:
	Images();
	~Images();
	//the atime is the time during the alpha changing from 0 to i_a
	void Load(int i_id, string i_path, int i_x = 0, int i_y = 0, int i_mtime = 0, int i_a = 255, int i_atime = 0);
	void Unload(int i_id);
	void Show(int i_id);
	void Hide(int i_id);
	void SetPos(int i_id, int i_x, int i_y, int i_mtime);
	void SetAlpha(int i_id, int i_a, int i_atime);

	inline void Init(SDL_Renderer * i_ren){ m_ren = i_ren; }
	void OnDraw();
	void OnNext();

private:
	FileMgr m_files;
	vector<Image> m_imgs;
	SDL_Renderer * m_ren;
};
#endif