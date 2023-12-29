#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include <cmath> //cmath library

using namespace std; //Namespace

int conversion(string num); //10진수로 변환하는 사용자정의 함수
float calculator_add(float num1, float num2); //덧셈 계산기 사용자정의 함수
float calculator_subtract(float num1, float num2); //뺄셈 계산기 사용자정의 함수
float calculator_multiply(float num1, float num2); //곱셈 계산기 사용자정의 함수
float calculator_divide(float num1, float num2); //나눗셈 계산기 사용자정의 함수

int main()
{
	char calc_operator; //연산자 변수를 char형으로 선언
	string num1, num2; //숫자 변수 두 개를 string형으로 선언
	int decimal_num1, decimal_num2; //변환한 10진수 값 변수 두 개를 int형으로 선언
	float value = 0; //최종 계산한 값 변수를 float형으로 선언

	cin >> calc_operator >> num1 >> num2; //입력

	decimal_num1 = conversion(num1); //10진수로 변환
	decimal_num2 = conversion(num2); //10진수로 변환

	if (calc_operator == '+') //덧셈인 경우
	{
		value = calculator_add(decimal_num1, decimal_num2); //덧셈
	}
	else if (calc_operator == '-') //뺄셈인 경우
	{
		value = calculator_subtract(decimal_num1, decimal_num2); //뺄셈
	}
	else if (calc_operator == '*') //곱셈인 경우
	{
		value = calculator_multiply(decimal_num1, decimal_num2); //곱셈
	}
	else if (calc_operator == '/') //나눗셈인 경우
	{
		value = calculator_divide(decimal_num1, decimal_num2); //나눗셈
	}

	if (value - int(value) != 0) //정수가 아니면
	{
		cout << fixed; //소수점 아래 자릿수 고정
		cout.precision(3); //3자리로 고정
	}
	cout << value << endl; //출력

	return 0; //프로그램 종료
}

int conversion(string num) //10진수로 변환하는 사용자정의 함수
{
	int decimal_digits = 0; //10진수 값 변수를 int형으로 선언
	int a = 2; //n제곱에서 n값 조절 변수를 int형으로 선언

	if (num[1] != 'b' && num[1] != 'X') //8진수인 경우
	{
		for (int i = 1; i < num.size(); i++) //'0'을 제외한 나머지 값에 대해서 반복
		{
			decimal_digits += int(num[i] - 48) * pow(8, num.size() - a); //ASCII 코드 이용, 각 자리 숫자의 8의 n제곱을 곱하여 더함
			a++; //n제곱에서 n값 조절
		}
	}
	else //2진수 또는 16진수인 경우
	{
		for (int i = 2; i < num.size(); i++) //'0b' 또는 '0X'를 제외한 나머지 값에 대해서 반복
		{
			if (num[1] == 'b') //2진수인 경우
			{
				decimal_digits += int(num[i] - 48) * pow(2, num.size() - a - 1); //ASCII 코드 이용, 각 자리 숫자의 2의 n제곱을 곱하여 더함
			}
			else if (num[1] == 'X') //16진수인 경우
			{
				if (int(num[i]) >= 48 && int(num[i]) <= 57) //각 자리가 숫자인 경우
				{
					decimal_digits += int(num[i] - 48) * pow(16, num.size() - a - 1); //ASCII 코드 이용, 각 자리 숫자의 16의 n제곱을 곱하여 더함
				}
				else //각 자리가 알파벳인 경우
				{
					decimal_digits += int(num[i] - 55) * pow(16, num.size() - a - 1); //ASCII 코드 이용, 각 자리 알파벳의 16의 n제곱을 곱하여 더함
				}
			}
			a++; //n제곱에서 n값 조절
		}
	}

	return decimal_digits; //변환한 10진수 값 반환
}

float calculator_add(float num1, float num2) //덧셈 계산기 사용자정의 함수
{
	return num1 + num2; //더한 값 반환
}

float calculator_subtract(float num1, float num2) //뺄셈 계산기 사용자정의 함수
{
	return num1 - num2; //뺀 값 반환
}

float calculator_multiply(float num1, float num2) //곱셈 계산기 사용자정의 함수
{
	return num1 * num2; //곱한 값 반환
}

float calculator_divide(float num1, float num2) //나눗셈 계산기 사용자정의 함수
{
	return num1 / num2; //나눈 값 반환
}