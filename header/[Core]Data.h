/*
MaikazeSekai Image System
*/
#ifndef MAIKAZE_DATA_H
#define MAIKAZE_DATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

#include "[Core]Error.h"

class Config{
public:
	Config(){ ReadCfgFile(); }
	~Config(){}
	int Load(int i_index);
	void CreateCfg();
	void ReadCfgFile();

private:
	map<int, int> cfgmap;
};

class CSV{
public:
    void Init(string i_file);
    int LoadInt(int i_index);
    string LoadStr(int i_index);

private:
    map<int, int> intmap;
    map<int, string> strmap;

};
#endif