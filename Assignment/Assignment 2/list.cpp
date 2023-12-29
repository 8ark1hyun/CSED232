//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "list.hpp" //"list.hpp" header file
#include "function.hpp" //"function.hpp" header file

using namespace std; //Namespace

list::list() //list ������
{
	count = 0; //��� ���� �ʱ�ȭ
	dept_cnt = 0; //�а� ���� �ʱ�ȭ
	head = NULL; //��� �ʱ�ȭ
	tail = NULL; //���� �ʱ�ȭ
	for (int i = 0; i < 9; i++)
	{
		dept[i] = "";
		dept_student[i] = 0; //�а� �л� �� �ʱ�ȭ
	}
}

list::~list() //list �Ҹ���
{
	node* temp; //temp ���

	while (!empty_list()) //�� ����Ʈ�� �� ������ �ݺ�
	{
		temp = head; //temp�� ��带 ����Ŵ
		head = head->next; //���� ����� next�� ����Ŵ
		delete temp; //temp ���� �Ҵ� ����
		count--; //��� ���� -1
	}
	tail = NULL;
	temp = NULL;
	dept_cnt = 0; //�а� ���� �ʱ�ȭ
	for (int i = 0; i < 9; i++)
	{
		dept[i] = "";
		dept_student[i] = 0; //�а� �л� �� �ʱ�ȭ
	}
}

bool list::empty_list() const //�� ����Ʈ Ȯ�� �Լ�
{
	return head == NULL; //�� ����Ʈ�̸� true ��ȯ
}

