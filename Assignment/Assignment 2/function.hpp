//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "list.hpp" //"list.hpp" header file

using namespace std; //Namespace

void print_menu(); //�޴� ��� �Լ�
void print_pivot_menu_1(); //ī�װ� �ɼ� �޴� ��� �Լ�
void print_pivot_menu_2(); //�Լ� �ɼ� �޴� ��� �Լ�
void save_node(list& list); //��� ���� �Լ�
void delete_node(list& list); //��� ���� �Լ�
void print_node(list& list); //��� ��� �Լ�
void print_pivot_table(list& list, string category, string function); //pivot table ��� �Լ�
int print_error(); //���� ��� �Լ