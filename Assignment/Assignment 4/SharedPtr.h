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
	SharedPtr() //default ������
	{
		m_object = nullptr; //��ü nullptr�� �ʱ�ȭ
		m_ref_counter = nullptr; //���� ī��Ʈ nullptr�� �ʱ�ȭ
	}
	SharedPtr(ObjectType* ptr) //���� �Ҵ�� �޸� ������ �̿��Ͽ� SharedPtr ��ü�� �ʱ�ȭ�ϴ� ������
	{
		m_object = ptr;
		m_ref_counter = new int(1); //���� ī��Ʈ ���� �Ҵ� �� 1�� �ʱ�ȭ
	}
	SharedPtr(const SharedPtr<ObjectType>& ptr) //���� Ÿ���� ��ü�� ����Ű�� �ٸ� SharedPtr ��ü�� �̿��Ͽ� �ʱ�ȭ�ϴ� ������
	{
		m_object = ptr.m_object;
		m_ref_counter = ptr.m_ref_counter;
		(*m_ref_counter)++; //���� ī��Ʈ +1
	}

	~SharedPtr() //�Ҹ���
	{
		if (m_ref_counter != nullptr) //���� ī��Ʈ�� nullptr�� �ƴϸ�
		{
			(*m_ref_counter)--; //���� ī��Ʈ -1
			if (*m_ref_counter == 0) //���� ī��Ʈ�� 0�̸�
			{
				Dealloc(m_object); //��ü ���� �Ҵ� ����
				m_ref_counter = nullptr; //���� ī��Ʈ nullptr�� �ʱ�ȭ
				delete m_ref_counter; //���� ī��Ʈ ���� �Ҵ� ����
			}
		}
	}

	////////////////////////////////////////////
	// Assignment operator
	////////////////////////////////////////////
	SharedPtr<ObjectType>& operator=(const SharedPtr<ObjectType>& ptr) //SharePtr Assignment operator
	{
		if (m_ref_counter != nullptr) //���� ī��Ʈ�� nullptr�� �ƴϸ�
		{
			(*m_ref_counter)--; //���� ī��Ʈ -1
			if (*m_ref_counter == 0) //���� ī��Ʈ�� 0�̸�
			{
				Dealloc(m_object); //��ü ���� �Ҵ� ����
				m_ref_counter = nullptr; //���� ī��Ʈ nullptr�� �ʱ�ȭ
				delete m_ref_counter; //���� ī��Ʈ ���� �Ҵ� ����
			}
		}
		m_object = ptr.m_object;
		m_ref_counter = ptr.m_ref_counter;
		if (m_ref_counter != nullptr) //���� ī��Ʈ�� nullptr�� �ƴϸ�
		{
			(*m_ref_counter)++; //���� ī��Ʈ +1
		}

		return *this; //SharedPtr ��ȯ
	}
	
	SharedPtr<ObjectType, ArrayDeallocator<ObjectType> >& operator=(const SharedPtr<ObjectType, ArrayDeallocator<ObjectType> >& ptr) //SharedArray Assignment Operator
	{
		if (m_ref_counter != nullptr) //���� ī��Ʈ�� nullptr�� �ƴϸ�
		{
			(*m_ref_counter)--; //���� ī��Ʈ -1
			if (*m_ref_counter == 0) //���� ī��Ʈ�� 0�̸�
			{
				Dealloc(m_object); //��ü ���� �Ҵ� ����
				m_ref_counter = nullptr; //���� ī��Ʈ nullptr�� �ʱ�ȭ
				delete m_ref_counter; //���� ī��Ʈ ���� �Ҵ� ����
			}
		}
		m_object = ptr.m_object;
		m_ref_counter = ptr.m_ref_counter;
		if (m_ref_counter != nullptr) //���� ī��Ʈ�� nullptr�� �ƴϸ�
		{
			(*m_ref_counter)++; //���� ī��Ʈ +1
		}

		return *this; //SharedArray ��ȯ
	}

	////////////////////////////////////////////
	// Pointer operators
	////////////////////////////////////////////
	// operator->
	// operator*
	ObjectType* operator->()
	{
		return m_object; //��ü ��ȯ
	}
	const ObjectType* operator->() const
	{
		return m_object; //��ü ��ȯ
	}
	ObjectType& operator*()
	{
		return *m_object; //��ü �ּ� ��ȯ
	}
	const ObjectType& operator*() const
	{
		return *m_object; //��ü �ּ� ��ȯ
	}
	
	////////////////////////////////////////////
	// Array element access operators
	////////////////////////////////////////////
	// operator[]
	ObjectType& operator[](int i)
	{
		return m_object[i]; //��ü �迭 �� ��ȯ
	}
	const ObjectType& operator[](int i) const
	{
		return m_object[i]; //��ü �迭 �� ��ȯ
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
