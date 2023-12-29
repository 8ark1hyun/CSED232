//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library

using namespace std; //Namespace

class student { //student class
private: //private

	string dept, gender, name; //학과, 성별, 이름
	int age; //나이

public: //public

	int input_info(student data); //데이터를 입력 받는 함수
	bool check_equal(student data1, student data2); //같은 데이터를 가진 학생인지 확인하는 함수
	string return_dept(student data); //학생의 학과를 반환하는 함수
	int return_gender(student data); //학생의 성별을 반환하는 함수
	int return_age(student data); //학생의 나이를 반환하는 함수
	void print_data(student& data, string* dept, string* gender, string* name, int* age); //출력을 위해 학생의 데이터를 반환하는 함수
	int compare_data(student data1, student data2, string metric); //두 학생의 데이터를 비교하는 함수
};