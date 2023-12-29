#pragma once
#include <iostream> //header file of the C++ standard library
#include <fstream> //fstream library
#include <string> //string library
#include <vector> //vector library

using namespace std; //Namespace

class parser //parser class
{
public: //public member
	vector<int> load_image(const char* filename); //image 파일 불러오기 함수
	vector<string> load_config(const char* filename); //config 파일 불러오기 함수
	void write_result(const char* filename, const string& contents); //결과 출력 함수
};