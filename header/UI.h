/*
Maikaze UI System
<important>
*/
#ifndef MAIKAZE_UI_H
#define MAIKAZE_UI_H
        
#include "Chara.h"
#include "Item.h"

struct button{
	int index;
	SDL_Rect rect;
	void(*event)();
};

class UI{
public:
	void Susume();
	void Refresh();
private:
	int m_i;
};

#endif