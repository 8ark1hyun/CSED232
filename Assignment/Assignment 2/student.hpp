//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library

using namespace std; //Namespace

class student { //student class
private: //private

	string dept, gender, name; //�а�, ����, �̸�
	int age; //����

public: //public

	int input_info(student data); //�����͸� �Է� �޴� �Լ�
	bool check_equal(student data1, student data2); //���� �����͸� ���� �л����� Ȯ���ϴ� �Լ�
	string return_dept(student data); //�л��� �а��� ��ȯ�ϴ� �Լ�
	int return_gender(student data); //�л��� ������ ��ȯ�ϴ� �Լ�
	int return_age(student data); //�л��� ���̸� ��ȯ�ϴ� �Լ�
	void print_data(student& data, string* dept, string* gender, string* name, int* age); //����� ���� �л��� �����͸� ��ȯ�ϴ� �Լ�
	int compare_data(student data1, student data2, string metric); //�� �л��� �����͸� ���ϴ� �Լ�
};