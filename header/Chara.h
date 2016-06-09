/*
MaikazeSekai Character System
*/
#ifndef MAIKAZE_CHARA_H
#define MAIKAZE_CHARA_H

#include "../API.hpp"

class NPC
{
public:
	void Load(int i_index, string i_path, int i_x = 0, int i_y = 0, bool show = true, bool i_doubledrt = false, int i_frames = 1);
	void Unload();
	void Show();
	void Hide();
	void Susume();
	void Refresh();

private:

};

class Chara
{
public:
	Chara();
	~Chara();
	void Init();
	void Load();
	void Show();
	void Hide();
	void Receive();
	void SetPos();
	void SetAlpha();
	void SetLeft(bool i_left = true);

private:

};
#endif