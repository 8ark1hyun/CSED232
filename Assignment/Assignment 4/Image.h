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
	SharedArray<PixelType> img_object; //�̹��� ��ü SharedArray
	size_t img_width; //�̹��� �ʺ�
	size_t img_height; //�̹��� ����
	
public:
	////////////////////////////////////////////
	// constructors & destructor
	////////////////////////////////////////////
	Image() //default ������
	{ 
		img_object = SharedArray<PixelType>(); //�ȼ������� ����� Ÿ�Կ� �´� �̹��� ��ü ����
	}
	Image(size_t _width, size_t _height) //�̹��� ũ�⸸ŭ �޸� �Ҵ��ϴ� ������
	{
		img_width = _width; //�ʺ� �Է�
		img_height = _height; //���� �Է�

		img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //�̹��� ũ�⸸ŭ ��ü �޸� ���� �Ҵ�
	}
	Image(size_t _width, size_t _height, const PixelType& val) //�̹��� ũ�⸸ŭ �޸� �Ҵ��ϰ� val ���� �̿��� ��� �ȼ��� �ʱ�ȭ�ϴ� ������
	{
		img_width = _width; //�ʺ� �Է�
		img_height = _height; //���� �Է�

		img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //�̹��� ũ�⸸ŭ ��ü �޸� ���� �Ҵ�

		for (int i = 0; i < img_height * img_width; i++) //�ȼ� ũ�⸸ŭ �ݺ�
		{
			img_object[i] = val; //val ������ �ȼ��� �ʱ�ȭ
		}
	}
	Image(const Image<PixelType>& img) //copy constructor
	{
		img_width = img.img_width; //�ʺ� ����
		img_height = img.img_height; //���� ����
		
		img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //�̹��� ũ�⸸ŭ ��ü �޸� ���� �Ҵ�

		for (int i = 0; i < img_height * img_width; i++) //�ȼ� ũ�⸸ŭ �ݺ�
		{
			img_object[i] = img.img_object[i]; //�ȼ��� ����
		}
	}

	~Image() {} //�Ҹ���

	////////////////////////////////////////////
	// assignment operator
	////////////////////////////////////////////
	Image<PixelType>& operator=(const Image<PixelType>& img)
	{
		if (this != &img) //���� ������
		{
			img_width = img.img_width; //�ʺ� ����
			img_height = img.img_height; //���� ����

			img_object = SharedArray<PixelType>(new PixelType[img_height * img_width]); //�̹��� ũ�⸸ŭ ��ü �޸� ���� �Ҵ�

			for (int i = 0; i < img_height * img_width; i++) //�ȼ� ũ�⸸ŭ �ݺ�
			{
				img_object = img.img_object; //�ȼ��� ����
			}
		}

		return *this; //Image ��ȯ
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
		return img_width; //�ʺ� ��ȯ
	}
	size_t height() const
	{
		return img_height; //���� ��ȯ
	}
};

// Miscellaneous functions
void convert_pixel_type(const Image<RGB8b>& src, Image<RGBf>& dst);
void convert_pixel_type(const Image<RGBf>& src, Image<RGB8b>& dst);

bool load_bmp(const char* path, Image<RGB8b>& img);
bool save_bmp(const char* path, const Image<RGB8b>& img);

#endif
