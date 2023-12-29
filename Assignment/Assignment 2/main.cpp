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
	string selection; //������� ���� ����
	list student_list; //�л� ����Ʈ

	while (1) //������ ������ �ݺ�
	{
		print_menu(); //�޴� ���
		cin >> selection; //������� �Է�

		if (selection == "1") //1���� �����ϸ�
		{
			save_node(student_list); //��� ����
		}
		else if (selection == "2") //2���� �����ϸ�
		{
			delete_node(student_list); //��� ����
		}
		else if (selection == "3") //3���� �����ϸ�
		{
			print_node(student_list); //��� ���
		}
		else if (selection == "4") //4���� �����ϸ�
		{
			string category; //ī�װ� �ɼ� ����
			string function; //�Լ� �ɼ� ����

			while (1) //����� �Է� ���� ������ �ݺ�
			{
				print_pivot_menu_1(); //ī�װ� �ɼ� �޴� ���
				cin >> category; //ī�װ� �ɼ� �Է�

				if (category == "1" || category == "2" || category == "3") //�ɼ��� �ǰ� �Է� ������
				{
					while (1) //����� �Է� ���� ������ �ݺ�
					{
						print_pivot_menu_2(); //�Լ� �ɼ� �޴� ���
						cin >> function; //�Լ� �ɼ� �Է�

						if (function == "1" || function == "2" || function == "3") //�ɼ��� �ǰ� �Է� ������
						{
							print_pivot_table(student_list, category, function); //pivot table ���
							break; //�ݺ� ����
						}
						else //�ɼ��� �߸� �Է� ������
						{
							cout << "[Invalid Input] Please re-enter." << endl << endl; //���� �޼��� ���
							continue; //�ٽ� �ݺ�
						}
					}
					break;
				}
				else //�ɼ��� �߸� �Է� ������
				{
					cout << "[Invalid Input] Please re-enter." << endl << endl; //���� �޼��� ���
					continue; //�ٽ� �ݺ�
				}
			}
		}
		else if (selection == "5") //5���� �����ϸ�
		{
			cout << "Exit!" << endl; //���� �޼��� ���
			break; //�ݺ� ����
		}
		else //����� �Է� ���� ������
		{	
			cout << "[Invalid Input] Please re-enter." << endl << endl; //���� �޼��� ���
			continue; //�ٽ� �ݺ�
		}
	}

	return 0; //���α׷� ����
}