#pragma once
#include <iostream> //header file of the C++ standard library
#include <vector> //vector library

class artist //artist class
{
private: //private member
	int width; //�ʺ�
	int height; //����
	std::vector<char> pixel; //�ȼ��� ���� ����

public: //public member
	artist(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //artist ������
	~artist() {}; //artist �Ҹ���
	virtual char mapper(int x_coordinate, int y_coordinate) = 0; //���� ���� ��ȯ �Լ�
	int getWidth() const { return width; } //�ʺ� ��ȯ �Լ�
	int getHeight() const { return height; } //���� ��ȯ �Լ�
	void savePixel(const std::vector<char>& _pixel) { pixel = _pixel; } //�ȼ��� ���� ���� ���� �Լ�
	std::vector<char> getPixel() { return pixel; } //�ȼ��� ���� ���� ��ȯ �Լ�
};

class classic : public artist //classic class : artist class ���
{
private: //private member
	std::vector<int> pixelnum; //�ȼ��� ���� ����
	std::vector<char> pixel; //�ȼ��� ���� ����

public: //public member
	classic(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //classic ������
	~classic() {}; //classic �Ҹ���
	char mapper(int x_coordinate, int y_coordinate); //���� ���� ��ȯ �Լ�
};

class iclassic : public artist //iclassic class : artist class ���
{
private: //private member
	std::vector<int> pixelnum; //�ȼ��� ���� ����
	std::vector<char> pixel; //�ȼ��� ���� ����

public: //public member
	iclassic(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //iclassic ������
	~iclassic() {}; //iclassic �Ҹ���
	char mapper(int x_coordinate, int y_coordinate); //���� ���� ��ȯ �Լ�
};

class sobelx : public artist //sobelx class : artist class ���
{
private: //private member
	std::vector<int> pixelnum; //�ȼ��� ���� ����
	std::vector<char> pixel; //�ȼ��� ���� ����

public: //public member
	sobelx(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //soblex ������
	~sobelx() {}; //sobelx �Ҹ���
	char mapper(int x_coordinate, int y_coordinate); //���� ���� ��ȯ �Լ�
};

class sobely : public artist //sobely class : artist class ���
{
private: //private member
	std::vector<int> pixelnum; //�ȼ��� ���� ����
	std::vector<char> pixel; //�ȼ��� ���� ����

public: //public member
	sobely(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //sobely ������
	~sobely() {}; //sobely �Ҹ���
	char mapper(int x_coordinate, int y_coordinate); //���� ���� ��ȯ �Լ�
};

class gradient : public artist //gradient class : artist class ���
{
private: //private member
	std::vector<int> pixelnum; //�ȼ��� ���� ����
	std::vector<char> pixel; //�ȼ��� ���� ����

public: //public member
	gradient(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //gradient ������
	~gradient() {}; //gradient �Ҹ���
	char mapper(int x_coordinate, int y_coordinate); //���� ���� ��ȯ �Լ�
};

class mystyle : public artist //mystyle class : artist class ���
{
private: //private member
	std::vector<int> pixelnum; //�ȼ��� ���� ����
	std::vector<char> pixel; //�ȼ��� ���� ����

public: //public member
	mystyle(int _width = 0, int _height = 0, const std::vector<int>& _pixel = std::vector<int>()); //mystyle ������
	~mystyle() {}; //mystyle �Ҹ���
	char mapper(int x_coordinate, int y_coordinate); //���� ���� ��ȯ �Լ�
};