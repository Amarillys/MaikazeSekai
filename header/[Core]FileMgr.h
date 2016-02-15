/*
Maikaze
Package System:

1.Index Inside/Outside Support(default:Outside)
2.Compress Support(default:none, support: deflate)
3.Multi Part Support

*/
#ifndef MAIKAZE_PACKAGE_H
#define MAIKAZE_PACKAGE_H

#define AUTOFREE 1

#include <fstream>
#include <string>
#include <vector>

#include "SDL.h"
#include "[Core]Error.h"

using namespace std;

struct RWPack{
	int index;
	SDL_RWops * rw;
	string path;
};

class FileMgr
{
public:
	void Init();
	void AddRW(int i_index, SDL_RWops* i_rw, SDL_RWops** o_rw);
	int GetIndex(string i_path);
	void GetRW(string i_path, SDL_RWops** o_rw);
	void FreeRW(int i_index);
	bool ReadRW(string i_path, SDL_RWops** o_rw, int & o_index);

private:
	vector<ifstream> m_pkg_ifs;
	vector<RWPack> m_files;

};

#endif
