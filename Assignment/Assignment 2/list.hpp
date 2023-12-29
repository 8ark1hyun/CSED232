//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "node.hpp" //"node.hpp" header file

using namespace std; //Namespace

class list { //list class
private: //private

	int count, dept_cnt; //노드 개수(학생 수), 학과 개수
	string dept[9]; //학과 배열
	int dept_student[9]; //학과 학생 수 배열
	node* head; //헤드를 가리키는 포인터
	node* tail; //테일을 가리키는 포인터

public: //public

	list(); //list 생성자
	~list(); //list 소멸자
	bool empty_list() const; //빈 리스트 확인 함수
	void insert_node(); //노드 삽입 함수
	void delete_node(); //노드 삭제 함수
	void print_node(); //노드 출력 함수
	void print_pivot_node(string category, string function); //pivot 노드 출력 함수
	int sort(int* move_count, node* one_node, string metric); //노드 정렬 함수
};