//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "list.hpp" //"list.hpp" header file
#include "function.hpp" //"function.hpp" header file

using namespace std; //Namespace

list::list() //list 생성자
{
	count = 0; //노드 개수 초기화
	dept_cnt = 0; //학과 개수 초기화
	head = NULL; //헤드 초기화
	tail = NULL; //테일 초기화
	for (int i = 0; i < 9; i++)
	{
		dept[i] = "";
		dept_student[i] = 0; //학과 학생 수 초기화
	}
}

list::~list() //list 소멸자
{
	node* temp; //temp 노드

	while (!empty_list()) //빈 리스트가 될 때까지 반복
	{
		temp = head; //temp는 헤드를 가리킴
		head = head->next; //헤드는 헤드의 next를 가리킴
		delete temp; //temp 동적 할당 해제
		count--; //노드 개수 -1
	}
	tail = NULL;
	temp = NULL;
	dept_cnt = 0; //학과 개수 초기화
	for (int i = 0; i < 9; i++)
	{
		dept[i] = "";
		dept_student[i] = 0; //학과 학생 수 초기화
	}
}

bool list::empty_list() const //빈 리스트 확인 함수
{
	return head == NULL; //빈 리스트이면 true 반환
}

void list::insert_node() //노드 삽입 함수
{
	node* new_node = new node; //새 노드 동적 할당
	new_node->next = NULL; //노드의 next 초기화

	if (new_node->data.input_info(new_node->data) == -1) //새 노드의 학생 데이터 입력(반환값이 -1이면 오류 발생 의미)
	{
		delete new_node; //새 노드 동적 할당 해제
		return; //함수 종료
	}

	node* temp = head; //temp는 헤드를 가리킴

	while (temp != NULL) //temp가 NULL일 때까지 반복
	{
		if (new_node->data.check_equal(new_node->data, temp->data) == true) //두 노드의 데이터가 같은지 확인하고, 같은 경우
		{
			cout << "The student already exists" << endl << endl; //이미 존재한다는 메세지 출력

			delete new_node; //새 노드 동적 할당 해제

			return; //함수 종료
		}
		else //다른 경우
		{
			temp = temp->next; //temp는 temp의 next를 가리킴
		}
	}

	string new_node_dept; //새 노드의 학과 문자열 변수
	int dept_num = 0; //학과 번호 변수
	int error_value; //에러값 변수

	new_node_dept = new_node->data.return_dept(new_node->data); //새 노드의 학과 문자열 저장

	for (int i = 0; i < dept_cnt; i++) //이미 존재하는 학과인지 확인
	{
		if (new_node_dept == dept[i]) //이미 존재하는 학과인 경우
		{
			dept_num = i; //학과 번호 저장

			break; //반복 종료
		}
		else //존재하지 않는 학과인 경우
		{
			dept_num = -1; //-1 저장
		}
	}

	error_value = -1; //에러값 -1로 설정

	if (dept_cnt == 0 || dept_num == -1) //존재하지 않는 학과인 경우
	{
		dept_cnt++; //학과 개수 +1

		if (dept_cnt > 9) //학과 최대 개수인 9개를 넘어가는 경우
		{
			cout << "[Invalid Input] Up to 9 departments are possible." << endl; //오류 메세지 출력

			error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정

			if (error_value == 1) //다시 입력을 받는 경우
			{
				dept_cnt--; //학과 개수 -1
				delete new_node; //새 노드 동적 할당 해제

				insert_node(); //노드 삽입 함수 다시 시작

				return; //함수 종료
			}
			else if (error_value == 0) //메뉴로 돌아가는 경우
			{
				dept_cnt--; //학과 개수 -1
				delete new_node; //새 노드 동적 할당 해제

				return; //함수 종료
			}
		}
		else //학과 최대 개수인 9개 이내인 경우
		{
			dept_cnt--; //학과 개수 -1

			if (dept_cnt == 0) //학과 개수가 0개이면
			{
				dept[0] = new_node_dept; //학과 배열 첫 번째에 새 노드 학과 저장
				dept_student[0] = 1; //학과 학생 수 = 1
			}

			for (int i = dept_cnt - 1; i >= 0; i--) //학과 개수만큼 반복(뒤부터 시작)
			{
				int a; //새 노드 학과 문자열 길이 변수
				int b; //기존 학과 문자열 길이 변수
				int length; //문자열 길이 변수
				int k = -1;

				a = new_node_dept.size(); //새 노드의 학과 문자열 길이
				b = dept[i].size(); //기존 학과 문자열 길이

				length = a < b ? a : b; //더 짧은 길이로 선택

				for (int j = 0; j < length; j++) //길이만큼 반복
				{
					if (int(new_node_dept[j]) < int((dept[i])[j])) //문자열이 작으면
					{
						k = 1; //k에 1 저장

						break; //반복 종료
					}
					else if (int(new_node_dept[j]) == int((dept[i])[j])) //문자열이 같으면
					{
						continue; //반복 진행
					}
					else if (int(new_node_dept[j]) > int((dept[i])[j])) //문자열이 크면
					{
						k = 0; //k에 0 저장

						break; //반복 종료
					}
				}

				if (k == 0) //k가 0이면
				{
					dept[i+1] = new_node_dept; //학과 배열 알맞은 위치에 새 노드 학과 저장
					dept_student[i+1] = 1; //학과 학생 수 = 1

					break; //반복 종료
				}
				else if (k == 1) //k가 1이면
				{
					dept[i+1] = dept[i]; //학과 배열 알맞은 위치로 이동
					dept_student[i+1] = dept_student[i]; //학과 학생 수 배열 알맞은 위치로 이동
					dept[i] = new_node_dept; //학과 배열 알맞은 위치에 새 노드 학과 저장
					dept_student[i] = 1; //학과 학생 수 = 1

					continue; //반복 진행
				}
			}

			dept_cnt++; //학과 개수 +1
		}
	}
	else //이미 존재하는 학과인 경우
	{
		dept_student[dept_num]++; //학과 학생 수 +1

		if (dept_student[dept_num] > 10000) //학과 내 최대 학생 수인 10000명을 넘어가는 경우
		{
			cout << "[Invalid Input] Up to 10000 students per department can be entered." << endl; //오류 메세지 출력

			error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정

			if (error_value == 1) //다시 입력을 받는 경우
			{
				dept_student[dept_num]--; //학과 학생 수 -1
				delete new_node; //새 노드 동적 할당 해제

				insert_node(); //노드 삽입 함수 다시 시작

				return; //함수 종료
			}
			else if (error_value == 0) //메뉴로 돌아가는 경우
			{
				dept_student[dept_num]--; //학과 학생 수 -1
				delete new_node; //새 노드 동적 할당 해제

				return; //함수 종료
			}
		}
	}

	if (empty_list()) //빈 리스트이면
	{
		head = new_node; //새 노드를 헤드로 지정
		tail = new_node; //새 노드를 테일로 지정
		count++; //노드 개수 +1
		cout << "A student is added in table!" << endl << endl; //학생 저장 메세지 출력

		return; //함수 종료
	}

	int move_count = 0; //움직일 횟수 변수

	if (sort(&move_count, new_node, "dept") == -1) //학과를 기준으로 정렬(반환값이 -1이면 다음 기준으로 정렬)
	{
		if (sort(&move_count, new_node, "gender") == -1) //성별을 기준으로 정렬(반환값이 -1이면 다음 기준으로 정렬)
		{
			if (sort(&move_count, new_node, "name") == -1) //이름을 기준으로 정렬(반환값이 -1이면 다음 기준으로 정렬)
			{
				if (sort(&move_count, new_node, "age") == -1) //나이를 기준으로 정렬
				{
					move_count == 0; //움직일 횟수 = 0
				}
			}
		}
	}

	node* pcur; //현재 노드를 가리키는 포인터
	pcur = head; //현재 노드는 헤드를 가리킴

	if (move_count == 0) //움직일 횟수가 0이면
	{
		new_node->next = head; //새 노드의 next는 헤드를 가리킴
		head = new_node; //새 노드를 헤드로 지정
	}
	else //움직일 횟수가 0이 아니면
	{
		for (int i = 0; i < move_count - 1; i++) //움직일 횟수 - 1 만큼 반복
		{
			pcur = pcur->next; //현재 노드는 현재 노드의 next를 가리킴
		}
		if (pcur == tail) //현재 노드가 tail을 가리키면
		{
			pcur->next = new_node; //현재 노드의 next는 새 노드를 가리킴
			tail = new_node; //새 노드를 테일로 지정
		}
		else //그렇지 않으면
		{
			new_node->next = pcur->next; //새 노드의 next는 현재 노드의 next를 가리킴
			pcur->next = new_node; //현재 노드의 next는 새 노드를 가리킴
		}
	}

	count++; //노드 개수 +1

	cout << "A student is added in table!" << endl << endl; //학생 저장 메세지 출력

	return; //함수 종료
}

