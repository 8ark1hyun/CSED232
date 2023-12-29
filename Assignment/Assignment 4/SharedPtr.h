#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>
#include <cassert>

template<typename ObjectType>
void Deallocator(ObjectType* ptr)
{
	std::cout << "Dealloc Object" << std::endl;
	delete ptr;
}

template<typename ObjectType>
void ArrayDeallocator(ObjectType* ptr)
{
	std::cout << "Dealloc Array" << std::endl;
	delete[] ptr;
}

template<typename T>
using DeallocatorFuncType = void (T*);

// SharedPtr
template<typename ObjectType, DeallocatorFuncType<ObjectType> Dealloc = Deallocator<ObjectType> >
class SharedPtr
{
private:
	ObjectType* m_object;
	int* m_ref_counter;

	// ======= ADD CODE HERE IF NEEDED =========
				
public:
	////////////////////////////////////////////
	// Constructors & destructor
	////////////////////////////////////////////
	SharedPtr() //default 생성자
	{
		m_object = nullptr; //객체 nullptr로 초기화
		m_ref_counter = nullptr; //참조 카운트 nullptr로 초기화
	}
	SharedPtr(ObjectType* ptr) //동적 할당된 메모리 영역을 이용하여 SharedPtr 객체를 초기화하는 생성자
	{
		m_object = ptr;
		m_ref_counter = new int(1); //참조 카운트 동적 할당 후 1로 초기화
	}
	SharedPtr(const SharedPtr<ObjectType>& ptr) //같은 타입의 객체를 가리키는 다른 SharedPtr 객체를 이용하여 초기화하는 생성자
	{
		m_object = ptr.m_object;
		m_ref_counter = ptr.m_ref_counter;
		(*m_ref_counter)++; //참조 카운트 +1
	}

	~SharedPtr() //소멸자
	{
		if (m_ref_counter != nullptr) //참조 카운트가 nullptr이 아니면
		{
			(*m_ref_counter)--; //참조 카운트 -1
			if (*m_ref_counter == 0) //참조 카운트가 0이면
			{
				Dealloc(m_object); //객체 동적 할당 해제
				m_ref_counter = nullptr; //참조 카운트 nullptr로 초기화
				delete m_ref_counter; //참조 카운트 동적 할당 해제
			}
		}
	}

	////////////////////////////////////////////
	// Assignment operator
	////////////////////////////////////////////
	SharedPtr<ObjectType>& operator=(const SharedPtr<ObjectType>& ptr) //SharePtr Assignment operator
	{
		if (m_ref_counter != nullptr) //참조 카운트가 nullptr이 아니면
		{
			(*m_ref_counter)--; //참조 카운트 -1
			if (*m_ref_counter == 0) //참조 카운트가 0이면
			{
				Dealloc(m_object); //객체 동적 할당 해제
				m_ref_counter = nullptr; //참조 카운트 nullptr로 초기화
				delete m_ref_counter; //참조 카운트 동적 할당 해제
			}
		}
		m_object = ptr.m_object;
		m_ref_counter = ptr.m_ref_counter;
		if (m_ref_counter != nullptr) //참조 카운트가 nullptr이 아니면
		{
			(*m_ref_counter)++; //참조 카운트 +1
		}

		return *this; //SharedPtr 반환
	}
	
	SharedPtr<ObjectType, ArrayDeallocator<ObjectType> >& operator=(const SharedPtr<ObjectType, ArrayDeallocator<ObjectType> >& ptr) //SharedArray Assignment Operator
	{
		if (m_ref_counter != nullptr) //참조 카운트가 nullptr이 아니면
		{
			(*m_ref_counter)--; //참조 카운트 -1
			if (*m_ref_counter == 0) //참조 카운트가 0이면
			{
				Dealloc(m_object); //객체 동적 할당 해제
				m_ref_counter = nullptr; //참조 카운트 nullptr로 초기화
				delete m_ref_counter; //참조 카운트 동적 할당 해제
			}
		}
		m_object = ptr.m_object;
		m_ref_counter = ptr.m_ref_counter;
		if (m_ref_counter != nullptr) //참조 카운트가 nullptr이 아니면
		{
			(*m_ref_counter)++; //참조 카운트 +1
		}

		return *this; //SharedArray 반환
	}

	////////////////////////////////////////////
	// Pointer operators
	////////////////////////////////////////////
	// operator->
	// operator*
	ObjectType* operator->()
	{
		return m_object; //객체 반환
	}
	const ObjectType* operator->() const
	{
		return m_object; //객체 반환
	}
	ObjectType& operator*()
	{
		return *m_object; //객체 주소 반환
	}
	const ObjectType& operator*() const
	{
		return *m_object; //객체 주소 반환
	}
	
	////////////////////////////////////////////
	// Array element access operators
	////////////////////////////////////////////
	// operator[]
	ObjectType& operator[](int i)
	{
		return m_object[i]; //객체 배열 값 반환
	}
	const ObjectType& operator[](int i) const
	{
		return m_object[i]; //객체 배열 값 반환
	}

	////////////////////////////////////////////
	// Array element access operators
	////////////////////////////////////////////
	// operator[]
	
	////////////////////////////////////////////
	// Type casting operators
	////////////////////////////////////////////
	// operator ObjectType const*() const
	// operator ObjectType*()
	operator ObjectType* ()
	{
		return m_object;
	}
	operator ObjectType const* () const
	{
		return m_object;
	}
};

template<typename T>
using SharedArray = SharedPtr<T, ArrayDeallocator<T> >;

#endif
