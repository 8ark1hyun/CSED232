#pragma once
#include <iostream> //header file of the C++ standard library
#include <fstream> //fstream library
#include <string> //string library
#include <vector> //vector library

using namespace std; //Namespace

class parser //parser class
{
public: //public member
	vector<int> load_image(const char* filename); //image ���� �ҷ����� �Լ�
	vector<string> load_config(const char* filename); //config ���� �ҷ����� �Լ�
	void write_result(const char* filename, const string& contents); //��� ��� �Լ�
};