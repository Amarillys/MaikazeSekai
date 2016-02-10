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
	//vector<string> tmp_pkg_paths;
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
		AddRW(o_index, SDL_RWFromFile(i_path.c_str(), "rb"), o_rw_ptr);
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
	for (auto it = m_files.begin(); it != m_files.end(); ++it)
	if (it->path == i_path)
		return it->index;
	//SekaiAlert("Cannot find the file" + i_path);
	return -1;
}

void FileMgr::AddRW(int i_index, SDL_RWops* i_rw, SDL_RWops** o_rw_ptr)
{
	RWPack newRW;
	newRW.index = i_index;
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
			delete it->rw;
			m_files.erase(it);
			break;
		}
		else
			it++;
	}
}