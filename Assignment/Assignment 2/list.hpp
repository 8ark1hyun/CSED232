//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "node.hpp" //"node.hpp" header file

using namespace std; //Namespace

class list { //list class
private: //private

	int count, dept_cnt; //��� ����(�л� ��), �а� ����
	string dept[9]; //�а� �迭
	int dept_student[9]; //�а� �л� �� �迭
	node* head; //��带 ����Ű�� ������
	node* tail; //������ ����Ű�� ������

public: //public

	list(); //list ������
	~list(); //list �Ҹ���
	bool empty_list() const; //�� ����Ʈ Ȯ�� �Լ�
	void insert_node(); //��� ���� �Լ�
	void delete_node(); //��� ���� �Լ�
	void print_node(); //��� ��� �Լ�
	void print_pivot_node(string category, string function); //pivot ��� ��� �Լ�
	int sort(int* move_count, node* one_node, string metric); //��� ���� �Լ�
};