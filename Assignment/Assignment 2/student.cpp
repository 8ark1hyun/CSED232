//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "student.hpp" //"student.hpp" header file
#include "function.hpp" //"function.hpp header file

using namespace std; //Namespace

int student::input_info(student data) //�����͸� �Է� �޴� �Լ�
{
	int error_value; //������

	while (1) //������ ���� ������ �ݺ�
	{
		cout << "Dept: "; //�а�
		getline(cin, dept); //�а� �Է�(���� ���� ���� Ȯ���� ���� getline Ȱ��)

		error_value = -1; //������ -1�� ����

		if (dept.size() == 0) //�ƹ��͵� �Է����� ������
		{
			while (dept.size() == 0) //�Է��� ������ �ݺ�
			{
				cout << "[Invalid Input] Please enter the student's department." << endl; //���� �޼��� ���
				cout << "Dept: "; //�а�
				getline(cin, dept); //�а� �Է�(���� ���� ���� Ȯ���� ���� getline Ȱ��)
			}
		}

		for (int i = 0; i < dept.size(); i++) //�а� ���ڿ� ó������ ������ �ݺ��Ͽ� ���� Ȯ��
		{
			if (dept[i] == ' ') //������ �ִ� ���
			{
				cout << "[Invalid Input] Can't include spaces." << endl; //���� �޼��� ���

				error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����
				if (error_value == 1) //�ٽ� �Է��� �޴� ���
				{
					break; //�ݺ� ����
				}
				else if (error_value == 0) //�޴��� ���ư��� ���
				{
					return -1; //�޴��� ���ư�
				}
			}

			if (int(dept[i]) < 65 || int(dept[i]) > 90) //�빮�ڰ� �ƴ� ���
			{
				cout << "[Invalid Input] Only uppercase letters can be entered." << endl; //���� �޼��� ���

				error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����
				if (error_value == 1) //�ٽ� �Է��� �޴� ���
				{
					break; //�ݺ� ����
				}
				else if (error_value == 0) //�޴��� ���ư��� ���
				{
					return -1; //�޴��� ���ư�
				}
			}
		}

		if (error_value == 1) //�ٽ� �Է��� �޴� ���
		{
			continue; //ó������ �ݺ�
		}
		else //����� �Է� ���� ���
		{
			break; //�ݺ� ����
		}
	}
	data.dept = dept; //�л� ������ �� �а� ���� ����

	while (1) //������ ���� ������ �ݺ�
	{
		cout << "Gender: "; //����
		getline(cin, gender); //���� �Է�(���� ���� ���� Ȯ���� ���� getline Ȱ��)

		error_value = -1; //������ -1�� ����

		if (gender != "M" && gender != "F") //'M' �Ǵ� 'F'�� �ƴ� ��� (���� M�� F�� ��츸 ����ǵ��� �Ͽ� ���� ���� ���� Ȯ�� skip)
		{
			cout << "[Invalid Input] Only 'M'(= male) or 'F'(= female) can be entered." << endl; //���� �޼��� ���

			error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����
			if (error_value == 1) //�ٽ� �Է��� �޴� ���
			{
				continue; //ó������ �ݺ�
			}
			else if (error_value == 0) //�޴��� ���ư��� ���
			{
				return -1; //�޴��� ���ư�
			}
		}
		else //����� �Է� ���� ���
		{
			break; //�ݺ� ����
		}
	}
	data.gender = gender; //�л� ������ �� ���� ���� ����

	while (1)
	{
		cout << "Name: "; //�̸�
		getline(cin, name); //�̸� �Է�(���� ���� ���� Ȯ���� ���� getline Ȱ��)

		error_value = -1; //������ -1�� ����

		if (name.size() == 0) //�ƹ��͵� �Է����� ������
		{
			while (name.size() == 0) //�Է��� ������ �ݺ�
			{
				cout << "[Invalid Input] Please enter the student's name." << endl; //���� �޼��� ���
				cout << "Name: "; //�а�
				getline(cin, name); //�̸� �Է�
			}
		}

		for (int i = 0; i < name.size(); i++) //�̸� ���ڿ� ó������ ������ �ݺ��Ͽ� ���� Ȯ��
		{
			if (name[i] == ' ') //������ �ִ� ���
			{
				cout << "[Invalid Input] Can't include spaces." << endl; //���� �޼��� ���
				error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����
				if (error_value == 1) //�ٽ� �Է��� �޴� ���
				{
					break; //�ݺ� ����
				}
				else if (error_value == 0) //�޴��� ���ư��� ���
				{
					return -1; //�޴��� ���ư�
				}
			}

			if (!(int(name[i]) >= 65 && int(name[i]) <= 90 || int(name[i]) >= 97 && int(name[i]) <= 122)) //���ĺ��� �ƴ� ���
			{
				cout << "[Invalid Input] Only uppercase letters can be entered." << endl; //���� �޼��� ���

				error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����
				if (error_value == 1) //�ٽ� �Է��� �޴� ���
				{
					break; //�ݺ� ����
				}
				else if (error_value == 0) //�޴��� ���ư��� ���
				{
					return -1; //�޴��� ���ư�
				}
			}
		}

		if (error_value == 1) //�ٽ� �Է��� �޴� ���
		{
			continue; //ó������ �ݺ�
		}
		else //����� �Է� ���� ���
		{
			break; //�ݺ� ����
		}
	}
	data.name = name; //�л� ������ �� �̸� ���� ����

	while (1)
	{
		cout << "Age: "; //����

		cin >> age; //���� �Է�

		error_value = -1; //������ -1�� ����

		if (cin.fail() == 1) //���� �߻� ��
		{
			cin.clear(); //cin.fail �ʱ�ȭ
			cin.ignore(); //�Է� ���� ����
			cout << "[Invalid Input] Only 18 to 30 years of age can be entered." << endl; //���� �޼��� ���

			error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����
			if (error_value == 1) //�ٽ� �Է��� �޴� ���
			{
				continue; //ó������ �ݺ�
			}
			else if (error_value == 0) //�޴��� ���ư��� ���
			{
				return -1; //�޴��� ���ư�
			}
		}

		if (age < 18 || age > 30) //18�� �̸� 30�� �ʰ��� ���
		{
			cout << "[Invalid Input] Only 18 to 30 years of age can be entered." << endl; //���� �޼��� ���
			error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����
			if (error_value == 1) //�ٽ� �Է��� �޴� ���
			{
				continue; //ó������ �ݺ�
			}
			else if (error_value == 0) //�޴��� ���ư��� ���
			{
				return -1; //�޴��� ���ư�
			}
		}
		else //����� �Է� ���� ���
		{
			break; //�ݺ� ����
		}
	}
	data.age = age; //�л� ������ �� ���� ���� ����

	return 1; //�Լ� ����
}

