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

void CSV::Init(string i_file)
{
    //Open and check
    intmap.clear();
    strmap.clear();

    ifstream l_csv;
    l_csv.open(i_file, ios::in);
    if (!l_csv) 
        SekaiAlert(i_file + "not found!\n");

    //1 = str,  0 = int
    char line[64] = { 0 };
    int key = 0, value = 0;
    int type = 0;
    string strval;
    while (l_csv.getline(line, sizeof(line))){
        //skip the line start with '#'(Regarded as comment)
        if (line[0] == '#')
            continue;
        std::stringstream word(line);
        word >> key;
        word >> type;
        if (type == 0){
            word >> value;
            intmap.insert(pair<int, int>(key, value));
        } else {
            word >> strval;
            strmap.insert(pair<int, string>(key, strval));
        }
    }
    l_csv.close();
}

int CSV::LoadInt(int i_index) {
    //Return the value from intmap
    auto it = intmap.find(i_index);
    if (it == intmap.end()){
        SekaiAlert("fail to get the value of key" + to_string(i_index));
        return -1;
    }
    return intmap[i_index];
}

string CSV::LoadStr(int i_index) {
    //Return the value from strmap
    auto it = strmap.find(i_index);
    if (it == strmap.end()) {
        SekaiAlert("fail to get the value of key" + to_string(i_index));
        return NULL;
    }
    return strmap[i_index];
}
