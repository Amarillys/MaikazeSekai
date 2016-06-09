/*
Error Report System

*/
#ifndef MAIKAZE_ERROR_H
#define MAIKAZE_ERROR_H

#include <iostream>
#include <string>

using namespace std;

inline void SekaiAlert(string i_detail){
	cout << "Warning : " << i_detail << std::endl;
}

inline void SekaiBoom(string i_detail){
	cout << "Error : " << i_detail << std::endl;
}

inline void SekaiCheck(string i_detail){
	cout << "Check : " << i_detail << std::endl;
}

#endif