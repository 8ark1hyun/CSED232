//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "student.hpp" //"student.hpp" header file

class node { //node class
public: //public

	student data; //����� ������
	node* next; //���� ��带 ����Ű�� ������
};