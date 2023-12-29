#pragma once
#include "artist.hpp" //"artist.hpp" header

artist::artist(int _width, int _height, const std::vector<int>& _pixel) //artist ������
{
	width = _width; //�ʺ� �Է�
	height = _height; //���� �Է�
}


classic::classic(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //classsic ������
{
	for (int i = 0; i < _width * _height; i++) //�ȼ� ������ŭ �ݺ�
	{
		pixelnum.push_back(_pixel[i]); //�ȼ� ���� ���� �Է�
	}

	pixel.resize(_width * _height); //�ȼ� ������ŭ ���� ũ�� ����

	for (int i = 0; i < _height; i++) //���̸�ŭ �ݺ�
	{
		for (int j = 0; j < _width; j++) //�ʺ�ŭ �ݺ�
		{
			pixel[j + i * _width] = mapper(j, i); //���� ���ڷ� ��ȯ
		}
	}

	artist::savePixel(pixel); //�ȼ��� ���� ���� ����
}

char classic::mapper(int x_coordinate, int y_coordinate) //���� ���� ��ȯ �Լ�
{
	int i = x_coordinate + y_coordinate * getWidth(); //�ȼ� ��ǥ

	if (pixelnum[i] >= 0 && pixelnum[i] <= 16) //�ȼ� ������ 0~16�̸�
	{
		return char(64); //'@' ��ȯ
	}
	else if (pixelnum[i] >= 17 && pixelnum[i] <= 33) //�ȼ� ������ 7~33�̸�
	{
		return char(38); //'&' ��ȯ
	}
	else if (pixelnum[i] >= 34 && pixelnum[i] <= 50) //�ȼ� ������ 34~50�̸�
	{
		return char(37); //'%' ��ȯ
	}
	else if (pixelnum[i] >= 51 && pixelnum[i] <= 67) //�ȼ� ������ 51~67�̸�
	{
		return char(87); //'W' ��ȯ
	}
	else if (pixelnum[i] >= 68 && pixelnum[i] <= 84) //�ȼ� ������ 68~84�̸�
	{
		return char(88); //'X' ��ȯ
	}
	else if (pixelnum[i] >= 85 && pixelnum[i] <= 101) //�ȼ� ������ 85~101�̸�
	{
		return char(65); //'A' ��ȯ
	}
	else if (pixelnum[i] >= 102 && pixelnum[i] <= 118) //�ȼ� ������ 102~118�̸�
	{
		return char(72); //'H' ��ȯ
	}
	else if (pixelnum[i] >= 119 && pixelnum[i] <= 135) //�ȼ� ������ 119~135�̸�
	{
		return char(79); //'O' ��ȯ
	}
	else if (pixelnum[i] >= 136 && pixelnum[i] <= 152) //�ȼ� ������ 136~152�̸�
	{
		return char(84); //'T' ��ȯ
	}
	else if (pixelnum[i] >= 153 && pixelnum[i] <= 169) //�ȼ� ������ 153~169�̸�
	{
		return char(42); //'*' ��ȯ
	}
	else if (pixelnum[i] >= 170 && pixelnum[i] <= 186) //�ȼ� ������ 170~186�̸�
	{
		return char(94); //'^' ��ȯ
	}
	else if (pixelnum[i] >= 187 && pixelnum[i] <= 203) //�ȼ� ������ 187~203�̸�
	{
		return char(43); //'+' ��ȯ
	}
	else if (pixelnum[i] >= 204 && pixelnum[i] <= 220) //�ȼ� ������ 204~220�̸�
	{
		return char(45); //'-' ��ȯ
	}
	else if (pixelnum[i] >= 221 && pixelnum[i] <= 237) //�ȼ� ������ 221~237�̸�
	{
		return char(46); //'.' ��ȯ
	}
	else if (pixelnum[i] >= 238 && pixelnum[i] <= 255) //�ȼ� ������ 238~255�̸�
	{
		return char(32); //���� ��ȯ
	}
}

iclassic::iclassic(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //iclassic ������
{
	for (int i = 0; i < _width * _height; i++) //�ȼ� ������ŭ �ݺ�
	{
		pixelnum.push_back(_pixel[i]); //�ȼ� ���� ���� �Է�
	}

	pixel.resize(_width * _height); //�ȼ� ������ŭ ���� ũ�� ����

	for (int i = 0; i < _height; i++) //���̸�ŭ �ݺ�
	{
		for (int j = 0; j < _width; j++) //�ʺ�ŭ �ݺ�
		{
			pixel[j + i * _width] = mapper(j, i); //���� ���ڷ� ��ȯ
		}
	}

	artist::savePixel(pixel); //�ȼ��� ���� ���� ����
}

char iclassic::mapper(int x_coordinate, int y_coordinate) //���� ���� ��ȯ �Լ�
{
	int i = x_coordinate + y_coordinate * getWidth(); //�ȼ� ��ǥ

	if (pixelnum[i] >= 0 && pixelnum[i] <= 16) //�ȼ� ������ 0~16�̸�
	{
		return char(32); //���� ��ȯ
	}
	else if (pixelnum[i] >= 17 && pixelnum[i] <= 33) //�ȼ� ������ 17~33�̸�
	{
		return char(46); //'.' ��ȯ
	}
	else if (pixelnum[i] >= 34 && pixelnum[i] <= 50) //�ȼ� ������ 34~50�̸�
	{
		return char(45); //'-' ��ȯ
	}
	else if (pixelnum[i] >= 51 && pixelnum[i] <= 67) //�ȼ� ������ 51~67�̸�
	{
		return char(43); //'+' ��ȯ
	}
	else if (pixelnum[i] >= 68 && pixelnum[i] <= 84) //�ȼ� ������ 68~84�̸�
	{
		return char(94); //'^' ��ȯ
	}
	else if (pixelnum[i] >= 85 && pixelnum[i] <= 101) //�ȼ� ������ 85~101�̸�
	{
		return char(42); //'*' ��ȯ
	}
	else if (pixelnum[i] >= 102 && pixelnum[i] <= 118) //�ȼ� ������ 102~118�̸�
	{
		return char(84); //'T' ��ȯ
	}
	else if (pixelnum[i] >= 119 && pixelnum[i] <= 135) //�ȼ� ������ 119~135�̸�
	{
		return char(79); //'O' ��ȯ
	}
	else if (pixelnum[i] >= 136 && pixelnum[i] <= 152) //�ȼ� ������ 136~152�̸�
	{
		return char(72); //'H' ��ȯ
	}
	else if (pixelnum[i] >= 153 && pixelnum[i] <= 169) //�ȼ� ������ 153~169�̸�
	{
		return char(65); //'A' ��ȯ
	}
	else if (pixelnum[i] >= 170 && pixelnum[i] <= 186) //�ȼ� ������ 170~186�̸�
	{
		return char(88); //'X' ��ȯ
	}
	else if (pixelnum[i] >= 187 && pixelnum[i] <= 203) //�ȼ� ������ 187~203�̸�
	{
		return char(87); //'W' ��ȯ
	}
	else if (pixelnum[i] >= 204 && pixelnum[i] <= 220) //�ȼ� ������ 204~220�̸�
	{
		return char(37); //'%' ��ȯ
	}
	else if (pixelnum[i] >= 221 && pixelnum[i] <= 237) //�ȼ� ������ 221~237�̸�
	{
		return char(38); //'&' ��ȯ
	}
	else if (pixelnum[i] >= 238 && pixelnum[i] <= 255) //�ȼ� ������ 238~255�̸�
	{
		return char(64); //'@' ��ȯ
	}
}

sobelx::sobelx(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //sobelx ������
{
	for (int i = 0; i < _width * _height; i++) //�ȼ� ������ŭ �ݺ�
	{
		pixelnum.push_back(_pixel[i]); //�ȼ� ���� ���� �Է�
	}

	pixel.resize(_width * _height); //�ȼ� ������ŭ ���� ũ�� ����

	for (int i = 0; i < _height; i++) //���̸�ŭ �ݺ�
	{
		for (int j = 0; j < _width; j++) //�ʺ�ŭ �ݺ�
		{
			pixel[j + i * _width] = mapper(j, i); //���� ���ڷ� ��ȯ
		}
	}

	artist::savePixel(pixel); //�ȼ��� ���� ���� ����
}

char sobelx::mapper(int x_coordinate, int y_coordinate) //���� ���� ��ȯ �Լ�
{
	int coordinate = x_coordinate + y_coordinate * getWidth(); //��ǥ
	int i = pixelnum[coordinate]; //�ȼ� ��ǥ�� �ش��ϴ� ����
	if (coordinate != 0 && (coordinate + 1) % getWidth() == 0) //�� ������ �ȼ��̸�
	{
		return char(32); //���� ��ȯ
	}
	int j = pixelnum[coordinate + 1]; //x�� ���� �������� +1 ��ǥ�� ����

	if (i - j >= 50 || j - i >= 50) //x������ ������ �ȼ� ���� ���̰� 50�̻��� ���
	{
		return char(124); //'|' ��ȯ
	}
	else //x������ ������ �ȼ� ���� ���̰� 50�̸��� ���
	{
		return char(32); //���� ��ȯ
	}
}

sobely::sobely(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //sobely ������
{
	for (int i = 0; i < _width * _height; i++) //�ȼ� ������ŭ �ݺ�
	{
		pixelnum.push_back(_pixel[i]); //�ȼ� ���� ���� �Է�
	}

	pixel.resize(_width * _height); //�ȼ� ������ŭ ���� ũ�� ����

	for (int i = 0; i < _height; i++) //���̸�ŭ �ݺ�
	{
		for (int j = 0; j < _width; j++) //�ʺ�ŭ �ݺ�
		{
			pixel[j + i * _width] = mapper(j, i); //���� ���ڷ� ��ȯ
		}
	}

	artist::savePixel(pixel); //�ȼ��� ���� ���� ����
}

char sobely::mapper(int x_coordinate, int y_coordinate) //���� ���� ��ȯ �Լ�
{
	int coordinate = x_coordinate + y_coordinate * getWidth(); //��ǥ
	int i = pixelnum[coordinate]; //�ȼ� ��ǥ�� �ش��ϴ� ����
	if (coordinate >= ((getHeight() - 1) * getWidth())) //�� �Ʒ��� �ȼ��̸�
	{
		return char(32); //���� ��ȯ
	}
	int j = pixelnum[coordinate + getWidth()]; //y�� ���� �������� +1 ��ǥ�� ����

	if (i - j >= 50 || j - i >= 50) //y������ ������ �ȼ� ���� ���̰� 50�̻��� ���
	{
		return char(45); //'-' ��ȯ
	}
	else //y������ ������ �ȼ� ���� ���̰� 50�̸��� ���
	{
		return char(32); //���� ��ȯ
	}
}

gradient::gradient(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //gradient ������
{
	for (int i = 0; i < _width * _height; i++) //�ȼ� ������ŭ �ݺ�
	{
		pixelnum.push_back(_pixel[i]); //�ȼ� ���� ���� �Է�
	}

	pixel.resize(_width * _height); //�ȼ� ������ŭ ���� ũ�� ����

	for (int i = 0; i < _height; i++) //���̸�ŭ �ݺ�
	{
		for (int j = 0; j < _width; j++) //�ʺ�ŭ �ݺ�
		{
			pixel[j + i * _width] = mapper(j, i); //���� ���ڷ� ��ȯ
		}
	}

	artist::savePixel(pixel); //�ȼ��� ���� ���� ����
}

char gradient::mapper(int x_coordinate, int y_coordinate) //���� ���� ��ȯ �Լ�
{
	int coordinate = x_coordinate + y_coordinate * getWidth(); //��ǥ
	int i = pixelnum[coordinate]; //�ȼ� ��ǥ�� �ش��ϴ� ����
	if (coordinate != 0 && (coordinate + 1) % getWidth() == 0) //�� ������ �ȼ��̸�
	{
		return char(32); //���� ��ȯ
	}
	int j = pixelnum[coordinate + 1]; //x�� ���� �������� +1 ��ǥ�� 
	if (coordinate >= ((getHeight() - 1) * getWidth())) //�� �Ʒ��� �ȼ��̸�
	{
		return char(32); //���� ��ȯ
	}
	int k = pixelnum[coordinate + getWidth()]; //y�� ���� �������� +1 ��ǥ�� ����

	if (i - j >= 50 || j - i >= 50) //x������ ������ �ȼ� ���� ���̰� 50�̻��� ���
	{
		if (i - k >= 50 || k - i >= 50) //y������ ������ �ȼ� ���� ���̰� 50�̻��� ���
		{
			return char(43); //'+' ��ȯ
		}
		else //y������ ������ �ȼ� ���� ���̰� 50 �̸��� ���
		{
			return char(124); //'|' ��ȯ
		}
	}
	else //x������ ������ �ȼ� ���� ���̰� 50�̸��� ���
	{
		if (i - k >= 50 || k - i >= 50) //y������ ������ �ȼ� ���� ���̰� 50�̻��� ���
		{
			return char(45); //'-' ��ȯ
		}
		else //y������ ������ �ȼ� ���� ���̰� 50�̸��� ���
		{
			return char(32); //���� ��ȯ
		}
	}
}

mystyle::mystyle(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //mystyle ������
{
	for (int i = 0; i < _width * _height; i++) //�ȼ� ������ŭ �ݺ�
	{
		pixelnum.push_back(_pixel[i]); //�ȼ� ���� ���� �Է�
	}

	pixel.resize(_width * _height); //�ȼ� ������ŭ ���� ũ�� ����

	for (int i = 0; i < _height; i++) //���̸�ŭ �ݺ�
	{
		for (int j = 0; j < _width; j++) //�ʺ�ŭ �ݺ�
		{
			pixel[(_width*_height) - 1 - (j + i * _width)] = mapper(j, i); //���� ���ڷ� ��ȯ(classic�� x������ ��Ī)
		}
	}

	artist::savePixel(pixel); //�ȼ��� ���� ���� ����
}

char mystyle::mapper(int x_coordinate, int y_coordinate) //���� ���� ��ȯ �Լ�
{
	int i = x_coordinate + y_coordinate * getWidth(); //�ȼ� ��ǥ

	if (pixelnum[i] >= 0 && pixelnum[i] <= 16) //�ȼ� ������ 0~16�̸�
	{
		return char(64); //'@' ��ȯ
	}
	else if (pixelnum[i] >= 17 && pixelnum[i] <= 33) //�ȼ� ������ 7~33�̸�
	{
		return char(38); //'&' ��ȯ
	}
	else if (pixelnum[i] >= 34 && pixelnum[i] <= 50) //�ȼ� ������ 34~50�̸�
	{
		return char(37); //'%' ��ȯ
	}
	else if (pixelnum[i] >= 51 && pixelnum[i] <= 67) //�ȼ� ������ 51~67�̸�
	{
		return char(87); //'W' ��ȯ
	}
	else if (pixelnum[i] >= 68 && pixelnum[i] <= 84) //�ȼ� ������ 68~84�̸�
	{
		return char(88); //'X' ��ȯ
	}
	else if (pixelnum[i] >= 85 && pixelnum[i] <= 101) //�ȼ� ������ 85~101�̸�
	{
		return char(65); //'A' ��ȯ
	}
	else if (pixelnum[i] >= 102 && pixelnum[i] <= 118) //�ȼ� ������ 102~118�̸�
	{
		return char(72); //'H' ��ȯ
	}
	else if (pixelnum[i] >= 119 && pixelnum[i] <= 135) //�ȼ� ������ 119~135�̸�
	{
		return char(79); //'O' ��ȯ
	}
	else if (pixelnum[i] >= 136 && pixelnum[i] <= 152) //�ȼ� ������ 136~152�̸�
	{
		return char(84); //'T' ��ȯ
	}
	else if (pixelnum[i] >= 153 && pixelnum[i] <= 169) //�ȼ� ������ 153~169�̸�
	{
		return char(42); //'*' ��ȯ
	}
	else if (pixelnum[i] >= 170 && pixelnum[i] <= 186) //�ȼ� ������ 170~186�̸�
	{
		return char(94); //'^' ��ȯ
	}
	else if (pixelnum[i] >= 187 && pixelnum[i] <= 203) //�ȼ� ������ 187~203�̸�
	{
		return char(43); //'+' ��ȯ
	}
	else if (pixelnum[i] >= 204 && pixelnum[i] <= 220) //�ȼ� ������ 204~220�̸�
	{
		return char(45); //'-' ��ȯ
	}
	else if (pixelnum[i] >= 221 && pixelnum[i] <= 237) //�ȼ� ������ 221~237�̸�
	{
		return char(46); //'.' ��ȯ
	}
	else if (pixelnum[i] >= 238 && pixelnum[i] <= 255) //�ȼ� ������ 238~255�̸�
	{
		return char(32); //���� ��ȯ
	}
}