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
	UI();
	~UI();
	void Init();
	void Receive();
	void Susume();
	void Refresh();
	void JmpTo();

private:
	NPC m_npc;
	vector<button> m_btns;
	//0 - chara
	int m_static;
};

#endif