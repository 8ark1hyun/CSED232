#include <iostream> //header file of the C++ standard library
#include <string> //string library

using namespace std; //Namespace

void conversion(int decimal_digits, int base); //진수 변환하는 사용자정의 함수

int main()
{
	int decimal_digits, base; //10진수 변수와 변환해야 할 진수 변수를 int형으로 선언

	cin >> decimal_digits >> base; //입력

	conversion(decimal_digits, base); //진수 변환

	return 0; //프로그램 종료
}

void conversion(int decimal_digits, int base) //진수 변환하는 사용자정의 함수
{
	int quotient = true; //몫 변수를 int형으로 선언
	int remainder; //나머지 변수를 int형으로 선언
	string value; //변환한 값 변수를 string형으로 선언

	while (quotient != 0) //몫이 0이 될 때까지 반복
	{
		quotient = decimal_digits / base; //몫 계산
		remainder = decimal_digits % base; //나머지 계산

		decimal_digits = quotient; //몫을 10진수 변수에 다시 대입하여 반복문을 통해 연산이 반복될 수 있도록 구현

		if (remainder >= 0 && remainder <= 9) //나머지가 0~9이면 숫자 그대로 앞에 배치 (2진수, 8진수, 16진수)
			value = char(48 + remainder) + value; //ASCII 코드 이용
		else if (remainder >= 10 && remainder <= 15) //나머지가 10에서 15이면 알파벳으로 앞에 배치 (16진수)
			value = char(55 + remainder) + value; //ASCII 코드 이용
	}

	cout << value << endl; //출력

	return; //사용자정의 함수 종료
}