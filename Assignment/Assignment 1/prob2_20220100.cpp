#include <iostream> //header file of the C++ standard library
#include <cmath> //cmath library
#include <cstring> //cstring library

using namespace std; //Namespace

float calculator_add(float num1, float num2); //덧셈 계산기 사용자정의 함수
float calculator_subtract(float num1, float num2); //뺄셈 계산기 사용자정의 함수
float calculator_multiply(float num1, float num2); //곱셈 계산기 사용자정의 함수
float calculator_divide(float num1, float num2); //나눗셈 계산기 사용자정의 함수
float calculator_sqrt(float num); //루트 계산기 사용자정의 함수
float calculator_square(float num); //제곱 계산기 사용자정의 함수

int main()
{
	char* calc_operator = new char[7]; //연산자 변수를 char형 배열로 동적 할당
	float num1, num2; //숫자 변수 두 개를 float형으로 선언
	float value = 0; //최종 계산한 값 변수를 float형으로 선언
	char add_operator[] = "+"; //덧셈 연산자
	char subtract_operator[] = "-"; //뺼셈 연산자
	char multiply_operator[] = "*"; //곱셈 연산자
	char divide_operator[] = "/"; //나눗셈 연산자
	char sqrt_operator[] = "sqrt"; //루트 연산자
	char square_operator[] = "square"; //제곱 연산자

	cin >> calc_operator; //연산자 입력

	if (strcmp(calc_operator, add_operator) == 0) //덧셈인 경우
	{
		cin >> num1 >> num2; //숫자 두 개 입력
		value = calculator_add(num1, num2); //덧셈
	}
	else if (strcmp(calc_operator, subtract_operator) == 0) //뺄셈인 경우
	{
		cin >> num1 >> num2; //숫자 두 개 입력
		value = calculator_subtract(num1, num2); //뺄셈
	}
	else if (strcmp(calc_operator, multiply_operator) == 0) //곱셈인 경우
	{
		cin >> num1 >> num2; //숫자 두 개 입력
		value = calculator_multiply(num1, num2); //곱셈
	}
	else if (strcmp(calc_operator, divide_operator) == 0) //나눗셈인 경우
	{
		cin >> num1 >> num2; //숫자 두 개 입력
		value = calculator_divide(num1, num2); //나눗셈
	}
	else if (strcmp(calc_operator, sqrt_operator) == 0) //루트인 경우
	{
		cin >> num1; //숫자 한 개 입력
		value = calculator_sqrt(num1); //루트
	}
	else if (strcmp(calc_operator, square_operator) == 0) //제곱인 경우
	{
		cin >> num1; //숫자 한 개 입력
		value = calculator_square(num1); //제곱
	}

	delete[] calc_operator; //동적 할당 해제

	if (value - int(value) != 0) //정수가 아니면
	{
		cout << fixed; //소수점 아래 자릿수 고정
		cout.precision(3); //3자리로 고정
	}
	cout << value << endl; //출력

	return 0; //프로그램 종료
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

float calculator_sqrt(float num) //루트 계산기 사용자정의 함수
{
	return sqrt(num); //루트 값 반환
}

float calculator_square(float num) //제곱 계산기 사용자정의 함수
{
	return num * num; //제곱 값 반환
}