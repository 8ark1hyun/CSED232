#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <cstdint>
#include <cassert>
#include "SharedPtr.h"

///////////////////////////////////////////////////////////////////////////
// RGB pixel type
//    Usage:
//      - RGB<float> rgb(0.5f, 0.1f, 0.3f);
//        rgb[0] = 0.2f; // or equivalently, rgb.r = 0.2f;
template<typename ValType>
struct RGB
{
	union {
		ValType data[3];
		struct {
			ValType r, g, b;
		};
	};

	RGB() {}
	RGB(ValType r_, ValType g_, ValType b_) : r(r_), g(g_), b(b_) {}

	ValType operator[](int idx) const { return data[idx]; }
	ValType& operator[](int idx) { return data[idx]; }
};

typedef RGB<uint8_t>	RGB8b;
typedef RGB<float>		RGBf;


///////////////////////////////////////////////////////////////////////////
// Image class template
//
template<typename PixelType>
class Image
{
private:
	SharedArray<PixelType> img_object; //이미지 객체 SharedArray
	size_t img_width; //이미지 너비
	size_t img_height; //이미지 높이
	
public:
	////////////////////////////////////////////
	// constructors & destructor
	////////////////////////////////////////////
	Image() //default 생성자
	{ 
		img_object = SharedArray<PixelType>(); //픽셀값으로 사용할 타입에 맞는 이미지 객체 생성
	}
	Image(size_t _width, size_t _height) //이미지 크기만큼 메모리 할당하는 생성자
	{
		img_width = _width; //너비 입력
		img_height = _height; //높이 입력

		img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //이미지 크기만큼 객체 메모리 동적 할당
	}
	Image(size_t _width, size_t _height, const PixelType& val) //이미지 크기만큼 메모리 할당하고 val 값을 이용해 모든 픽셀값 초기화하는 생성자
	{
		img_width = _width; //너비 입력
		img_height = _height; //높이 입력

		img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //이미지 크기만큼 객체 메모리 동적 할당

		for (int i = 0; i < img_height * img_width; i++) //픽셀 크기만큼 반복
		{
			img_object[i] = val; //val 값으로 픽셀값 초기화
		}
	}
	Image(const Image<PixelType>& img) //copy constructor
	{
		img_width = img.img_width; //너비 복사
		img_height = img.img_height; //높이 복사
		
		img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //이미지 크기만큼 객체 메모리 동적 할당

		for (int i = 0; i < img_height * img_width; i++) //픽셀 크기만큼 반복
		{
			img_object[i] = img.img_object[i]; //픽셀값 복사
		}
	}

	~Image() {} //소멸자

	////////////////////////////////////////////
	// assignment operator
	////////////////////////////////////////////
	Image<PixelType>& operator=(const Image<PixelType>& img)
	{
		if (this != &img) //같지 않으면
		{
			img_width = img.img_width; //너비 대입
			img_height = img.img_height; //높이 대입

			img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //이미지 크기만큼 객체 메모리 동적 할당

			for (int i = 0; i < img_height * img_width; i++) //픽셀 크기만큼 반복
			{
				img_object = img.img_object; //픽셀값 대입
			}
		}

		return *this; //Image 반환
	}

	////////////////////////////////////////////
	// element access operators
	////////////////////////////////////////////
	PixelType* operator[](int y) { return &img_object[y * img_width]; }
	const PixelType* operator[](int y) const { return &img_object[y * img_width]; }

	////////////////////////////////////////////
	// other methods
	////////////////////////////////////////////
	//   - width(), height()
	size_t width() const
	{
		return img_width; //너비 반환
	}
	size_t height() const
	{
		return img_height; //높이 반환
	}
};

// Miscellaneous functions
void convert_pixel_type(const Image<RGB8b>& src, Image<RGBf>& dst);
void convert_pixel_type(const Image<RGBf>& src, Image<RGB8b>& dst);

bool load_bmp(const char* path, Image<RGB8b>& img);
bool save_bmp(const char* path, const Image<RGB8b>& img);

#endif
