//
#include "../header/[Core]Data.h"

void Config::ReadCfgFile()
{
	//Open and check config.ini
	ifstream file;
	file.open("config.ini", ios::in);
	if (!file){
		SekaiAlert("config.ini not found!\nNow create one new.");
		CreateCfg();
	}

	//Read and Save the value
	char line[32] = { 0 };
	int key = 0;
	int value = 0;
	while (file.getline(line, sizeof(line))){
		//skip the line start with '#'(Regarded as comment)
		if (line[0] == '#')
			continue;
		std::stringstream word(line);
		word >> key;
		word >> value;
		cfgmap.insert(pair<int, int>(key, value));
	}
	file.close();
}

int Config::Load(int i_index)
{
	//Return the value in config.ini
	auto it = cfgmap.find(i_index);
	if (it == cfgmap.end()){
		SekaiAlert("fail to get the value of key" + to_string(i_index));
		return -1;
	}
	return cfgmap[i_index];
}

void Config::CreateCfg()
{
	ofstream file("config.ini");
	if (!file){
		SekaiAlert("Failed to create config.ini");
		return;
	}
	//write down the content of config.ini

	file.close();
}