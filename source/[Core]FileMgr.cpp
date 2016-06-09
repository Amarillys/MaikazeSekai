//
#include "../header/[Core]FileMgr.h"

void FileMgr::Init()
{
	//Open the list of packages
	ifstream lst;
	lst.open("pkg.lst",ios::in);
	if (!lst)
		cout << "Failed to open the list of packages!" << endl;

	//Read the packages
	string tmp_str;
	ifstream tmp_if;
	while (!lst.eof()) 
	{
		tmp_str = "";
		getline(lst, tmp_str, '\n');
		tmp_if.open(tmp_str, ios::in);
		if (!tmp_if)
		{
			SekaiAlert("Cannot open the package!" + tmp_str);
			continue;
		}
	}
}

bool FileMgr::ReadRW(string i_path, SDL_RWops** o_rw_ptr, int& o_index)
{
	//search if it has been loaded
	for (auto it = m_files.begin(); it != m_files.end(); ++it)
	{
		if (i_path == it->path)
		{
			*o_rw_ptr = it->rw;
			o_index = it->index;
			return true;
		}
	}

	//find the target file outside
	ifstream res;
	res.open(i_path, ios::in);
	if (res)
	{
		o_index = GetIndex(i_path);
		AddRW(o_index, i_path, SDL_RWFromFile(i_path.c_str(), "rb"), o_rw_ptr);
		return true;
	}

	//find the target file in packages
	for (auto it = m_files.begin(); it != m_files.end(); ++it)
	if (it->path == i_path)
	{
		GetRW(it->path, o_rw_ptr);
		return true;
	}
	SekaiAlert("Cannot find the file!");
	return false;
}

int FileMgr::GetIndex(string i_path)
{
    //return if
    bool got = false, exist;
    int index = 0;
    while (!got)
    {
        exist = false;
        for (auto it = m_files.begin(); it != m_files.end(); ++it)
        if (index == it->index)
            exist = true;
        if (exist)
        {
            index++;
            continue;
        }
        else
            return index;
    }
	
	//SekaiAlert("Cannot find the file" + i_path);
	return m_files.size();
}

void FileMgr::AddRW(int i_index, string i_path, SDL_RWops* i_rw, SDL_RWops** o_rw_ptr)
{
	RWPack newRW;
	newRW.index = i_index;
    newRW.path = i_path;
	*o_rw_ptr = newRW.rw = i_rw;
	m_files.push_back(newRW);
}

void FileMgr::GetRW(string i_path, SDL_RWops** o_rw)
{

}

void FileMgr::FreeRW(int i_index)
{
	for (auto it = m_files.begin(); it != m_files.end();)
	{
		if (it->index == i_index)
		{
            SDL_RWclose(it->rw);
			m_files.erase(it);
			break;
		}
		else
			it++;
	}
}