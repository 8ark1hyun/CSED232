#pragma once
#include "drawer.hpp" //"drawer.hpp" header

drawer::drawer(artist* _artist) //drawer 생성자
{
	a = _artist;

	image_string = "";

	vector<char> v = _artist->getPixel(); //픽셀별 문자 벡터 저장

	for (int i = 0; i < v.size(); i++) //벡터 크기만큼 반복
	{
		image_string += v[i]; //픽셀별 문자 추가
		if (i != 0 && (i + 1) % _artist->getWidth() == 0) //맨 오른쪽 줄이면
		{
			image_string += '\n'; //엔터 추가
		}
	}
}

string drawer::draw() //이미지 문자열 반환 함수
{
	return image_string; //이미지 문자열 반환
}

downsample::downsample(artist* _artist) : drawer(_artist) //downsample 생성자
{
	image_string = "";

	vector<char> v = _artist->getPixel(); //픽셀별 문자 벡터 저장

	for (int i = 0; i < _artist->getHeight(); i++) //높이만큼 반복
	{
		for (int j = 0; j < _artist->getWidth(); j++) //너비만큼 반복
		{
			image_string += v[j + i * _artist->getWidth()]; //픽셀별 문자 추가
			if (_artist->getWidth() % 2 == 1 && (j + 1) % _artist->getWidth() == 0 || _artist->getWidth() % 2 == 0 && (j + 2) % _artist->getWidth() == 0) //너비가 홀수일 때 맨 오른쪽 줄인 경우와, 짝수일 때 행의 마지막 픽셀인 경우
			{
				image_string += '\n'; //엔터 추가
			}
			j++; //두 칸 이동을 위해 한 칸 더 이동
		}
		i++; //두 칸 이동을 위해 한 칸 더 이동
	}

	drawer::saveString(image_string); //이미지 문자열 저장
}

string downsample::draw() //이미지 문자열 반환 함수
{
	return image_string; //이미지 문자열 반환
}

upsample::upsample(artist* _artist) : drawer(_artist) //upsample 생성자
{
	image_string = "";

	vector<char> v = _artist->getPixel(); //픽셀별 문자 벡터 저장

	for (int i = 0; i < _artist->getHeight(); i++) //높이만큼 반복
	{
		string one_line_string = ""; //이미지 문자열의 한 행
		for (int j = 0; j < _artist->getWidth(); j++) //너비만큼 반복
		{
			one_line_string += v[j + i * _artist->getWidth()]; //픽셀별 문자 추가
			one_line_string += v[j + i * _artist->getWidth()]; //픽셀별 문자 추가
			if (j != 0 && (j + 1) % _artist->getWidth() == 0) //맨 오른쪽 줄이면
			{
				one_line_string += '\n'; //엔터 추가
			}
		}
		image_string += one_line_string; //이미지 문자열의 한 행 추가
		image_string += one_line_string; //이미지 문자열의 한 행 추가
	}

	drawer::saveString(image_string); //이미지 문자열 저장
}

string upsample::draw() //이미지 문자열 반환 함수
{
	return image_string; //이미지 문자열 반환
}

scale::scale(artist* _artist, int _x_scale, int _y_scale) : drawer(_artist) //scale 생성자
{	
	image_string = "";

	vector<char> v = _artist->getPixel(); //픽셀별 문자 벡터 저장
	
	for (int i = 0; i < _artist->getHeight(); i++) //높이만큼 반복
	{
		string one_line_string = ""; //이미지 문자열의 한 행
		for (int j = 0; j < _artist->getWidth(); j++) //너비만큼 반복
		{
			if (_x_scale > 0) //x축에 대해 확대하는 경우
			{
				for (int k = 0; k < _x_scale; k++) //확대 비율만큼 반복
				{
					one_line_string += v[j + i * _artist->getWidth()]; //픽셀별 문자 추가
				}
				if (j != 0 && (j + 1) % _artist->getWidth() == 0) //맨 오른쪽 줄이면
				{
					one_line_string += '\n'; //엔터 추가
				}
			}
			else //x축에 대해 축소하는 경우
			{
				one_line_string += v[j + i * _artist->getWidth()]; //픽셀별 문자 추가
				if (_artist->getWidth() % 2 == 1 && (j + 1) % _artist->getWidth() == 0 || _artist->getWidth() % 2 == 0 && (j + 2) % _artist->getWidth() == 0) //너비가 홀수일 때 맨 오른쪽 줄인 경우와, 짝수일 때 행의 마지막 픽셀인 경우
				{
					one_line_string += '\n'; //엔터 추가
				}
				for (int k = 0; k < -1 * _x_scale - 1; k++) //축소 비율만큼 반복
				{
					j++; //칸 이동
				}
			}
		}
		if (_y_scale > 0) //y축에 대해 확대하는 경우
		{
			for (int k = 0; k < _y_scale; k++) //확대 비율만큼 반복
			{
				image_string += one_line_string; //이미지 문자열의 한 행 추가
			}
		}
		else //y축에 대해 축소하는 경우
		{
			image_string += one_line_string; //이미지 문자열의 한 행 추가
			for (int k = 0; k < -1 * _y_scale - 1; k++) //축소 비율만큼 반복
			{
				i++; //칸 이동
			}
		}
	}

	drawer::saveString(image_string); //이미지 문자열 저장
}

string scale::draw() //이미지 문자열 반환 함수
{
	return image_string; //이미지 문자열 반환
}