void list::insert_node() //��� ���� �Լ�
{
	node* new_node = new node; //�� ��� ���� �Ҵ�
	new_node->next = NULL; //����� next �ʱ�ȭ

	if (new_node->data.input_info(new_node->data) == -1) //�� ����� �л� ������ �Է�(��ȯ���� -1�̸� ���� �߻� �ǹ�)
	{
		delete new_node; //�� ��� ���� �Ҵ� ����
		return; //�Լ� ����
	}

	node* temp = head; //temp�� ��带 ����Ŵ

	while (temp != NULL) //temp�� NULL�� ������ �ݺ�
	{
		if (new_node->data.check_equal(new_node->data, temp->data) == true) //�� ����� �����Ͱ� ������ Ȯ���ϰ�, ���� ���
		{
			cout << "The student already exists" << endl << endl; //�̹� �����Ѵٴ� �޼��� ���

			delete new_node; //�� ��� ���� �Ҵ� ����

			return; //�Լ� ����
		}
		else //�ٸ� ���
		{
			temp = temp->next; //temp�� temp�� next�� ����Ŵ
		}
	}

	string new_node_dept; //�� ����� �а� ���ڿ� ����
	int dept_num = 0; //�а� ��ȣ ����
	int error_value; //������ ����

	new_node_dept = new_node->data.return_dept(new_node->data); //�� ����� �а� ���ڿ� ����

	for (int i = 0; i < dept_cnt; i++) //�̹� �����ϴ� �а����� Ȯ��
	{
		if (new_node_dept == dept[i]) //�̹� �����ϴ� �а��� ���
		{
			dept_num = i; //�а� ��ȣ ����

			break; //�ݺ� ����
		}
		else //�������� �ʴ� �а��� ���
		{
			dept_num = -1; //-1 ����
		}
	}

	error_value = -1; //������ -1�� ����

	if (dept_cnt == 0 || dept_num == -1) //�������� �ʴ� �а��� ���
	{
		dept_cnt++; //�а� ���� +1

		if (dept_cnt > 9) //�а� �ִ� ������ 9���� �Ѿ�� ���
		{
			cout << "[Invalid Input] Up to 9 departments are possible." << endl; //���� �޼��� ���

			error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����

			if (error_value == 1) //�ٽ� �Է��� �޴� ���
			{
				dept_cnt--; //�а� ���� -1
				delete new_node; //�� ��� ���� �Ҵ� ����

				insert_node(); //��� ���� �Լ� �ٽ� ����

				return; //�Լ� ����
			}
			else if (error_value == 0) //�޴��� ���ư��� ���
			{
				dept_cnt--; //�а� ���� -1
				delete new_node; //�� ��� ���� �Ҵ� ����

				return; //�Լ� ����
			}
		}
		else //�а� �ִ� ������ 9�� �̳��� ���
		{
			dept_cnt--; //�а� ���� -1

			if (dept_cnt == 0) //�а� ������ 0���̸�
			{
				dept[0] = new_node_dept; //�а� �迭 ù ��°�� �� ��� �а� ����
				dept_student[0] = 1; //�а� �л� �� = 1
			}

			for (int i = dept_cnt - 1; i >= 0; i--) //�а� ������ŭ �ݺ�(�ں��� ����)
			{
				int a; //�� ��� �а� ���ڿ� ���� ����
				int b; //���� �а� ���ڿ� ���� ����
				int length; //���ڿ� ���� ����
				int k = -1;

				a = new_node_dept.size(); //�� ����� �а� ���ڿ� ����
				b = dept[i].size(); //���� �а� ���ڿ� ����

				length = a < b ? a : b; //�� ª�� ���̷� ����

				for (int j = 0; j < length; j++) //���̸�ŭ �ݺ�
				{
					if (int(new_node_dept[j]) < int((dept[i])[j])) //���ڿ��� ������
					{
						k = 1; //k�� 1 ����

						break; //�ݺ� ����
					}
					else if (int(new_node_dept[j]) == int((dept[i])[j])) //���ڿ��� ������
					{
						continue; //�ݺ� ����
					}
					else if (int(new_node_dept[j]) > int((dept[i])[j])) //���ڿ��� ũ��
					{
						k = 0; //k�� 0 ����

						break; //�ݺ� ����
					}
				}

				if (k == 0) //k�� 0�̸�
				{
					dept[i+1] = new_node_dept; //�а� �迭 �˸��� ��ġ�� �� ��� �а� ����
					dept_student[i+1] = 1; //�а� �л� �� = 1

					break; //�ݺ� ����
				}
				else if (k == 1) //k�� 1�̸�
				{
					dept[i+1] = dept[i]; //�а� �迭 �˸��� ��ġ�� �̵�
					dept_student[i+1] = dept_student[i]; //�а� �л� �� �迭 �˸��� ��ġ�� �̵�
					dept[i] = new_node_dept; //�а� �迭 �˸��� ��ġ�� �� ��� �а� ����
					dept_student[i] = 1; //�а� �л� �� = 1

					continue; //�ݺ� ����
				}
			}

			dept_cnt++; //�а� ���� +1
		}
	}
	else //�̹� �����ϴ� �а��� ���
	{
		dept_student[dept_num]++; //�а� �л� �� +1

		if (dept_student[dept_num] > 10000) //�а� �� �ִ� �л� ���� 10000���� �Ѿ�� ���
		{
			cout << "[Invalid Input] Up to 10000 students per department can be entered." << endl; //���� �޼��� ���

			error_value = print_error(); //�ٽ� �Է��� ������, �޴��� ���ư��� ����

			if (error_value == 1) //�ٽ� �Է��� �޴� ���
			{
				dept_student[dept_num]--; //�а� �л� �� -1
				delete new_node; //�� ��� ���� �Ҵ� ����

				insert_node(); //��� ���� �Լ� �ٽ� ����

				return; //�Լ� ����
			}
			else if (error_value == 0) //�޴��� ���ư��� ���
			{
				dept_student[dept_num]--; //�а� �л� �� -1
				delete new_node; //�� ��� ���� �Ҵ� ����

				return; //�Լ� ����
			}
		}
	}

	if (empty_list()) //�� ����Ʈ�̸�
	{
		head = new_node; //�� ��带 ���� ����
		tail = new_node; //�� ��带 ���Ϸ� ����
		count++; //��� ���� +1
		cout << "A student is added in table!" << endl << endl; //�л� ���� �޼��� ���

		return; //�Լ� ����
	}

	int move_count = 0; //������ Ƚ�� ����

	if (sort(&move_count, new_node, "dept") == -1) //�а��� �������� ����(��ȯ���� -1�̸� ���� �������� ����)
	{
		if (sort(&move_count, new_node, "gender") == -1) //������ �������� ����(��ȯ���� -1�̸� ���� �������� ����)
		{
			if (sort(&move_count, new_node, "name") == -1) //�̸��� �������� ����(��ȯ���� -1�̸� ���� �������� ����)
			{
				if (sort(&move_count, new_node, "age") == -1) //���̸� �������� ����
				{
					move_count == 0; //������ Ƚ�� = 0
				}
			}
		}
	}

	node* pcur; //���� ��带 ����Ű�� ������
	pcur = head; //���� ���� ��带 ����Ŵ

	if (move_count == 0) //������ Ƚ���� 0�̸�
	{
		new_node->next = head; //�� ����� next�� ��带 ����Ŵ
		head = new_node; //�� ��带 ���� ����
	}
	else //������ Ƚ���� 0�� �ƴϸ�
	{
		for (int i = 0; i < move_count - 1; i++) //������ Ƚ�� - 1 ��ŭ �ݺ�
		{
			pcur = pcur->next; //���� ���� ���� ����� next�� ����Ŵ
		}
		if (pcur == tail) //���� ��尡 tail�� ����Ű��
		{
			pcur->next = new_node; //���� ����� next�� �� ��带 ����Ŵ
			tail = new_node; //�� ��带 ���Ϸ� ����
		}
		else //�׷��� ������
		{
			new_node->next = pcur->next; //�� ����� next�� ���� ����� next�� ����Ŵ
			pcur->next = new_node; //���� ����� next�� �� ��带 ����Ŵ
		}
	}

	count++; //��� ���� +1

	cout << "A student is added in table!" << endl << endl; //�л� ���� �޼��� ���

	return; //�Լ� ����
}

