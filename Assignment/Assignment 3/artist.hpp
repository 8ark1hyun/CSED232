#pragma once
#include <iostream> //header file of the C++ standard library
#include <vector> //vector library

class artist //artist class
{
private: //private member
	int width; //너비
	int height; //높이
	std::vector<char> pixel; //픽셀별 문자 벡터

public: //public member
	artist(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //artist 생성자
	~artist() {}; //artist 소멸자
	virtual char mapper(int x_coordinate, int y_coordinate) = 0; //명도값 문자 변환 함수
	int getWidth() const { return width; } //너비 반환 함수
	int getHeight() const { return height; } //높이 반환 함수
	void savePixel(const std::vector<char>& _pixel) { pixel = _pixel; } //픽셀별 문자 벡터 저장 함수
	std::vector<char> getPixel() { return pixel; } //픽셀별 문자 벡터 반환 함수
};

class classic : public artist //classic class : artist class 상속
{
private: //private member
	std::vector<int> pixelnum; //픽셀별 명도값 벡터
	std::vector<char> pixel; //픽셀별 문자 벡터

public: //public member
	classic(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //classic 생성자
	~classic() {}; //classic 소멸자
	char mapper(int x_coordinate, int y_coordinate); //명도값 문자 변환 함수
};

class iclassic : public artist //iclassic class : artist class 상속
{
private: //private member
	std::vector<int> pixelnum; //픽셀별 명도값 벡터
	std::vector<char> pixel; //픽셀별 문자 벡터

public: //public member
	iclassic(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //iclassic 생성자
	~iclassic() {}; //iclassic 소멸자
	char mapper(int x_coordinate, int y_coordinate); //명도값 문자 변환 함수
};

class sobelx : public artist //sobelx class : artist class 상속
{
private: //private member
	std::vector<int> pixelnum; //픽셀별 명도값 벡터
	std::vector<char> pixel; //픽셀별 문자 벡터

public: //public member
	sobelx(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //soblex 생성자
	~sobelx() {}; //sobelx 소멸자
	char mapper(int x_coordinate, int y_coordinate); //명도값 문자 변환 함수
};

class sobely : public artist //sobely class : artist class 상속
{
private: //private member
	std::vector<int> pixelnum; //픽셀별 명도값 벡터
	std::vector<char> pixel; //픽셀별 문자 벡터

public: //public member
	sobely(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //sobely 생성자
	~sobely() {}; //sobely 소멸자
	char mapper(int x_coordinate, int y_coordinate); //명도값 문자 변환 함수
};

class gradient : public artist //gradient class : artist class 상속
{
private: //private member
	std::vector<int> pixelnum; //픽셀별 명도값 벡터
	std::vector<char> pixel; //픽셀별 문자 벡터

public: //public member
	gradient(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //gradient 생성자
	~gradient() {}; //gradient 소멸자
	char mapper(int x_coordinate, int y_coordinate); //명도값 문자 변환 함수
};

class mystyle : public artist //mystyle class : artist class 상속
{
private: //private member
	std::vector<int> pixelnum; //픽셀별 명도값 벡터
	std::vector<char> pixel; //픽셀별 문자 벡터

public: //public member
	mystyle(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //mystyle 생성자
	~mystyle() {}; //mystyle 소멸자
	char mapper(int x_coordinate, int y_coordinate); //명도값 문자 변환 함수
};