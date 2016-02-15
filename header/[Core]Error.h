/*
Error Report System

*/
#ifndef MAIKAZE_ERROR_H
#define MAIKAZE_ERROR_H

#include <iostream>
#include <string>

using namespace std;

inline void SekaiAlert(std::string i_detail){
	cout << "Warning : " << i_detail << std::endl;
}

inline void SekaiBoom(std::string i_detail){
	cout << "Error : " << i_detail << std::endl;
}

inline void SekaiCheck(std::string i_detail){
	cout << "Check : " << i_detail << std::endl;
}

#endif