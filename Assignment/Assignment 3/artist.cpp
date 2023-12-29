#pragma once
#include "artist.hpp" //"artist.hpp" header

artist::artist(int _width, int _height, const std::vector<int>& _pixel) //artist 생성자
{
	width = _width; //너비 입력
	height = _height; //넓이 입력
}


classic::classic(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //classsic 생성자
{
	for (int i = 0; i < _width * _height; i++) //픽셀 개수만큼 반복
	{
		pixelnum.push_back(_pixel[i]); //픽셀 명도값 벡터 입력
	}

	pixel.resize(_width * _height); //픽셀 개수만큼 벡터 크기 조정

	for (int i = 0; i < _height; i++) //높이만큼 반복
	{
		for (int j = 0; j < _width; j++) //너비만큼 반복
		{
			pixel[j + i * _width] = mapper(j, i); //명도값 문자로 변환
		}
	}

	artist::savePixel(pixel); //픽셀별 문자 벡터 저장
}

char classic::mapper(int x_coordinate, int y_coordinate) //명도값 문자 변환 함수
{
	int i = x_coordinate + y_coordinate * getWidth(); //픽셀 좌표

	if (pixelnum[i] >= 0 && pixelnum[i] <= 16) //픽셀 명도값이 0~16이면
	{
		return char(64); //'@' 반환
	}
	else if (pixelnum[i] >= 17 && pixelnum[i] <= 33) //픽셀 명도값이 7~33이면
	{
		return char(38); //'&' 반환
	}
	else if (pixelnum[i] >= 34 && pixelnum[i] <= 50) //픽셀 명도값이 34~50이면
	{
		return char(37); //'%' 반환
	}
	else if (pixelnum[i] >= 51 && pixelnum[i] <= 67) //픽셀 명도값이 51~67이면
	{
		return char(87); //'W' 반환
	}
	else if (pixelnum[i] >= 68 && pixelnum[i] <= 84) //픽셀 명도값이 68~84이면
	{
		return char(88); //'X' 반환
	}
	else if (pixelnum[i] >= 85 && pixelnum[i] <= 101) //픽셀 명도값이 85~101이면
	{
		return char(65); //'A' 반환
	}
	else if (pixelnum[i] >= 102 && pixelnum[i] <= 118) //픽셀 명도값이 102~118이면
	{
		return char(72); //'H' 반환
	}
	else if (pixelnum[i] >= 119 && pixelnum[i] <= 135) //픽셀 명도값이 119~135이면
	{
		return char(79); //'O' 반환
	}
	else if (pixelnum[i] >= 136 && pixelnum[i] <= 152) //픽셀 명도값이 136~152이면
	{
		return char(84); //'T' 반환
	}
	else if (pixelnum[i] >= 153 && pixelnum[i] <= 169) //픽셀 명도값이 153~169이면
	{
		return char(42); //'*' 반환
	}
	else if (pixelnum[i] >= 170 && pixelnum[i] <= 186) //픽셀 명도값이 170~186이면
	{
		return char(94); //'^' 반환
	}
	else if (pixelnum[i] >= 187 && pixelnum[i] <= 203) //픽셀 명도값이 187~203이면
	{
		return char(43); //'+' 반환
	}
	else if (pixelnum[i] >= 204 && pixelnum[i] <= 220) //픽셀 명도값이 204~220이면
	{
		return char(45); //'-' 반환
	}
	else if (pixelnum[i] >= 221 && pixelnum[i] <= 237) //픽셀 명도값이 221~237이면
	{
		return char(46); //'.' 반환
	}
	else if (pixelnum[i] >= 238 && pixelnum[i] <= 255) //픽셀 명도값이 238~255이면
	{
		return char(32); //공백 반환
	}
}

iclassic::iclassic(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //iclassic 생성자
{
	for (int i = 0; i < _width * _height; i++) //픽셀 개수만큼 반복
	{
		pixelnum.push_back(_pixel[i]); //픽셀 명도값 벡터 입력
	}

	pixel.resize(_width * _height); //픽셀 개수만큼 벡터 크기 조정

	for (int i = 0; i < _height; i++) //높이만큼 반복
	{
		for (int j = 0; j < _width; j++) //너비만큼 반복
		{
			pixel[j + i * _width] = mapper(j, i); //명도값 문자로 변환
		}
	}

	artist::savePixel(pixel); //픽셀별 문자 벡터 저장
}

char iclassic::mapper(int x_coordinate, int y_coordinate) //명도값 문자 변환 함수
{
	int i = x_coordinate + y_coordinate * getWidth(); //픽셀 좌표

	if (pixelnum[i] >= 0 && pixelnum[i] <= 16) //픽셀 명도값이 0~16이면
	{
		return char(32); //공백 반환
	}
	else if (pixelnum[i] >= 17 && pixelnum[i] <= 33) //픽셀 명도값이 17~33이면
	{
		return char(46); //'.' 반환
	}
	else if (pixelnum[i] >= 34 && pixelnum[i] <= 50) //픽셀 명도값이 34~50이면
	{
		return char(45); //'-' 반환
	}
	else if (pixelnum[i] >= 51 && pixelnum[i] <= 67) //픽셀 명도값이 51~67이면
	{
		return char(43); //'+' 반환
	}
	else if (pixelnum[i] >= 68 && pixelnum[i] <= 84) //픽셀 명도값이 68~84이면
	{
		return char(94); //'^' 반환
	}
	else if (pixelnum[i] >= 85 && pixelnum[i] <= 101) //픽셀 명도값이 85~101이면
	{
		return char(42); //'*' 반환
	}
	else if (pixelnum[i] >= 102 && pixelnum[i] <= 118) //픽셀 명도값이 102~118이면
	{
		return char(84); //'T' 반환
	}
	else if (pixelnum[i] >= 119 && pixelnum[i] <= 135) //픽셀 명도값이 119~135이면
	{
		return char(79); //'O' 반환
	}
	else if (pixelnum[i] >= 136 && pixelnum[i] <= 152) //픽셀 명도값이 136~152이면
	{
		return char(72); //'H' 반환
	}
	else if (pixelnum[i] >= 153 && pixelnum[i] <= 169) //픽셀 명도값이 153~169이면
	{
		return char(65); //'A' 반환
	}
	else if (pixelnum[i] >= 170 && pixelnum[i] <= 186) //픽셀 명도값이 170~186이면
	{
		return char(88); //'X' 반환
	}
	else if (pixelnum[i] >= 187 && pixelnum[i] <= 203) //픽셀 명도값이 187~203이면
	{
		return char(87); //'W' 반환
	}
	else if (pixelnum[i] >= 204 && pixelnum[i] <= 220) //픽셀 명도값이 204~220이면
	{
		return char(37); //'%' 반환
	}
	else if (pixelnum[i] >= 221 && pixelnum[i] <= 237) //픽셀 명도값이 221~237이면
	{
		return char(38); //'&' 반환
	}
	else if (pixelnum[i] >= 238 && pixelnum[i] <= 255) //픽셀 명도값이 238~255이면
	{
		return char(64); //'@' 반환
	}
}

sobelx::sobelx(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //sobelx 생성자
{
	for (int i = 0; i < _width * _height; i++) //픽셀 개수만큼 반복
	{
		pixelnum.push_back(_pixel[i]); //픽셀 명도값 벡터 입력
	}

	pixel.resize(_width * _height); //픽셀 개수만큼 벡터 크기 조정

	for (int i = 0; i < _height; i++) //높이만큼 반복
	{
		for (int j = 0; j < _width; j++) //너비만큼 반복
		{
			pixel[j + i * _width] = mapper(j, i); //명도값 문자로 변환
		}
	}

	artist::savePixel(pixel); //픽셀별 문자 벡터 저장
}

char sobelx::mapper(int x_coordinate, int y_coordinate) //명도값 문자 변환 함수
{
	int coordinate = x_coordinate + y_coordinate * getWidth(); //좌표
	int i = pixelnum[coordinate]; //픽셀 좌표에 해당하는 명도값
	if (coordinate != 0 && (coordinate + 1) % getWidth() == 0) //맨 오른쪽 픽셀이면
	{
		return char(32); //공백 반환
	}
	int j = pixelnum[coordinate + 1]; //x축 양의 방향으로 +1 좌표의 명도값

	if (i - j >= 50 || j - i >= 50) //x축으로 인접한 픽셀 명도값 차이가 50이상인 경우
	{
		return char(124); //'|' 반환
	}
	else //x축으로 인접한 픽셀 명도값 차이가 50미만인 경우
	{
		return char(32); //공백 반환
	}
}

sobely::sobely(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //sobely 생성자
{
	for (int i = 0; i < _width * _height; i++) //픽셀 개수만큼 반복
	{
		pixelnum.push_back(_pixel[i]); //픽셀 명도값 벡터 입력
	}

	pixel.resize(_width * _height); //픽셀 개수만큼 벡터 크기 조정

	for (int i = 0; i < _height; i++) //높이만큼 반복
	{
		for (int j = 0; j < _width; j++) //너비만큼 반복
		{
			pixel[j + i * _width] = mapper(j, i); //명도값 문자로 변환
		}
	}

	artist::savePixel(pixel); //픽셀별 문자 벡터 저장
}

char sobely::mapper(int x_coordinate, int y_coordinate) //명도값 문자 변환 함수
{
	int coordinate = x_coordinate + y_coordinate * getWidth(); //좌표
	int i = pixelnum[coordinate]; //픽셀 좌표에 해당하는 명도값
	if (coordinate >= ((getHeight() - 1) * getWidth())) //맨 아래쪽 픽셀이면
	{
		return char(32); //공백 반환
	}
	int j = pixelnum[coordinate + getWidth()]; //y축 양의 방향으로 +1 좌표의 명도값

	if (i - j >= 50 || j - i >= 50) //y축으로 인접한 픽셀 명도값 차이가 50이상인 경우
	{
		return char(45); //'-' 반환
	}
	else //y축으로 인접한 픽셀 명도값 차이가 50미만인 경우
	{
		return char(32); //공백 반환
	}
}

gradient::gradient(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //gradient 생성자
{
	for (int i = 0; i < _width * _height; i++) //픽셀 개수만큼 반복
	{
		pixelnum.push_back(_pixel[i]); //픽셀 명도값 벡터 입력
	}

	pixel.resize(_width * _height); //픽셀 개수만큼 벡터 크기 조정

	for (int i = 0; i < _height; i++) //높이만큼 반복
	{
		for (int j = 0; j < _width; j++) //너비만큼 반복
		{
			pixel[j + i * _width] = mapper(j, i); //명도값 문자로 변환
		}
	}

	artist::savePixel(pixel); //픽셀별 문자 벡터 저장
}

char gradient::mapper(int x_coordinate, int y_coordinate) //명도값 문자 변환 함수
{
	int coordinate = x_coordinate + y_coordinate * getWidth(); //좌표
	int i = pixelnum[coordinate]; //픽셀 좌표에 해당하는 명도값
	if (coordinate != 0 && (coordinate + 1) % getWidth() == 0) //맨 오른쪽 픽셀이면
	{
		return char(32); //공백 반환
	}
	int j = pixelnum[coordinate + 1]; //x축 양의 방향으로 +1 좌표의 
	if (coordinate >= ((getHeight() - 1) * getWidth())) //맨 아래쪽 픽셀이면
	{
		return char(32); //공백 반환
	}
	int k = pixelnum[coordinate + getWidth()]; //y축 양의 방향으로 +1 좌표의 명도값

	if (i - j >= 50 || j - i >= 50) //x축으로 인접한 픽셀 명도값 차이가 50이상인 경우
	{
		if (i - k >= 50 || k - i >= 50) //y축으로 인접한 픽셀 명도값 차이가 50이상인 경우
		{
			return char(43); //'+' 반환
		}
		else //y축으로 인접한 픽셀 명도값 차이가 50 미만인 경우
		{
			return char(124); //'|' 반환
		}
	}
	else //x축으로 인접한 픽셀 명도값 차이가 50미만인 경우
	{
		if (i - k >= 50 || k - i >= 50) //y축으로 인접한 픽셀 명도값 차이가 50이상인 경우
		{
			return char(45); //'-' 반환
		}
		else //y축으로 인접한 픽셀 명도값 차이가 50미만인 경우
		{
			return char(32); //공백 반환
		}
	}
}

mystyle::mystyle(int _width, int _height, const std::vector<int>& _pixel) : artist(_width, _height) //mystyle 생성자
{
	for (int i = 0; i < _width * _height; i++) //픽셀 개수만큼 반복
	{
		pixelnum.push_back(_pixel[i]); //픽셀 명도값 벡터 입력
	}

	pixel.resize(_width * _height); //픽셀 개수만큼 벡터 크기 조정

	for (int i = 0; i < _height; i++) //높이만큼 반복
	{
		for (int j = 0; j < _width; j++) //너비만큼 반복
		{
			pixel[(_width*_height) - 1 - (j + i * _width)] = mapper(j, i); //명도값 문자로 변환(classic과 x축으로 대칭)
		}
	}

	artist::savePixel(pixel); //픽셀별 문자 벡터 저장
}

char mystyle::mapper(int x_coordinate, int y_coordinate) //명도값 문자 변환 함수
{
	int i = x_coordinate + y_coordinate * getWidth(); //픽셀 좌표

	if (pixelnum[i] >= 0 && pixelnum[i] <= 16) //픽셀 명도값이 0~16이면
	{
		return char(64); //'@' 반환
	}
	else if (pixelnum[i] >= 17 && pixelnum[i] <= 33) //픽셀 명도값이 7~33이면
	{
		return char(38); //'&' 반환
	}
	else if (pixelnum[i] >= 34 && pixelnum[i] <= 50) //픽셀 명도값이 34~50이면
	{
		return char(37); //'%' 반환
	}
	else if (pixelnum[i] >= 51 && pixelnum[i] <= 67) //픽셀 명도값이 51~67이면
	{
		return char(87); //'W' 반환
	}
	else if (pixelnum[i] >= 68 && pixelnum[i] <= 84) //픽셀 명도값이 68~84이면
	{
		return char(88); //'X' 반환
	}
	else if (pixelnum[i] >= 85 && pixelnum[i] <= 101) //픽셀 명도값이 85~101이면
	{
		return char(65); //'A' 반환
	}
	else if (pixelnum[i] >= 102 && pixelnum[i] <= 118) //픽셀 명도값이 102~118이면
	{
		return char(72); //'H' 반환
	}
	else if (pixelnum[i] >= 119 && pixelnum[i] <= 135) //픽셀 명도값이 119~135이면
	{
		return char(79); //'O' 반환
	}
	else if (pixelnum[i] >= 136 && pixelnum[i] <= 152) //픽셀 명도값이 136~152이면
	{
		return char(84); //'T' 반환
	}
	else if (pixelnum[i] >= 153 && pixelnum[i] <= 169) //픽셀 명도값이 153~169이면
	{
		return char(42); //'*' 반환
	}
	else if (pixelnum[i] >= 170 && pixelnum[i] <= 186) //픽셀 명도값이 170~186이면
	{
		return char(94); //'^' 반환
	}
	else if (pixelnum[i] >= 187 && pixelnum[i] <= 203) //픽셀 명도값이 187~203이면
	{
		return char(43); //'+' 반환
	}
	else if (pixelnum[i] >= 204 && pixelnum[i] <= 220) //픽셀 명도값이 204~220이면
	{
		return char(45); //'-' 반환
	}
	else if (pixelnum[i] >= 221 && pixelnum[i] <= 237) //픽셀 명도값이 221~237이면
	{
		return char(46); //'.' 반환
	}
	else if (pixelnum[i] >= 238 && pixelnum[i] <= 255) //픽셀 명도값이 238~255이면
	{
		return char(32); //공백 반환
	}
}