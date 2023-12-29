//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string>
#include "function.hpp"

using namespace std;

void print_menu() //�޴� ��� �Լ�
{
	cout << "----------MENU----------" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Delete a student" << endl;
	cout << "3. Print the student's list" << endl;
	cout << "4. Pivot Table" << endl;
	cout << "5. Exit" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";

	return; //�Լ� ����
}

void print_pivot_menu_1() //ī�װ� �ɼ� �޴� ��� �Լ�
{
	cout << "--------Category--------" << endl;
	cout << "1. Dept" << endl;
	cout << "2. Gender" << endl;
	cout << "3. Dept and Gender" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";

	return; //�Լ� ����
}

void print_pivot_menu_2() //�Լ� �ɼ� �޴� ��� �Լ�
{
	cout << "--------Function--------" << endl;
	cout << "1. Average" << endl;
	cout << "2. Max" << endl;
	cout << "3. Min" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";

	return; //�Լ� ����
}

void save_node(list& list) //��� ���� �Լ�
{
	cin.ignore(); //�Է� ���� ����
	list.insert_node(); //����Ʈ�� ��� ����

	return; //�Լ� ����
}

void delete_node(list& list) //��� ���� ����
{
	cin.ignore(); //�Է� ���� ����
	list.delete_node(); //����Ʈ���� ��� ����

	return; //�Լ� ����
}

void print_node(list& list) //��� ��� �Լ�
{
	cin.ignore(); //�Է� ���� ����
	list.print_node(); //����Ʈ�� ��� ���

	return; //�Լ� ����
}

void print_pivot_table(list& list, string category, string function) //pivot table ��� �Լ�
{
	cin.ignore(); //�Է� ���� ����
	list.print_pivot_node(category, function); //����Ʈ�� pivot table ���

	return; //�Լ� ����
}

int print_error() //���� ��� �Լ�
{
	string option; //�ɼ� ����

	while (1) //����� �Է� ���� ������ �ݺ�
	{
		cout << "Enter '1' to re-enter or '0' to return to menu." << endl; //�ȳ� �޼��� ���
		cin >> option; //�ɼ� �Է�

		if (option == "1") //"1"�� �Է��ϸ�
		{
			cin.ignore(); //�Է� ���� ����
			return 1; //1 ��ȯ
		}
		else if (option == "0") //"0"�� �Է��ϸ�
		{
			cin.ignore(); //�Է� ���� ����
			return 0; //0 ��ȯ
		}
		else //����� �Է� ���� ������
		{
			continue; //�ݺ� ����
		}
	}
}