void list::delete_node() //��� ���� �Լ�
{
	node* del_node = new node; //������ ��� ���� �Ҵ�

	int delete_check = 0; //���� ���� Ȯ�� ����

	if ((del_node->data.input_info(del_node->data)) == -1) //������ �л� ������ �Է�(��ȯ���� -1�̸� ���� �߻� �ǹ�)
	{
		delete del_node; //������ ��� ���� �Ҵ� ����

		return; //�Լ� ����
	}
	if (empty_list()) //�� ����Ʈ�̸�
	{
		cout << "Can't Delete it" << endl << endl; //���� �Ұ� �޼��� ���

		delete del_node; //������ ��� ���� �Ҵ� ����

		return; //�Լ� ����
	}

	node* ppre; //���� ��带 ����Ű�� ������
	node* pcur; //���� ��带 ����Ű�� ������
	ppre = head; //���� ���� ��带 ����Ŵ
	pcur = ppre->next; //���� ���� ���� ����� next�� ����Ŵ

	if (del_node->data.check_equal(del_node->data, ppre->data) == true) //�� ����� �����Ͱ� ������ Ȯ���ϰ�, ���� ���
	{
		cout << "Deleted!" << endl << endl; //���� �Ϸ� �޼��� ���

		delete ppre; //���� ��� ���� �Ҵ� ����
		head = pcur; //���� ��带 ���� ����
		count--; //��� ���� -1

		delete_check = 1; //���� ���� 1�� ����
	}
	else //�ٸ� ���
	{
		while (pcur != NULL) //���� ��尡 NULL�� ������ �ݺ�
		{
			if (del_node->data.check_equal(del_node->data, pcur->data) == true) //�� ����� �����Ͱ� ������ Ȯ���ϰ�, ���� ���
			{
				if (pcur == tail) //���� ��尡 ������ ����Ű��
				{
					cout << "Deleted!" << endl << endl; //���� �Ϸ� �޼��� ���

					tail = ppre; //���� ��带 ���Ϸ� ����
					ppre->next = NULL; //���� ����� next �ʱ�ȭ
					delete pcur; //���� ��� ���� �Ҵ� ����
					count--; //��� ���� -1

					delete_check = 1; //���� ���� 1�� ����
					
					break; //�ݺ� ����
				}
				else //�׷��� ������
				{
					cout << "Deleted!" << endl << endl; //���� �Ϸ� �޼��� ���

					ppre->next = pcur->next; //���� ����� next�� ���� ����� next�� ����Ŵ
					delete pcur; //���� ��� ���� �Ҵ� ����
					count--; //��� ���� -1

					delete_check = 1; //���� ���� 1�� ����
					
					break; //�ݺ� ����
				}
			}
			else //�ٸ� ���
			{
				ppre = pcur; //���� ���� ���� ��带 ����Ŵ
				pcur = pcur->next; //���� ���� ���� ����� next�� ����Ŵ
			}
		}
	}

	string del_dept; //������ �а� ���ڿ� ����
	int dept_num = 0; //������ �а� ��ȣ ����
	int a = 0;

	del_dept = del_node->data.return_dept(del_node->data); //������ �а� ���ڿ� ����

	if (delete_check != 1) //���� ���ΰ� 1�� �ƴϸ�
	{
		cout << "Can't Delete it" << endl << endl; //���� �Ұ� �޼��� ���

		delete del_node; //������ ��� ���� �Ҵ� ����

		return; //�Լ� ����
	}
	else //���� ���ΰ� 1�̸�
	{
		for (int i = 0; i < dept_cnt; i++) //�а� ������ŭ �ݺ�
		{
			if (del_dept == dept[i]) //������ �а� ���ڿ��� �а� ���ڿ��� ������
			{
				dept_num = i; //�а� ��ȣ ����

				break; //�ݺ� ����
			}
		}

		if (dept_student[dept_num] == 1) //������ �а� �л� ���� 1���̸�
		{
			for (int i = 0; i < dept_cnt - dept_num - 1; i++) //�а� ���� - �а� ��ȣ - 1 ��ŭ �ݺ�
			{
				dept[dept_num + i] = dept[dept_num + i + 1]; //�а� �迭 �˸��� ��ġ�� �̵�
				dept_student[dept_num + i] = dept_student[dept_num + i + 1]; //�а� �л� �� �迭 �˸��� ��ġ�� �̵�
			}
			dept_cnt--; //�а� ���� -1
			dept_student[dept_cnt] = 0; //�а� �л� �� = 0
		}
		else //�׷��� ������
		{
			dept_student[dept_num]--; //�а� �л� �� -1
		}

		delete del_node; //������ ��� ���� �Ҵ� ����

		return; //�Լ� ����
	}
}

