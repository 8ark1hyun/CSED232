#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include <cmath> //cmath library

using namespace std; //Namespace

int conversion(string num); //10������ ��ȯ�ϴ� ��������� �Լ�
float calculator_add(float num1, float num2); //���� ���� ��������� �Լ�
float calculator_subtract(float num1, float num2); //���� ���� ��������� �Լ�
float calculator_multiply(float num1, float num2); //���� ���� ��������� �Լ�
float calculator_divide(float num1, float num2); //������ ���� ��������� �Լ�

int main()
{
	char calc_operator; //������ ������ char������ ����
	string num1, num2; //���� ���� �� ���� string������ ����
	int decimal_num1, decimal_num2; //��ȯ�� 10���� �� ���� �� ���� int������ ����
	float value = 0; //���� ����� �� ������ float������ ����

	cin >> calc_operator >> num1 >> num2; //�Է�

	decimal_num1 = conversion(num1); //10������ ��ȯ
	decimal_num2 = conversion(num2); //10������ ��ȯ

	if (calc_operator == '+') //������ ���
	{
		value = calculator_add(decimal_num1, decimal_num2); //����
	}
	else if (calc_operator == '-') //������ ���
	{
		value = calculator_subtract(decimal_num1, decimal_num2); //����
	}
	else if (calc_operator == '*') //������ ���
	{
		value = calculator_multiply(decimal_num1, decimal_num2); //����
	}
	else if (calc_operator == '/') //�������� ���
	{
		value = calculator_divide(decimal_num1, decimal_num2); //������
	}

	if (value - int(value) != 0) //������ �ƴϸ�
	{
		cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
		cout.precision(3); //3�ڸ��� ����
	}
	cout << value << endl; //���

	return 0; //���α׷� ����
}

int conversion(string num) //10������ ��ȯ�ϴ� ��������� �Լ�
{
	int decimal_digits = 0; //10���� �� ������ int������ ����
	int a = 2; //n�������� n�� ���� ������ int������ ����

	if (num[1] != 'b' && num[1] != 'X') //8������ ���
	{
		for (int i = 1; i < num.size(); i++) //'0'�� ������ ������ ���� ���ؼ� �ݺ�
		{
			decimal_digits += int(num[i] - 48) * pow(8, num.size() - a); //ASCII �ڵ� �̿�, �� �ڸ� ������ 8�� n������ ���Ͽ� ����
			a++; //n�������� n�� ����
		}
	}
	else //2���� �Ǵ� 16������ ���
	{
		for (int i = 2; i < num.size(); i++) //'0b' �Ǵ� '0X'�� ������ ������ ���� ���ؼ� �ݺ�
		{
			if (num[1] == 'b') //2������ ���
			{
				decimal_digits += int(num[i] - 48) * pow(2, num.size() - a - 1); //ASCII �ڵ� �̿�, �� �ڸ� ������ 2�� n������ ���Ͽ� ����
			}
			else if (num[1] == 'X') //16������ ���
			{
				if (int(num[i]) >= 48 && int(num[i]) <= 57) //�� �ڸ��� ������ ���
				{
					decimal_digits += int(num[i] - 48) * pow(16, num.size() - a - 1); //ASCII �ڵ� �̿�, �� �ڸ� ������ 16�� n������ ���Ͽ� ����
				}
				else //�� �ڸ��� ���ĺ��� ���
				{
					decimal_digits += int(num[i] - 55) * pow(16, num.size() - a - 1); //ASCII �ڵ� �̿�, �� �ڸ� ���ĺ��� 16�� n������ ���Ͽ� ����
				}
			}
			a++; //n�������� n�� ����
		}
	}

	return decimal_digits; //��ȯ�� 10���� �� ��ȯ
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