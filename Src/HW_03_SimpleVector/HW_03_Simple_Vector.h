#pragma once

#include <algorithm>

int HW_03_SimpleVectorMain();

template <typename T>
class SimpleVector
{
public:
	SimpleVector();
	SimpleVector(int capacity);
	SimpleVector(const SimpleVector& other);
	~SimpleVector();

public:
	void push_back(const T& value);
	void pop_back();
	int size() const;
	int capacity() const;
	void sortData();

	const T& operator [](int Idx)
	{
		return data[Idx];
	}

private:
	void resize(int newCapacity);

private:
	T* data;
	int currentSize;
	int currentCapacity;
};

template <typename T>
SimpleVector<T>::SimpleVector()
{
	constexpr size_t DefaultCapacity = 10;
	data = new T[DefaultCapacity]();
	currentCapacity = 10;
}

template <typename T>
SimpleVector<T>::SimpleVector(int capacity)
{
	data = new T[static_cast<size_t>(capacity)]();
}

template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
{
	// 1. 기존 데이터 삭제
	delete[] data;
	// 2. 현재 배열 크기 확인
	int OtherCapacity = other.capacity();
	if(currentCapacity < OtherCapacity)
	{
		// 2-1. 조정 필요하면 조정
		resize(OtherCapacity);
	}
	// 2-2. 아니면 무시
	// 3. 데이터 복사
	int OtherSize = other.size();
	std::copy(other.data, other.data + OtherSize, data);
	// 4. other의 배열 원소 개수를 현재 배열 원소 개수로 설정
	currentSize = OtherSize;
}

template <typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data;
}

template <typename T>
void SimpleVector<T>::push_back(const T& value)
{
	if(currentSize == currentCapacity)
	{
		resize(currentCapacity + 5);
	}

	data[currentSize++] = value;
}

template <typename T>
void SimpleVector<T>::pop_back()
{
	currentSize--;
}

template <typename T>
int SimpleVector<T>::size() const
{
	return currentSize;
}

template <typename T>
int SimpleVector<T>::capacity() const
{
	return currentCapacity;
}

template <typename T>
void SimpleVector<T>::sortData()
{
	std::sort(data, data + currentSize);
}

template <typename T>
void SimpleVector<T>::resize(int newCapacity)
{
	if(newCapacity < currentCapacity)
	{
		return;
	}

	T* newData = new T[newCapacity]();
	std::copy(data, data+currentSize, newData);

	delete[] data;
	data = newData;
	newData = nullptr;

	currentCapacity = newCapacity;
}