#pragma once
#include "parser.hpp" //"parser.hpp" header file

vector<int> parser::load_image(const char* filename) //image ���� �ҷ����� �Լ�
{
	vector<int> v;
	int content;
	char delimiter;

	ifstream image_file; //image ����
	image_file.open(filename); //image ���� ����
	
	if (image_file.is_open())
	{
		while (image_file.good())
		{
			image_file >> content >> delimiter; //���� �Է�
			v.push_back(content); //���Ϳ� ����
		}
	}

	image_file.close(); //image ���� �ݱ�

	return v; //���� ��ȯ
}

vector<string> parser::load_config(const char* filename) //config ���� �ҷ����� �Լ�
{
	vector<string> v;
	string line;
	string content;

	ifstream config_file; //config ����
	config_file.open(filename); //config ���� ����

	if (config_file.is_open())
	{
		getline(config_file, line); //���� �Է�

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] != char(124))
			{
				content += line[i];
			}
			else
			{
				v.push_back(content); //���Ϳ� ����
				content = "";
			}
		}
		v.push_back(content); //���Ϳ� ����
	}

	config_file.close(); //config ���� �ݱ�

	return v; //���� ��ȯ
}

void parser::write_result(const char* filename, const string& contents) //��� ��� �Լ�
{
	ofstream output_file; //��� ����
	output_file.open(filename); //��� ���� ����
	if (output_file.is_open())
	{
		output_file << contents; //��� ���� ���� ����
	}
	output_file.close(); //��� ���� �ݱ�
}