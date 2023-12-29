#pragma once
#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include <vector> //vector library
#include "artist.hpp" //"artist.hpp" header

using namespace std; //Namespace

class drawer //drawer class
{
private: //private member
	artist* a;
	string image_string; //�̹��� ���ڿ�

public: //public member
	drawer(artist* _artist); //drawer ������
	~drawer() { delete a; }; //drawer �Ҹ���
	virtual string draw(); //�̹��� ���ڿ� ��ȯ �Լ�
	void saveString(const string& _image_string) { image_string = _image_string; } //�̹��� ���ڿ� ���� �Լ�
};

class downsample : public drawer //downsample class : drawer class ���
{
private: //private member
	string image_string; //�̹��� ���ڿ�

public: //public member
	downsample(artist* _artist); //downsample ������
	~downsample() {}; //downsample �Ҹ���
	string draw(); //�̹��� ���ڿ� ��ȯ �Լ�
};

class upsample : public drawer //upsample class : drawer class ���
{
private: //private member
	string image_string; //�̹��� ���ڿ�

public: //public member
	upsample(artist* _artist); //upsample ������
	~upsample() {}; //upsample �Ҹ���
	string draw(); //�̹��� ���ڿ� ��ȯ �Լ�
};

class scale : public drawer //scale class : drawer class ���
{
private: //private member
	string image_string; //�̹��� ���ڿ�

public: //public member
	scale(artist* _artist, int _x_scale, int _y_scale); //scale ������
	~scale() {}; //scale �Ҹ���
	string draw(); //�̹��� ���ڿ� ��ȯ �Լ�
};