void list::print_node() //��� ��� �Լ�
{
	node* temp; //temp ���
	temp = head; //temp�� ��带 ����Ŵ

	string print_dept, print_gender, print_name; //����� �а� ���ڿ�, ����� ���� ���ڿ�, ����� �̸� ���ڿ� ����
	int print_age; //����� ���� ����

	if (empty_list()) //�� ����Ʈ�̸�
	{
		cout << "Empty list" << endl << endl; //�� ����Ʈ �޼��� ���

		return; //�Լ� ����
	}

	cout << "Dept" << '\t' << "Gender" << '\t' << "Name" << '\t' << "Age" << endl; //ù ��° �� ���

	for (int i = 0; i < count; i++) //��� ������ŭ �ݺ�
	{
		temp->data.print_data(temp->data, &print_dept, &print_gender, &print_name, &print_age); //����� �л� ������ ����
		cout << print_dept << '\t' << print_gender << '\t' << print_name << '\t' << print_age << endl; //������� ���
		temp = temp->next; //temp�� temp�� next�� ����Ŵ
	}

	cout << endl;

	return; //�Լ� ����
}

void list::print_pivot_node(string category, string function) //pivot ��� ��� �Լ�
{
	int sum = 0; //���� ���� ����
	int k = 0;
	int max_or_min = 0; //���� �ִ� �Ǵ� �ּڰ� ���� ����
	float value = 0; //���� ��� ����
	int woman_value = 0; //���� ���� ���� ����
	int woman_count = 0; //���� ��� ����
	int man_value = 0; //���� ���� ���� ����
	int man_count = 0; //���� ��� ����

	node* temp; //temp ���
	temp = head; //temp�� ��带 ����Ŵ

	if (category == "1") //ī�װ� �ɼ��� 1���̸�
	{
		if (function == "1") //�Լ� �ɼ��� 1���̸�
		{
			cout << "Dept" << '\t' << "Average" << endl; //ù ��° �� ���

			for (int i = 0; i < dept_cnt; i++) //�а� ������ŭ �ݺ�
			{
				sum = 0; //���� ���� �ʱ�ȭ

				cout << dept[i] << '\t'; //�а� ���

				for (int j = 0; j < dept_student[i]; j++) //�а� �л� ����ŭ �ݺ�
				{
					sum += temp->data.return_age(temp->data); //���� ���� ���
					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}

				value = float(sum) / float(dept_student[i]); //���� ��� ���

				if (value - int(value) != 0) //������ �ƴϸ�
				{
					cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
					cout.precision(1); //1�ڸ��� ����
				}
				else //�����̸�
				{
					cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
					cout.precision(0); //�Ҽ��� �Ʒ� ��� X
				}

				cout << value << endl; //���� ��� ���
			}

			cout << endl;
		}
		else if (function == "2") //�Լ� �ɼ��� 2���̸�
		{
			cout << "Dept" << '\t' << "Max" << endl; //ù ��° �� ���

			for (int i = 0; i < dept_cnt; i++) //�а� ������ŭ �ݺ�
			{
				max_or_min = 0; //���� �ִ� �ʱ�ȭ

				cout << dept[i] << '\t'; //�а� ���

				for (int j = 0; j < dept_student[i]; j++) //�а� �л� ����ŭ �ݺ�
				{
					k = temp->data.return_age(temp->data); //�л� ���� ����

					if (max_or_min < k) //���� �ִ񰪺��� ũ��
					{
						max_or_min = k; //�ִ� ����
					}

					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}

				cout << max_or_min << endl; //���� �ִ� ���
			}

			cout << endl;
		}
		else if (function == "3") //�Լ� �ɼ��� 3���̸�
		{
			cout << "Dept" << '\t' << "Min" << endl; //ù ��° �� ���

			for (int i = 0; i < dept_cnt; i++) //�а� ������ŭ �ݺ�
			{
				max_or_min = 100; //���� �ּڰ� �ʱ�ȭ

				cout << dept[i] << '\t'; //�а� ���

				for (int j = 0; j < dept_student[i]; j++) //�а� �л� ����ŭ �ݺ�
				{
					k = temp->data.return_age(temp->data); //�л� ���� ����

					if (max_or_min > k) //���� �ּڰ����� ������
					{
						max_or_min = k; //�ּڰ� ����
					}

					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}

				cout << max_or_min << endl; //���� �ּڰ� ���
			}

			cout << endl;
		}
	}
	else if (category == "2") //ī�װ� �ɼ��� 2���̸�
	{
		if (function == "1") //�Լ� �ɼ��� 1���̸�
		{
			cout << "Gender" << '\t' << "Average" << endl; //ù ��° �� ���

			for (int i = 0; i < count; i++) //��� ������ŭ �ݺ�
			{
				if (temp->data.return_gender(temp->data) == 1) //�����̸�
				{
					woman_value += temp->data.return_age(temp->data); //���� ���� ���� ���
					woman_count++; //���� ��� +1
					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}
				else //�����̸�
				{
					man_value += temp->data.return_age(temp->data); //���� ���� ���� ���
					man_count++; //���� ��� +1
					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}
			}

			if (woman_count != 0) //���ڰ� 0���� �ƴϸ�
			{
				value = float(woman_value) / float(woman_count); //���� ���� ��� ���
			}
			else //���ڰ� 0���̸�
			{
				value = 0; //���� ���� ��� = 0
			}

			if (value - int(value) != 0) //������ �ƴϸ�
			{
				cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
				cout.precision(1); //1�ڸ��� ����
			}
			else //�����̸�
			{
				cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
				cout.precision(0); //�Ҽ��� �Ʒ� ��� X
			}

			if (value != 0) //���� ���� ����� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
			{
				cout << "F" << '\t' << value << endl; //����, ���� ��� ���
			}

			if (man_count != 0) //���ڰ� 0���� �ƴϸ�
			{
				value = float(man_value) / float(man_count); //���� ���� ��� ���
			}
			else //���ڰ� 0���̸�
			{
				value = 0; //���� ���� ��� = 0
			}

			if (value - int(value) != 0) //������ �ƴϸ�
			{
				cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
				cout.precision(1); //1�ڸ��� ����
			}
			else //�����̸�
			{
				cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
				cout.precision(0); //�Ҽ��� �Ʒ� ��� X
			}

			if (value != 0) //���� ���� ����� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
			{
				cout << "M" << '\t' << value << endl; //����, ���� ��� ���
			}

			cout << endl;
		}
		else if (function == "2") //�Լ� �ɼ��� 2���̸�
		{
			cout << "Gender" << '\t' << "Max" << endl; //ù ��° �� ���

			woman_value = 0; //���� ���� �ִ� �ʱ�ȭ
			man_value = 0; //���� ���� �ִ� �ʱ�ȭ

			for (int i = 0; i < count; i++) //��� ������ŭ �ݺ�
			{
				if (temp->data.return_gender(temp->data) == 1) //�����̸�
				{
					k = temp->data.return_age(temp->data); //�л� ���� ����

					if (woman_value < k) //���� �ִ񰪺��� ũ��
					{
						woman_value = k; //�ִ� ����
					}

					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}
				else //�����̸�
				{
					k = temp->data.return_age(temp->data); //�л� ���� ����

					if (man_value < k) //���� �ִ񰪺��� ũ��
					{
						man_value = k; //�ִ� ����
					}

					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}
			}

			if (woman_value != 0) //���� ���� �ִ��� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
			{
				cout << "F" << '\t' << woman_value << endl; //����, ���� �ִ� ���
			}

			if (man_value != 0) //���� ���� �ִ��� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
			{
				cout << "M" << '\t' << man_value << endl; //����, ���� �ִ� ���
			}

			cout << endl;
		}
		else if (function == "3") //�Լ� �ɼ��� 3���̸�
		{
			cout << "Gender" << '\t' << "Min" << endl; //ù ��° �� ���

			woman_value = 100; //���� ���� �ּڰ� �ʱ�ȭ
			man_value = 100; //���� ���� �ּڰ� �ʱ�ȭ

			for (int i = 0; i < count; i++) //��� ������ŭ �ݺ�
			{
				if (temp->data.return_gender(temp->data) == 1) //�����̸�
				{
					k = temp->data.return_age(temp->data); //�л� ���� ����

					if (woman_value > k) //���� �ּڰ����� ������
					{
						woman_value = k; //�ּڰ� ����
					}

					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}
				else //�����̸�
				{
					k = temp->data.return_age(temp->data); //�л� ���� ����

					if (man_value > k) //���� �ּڰ����� ������
					{
						man_value = k; //�ּڰ� ����
					}

					temp = temp->next; //temp�� temp�� next�� ����Ŵ
				}
			}

			if (woman_value != 100) //���� ���� �ּڰ��� 100�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
			{
				cout << "F" << '\t' << woman_value << endl; //����, ���� �ּڰ� ���
			}

			if (man_value != 100) //���� ���� �ּڰ��� 100�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
			{
				cout << "M" << '\t' << man_value << endl; //����, ���� �ּڰ� ���
			}

			cout << endl;
		}
	}
	else if (category == "3") //ī�װ� �ɼ��� 3���̸�
	{
		if (function == "1") //�Լ� �ɼ��� 1���̸�
		{
			cout << "Dept" << '\t' << "Gender" << '\t' << "Average" << endl; //ù ��° �� ���

			for (int i = 0; i < dept_cnt; i++) //�а� ������ŭ �ݺ�
			{
				woman_value = 0; //���� ���� ���� �ʱ�ȭ
				man_value = 0; //���� ���� ���� �ʱ�ȭ
				woman_count = 0; //���� ��� �ʱ�ȭ
				man_count = 0; //���� ��� �ʱ�ȭ

				for (int j = 0; j < dept_student[i]; j++) //�а� �л� ����ŭ �ݺ�
				{
					if (temp->data.return_gender(temp->data) == 1) //�����̸�
					{
						woman_value += temp->data.return_age(temp->data); //���� ���� ���� ���
						woman_count++; //���� ��� +1
						temp = temp->next; //temp�� temp�� next�� ����Ŵ
					}
					else //�����̸�
					{
						man_value += temp->data.return_age(temp->data); //���� ���� ���� ���
						man_count++; //���� ��� +1
						temp = temp->next; //temp�� temp�� next�� ����Ŵ
					}
				}

				if (woman_count != 0) //���ڰ� 0���� �ƴϸ�
				{
					value = float(woman_value) / float(woman_count); //���� ���� ��� ���
				}
				else //���ڰ� 0���̸�
				{
					value = 0; //���� ���� ��� = 0
				}

				if (value - int(value) != 0) //������ �ƴϸ�
				{
					cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
					cout.precision(1); //1�ڸ��� ����
				}
				else //�����̸�
				{
					cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
					cout.precision(0); //1�ڸ��� ����
				}

				if (value != 0) //���� ���� ����� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
				{
					cout << dept[i] << '\t' << "F" << '\t' << value << endl; //�а�, ����, ���� ��� ���
				}

				if (man_count != 0) //���ڰ� 0���� �ƴϸ�
				{
					value = float(man_value) / float(man_count); //���� ���� ��� ���
				}
				else //���ڰ� 0���̸�
				{
					value = 0; //���� ���� ��� = 0
				}

				if (value - int(value) != 0) //������ �ƴϸ�
				{
					cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
					cout.precision(1); //1�ڸ��� ����
				}
				else //�����̸�
				{
					cout << fixed; //�Ҽ��� �Ʒ� �ڸ��� ����
					cout.precision(0); //1�ڸ��� ����
				}

				if (value != 0) //���� ���� ����� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
				{
					cout << dept[i] << '\t' << "M" << '\t' << value << endl; //�а�, ����, ���� ��� ���
				}
			}

			cout << endl;
		}
		else if (function == "2") //�Լ� �ɼ��� 2���̸�
		{
			cout << "Dept" << '\t' << "Gender" << '\t' << "Max" << endl; //ù ��° �� ���

			for (int i = 0; i < dept_cnt; i++) //�а� ������ŭ �ݺ�
			{
				woman_value = 0; //���� ���� �ִ� �ʱ�ȭ
				man_value = 0; //���� ���� �ִ� �ʱ�ȭ

				for (int j = 0; j < dept_student[i]; j++) //�а� �л� ����ŭ �ݺ�
				{
					if (temp->data.return_gender(temp->data) == 1) //�����̸�
					{
						k = temp->data.return_age(temp->data); //�л� ���� ����

						if (woman_value < k) //���� �ִ񰪺��� ũ��
						{
							woman_value = k; //�ִ� ����
						}

						temp = temp->next; //temp�� temp�� next�� ����Ŵ
					}
					else //�����̸�
					{
						k = temp->data.return_age(temp->data); //�л� ���� ����

						if (man_value < k) //���� �ִ񰪺��� ũ��
						{
							man_value = k; //�ִ� ����
						}

						temp = temp->next; //temp�� temp�� next�� ����Ŵ
					}
				}

				if (woman_value != 0) //���� ���� �ִ��� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
				{
					cout << dept[i] << '\t' << "F" << '\t' << woman_value << endl; //�а�, ����, ���� �ִ� ���
				}

				if (man_value != 0) //���� ���� �ִ��� 0�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
				{
					cout << dept[i] << '\t' << "M" << '\t' << man_value << endl; //�а�, ����, ���� �ִ� ���
				}
			}

			cout << endl;
		}
		else if (function == "3") //�Լ� �ɼ��� 3���̸�
		{
			cout << "Dept" << '\t' << "Gender" << '\t' << "Min" << endl; //ù ��° �� ���

			for (int i = 0; i < dept_cnt; i++) //�а� ������ŭ �ݺ�
			{
				woman_value = 100; //���� ���� �ּڰ� �ʱ�ȭ
				man_value = 100; //���� ���� �ּڰ� �ʱ�ȭ

				for (int j = 0; j < dept_student[i]; j++) //�а� �л� ����ŭ �ݺ�
				{
					if (temp->data.return_gender(temp->data) == 1) //�����̸�
					{
						k = temp->data.return_age(temp->data); //�л� ���� ����

						if (woman_value > k) //���� �ּڰ����� ������
						{
							woman_value = k; //�ּڰ� ����
						}

						temp = temp->next; //temp�� temp�� next�� ����Ŵ
					}
					else //�����̸�
					{
						k = temp->data.return_age(temp->data); //�л� ���� ����

						if (man_value > k) //���� �ּڰ����� ������
						{
							man_value = k; //�ּڰ� ����
						}

						temp = temp->next; //temp�� temp�� next�� ����Ŵ
					}
				}

				if (woman_value != 100) //���� ���� �ּڰ��� 100�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
				{
					cout << dept[i] << '\t' << "F" << '\t' << woman_value << endl; //�а�, ����, ���� �ּڰ� ���
				}

				if (man_value != 100) //���� ���� �ּڰ��� 100�� �ƴϸ�(���ڰ� 0���� �ƴϸ�)
				{
					cout << dept[i] << '\t' << "M" << '\t' << man_value << endl; //�а�, ����, ���� �ּڰ� ���
				}
			}

			cout << endl;
		}
	}
}

