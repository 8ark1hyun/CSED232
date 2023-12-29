//20220100 PKH

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include <cmath> //cmath library
#include "student.hpp" //"student.hpp" header file
#include "node.hpp" //"node.hpp" header file
#include "list.hpp" //"list.hpp" header file
#include "function.hpp" //"function.hpp" header file

using namespace std; //Namespace

int main()
{
	string selection; //사용자의 선택 변수
	list student_list; //학생 리스트

	while (1) //종료할 때까지 반복
	{
		print_menu(); //메뉴 출력
		cin >> selection; //사용자의 입력

		if (selection == "1") //1번을 선택하면
		{
			save_node(student_list); //노드 저장
		}
		else if (selection == "2") //2번을 선택하면
		{
			delete_node(student_list); //노드 삭제
		}
		else if (selection == "3") //3번을 선택하면
		{
			print_node(student_list); //노드 출력
		}
		else if (selection == "4") //4번을 선택하면
		{
			string category; //카테고리 옵션 변수
			string function; //함수 옵션 변수

			while (1) //제대로 입력 받을 때까지 반복
			{
				print_pivot_menu_1(); //카테고리 옵션 메뉴 출력
				cin >> category; //카테고리 옵션 입력

				if (category == "1" || category == "2" || category == "3") //옵션을 옳게 입력 받으면
				{
					while (1) //제대로 입력 받을 때까지 반복
					{
						print_pivot_menu_2(); //함수 옵션 메뉴 출력
						cin >> function; //함수 옵션 입력

						if (function == "1" || function == "2" || function == "3") //옵션을 옳게 입력 받으면
						{
							print_pivot_table(student_list, category, function); //pivot table 출력
							break; //반복 종료
						}
						else //옵션을 잘못 입력 받으면
						{
							cout << "[Invalid Input] Please re-enter." << endl << endl; //오류 메세지 출력
							continue; //다시 반복
						}
					}
					break;
				}
				else //옵션을 잘못 입력 받으면
				{
					cout << "[Invalid Input] Please re-enter." << endl << endl; //오류 메세지 출력
					continue; //다시 반복
				}
			}
		}
		else if (selection == "5") //5번을 선택하면
		{
			cout << "Exit!" << endl; //종료 메세지 출력
			break; //반복 종료
		}
		else //제대로 입력 받지 않으면
		{	
			cout << "[Invalid Input] Please re-enter." << endl << endl; //오류 메세지 출력
			continue; //다시 반복
		}
	}

	return 0; //프로그램 종료
}