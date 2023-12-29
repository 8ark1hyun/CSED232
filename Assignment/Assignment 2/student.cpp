//20220100 PKH

#pragma once

#include <iostream> //header file of the C++ standard library
#include <string> //string library
#include "student.hpp" //"student.hpp" header file
#include "function.hpp" //"function.hpp header file

using namespace std; //Namespace

int student::input_info(student data) //데이터를 입력 받는 함수
{
	int error_value; //에러값

	while (1) //오류가 없을 때까지 반복
	{
		cout << "Dept: "; //학과
		getline(cin, dept); //학과 입력(공백 존재 여부 확인을 위해 getline 활용)

		error_value = -1; //에러값 -1로 설정

		if (dept.size() == 0) //아무것도 입력하지 않으면
		{
			while (dept.size() == 0) //입력할 때까지 반복
			{
				cout << "[Invalid Input] Please enter the student's department." << endl; //오류 메세지 출력
				cout << "Dept: "; //학과
				getline(cin, dept); //학과 입력(공백 존재 여부 확인을 위해 getline 활용)
			}
		}

		for (int i = 0; i < dept.size(); i++) //학과 문자열 처음부터 끝까지 반복하여 오류 확인
		{
			if (dept[i] == ' ') //공백이 있는 경우
			{
				cout << "[Invalid Input] Can't include spaces." << endl; //오류 메세지 출력

				error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정
				if (error_value == 1) //다시 입력을 받는 경우
				{
					break; //반복 종료
				}
				else if (error_value == 0) //메뉴로 돌아가는 경우
				{
					return -1; //메뉴로 돌아감
				}
			}

			if (int(dept[i]) < 65 || int(dept[i]) > 90) //대문자가 아닌 경우
			{
				cout << "[Invalid Input] Only uppercase letters can be entered." << endl; //오류 메세지 출력

				error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정
				if (error_value == 1) //다시 입력을 받는 경우
				{
					break; //반복 종료
				}
				else if (error_value == 0) //메뉴로 돌아가는 경우
				{
					return -1; //메뉴로 돌아감
				}
			}
		}

		if (error_value == 1) //다시 입력을 받는 경우
		{
			continue; //처음부터 반복
		}
		else //제대로 입력 받은 경우
		{
			break; //반복 종료
		}
	}
	data.dept = dept; //학생 데이터 중 학과 정보 저장

	while (1) //오류가 없을 때까지 반복
	{
		cout << "Gender: "; //성별
		getline(cin, gender); //성별 입력(공백 존재 여부 확인을 위해 getline 활용)

		error_value = -1; //에러값 -1로 설정

		if (gender != "M" && gender != "F") //'M' 또는 'F'가 아닌 경우 (오직 M과 F인 경우만 진행되도록 하여 공백 존재 여부 확인 skip)
		{
			cout << "[Invalid Input] Only 'M'(= male) or 'F'(= female) can be entered." << endl; //오류 메세지 출력

			error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정
			if (error_value == 1) //다시 입력을 받는 경우
			{
				continue; //처음부터 반복
			}
			else if (error_value == 0) //메뉴로 돌아가는 경우
			{
				return -1; //메뉴로 돌아감
			}
		}
		else //제대로 입력 받은 경우
		{
			break; //반복 종료
		}
	}
	data.gender = gender; //학생 데이터 중 성별 정보 저장

	while (1)
	{
		cout << "Name: "; //이름
		getline(cin, name); //이름 입력(공백 존재 여부 확인을 위해 getline 활용)

		error_value = -1; //에러값 -1로 설정

		if (name.size() == 0) //아무것도 입력하지 않으면
		{
			while (name.size() == 0) //입력할 때까지 반복
			{
				cout << "[Invalid Input] Please enter the student's name." << endl; //오류 메세지 출력
				cout << "Name: "; //학과
				getline(cin, name); //이름 입력
			}
		}

		for (int i = 0; i < name.size(); i++) //이름 문자열 처음부터 끝까지 반복하여 오류 확인
		{
			if (name[i] == ' ') //공백이 있는 경우
			{
				cout << "[Invalid Input] Can't include spaces." << endl; //오류 메세지 출력
				error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정
				if (error_value == 1) //다시 입력을 받는 경우
				{
					break; //반복 종료
				}
				else if (error_value == 0) //메뉴로 돌아가는 경우
				{
					return -1; //메뉴로 돌아감
				}
			}

			if (!(int(name[i]) >= 65 && int(name[i]) <= 90 || int(name[i]) >= 97 && int(name[i]) <= 122)) //알파벳이 아닌 경우
			{
				cout << "[Invalid Input] Only uppercase letters can be entered." << endl; //오류 메세지 출력

				error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정
				if (error_value == 1) //다시 입력을 받는 경우
				{
					break; //반복 종료
				}
				else if (error_value == 0) //메뉴로 돌아가는 경우
				{
					return -1; //메뉴로 돌아감
				}
			}
		}

		if (error_value == 1) //다시 입력을 받는 경우
		{
			continue; //처음부터 반복
		}
		else //제대로 입력 받은 경우
		{
			break; //반복 종료
		}
	}
	data.name = name; //학생 데이터 중 이름 정보 저장

	while (1)
	{
		cout << "Age: "; //나이

		cin >> age; //나이 입력

		error_value = -1; //에러값 -1로 설정

		if (cin.fail() == 1) //에러 발생 시
		{
			cin.clear(); //cin.fail 초기화
			cin.ignore(); //입력 버퍼 정리
			cout << "[Invalid Input] Only 18 to 30 years of age can be entered." << endl; //오류 메세지 출력

			error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정
			if (error_value == 1) //다시 입력을 받는 경우
			{
				continue; //처음부터 반복
			}
			else if (error_value == 0) //메뉴로 돌아가는 경우
			{
				return -1; //메뉴로 돌아감
			}
		}

		if (age < 18 || age > 30) //18세 미만 30세 초과인 경우
		{
			cout << "[Invalid Input] Only 18 to 30 years of age can be entered." << endl; //오류 메세지 출력
			error_value = print_error(); //다시 입력을 받을지, 메뉴로 돌아갈지 결정
			if (error_value == 1) //다시 입력을 받는 경우
			{
				continue; //처음부터 반복
			}
			else if (error_value == 0) //메뉴로 돌아가는 경우
			{
				return -1; //메뉴로 돌아감
			}
		}
		else //제대로 입력 받은 경우
		{
			break; //반복 종료
		}
	}
	data.age = age; //학생 데이터 중 나이 정보 저장

	return 1; //함수 종료
}