void list::delete_node() //노드 삭제 함수
{
	node* del_node = new node; //삭제할 노드 동적 할당

	int delete_check = 0; //삭제 여부 확인 변수

	if ((del_node->data.input_info(del_node->data)) == -1) //삭제할 학생 데이터 입력(반환값이 -1이면 오류 발생 의미)
	{
		delete del_node; //삭제할 노드 동적 할당 해제

		return; //함수 종료
	}
	if (empty_list()) //빈 리스트이면
	{
		cout << "Can't Delete it" << endl << endl; //삭제 불가 메세지 출력

		delete del_node; //삭제할 노드 동적 할당 해제

		return; //함수 종료
	}

	node* ppre; //이전 노드를 가리키는 포인터
	node* pcur; //현재 노드를 가리키는 포인터
	ppre = head; //이전 노드는 헤드를 가리킴
	pcur = ppre->next; //현재 노드는 이전 노드의 next를 가리킴

	if (del_node->data.check_equal(del_node->data, ppre->data) == true) //두 노드의 데이터가 같은지 확인하고, 같은 경우
	{
		cout << "Deleted!" << endl << endl; //삭제 완료 메세지 출력

		delete ppre; //이전 노드 동적 할당 해제
		head = pcur; //현재 노드를 헤드로 지정
		count--; //노드 개수 -1

		delete_check = 1; //삭제 여부 1로 지정
	}
	else //다른 경우
	{
		while (pcur != NULL) //현재 노드가 NULL일 때까지 반복
		{
			if (del_node->data.check_equal(del_node->data, pcur->data) == true) //두 노드의 데이터가 같은지 확인하고, 같은 경우
			{
				if (pcur == tail) //현재 노드가 테일을 가리키면
				{
					cout << "Deleted!" << endl << endl; //삭제 완료 메세지 출력

					tail = ppre; //이전 노드를 테일로 지정
					ppre->next = NULL; //이전 노드의 next 초기화
					delete pcur; //현재 노드 동적 할당 해제
					count--; //노드 개수 -1

					delete_check = 1; //삭제 여부 1로 지정
					
					break; //반복 종료
				}
				else //그렇지 않으면
				{
					cout << "Deleted!" << endl << endl; //삭제 완료 메세지 출력

					ppre->next = pcur->next; //이전 노드의 next는 현재 노드의 next를 가리킴
					delete pcur; //현재 노드 동적 할당 해제
					count--; //노드 개수 -1

					delete_check = 1; //삭제 여부 1로 지정
					
					break; //반복 종료
				}
			}
			else //다른 경우
			{
				ppre = pcur; //이전 노드는 현재 노드를 가라킴
				pcur = pcur->next; //현재 노드는 현재 노드의 next를 가리킴
			}
		}
	}

	string del_dept; //삭제할 학과 문자열 변수
	int dept_num = 0; //삭제할 학과 번호 변수
	int a = 0;

	del_dept = del_node->data.return_dept(del_node->data); //삭제할 학과 문자열 저장

	if (delete_check != 1) //삭제 여부가 1이 아니면
	{
		cout << "Can't Delete it" << endl << endl; //삭제 불가 메세지 출력

		delete del_node; //삭제할 노드 동적 할당 해제

		return; //함수 종료
	}
	else //삭제 여부가 1이면
	{
		for (int i = 0; i < dept_cnt; i++) //학과 개수만큼 반복
		{
			if (del_dept == dept[i]) //삭제할 학과 문자열이 학과 문자열과 같으면
			{
				dept_num = i; //학과 번호 저장

				break; //반복 종료
			}
		}

		if (dept_student[dept_num] == 1) //삭제할 학과 학생 수가 1명이면
		{
			for (int i = 0; i < dept_cnt - dept_num - 1; i++) //학과 개수 - 학과 번호 - 1 만큼 반복
			{
				dept[dept_num + i] = dept[dept_num + i + 1]; //학과 배열 알맞은 위치로 이동
				dept_student[dept_num + i] = dept_student[dept_num + i + 1]; //학과 학생 수 배열 알맞은 위치로 이동
			}
			dept_cnt--; //학과 개수 -1
			dept_student[dept_cnt] = 0; //학과 학생 수 = 0
		}
		else //그렇지 않으면
		{
			dept_student[dept_num]--; //학과 학생 수 -1
		}

		delete del_node; //삭제할 노드 동적 할당 해제

		return; //함수 종료
	}
}