int list::sort(int* move_count, node* one_node, string metric) //��� ���� �Լ�
{
	int connect; //���� ���� ����
	int next = 0; //���� �������� ���� ���� ���� ����

	node* temp; //temp ���
	temp = head; //temp�� ��带 ����Ŵ

	if (metric == "gender") //"gender"�� �������� �����ϸ�
	{
		while (temp != NULL) //temp�� NULL�� ������ �ݺ�
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, "dept"); //�� �л��� �а� ��

			if (connect == 1) //�����ϰ��� �ϴ� ����� �а� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� ���� X

				return 0; //0�� ��ȯ�ϸ� �Լ� ����
			}
			else if (connect == 0) //�����ϰ��� �ϴ� ����� �а� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� ���� X
				temp = temp->next; //temp�� temp�� next�� ����Ŵ
			}
			else if (connect == 2) //�����ϰ��� �ϴ� ����� �а� ���ڿ��� ũ��
			{
				next = 1; //���� �������� ���� ����

				break; //�ݺ� ����
			}
		}
	}
	else if (metric == "name") //"name"�� �������� �����ϸ�
	{
		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 0) //�� �л��� �а��� ������ ������ �ݺ�
		{
			temp = temp->next; //temp�� temp�� next�� ����Ŵ
		}

		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 2) //�� �л��� �а��� ���� ���� �ݺ�
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, "gender"); //�� �л��� ���� ��

			if (connect == 1) //�����ϰ��� �ϴ� ����� ���� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� X

				return 0; //0�� ��ȯ�ϸ� �Լ� ����
			}
			else if (connect == 0) //�����ϰ��� �ϴ� ����� ���� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� X
				temp = temp->next; //temp�� temp�� next�� ����Ŵ
			}
			else if (connect == 2) //�����ϰ��� �ϴ� ����� ���� ���ڿ��� ũ��
			{
				next = 1; //���� �������� ����

				break; //�ݺ� ����
			}
		}
	}
	else if (metric == "age") //"age"�� �������� �����ϸ�
	{
		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 0) //�� �л��� �а��� ������ ������ �ݺ�
		{
			temp = temp->next; //temp�� temp�� next�� ����Ŵ
		}

		while (one_node->data.compare_data(one_node->data, temp->data, "gender") == 0) //�� �л��� ������ ������ ������ �ݺ�
		{
			temp = temp->next; //temp�� temp�� next�� ����Ŵ
		}

		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 2 && one_node->data.compare_data(one_node->data, temp->data, "gender") == 2) //�� �л��� �а��� ������ ���� ���� �ݺ�
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, "name"); //�� �л��� �̸� ��

			if (connect == 1) //�����ϰ��� �ϴ� ����� �̸� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� ���� X

				return 0; //0�� ��ȯ�ϸ� �Լ� ����
			}
			else if (connect == 0) //�����ϰ��� �ϴ� ����� �̸� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� ���� X
				temp = temp->next; //temp�� temp�� next�� ����Ŵ
			}
			else if (connect == 2) //�����ϰ��� �ϴ� ����� �̸� ���ڿ��� ũ��
			{
				next = 1; //���� �������� ���� ����

				break; //�ݺ� ����
			}
		}
	}


	if (metric == "dept") //"dept"�� �������� �����ϸ�
	{
		while (temp != NULL) //temp�� NULL�� ������ �ݺ�
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, metric); //�� �л��� �а� ��

			if (connect == 1) //�����ϰ��� �ϴ� ����� �а� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� ���� X
				
				return 0; //0�� ��ȯ�ϸ� �Լ� ����
			}
			else if (connect == 0) //�����ϰ��� �ϴ� ����� �а� ���ڿ��� ������
			{
				next = 0; //���� �������� ���� ���� X
				temp = temp->next; //temp�� temp�� next�� ����Ŵ
				(*move_count)++; //������ Ƚ�� +1
			}
			else if (connect == 2) //�����ϰ��� �ϴ� ����� �а� ���ڿ��� ũ��
			{
				next = 1; //���� �������� ���� ����

				break; //�ݺ� ����
			}
		}
	}
	else
	{	
		if (metric == "gender") //"gender"�� �������� �����ϸ�
		{
			while (temp != NULL && one_node->data.compare_data(one_node->data, temp->data, "dept") == 2) //�� �л��� �а��� ���� ���� �ݺ�
			{
				connect = one_node->data.compare_data(one_node->data, temp->data, metric); //�� �л��� ���� ��

				if (connect == 1) //�����ϰ��� �ϴ� ����� ���� ���ڿ��� ������
				{
					next = 0; //���� �������� ���� ���� X

					return 0; //0�� ��ȯ�ϸ� �Լ� ����
				}
				else if (connect == 0) //�����ϰ��� �ϴ� ����� ���� ���ڿ��� ������
				{
					next = 0; //���� �������� ���� ���� X
					temp = temp->next; //temp�� temp�� next�� ����Ŵ
					(*move_count)++; //������ Ƚ�� +1
				}
				else if (connect == 2) //�����ϰ��� �ϴ� ����� ���� ���ڿ��� ũ��
				{
					next = 1; //���� �������� ���� ����

					break; //�ݺ� ����
				}
			}
		}
		else if (metric == "name") //"name"�� �������� �����ϸ�
		{
			while(temp != NULL && one_node->data.compare_data(one_node->data, temp->data, "dept") == 2 && one_node->data.compare_data(one_node->data, temp->data, "gender") == 2) //temp�� NULL�� ������, �� �л��� �а��� ������ ���� ���� �ݺ�
			{
				connect = one_node->data.compare_data(one_node->data, temp->data, metric); //�� �л��� �̸� ��

				if (connect == 1) //�����ϰ��� �ϴ� ����� �̸� ���ڿ��� ������
				{
					next = 0; //���� �������� ���� ���� X

					return 0; //0�� ��ȯ�ϸ� �Լ� ����
				}
				else if (connect == 0) //�����ϰ��� �ϴ� ����� �̸� ���ڿ��� ������
				{
					next = 0; //���� �������� ���� ���� X
					temp = temp->next; //temp�� temp�� next�� ����Ŵ
					(*move_count)++; //������ Ƚ�� +1
				}
				else if (connect == 2) //�����ϰ��� �ϴ� ����� �̸� ���ڿ��� ũ��
				{
					next = 1; //���� �������� ���� ����

					break; //�ݺ� ����
				}
			}
		}
		else if (metric == "age") //"age"�� �������� �����ϸ�
		{
			while (temp != NULL && one_node->data.compare_data(one_node->data, temp->data, "dept") == 2 && one_node->data.compare_data(one_node->data, temp->data, "gender") == 2 && one_node->data.compare_data(one_node->data, temp->data, "name") == 2) //temp�� NULL�� ������, �� �л��� �а��� ����, �̸��� ���� ���� �ݺ�
			{
				connect = one_node->data.compare_data(one_node->data, temp->data, metric); //�� �л��� ���� ��

				if (connect == 1) //�����ϰ��� �ϴ� ����� ���̰� ������
				{
					next = 0; //���� �������� ���� ���� X

					return 0; //0�� ��ȯ�ϸ� �Լ� ����
				}
				else if (connect == 0) //�����ϰ��� �ϴ� ����� ���̰� ������
				{
					next = 0; //���� �������� ���� ���� X
					temp = temp->next; //temp�� temp�� next�� ����Ŵ
					(*move_count)++; //������ Ƚ�� +1
				}
				else if (connect == 2) //�����ϰ��� �ϴ� ����� ���̰� ũ��
				{
					next = 1; //���� �������� ���� ����

					break; //�ݺ� ����
				}
			}
		}
	}

	if (next == 1) //���� �������� ������ �����ϰ��� �ϸ�
	{
		return -1; //-1�� ��ȯ�ϸ� �Լ� ����
	}

	return 0; //0�� ��ȯ�ϸ� �Լ� ����
}