bool student::check_equal(student data1, student data2) //같은 데이터를 가진 학생인지 확인하는 변수
{
	if (data1.dept == data2.dept && data1.gender == data2.gender && data1.name == data2.name && data1.age == data2.age) //두 학생의 데이터가 같으면
	{
		return true; //true 반환
	}
	else //다르면
	{
		return false; //false 반환
	}
}

string student::return_dept(student data) //학생의 학과를 반환하는 함수
{
	return data.dept; //학과 반환
}

int student::return_gender(student data) //학생의 성별을 반환하는 함수
{
	if (data.gender == "F") //여학생인 경우
	{
		return 1; //1 반환
	}
	if (data.gender == "M") //남학생인 경우
	{
		return 0; //0 반환
	}
}

int student::return_age(student data) //학생의 나이를 반한하는 함수
{
	return data.age; //나이 봔한
}

void student::print_data(student& data, string* dept, string* gender, string* name, int* age) //출력을 위해 학생의 데이터를 반환하는 함수
{
	*dept = data.dept; //학과 반환
	*gender = data.gender; //성별 반환
	*name = data.name; //나이 반환
	*age = data.age; //성별 봔한

	return; //종료
}

int student::compare_data(student data1, student data2, string metric) //두 학생의 데이터를 비교하는 함수
{
	int a, b; //두 학생의 학과 문자열 길이 변수
	int length; //문자열 길이 변수

	if (metric == "dept") //"dept"를 입력 받았을 때
	{
		a = data1.dept.size(); //학생1의 학과 문자열 길이
		b = data2.dept.size(); //학생2의 학과 문자열 길이

		length = a < b ? a : b; //더 짧은 길이로 선택

		for (int i = 0; i < length; i++) //길이만큼 반복
		{
			if (int(data1.dept[i]) < int(data2.dept[i])) //문자열이 작으면
			{
				return 1; //1 반환
			}
			else if (int(data1.dept[i]) == int(data2.dept[i])) //문자열이 같으면
			{
				continue; //반복 진행
			}
			else if (int(data1.dept[i]) > int(data2.dept[i])) //문자열이 크면
			{
				return 0; //0 반환
			}
		}

		if (a < b) //학생2의 문자열 길이가 더 긴 경우
		{
			return 1;
		}
		else if (a > b) //학생1의 문자열 길이가 더 긴 경우
		{
			return 0; //0 반환
		}
		else if (a == b) //학생 1과 학생 2의 학과가 같다면
		{
			return 2; //2 반환
		}
	}
	else if (metric == "gender") //"gender"를 입력 받았을 때
	{
		if (data1.gender == "F" && data2.gender == "M") //학생1이 여학생이고, 학생2가 남학생인 경우
		{
			return 1; //1 반환
		}
		else if (data1.gender == data2.gender) //두 학생의 성별이 같은 경우
		{
			return 2; //2 반환
		}
		else if (data1.gender == "M" && data2.gender == "F") //학생1이 남학생이고, 학생2가 여학생인 경우
		{
			return 0; //0 반환
		}
	}
	else if (metric == "name") //"name"를 입력 받았을 때
	{
		a = data1.name.size(); //학생1의 이름 문자열 길이
		b = data2.name.size(); //학생2의 이름 문자열 길이

		length = a < b ? a : b; //더 짧은 길이로 선택

		for (int i = 0; i < length; i++) //길이만큼 반복
		{
			if (int(data1.name[i]) < int(data2.name[i])) //문자열이 작으면
			{
				return 1; //1 반환
			}
			else if (int(data1.name[i]) == int(data2.name[i])) //문자열이 같으면
			{
				continue; //반복 진행
			}
			else if (int(data1.name[i]) > int(data2.name[i])) //문자열이 크면
			{
				return 0; //0 반환
			}
		}

		if (a < b) //학생2의 문자열 길이가 더 긴 경우
		{
			return 1; //1 반환
		}
		else if (a > b) //학생1의 문자열 길이가 더 긴 경우
		{
			return 0; //0 반환
		}
		else if (a == b) ///학생1과 학생2가 이름이 같다면
		{
			return 2; //2 반환
		}

	}
	else if (metric == "age") //"age"를 입력 받았을 때
	{
		if (data1.age < data2.age) //학생2의 나이가 많은 경우
		{
			return 1; //1 반환
		}
		else if (data1.age == data2.age) //두 학생의 나이가 같은 경우
		{
			return 2; //2 반환
		}
		else if (data1.age > data2.age) //학생1의 나이가 많은 경우
		{
			return 0; //0 반환
		}
	}
}