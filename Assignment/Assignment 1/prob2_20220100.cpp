#include <iostream> //header file of the C++ standard library
#include <cmath> //cmath library
#include <cstring> //cstring library

using namespace std; //Namespace

float calculator_add(float num1, float num2); //���� ���� ��������� �Լ�
float calculator_subtract(float num1, float num2); //���� ���� ��������� �Լ�
float calculator_multiply(float num1, float num2); //���� ���� ��������� �Լ�
float calculator_divide(float num1, float num2); //������ ���� ��������� �Լ�
float calculator_sqrt(float num); //��Ʈ ���� ��������� �Լ�
float calculator_square(float num); //���� ���� ��������� �Լ�

int main()
{
	char* calc_operator = new char[7]; //������ ������ char�� �迭�� ���� �Ҵ�
	float num1, num2; //���� ���� �� ���� float������ ����
	float value = 0; //���� ����� �� ������ float������ ����
	char add_operator[] = "+"; //���� ������
	char subtract_operator[] = "-"; //�E�� ������
	char multiply_operator[] = "*"; //���� ������
	char divide_operator[] = "/"; //������ ������
	char sqrt_operator[] = "sqrt"; //��Ʈ ������
	char square_operator[] = "square"; //���� ������

	cin >> calc_operator; //������ �Է�

	if (strcmp(calc_operator, add_operator) == 0) //������ ���
	{
		cin >> num1 >> num2; //���� �� �� �Է�
		value = calculator_add(num1, num2); //����
	}
	else if (strcmp(calc_operator, subtract_operator) == 0) //������ ���
	{
		cin >> num1 >> num2; //���� �� �� �Է�
		value = calculator_subtract(num1, num2); //����
	}
	else if (strcmp(calc_operator, multiply_operator) == 0) //������ ���
	{
		cin >> num1 >> num2; //���� �� �� �Է�
		value = calculator_multiply(num1, num2); //����
	}
	else if (strcmp(calc_operator, divide_operator) == 0) //�������� ���
	{
		cin >> num1 >> num2; //���� �� �� �Է�
		value = calculator_divide(num1, num2); //������
	}
	else if (strcmp(calc_operator, sqrt_operator) == 0) //��Ʈ�� ���
	{
		cin >> num1; //���� �� �� �Է�
		value = calculator_sqrt(num1); //��Ʈ
	}
	else if (strcmp(calc_operator, square_operator) == 0) //������ ���
	{
		cin >> num1; //���� �� �� �Է�
		value = calculator_square(num1); //����
	}

	delete[] calc_operator; //���� �Ҵ� ����

	if (value - int(value) != 0) //������ �ƴϸ�
	{
		cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
		cout.precision(3); //3�ڸ��� ����
	}
	cout << value << endl; //���

	return 0; //���α׷� ����
}

float calculator_add(float num1, float num2) //���� ���� ��������� �Լ�
{
	return num1 + num2; //���� �� ��ȯ
}

float calculator_subtract(float num1, float num2) //���� ���� ��������� �Լ�
{
	return num1 - num2; //�� �� ��ȯ
}

float calculator_multiply(float num1, float num2) //���� ���� ��������� �Լ�
{
	return num1 * num2; //���� �� ��ȯ
}

float calculator_divide(float num1, float num2) //������ ���� ��������� �Լ�
{
	return num1 / num2; //���� �� ��ȯ
}

float calculator_sqrt(float num) //��Ʈ ���� ��������� �Լ�
{
	return sqrt(num); //��Ʈ �� ��ȯ
}

float calculator_square(float num) //���� ���� ��������� �Լ�
{
	return num * num; //���� �� ��ȯ
}