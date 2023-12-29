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
	string image_string; //이미지 문자열

public: //public member
	drawer(artist* _artist); //drawer 생성자
	~drawer() { delete a; }; //drawer 소멸자
	virtual string draw(); //이미지 문자열 반환 함수
	void saveString(const string& _image_string) { image_string = _image_string; } //이미지 문자열 저장 함수
};

class downsample : public drawer //downsample class : drawer class 상속
{
private: //private member
	string image_string; //이미지 문자열

public: //public member
	downsample(artist* _artist); //downsample 생성자
	~downsample() {}; //downsample 소멸자
	string draw(); //이미지 문자열 반환 함수
};

class upsample : public drawer //upsample class : drawer class 상속
{
private: //private member
	string image_string; //이미지 문자열

public: //public member
	upsample(artist* _artist); //upsample 생성자
	~upsample() {}; //upsample 소멸자
	string draw(); //이미지 문자열 반환 함수
};

class scale : public drawer //scale class : drawer class 상속
{
private: //private member
	string image_string; //이미지 문자열

public: //public member
	scale(artist* _artist, int _x_scale, int _y_scale); //scale 생성자
	~scale() {}; //scale 소멸자
	string draw(); //이미지 문자열 반환 함수
};