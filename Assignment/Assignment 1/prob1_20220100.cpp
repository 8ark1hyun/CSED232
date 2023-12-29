#include <iostream> //header file of the C++ standard library
#include <string> //string library

using namespace std; //Namespace

void conversion(int decimal_digits, int base); //���� ��ȯ�ϴ� ��������� �Լ�

int main()
{
	int decimal_digits, base; //10���� ������ ��ȯ�ؾ� �� ���� ������ int������ ����

	cin >> decimal_digits >> base; //�Է�

	conversion(decimal_digits, base); //���� ��ȯ

	return 0; //���α׷� ����
}

void conversion(int decimal_digits, int base) //���� ��ȯ�ϴ� ��������� �Լ�
{
	int quotient = true; //�� ������ int������ ����
	int remainder; //������ ������ int������ ����
	string value; //��ȯ�� �� ������ string������ ����

	while (quotient != 0) //���� 0�� �� ������ �ݺ�
	{
		quotient = decimal_digits / base; //�� ���
		remainder = decimal_digits % base; //������ ���

		decimal_digits = quotient; //���� 10���� ������ �ٽ� �����Ͽ� �ݺ����� ���� ������ �ݺ��� �� �ֵ��� ����

		if (remainder >= 0 && remainder <= 9) //�������� 0~9�̸� ���� �״�� �տ� ��ġ (2����, 8����, 16����)
			value = char(48 + remainder) + value; //ASCII �ڵ� �̿�
		else if (remainder >= 10 && remainder <= 15) //�������� 10���� 15�̸� ���ĺ����� �տ� ��ġ (16����)
			value = char(55 + remainder) + value; //ASCII �ڵ� �̿�
	}

	cout << value << endl; //���

	return; //��������� �Լ� ����
}