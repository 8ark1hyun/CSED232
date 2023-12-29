#pragma once
#include "parser.hpp" //"parser.hpp" header file

vector<int> parser::load_image(const char* filename) //image 파일 불러오기 함수
{
	vector<int> v;
	int content;
	char delimiter;

	ifstream image_file; //image 파일
	image_file.open(filename); //image 파일 열기
	
	if (image_file.is_open())
	{
		while (image_file.good())
		{
			image_file >> content >> delimiter; //내용 입력
			v.push_back(content); //벡터에 저장
		}
	}

	image_file.close(); //image 파일 닫기

	return v; //벡터 반환
}

vector<string> parser::load_config(const char* filename) //config 파일 불러오기 함수
{
	vector<string> v;
	string line;
	string content;

	ifstream config_file; //config 파일
	config_file.open(filename); //config 파일 열기

	if (config_file.is_open())
	{
		getline(config_file, line); //내용 입력

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] != char(124))
			{
				content += line[i];
			}
			else
			{
				v.push_back(content); //벡터에 저장
				content = "";
			}
		}
		v.push_back(content); //벡터에 저장
	}

	config_file.close(); //config 파일 닫기

	return v; //벡터 반환
}

void parser::write_result(const char* filename, const string& contents) //결과 출력 함수
{
	ofstream output_file; //출력 파일
	output_file.open(filename); //출력 파일 열기
	if (output_file.is_open())
	{
		output_file << contents; //출력 파일 내용 저장
	}
	output_file.close(); //출력 파일 닫기
}