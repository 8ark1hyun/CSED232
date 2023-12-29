#pragma once
#include "drawer.hpp" //"drawer.hpp" header

drawer::drawer(artist* _artist) //drawer ������
{
	a = _artist;

	image_string = "";

	vector<char> v = _artist->getPixel(); //�ȼ��� ���� ���� ����

	for (int i = 0; i < v.size(); i++) //���� ũ�⸸ŭ �ݺ�
	{
		image_string += v[i]; //�ȼ��� ���� �߰�
		if (i != 0 && (i + 1) % _artist->getWidth() == 0) //�� ������ ���̸�
		{
			image_string += '\n'; //���� �߰�
		}
	}
}

string drawer::draw() //�̹��� ���ڿ� ��ȯ �Լ�
{
	return image_string; //�̹��� ���ڿ� ��ȯ
}

downsample::downsample(artist* _artist) : drawer(_artist) //downsample ������
{
	image_string = "";

	vector<char> v = _artist->getPixel(); //�ȼ��� ���� ���� ����

	for (int i = 0; i < _artist->getHeight(); i++) //���̸�ŭ �ݺ�
	{
		for (int j = 0; j < _artist->getWidth(); j++) //�ʺ�ŭ �ݺ�
		{
			image_string += v[j + i * _artist->getWidth()]; //�ȼ��� ���� �߰�
			if (_artist->getWidth() % 2 == 1 && (j + 1) % _artist->getWidth() == 0 || _artist->getWidth() % 2 == 0 && (j + 2) % _artist->getWidth() == 0) //�ʺ� Ȧ���� �� �� ������ ���� ����, ¦���� �� ���� ������ �ȼ��� ���
			{
				image_string += '\n'; //���� �߰�
			}
			j++; //�� ĭ �̵��� ���� �� ĭ �� �̵�
		}
		i++; //�� ĭ �̵��� ���� �� ĭ �� �̵�
	}

	drawer::saveString(image_string); //�̹��� ���ڿ� ����
}

string downsample::draw() //�̹��� ���ڿ� ��ȯ �Լ�
{
	return image_string; //�̹��� ���ڿ� ��ȯ
}

upsample::upsample(artist* _artist) : drawer(_artist) //upsample ������
{
	image_string = "";

	vector<char> v = _artist->getPixel(); //�ȼ��� ���� ���� ����

	for (int i = 0; i < _artist->getHeight(); i++) //���̸�ŭ �ݺ�
	{
		string one_line_string = ""; //�̹��� ���ڿ��� �� ��
		for (int j = 0; j < _artist->getWidth(); j++) //�ʺ�ŭ �ݺ�
		{
			one_line_string += v[j + i * _artist->getWidth()]; //�ȼ��� ���� �߰�
			one_line_string += v[j + i * _artist->getWidth()]; //�ȼ��� ���� �߰�
			if (j != 0 && (j + 1) % _artist->getWidth() == 0) //�� ������ ���̸�
			{
				one_line_string += '\n'; //���� �߰�
			}
		}
		image_string += one_line_string; //�̹��� ���ڿ��� �� �� �߰�
		image_string += one_line_string; //�̹��� ���ڿ��� �� �� �߰�
	}

	drawer::saveString(image_string); //�̹��� ���ڿ� ����
}

string upsample::draw() //�̹��� ���ڿ� ��ȯ �Լ�
{
	return image_string; //�̹��� ���ڿ� ��ȯ
}

scale::scale(artist* _artist, int _x_scale, int _y_scale) : drawer(_artist) //scale ������
{	
	image_string = "";

	vector<char> v = _artist->getPixel(); //�ȼ��� ���� ���� ����
	
	for (int i = 0; i < _artist->getHeight(); i++) //���̸�ŭ �ݺ�
	{
		string one_line_string = ""; //�̹��� ���ڿ��� �� ��
		for (int j = 0; j < _artist->getWidth(); j++) //�ʺ�ŭ �ݺ�
		{
			if (_x_scale > 0) //x�࿡ ���� Ȯ���ϴ� ���
			{
				for (int k = 0; k < _x_scale; k++) //Ȯ�� ������ŭ �ݺ�
				{
					one_line_string += v[j + i * _artist->getWidth()]; //�ȼ��� ���� �߰�
				}
				if (j != 0 && (j + 1) % _artist->getWidth() == 0) //�� ������ ���̸�
				{
					one_line_string += '\n'; //���� �߰�
				}
			}
			else //x�࿡ ���� ����ϴ� ���
			{
				one_line_string += v[j + i * _artist->getWidth()]; //�ȼ��� ���� �߰�
				if (_artist->getWidth() % 2 == 1 && (j + 1) % _artist->getWidth() == 0 || _artist->getWidth() % 2 == 0 && (j + 2) % _artist->getWidth() == 0) //�ʺ� Ȧ���� �� �� ������ ���� ����, ¦���� �� ���� ������ �ȼ��� ���
				{
					one_line_string += '\n'; //���� �߰�
				}
				for (int k = 0; k < -1 * _x_scale - 1; k++) //��� ������ŭ �ݺ�
				{
					j++; //ĭ �̵�
				}
			}
		}
		if (_y_scale > 0) //y�࿡ ���� Ȯ���ϴ� ���
		{
			for (int k = 0; k < _y_scale; k++) //Ȯ�� ������ŭ �ݺ�
			{
				image_string += one_line_string; //�̹��� ���ڿ��� �� �� �߰�
			}
		}
		else //y�࿡ ���� ����ϴ� ���
		{
			image_string += one_line_string; //�̹��� ���ڿ��� �� �� �߰�
			for (int k = 0; k < -1 * _y_scale - 1; k++) //��� ������ŭ �ݺ�
			{
				i++; //ĭ �̵�
			}
		}
	}

	drawer::saveString(image_string); //�̹��� ���ڿ� ����
}

string scale::draw() //�̹��� ���ڿ� ��ȯ �Լ�
{
	return image_string; //�̹��� ���ڿ� ��ȯ
}