void list::print_node() //노드 출력 함수
{
	node* temp; //temp 노드
	temp = head; //temp는 헤드를 가리킴

	string print_dept, print_gender, print_name; //출력할 학과 문자열, 출력할 성별 문자열, 출력할 이름 문자열 변수
	int print_age; //출력할 나이 변수

	if (empty_list()) //빈 리스트이면
	{
		cout << "Empty list" << endl << endl; //빈 리스트 메세지 출력

		return; //함수 종료
	}

	cout << "Dept" << '\t' << "Gender" << '\t' << "Name" << '\t' << "Age" << endl; //첫 번째 행 출력

	for (int i = 0; i < count; i++) //노드 개수만큼 반복
	{
		temp->data.print_data(temp->data, &print_dept, &print_gender, &print_name, &print_age); //출력할 학생 데이터 저장
		cout << print_dept << '\t' << print_gender << '\t' << print_name << '\t' << print_age << endl; //순서대로 출력
		temp = temp->next; //temp는 temp의 next를 가리킴
	}

	cout << endl;

	return; //함수 종료
}

void list::print_pivot_node(string category, string function) //pivot 노드 출력 함수
{
	int sum = 0; //나이 총합 변수
	int k = 0;
	int max_or_min = 0; //나이 최댓값 또는 최솟값 저장 변수
	float value = 0; //나이 평균 변수
	int woman_value = 0; //여자 나이 관련 변수
	int woman_count = 0; //여자 명수 변수
	int man_value = 0; //남자 나이 관련 변수
	int man_count = 0; //남자 명수 변수

	node* temp; //temp 노드
	temp = head; //temp는 헤드를 가리킴

	if (category == "1") //카테고리 옵션이 1번이면
	{
		if (function == "1") //함수 옵션이 1번이면
		{
			cout << "Dept" << '\t' << "Average" << endl; //첫 번째 행 출력

			for (int i = 0; i < dept_cnt; i++) //학과 개수만큼 반복
			{
				sum = 0; //나이 총합 초기화

				cout << dept[i] << '\t'; //학과 출력

				for (int j = 0; j < dept_student[i]; j++) //학과 학생 수만큼 반복
				{
					sum += temp->data.return_age(temp->data); //나이 총합 계산
					temp = temp->next; //temp는 temp의 next를 가리킴
				}

				value = float(sum) / float(dept_student[i]); //나이 평균 계산

				if (value - int(value) != 0) //정수가 아니면
				{
					cout << fixed; //소수점 아래 자릿수 고정
					cout.precision(1); //1자리로 고정
				}
				else //정수이면
				{
					cout << fixed; //소수점 아래 자릿수 고정
					cout.precision(0); //소수점 아래 출력 X
				}

				cout << value << endl; //나이 평균 출력
			}

			cout << endl;
		}
		else if (function == "2") //함수 옵션이 2번이면
		{
			cout << "Dept" << '\t' << "Max" << endl; //첫 번째 행 출력

			for (int i = 0; i < dept_cnt; i++) //학과 개수만큼 반복
			{
				max_or_min = 0; //나이 최댓값 초기화

				cout << dept[i] << '\t'; //학과 출력

				for (int j = 0; j < dept_student[i]; j++) //학과 학생 수만큼 반복
				{
					k = temp->data.return_age(temp->data); //학생 나이 저장

					if (max_or_min < k) //기존 최댓값보다 크면
					{
						max_or_min = k; //최댓값 저장
					}

					temp = temp->next; //temp는 temp의 next를 가리킴
				}

				cout << max_or_min << endl; //나이 최댓값 출력
			}

			cout << endl;
		}
		else if (function == "3") //함수 옵션이 3번이면
		{
			cout << "Dept" << '\t' << "Min" << endl; //첫 번째 행 출력

			for (int i = 0; i < dept_cnt; i++) //학과 개수만큼 반복
			{
				max_or_min = 100; //나이 최솟값 초기화

				cout << dept[i] << '\t'; //학과 출력

				for (int j = 0; j < dept_student[i]; j++) //학과 학생 수만큼 반복
				{
					k = temp->data.return_age(temp->data); //학생 나이 저장

					if (max_or_min > k) //기존 최솟값보다 작으면
					{
						max_or_min = k; //최솟값 저장
					}

					temp = temp->next; //temp는 temp의 next를 가리킴
				}

				cout << max_or_min << endl; //나이 최솟값 출력
			}

			cout << endl;
		}
	}
	else if (category == "2") //카테고리 옵션이 2번이면
	{
		if (function == "1") //함수 옵션이 1번이면
		{
			cout << "Gender" << '\t' << "Average" << endl; //첫 번째 행 출력

			for (int i = 0; i < count; i++) //노드 개수만큼 반복
			{
				if (temp->data.return_gender(temp->data) == 1) //여자이면
				{
					woman_value += temp->data.return_age(temp->data); //여자 나이 총합 계산
					woman_count++; //여자 명수 +1
					temp = temp->next; //temp는 temp의 next를 가리킴
				}
				else //남자이면
				{
					man_value += temp->data.return_age(temp->data); //남자 나이 총합 계산
					man_count++; //남자 명수 +1
					temp = temp->next; //temp는 temp의 next를 가리킴
				}
			}

			if (woman_count != 0) //여자가 0명이 아니면
			{
				value = float(woman_value) / float(woman_count); //여자 나이 평균 계산
			}
			else //여자가 0명이면
			{
				value = 0; //여자 나이 평균 = 0
			}

			if (value - int(value) != 0) //정수가 아니면
			{
				cout << fixed; //소수점 아래 자릿수 고정
				cout.precision(1); //1자리로 고정
			}
			else //정수이면
			{
				cout << fixed; //소수점 아래 자릿수 고정
				cout.precision(0); //소수점 아래 출력 X
			}

			if (value != 0) //여자 나이 평균이 0이 아니면(여자가 0명이 아니면)
			{
				cout << "F" << '\t' << value << endl; //성별, 나이 평균 출력
			}

			if (man_count != 0) //남자가 0명이 아니면
			{
				value = float(man_value) / float(man_count); //남자 나이 평균 계산
			}
			else //남자가 0명이면
			{
				value = 0; //남자 나이 평균 = 0
			}

			if (value - int(value) != 0) //정수가 아니면
			{
				cout << fixed; //소수점 아래 자릿수 고정
				cout.precision(1); //1자리로 고정
			}
			else //정수이면
			{
				cout << fixed; //소수점 아래 자릿수 고정
				cout.precision(0); //소수점 아래 출력 X
			}

			if (value != 0) //남자 나이 평균이 0이 아니면(남자가 0명이 아니면)
			{
				cout << "M" << '\t' << value << endl; //성별, 나이 평균 출력
			}

			cout << endl;
		}
		else if (function == "2") //함수 옵션이 2번이면
		{
			cout << "Gender" << '\t' << "Max" << endl; //첫 번째 행 출력

			woman_value = 0; //여자 나이 최댓값 초기화
			man_value = 0; //남자 나이 최댓값 초기화

			for (int i = 0; i < count; i++) //노드 개수만큼 반복
			{
				if (temp->data.return_gender(temp->data) == 1) //여자이면
				{
					k = temp->data.return_age(temp->data); //학생 나이 저장

					if (woman_value < k) //기존 최댓값보다 크면
					{
						woman_value = k; //최댓값 저장
					}

					temp = temp->next; //temp는 temp의 next를 가리킴
				}
				else //남자이면
				{
					k = temp->data.return_age(temp->data); //학생 나이 저장

					if (man_value < k) //기존 최댓값보다 크면
					{
						man_value = k; //최댓값 저장
					}

					temp = temp->next; //temp는 temp의 next를 가리킴
				}
			}

			if (woman_value != 0) //여자 나이 최댓값이 0이 아니면(여자가 0명이 아니면)
			{
				cout << "F" << '\t' << woman_value << endl; //성별, 나이 최댓값 출력
			}

			if (man_value != 0) //남자 나이 최댓값이 0이 아니면(남자가 0명이 아니면)
			{
				cout << "M" << '\t' << man_value << endl; //성별, 나이 최댓값 출력
			}

			cout << endl;
		}
		else if (function == "3") //함수 옵션이 3번이면
		{
			cout << "Gender" << '\t' << "Min" << endl; //첫 번째 행 출력

			woman_value = 100; //여자 나이 최솟값 초기화
			man_value = 100; //남자 나이 최솟값 초기화

			for (int i = 0; i < count; i++) //노드 개수만큼 반복
			{
				if (temp->data.return_gender(temp->data) == 1) //여자이면
				{
					k = temp->data.return_age(temp->data); //학생 나이 저장

					if (woman_value > k) //기존 최솟값보다 작으면
					{
						woman_value = k; //최솟값 저장
					}

					temp = temp->next; //temp는 temp의 next를 가리킴
				}
				else //남자이면
				{
					k = temp->data.return_age(temp->data); //학생 나이 저장

					if (man_value > k) //기존 최솟값보다 작으면
					{
						man_value = k; //최솟값 저장
					}

					temp = temp->next; //temp는 temp의 next를 가리킴
				}
			}

			if (woman_value != 100) //여자 나이 최솟값이 100이 아니면(여자가 0명이 아니면)
			{
				cout << "F" << '\t' << woman_value << endl; //성별, 나이 최솟값 출력
			}

			if (man_value != 100) //남자 나이 최솟값이 100이 아니면(남자가 0명이 아니면)
			{
				cout << "M" << '\t' << man_value << endl; //성별, 나이 최솟값 출력
			}

			cout << endl;
		}
	}
	else if (category == "3") //카테고리 옵션이 3번이면
	{
		if (function == "1") //함수 옵션이 1번이면
		{
			cout << "Dept" << '\t' << "Gender" << '\t' << "Average" << endl; //첫 번째 행 출력

			for (int i = 0; i < dept_cnt; i++) //학과 개수만큼 반복
			{
				woman_value = 0; //여자 나이 총합 초기화
				man_value = 0; //남자 나이 총합 초기화
				woman_count = 0; //여자 명수 초기화
				man_count = 0; //남자 명수 초기화

				for (int j = 0; j < dept_student[i]; j++) //학과 학생 수만큼 반복
				{
					if (temp->data.return_gender(temp->data) == 1) //여자이면
					{
						woman_value += temp->data.return_age(temp->data); //여자 나이 총합 계산
						woman_count++; //여자 명수 +1
						temp = temp->next; //temp는 temp의 next를 가리킴
					}
					else //남자이면
					{
						man_value += temp->data.return_age(temp->data); //남자 나이 총합 계산
						man_count++; //남자 명수 +1
						temp = temp->next; //temp는 temp의 next를 가리킴
					}
				}

				if (woman_count != 0) //여자가 0명이 아니면
				{
					value = float(woman_value) / float(woman_count); //여자 나이 평균 계산
				}
				else //여자가 0명이면
				{
					value = 0; //여자 나이 평균 = 0
				}

				if (value - int(value) != 0) //정수가 아니면
				{
					cout << fixed; //소수점 아래 자릿수 고정
					cout.precision(1); //1자리로 고정
				}
				else //정수이면
				{
					cout << fixed; //소수점 아래 자릿수 고정
					cout.precision(0); //1자리로 고정
				}

				if (value != 0) //여자 나이 평균이 0이 아니면(여자가 0명이 아니면)
				{
					cout << dept[i] << '\t' << "F" << '\t' << value << endl; //학과, 성별, 나이 평균 출력
				}

				if (man_count != 0) //남자가 0명이 아니면
				{
					value = float(man_value) / float(man_count); //남자 나이 평균 계산
				}
				else //남자가 0명이면
				{
					value = 0; //남자 나이 평균 = 0
				}

				if (value - int(value) != 0) //정수가 아니면
				{
					cout << fixed; //소수점 아래 자릿수 고정
					cout.precision(1); //1자리로 고정
				}
				else //정수이면
				{
					cout << fixed; //소수점 아래 자릿수 고정
					cout.precision(0); //1자리로 고정
				}

				if (value != 0) //남자 나이 평균이 0이 아니면(남자가 0명이 아니면)
				{
					cout << dept[i] << '\t' << "M" << '\t' << value << endl; //학과, 성별, 나이 평균 출력
				}
			}

			cout << endl;
		}
		else if (function == "2") //함수 옵션이 2번이면
		{
			cout << "Dept" << '\t' << "Gender" << '\t' << "Max" << endl; //첫 번째 행 출력

			for (int i = 0; i < dept_cnt; i++) //학과 개수만큼 반복
			{
				woman_value = 0; //여자 나이 최댓값 초기화
				man_value = 0; //남자 나이 최댓값 초기화

				for (int j = 0; j < dept_student[i]; j++) //학과 학생 수만큼 반복
				{
					if (temp->data.return_gender(temp->data) == 1) //여자이면
					{
						k = temp->data.return_age(temp->data); //학생 나이 저장

						if (woman_value < k) //기존 최댓값보다 크면
						{
							woman_value = k; //최댓값 저장
						}

						temp = temp->next; //temp는 temp의 next를 가리킴
					}
					else //남자이면
					{
						k = temp->data.return_age(temp->data); //학생 나이 저장

						if (man_value < k) //기존 최댓값보다 크면
						{
							man_value = k; //최댓값 저장
						}

						temp = temp->next; //temp는 temp의 next를 가리킴
					}
				}

				if (woman_value != 0) //여자 나이 최댓값이 0이 아니면(여자가 0명이 아니면)
				{
					cout << dept[i] << '\t' << "F" << '\t' << woman_value << endl; //학과, 성별, 나이 최댓값 출력
				}

				if (man_value != 0) //남자 나이 최댓값이 0이 아니면(남자가 0명이 아니면)
				{
					cout << dept[i] << '\t' << "M" << '\t' << man_value << endl; //학과, 성별, 나이 최댓값 출력
				}
			}

			cout << endl;
		}
		else if (function == "3") //함수 옵션이 3번이면
		{
			cout << "Dept" << '\t' << "Gender" << '\t' << "Min" << endl; //첫 번째 행 출력

			for (int i = 0; i < dept_cnt; i++) //학과 개수만큼 반복
			{
				woman_value = 100; //여자 나이 최솟값 초기화
				man_value = 100; //남자 나이 최솟값 초기화

				for (int j = 0; j < dept_student[i]; j++) //학과 학생 수만큼 반복
				{
					if (temp->data.return_gender(temp->data) == 1) //여자이면
					{
						k = temp->data.return_age(temp->data); //학생 나이 저장

						if (woman_value > k) //기존 최솟값보다 작으면
						{
							woman_value = k; //최솟값 저장
						}

						temp = temp->next; //temp는 temp의 next를 가리킴
					}
					else //남자이면
					{
						k = temp->data.return_age(temp->data); //학생 나이 저장

						if (man_value > k) //기존 최솟값보다 작으면
						{
							man_value = k; //최솟값 저장
						}

						temp = temp->next; //temp는 temp의 next를 가리킴
					}
				}

				if (woman_value != 100) //여자 나이 최솟값이 100이 아니면(여자가 0명이 아니면)
				{
					cout << dept[i] << '\t' << "F" << '\t' << woman_value << endl; //학과, 성별, 나이 최솟값 출력
				}

				if (man_value != 100) //남자 나이 최솟값이 100이 아니면(남자가 0명이 아니면)
				{
					cout << dept[i] << '\t' << "M" << '\t' << man_value << endl; //학과, 성별, 나이 최솟값 출력
				}
			}

			cout << endl;
		}
	}
}