bool student::check_equal(student data1, student data2) //���� �����͸� ���� �л����� Ȯ���ϴ� ����
{
	if (data1.dept == data2.dept && data1.gender == data2.gender && data1.name == data2.name && data1.age == data2.age) //�� �л��� �����Ͱ� ������
	{
		return true; //true ��ȯ
	}
	else //�ٸ���
	{
		return false; //false ��ȯ
	}
}

string student::return_dept(student data) //�л��� �а��� ��ȯ�ϴ� �Լ�
{
	return data.dept; //�а� ��ȯ
}

int student::return_gender(student data) //�л��� ������ ��ȯ�ϴ� �Լ�
{
	if (data.gender == "F") //���л��� ���
	{
		return 1; //1 ��ȯ
	}
	if (data.gender == "M") //���л��� ���
	{
		return 0; //0 ��ȯ
	}
}

int student::return_age(student data) //�л��� ���̸� �����ϴ� �Լ�
{
	return data.age; //���� ����
}

void student::print_data(student& data, string* dept, string* gender, string* name, int* age) //����� ���� �л��� �����͸� ��ȯ�ϴ� �Լ�
{
	*dept = data.dept; //�а� ��ȯ
	*gender = data.gender; //���� ��ȯ
	*name = data.name; //���� ��ȯ
	*age = data.age; //���� ����

	return; //����
}

