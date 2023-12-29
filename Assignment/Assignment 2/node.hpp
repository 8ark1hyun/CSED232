//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "student.hpp" //"student.hpp" header file

class node { //node class
public: //public

	student data; //노드의 데이터
	node* next; //다음 노드를 가리키는 포인터
};