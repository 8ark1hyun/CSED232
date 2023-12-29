//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "list.hpp" //"list.hpp" header file

using namespace std; //Namespace

void print_menu(); //메뉴 출력 함수
void print_pivot_menu_1(); //카테고리 옵션 메뉴 출력 함수
void print_pivot_menu_2(); //함수 옵션 메뉴 출력 함수
void save_node(list& list); //노드 저장 함수
void delete_node(list& list); //노드 삭제 함수
void print_node(list& list); //노드 출력 함수
void print_pivot_table(list& list, string category, string function); //pivot table 출력 함수
int print_error(); //에러 출력 함수