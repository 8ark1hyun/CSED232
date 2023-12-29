//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string>
#include "function.hpp"

using namespace std;

void print_menu() //메뉴 출력 함수
{
	cout << "----------MENU----------" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Delete a student" << endl;
	cout << "3. Print the student's list" << endl;
	cout << "4. Pivot Table" << endl;
	cout << "5. Exit" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";

	return; //함수 종료
}

void print_pivot_menu_1() //카테고리 옵션 메뉴 출력 함수
{
	cout << "--------Category--------" << endl;
	cout << "1. Dept" << endl;
	cout << "2. Gender" << endl;
	cout << "3. Dept and Gender" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";

	return; //함수 종료
}

void print_pivot_menu_2() //함수 옵션 메뉴 출력 함수
{
	cout << "--------Function--------" << endl;
	cout << "1. Average" << endl;
	cout << "2. Max" << endl;
	cout << "3. Min" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";

	return; //함수 종료
}

void save_node(list& list) //노드 저장 함수
{
	cin.ignore(); //입력 버퍼 정리
	list.insert_node(); //리스트에 노드 삽입

	return; //함수 종료
}

void delete_node(list& list) //노드 삭제 변수
{
	cin.ignore(); //입력 버퍼 정리
	list.delete_node(); //리스트에서 노드 삭제

	return; //함수 종료
}

void print_node(list& list) //노드 출력 함수
{
	cin.ignore(); //입력 버퍼 정리
	list.print_node(); //리스트의 노드 출력

	return; //함수 종료
}

void print_pivot_table(list& list, string category, string function) //pivot table 출력 함수
{
	cin.ignore(); //입력 버퍼 정리
	list.print_pivot_node(category, function); //리스트의 pivot table 출력

	return; //함수 종료
}

int print_error() //에러 출력 함수
{
	string option; //옵션 변수

	while (1) //제대로 입력 받을 때까지 반복
	{
		cout << "Enter '1' to re-enter or '0' to return to menu." << endl; //안내 메세지 출력
		cin >> option; //옵션 입력

		if (option == "1") //"1"을 입력하면
		{
			cin.ignore(); //입력 버퍼 정리
			return 1; //1 반환
		}
		else if (option == "0") //"0"을 입력하면
		{
			cin.ignore(); //입력 버퍼 정리
			return 0; //0 반환
		}
		else //제대로 입력 받지 않으면
		{
			continue; //반복 진행
		}
	}
}