int list::sort(int* move_count, node* one_node, string metric) //노드 정렬 함수
{
	int connect; //연결 여부 변수
	int next = 0; //다음 기준으로 정렬 진행 여부 변수

	node* temp; //temp 노드
	temp = head; //temp는 헤드를 가리킴

	if (metric == "gender") //"gender"를 기준으로 정렬하면
	{
		while (temp != NULL) //temp가 NULL일 때까지 반복
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, "dept"); //두 학생의 학과 비교

			if (connect == 1) //삽입하고자 하는 노드의 학과 문자열이 작으면
			{
				next = 0; //다음 기준으로 정렬 진행 X

				return 0; //0을 반환하며 함수 종료
			}
			else if (connect == 0) //삽입하고자 하는 노드의 학과 문자열이 같으면
			{
				next = 0; //다음 기준으로 정렬 진행 X
				temp = temp->next; //temp는 temp의 next를 가리킴
			}
			else if (connect == 2) //삽입하고자 하는 노드의 학과 문자열이 크면
			{
				next = 1; //다음 기준으로 정렬 진행

				break; //반복 종료
			}
		}
	}
	else if (metric == "name") //"name"를 기준으로 정렬하면
	{
		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 0) //두 학생의 학과가 같아질 때까지 반복
		{
			temp = temp->next; //temp는 temp의 next를 가리킴
		}

		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 2) //두 학생의 학과가 같은 동안 반복
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, "gender"); //두 학생의 성별 비교

			if (connect == 1) //삽입하고자 하는 노드의 성별 문자열이 작으면
			{
				next = 0; //다음 기준으로 정렬 X

				return 0; //0을 반환하며 함수 종료
			}
			else if (connect == 0) //삽입하고자 하는 노드의 성별 문자열이 같으면
			{
				next = 0; //다음 기준으로 정렬 X
				temp = temp->next; //temp는 temp의 next를 가리킴
			}
			else if (connect == 2) //삽입하고자 하는 노드의 성별 문자열이 크면
			{
				next = 1; //다음 기준으로 정렬

				break; //반복 종료
			}
		}
	}
	else if (metric == "age") //"age"를 기준으로 정렬하면
	{
		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 0) //두 학생의 학과가 같아질 때까지 반복
		{
			temp = temp->next; //temp는 temp의 next를 가리킴
		}

		while (one_node->data.compare_data(one_node->data, temp->data, "gender") == 0) //두 학생의 성별이 같아질 때까지 반복
		{
			temp = temp->next; //temp는 temp의 next를 가리킴
		}

		while (one_node->data.compare_data(one_node->data, temp->data, "dept") == 2 && one_node->data.compare_data(one_node->data, temp->data, "gender") == 2) //두 학생의 학과와 성별이 같은 동안 반복
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, "name"); //두 학생의 이름 비교

			if (connect == 1) //삽입하고자 하는 노드의 이름 문자열이 작으면
			{
				next = 0; //다음 기준으로 정렬 진행 X

				return 0; //0을 반환하며 함수 종료
			}
			else if (connect == 0) //삽입하고자 하는 노드의 이름 문자열이 같으면
			{
				next = 0; //다음 기준으로 정렬 진행 X
				temp = temp->next; //temp는 temp의 next를 가리킴
			}
			else if (connect == 2) //삽입하고자 하는 노드의 이름 문자열이 크면
			{
				next = 1; //다음 기준으로 정렬 진행

				break; //반복 종료
			}
		}
	}


	if (metric == "dept") //"dept"를 기준으로 정렬하면
	{
		while (temp != NULL) //temp가 NULL일 때까지 반복
		{
			connect = one_node->data.compare_data(one_node->data, temp->data, metric); //두 학생의 학과 비교

			if (connect == 1) //삽입하고자 하는 노드의 학과 문자열이 작으면
			{
				next = 0; //다음 기준으로 정렬 진행 X
				
				return 0; //0을 반환하며 함수 종료
			}
			else if (connect == 0) //삽입하고자 하는 노드의 학과 문자열이 같으면
			{
				next = 0; //다음 기준으로 정렬 진행 X
				temp = temp->next; //temp는 temp의 next를 가리킴
				(*move_count)++; //움직일 횟수 +1
			}
			else if (connect == 2) //삽입하고자 하는 노드의 학과 문자열이 크면
			{
				next = 1; //다음 기준으로 정렬 진행

				break; //반복 종료
			}
		}
	}
	else
	{	
		if (metric == "gender") //"gender"를 기준으로 정렬하면
		{
			while (temp != NULL && one_node->data.compare_data(one_node->data, temp->data, "dept") == 2) //두 학생의 학과가 같은 동안 반복
			{
				connect = one_node->data.compare_data(one_node->data, temp->data, metric); //두 학생의 성별 비교

				if (connect == 1) //삽입하고자 하는 노드의 성별 문자열이 작으면
				{
					next = 0; //다음 기준으로 정렬 진행 X

					return 0; //0을 반환하며 함수 종료
				}
				else if (connect == 0) //삽입하고자 하는 노드의 성별 문자열이 같으면
				{
					next = 0; //다음 기준으로 정렬 진행 X
					temp = temp->next; //temp는 temp의 next를 가리킴
					(*move_count)++; //움직일 횟수 +1
				}
				else if (connect == 2) //삽입하고자 하는 노드의 성별 문자열이 크면
				{
					next = 1; //다음 기준으로 정렬 진행

					break; //반복 종료
				}
			}
		}
		else if (metric == "name") //"name"를 기준으로 정렬하면
		{
			while(temp != NULL && one_node->data.compare_data(one_node->data, temp->data, "dept") == 2 && one_node->data.compare_data(one_node->data, temp->data, "gender") == 2) //temp가 NULL일 때까지, 두 학생의 학과와 성별이 같은 동안 반복
			{
				connect = one_node->data.compare_data(one_node->data, temp->data, metric); //두 학생의 이름 비교

				if (connect == 1) //삽입하고자 하는 노드의 이름 문자열이 작으면
				{
					next = 0; //다음 기준으로 정렬 진행 X

					return 0; //0을 반환하며 함수 종료
				}
				else if (connect == 0) //삽입하고자 하는 노드의 이름 문자열이 같으면
				{
					next = 0; //다음 기준으로 정렬 진행 X
					temp = temp->next; //temp는 temp의 next를 가리킴
					(*move_count)++; //움직일 횟수 +1
				}
				else if (connect == 2) //삽입하고자 하는 노드의 이름 문자열이 크면
				{
					next = 1; //다음 기준으로 정렬 진행

					break; //반복 종료
				}
			}
		}
		else if (metric == "age") //"age"를 기준으로 정렬하면
		{
			while (temp != NULL && one_node->data.compare_data(one_node->data, temp->data, "dept") == 2 && one_node->data.compare_data(one_node->data, temp->data, "gender") == 2 && one_node->data.compare_data(one_node->data, temp->data, "name") == 2) //temp가 NULL일 때까지, 두 학생의 학과와 성별, 이름이 같은 동안 반복
			{
				connect = one_node->data.compare_data(one_node->data, temp->data, metric); //두 학생의 나이 비교

				if (connect == 1) //삽입하고자 하는 노드의 나이가 작으면
				{
					next = 0; //다음 기준으로 정렬 진행 X

					return 0; //0을 반환하며 함수 종료
				}
				else if (connect == 0) //삽입하고자 하는 노드의 나이가 같으면
				{
					next = 0; //다음 기준으로 정렬 진행 X
					temp = temp->next; //temp는 temp의 next를 가리킴
					(*move_count)++; //움직일 횟수 +1
				}
				else if (connect == 2) //삽입하고자 하는 노드의 나이가 크면
				{
					next = 1; //다음 기준으로 정렬 진행

					break; //반복 종료
				}
			}
		}
	}

	if (next == 1) //다음 기준으로 정렬을 진행하고자 하면
	{
		return -1; //-1을 반환하며 함수 종료
	}

	return 0; //0을 반환하며 함수 종료
}