int student::compare_data(student data1, student data2, string metric) //�� �л��� �����͸� ���ϴ� �Լ�
{
	int a, b; //�� �л��� �а� ���ڿ� ���� ����
	int length; //���ڿ� ���� ����

	if (metric == "dept") //"dept"�� �Է� �޾��� ��
	{
		a = data1.dept.size(); //�л�1�� �а� ���ڿ� ����
		b = data2.dept.size(); //�л�2�� �а� ���ڿ� ����

		length = a < b ? a : b; //�� ª�� ���̷� ����

		for (int i = 0; i < length; i++) //���̸�ŭ �ݺ�
		{
			if (int(data1.dept[i]) < int(data2.dept[i])) //���ڿ��� ������
			{
				return 1; //1 ��ȯ
			}
			else if (int(data1.dept[i]) == int(data2.dept[i])) //���ڿ��� ������
			{
				continue; //�ݺ� ����
			}
			else if (int(data1.dept[i]) > int(data2.dept[i])) //���ڿ��� ũ��
			{
				return 0; //0 ��ȯ
			}
		}

		if (a < b) //�л�2�� ���ڿ� ���̰� �� �� ���
		{
			return 1;
		}
		else if (a > b) //�л�1�� ���ڿ� ���̰� �� �� ���
		{
			return 0; //0 ��ȯ
		}
		else if (a == b) //�л� 1�� �л� 2�� �а��� ���ٸ�
		{
			return 2; //2 ��ȯ
		}
	}
	else if (metric == "gender") //"gender"�� �Է� �޾��� ��
	{
		if (data1.gender == "F" && data2.gender == "M") //�л�1�� ���л��̰�, �л�2�� ���л��� ���
		{
			return 1; //1 ��ȯ
		}
		else if (data1.gender == data2.gender) //�� �л��� ������ ���� ���
		{
			return 2; //2 ��ȯ
		}
		else if (data1.gender == "M" && data2.gender == "F") //�л�1�� ���л��̰�, �л�2�� ���л��� ���
		{
			return 0; //0 ��ȯ
		}
	}
	else if (metric == "name") //"name"�� �Է� �޾��� ��
	{
		a = data1.name.size(); //�л�1�� �̸� ���ڿ� ����
		b = data2.name.size(); //�л�2�� �̸� ���ڿ� ����

		length = a < b ? a : b; //�� ª�� ���̷� ����

		for (int i = 0; i < length; i++) //���̸�ŭ �ݺ�
		{
			if (int(data1.name[i]) < int(data2.name[i])) //���ڿ��� ������
			{
				return 1; //1 ��ȯ
			}
			else if (int(data1.name[i]) == int(data2.name[i])) //���ڿ��� ������
			{
				continue; //�ݺ� ����
			}
			else if (int(data1.name[i]) > int(data2.name[i])) //���ڿ��� ũ��
			{
				return 0; //0 ��ȯ
			}
		}

		if (a < b) //�л�2�� ���ڿ� ���̰� �� �� ���
		{
			return 1; //1 ��ȯ
		}
		else if (a > b) //�л�1�� ���ڿ� ���̰� �� �� ���
		{
			return 0; //0 ��ȯ
		}
		else if (a == b) ///�л�1�� �л�2�� �̸��� ���ٸ�
		{
			return 2; //2 ��ȯ
		}

	}
	else if (metric == "age") //"age"�� �Է� �޾��� ��
	{
		if (data1.age < data2.age) //�л�2�� ���̰� ���� ���
		{
			return 1; //1 ��ȯ
		}
		else if (data1.age == data2.age) //�� �л��� ���̰� ���� ���
		{
			return 2; //2 ��ȯ
		}
		else if (data1.age > data2.age) //�л�1�� ���̰� ���� ���
		{
			return 0; //0 ��ȯ
		}
	}
}