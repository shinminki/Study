#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class BoundCheckTArray {
private:
	T* arr;
	int arrlen;

	BoundCheckTArray(const BoundCheckTArray& ref) {}
	BoundCheckTArray& operator=(const BoundCheckTArray& ref) {}

public:

	BoundCheckTArray(int len);
	T& operator[](int idx);
	T operator[](int idx) const;
	int getArrLen();
	~BoundCheckTArray();
};

template<typename T>
BoundCheckTArray<T>::BoundCheckTArray(int len) : arrlen(len) {
	arr = new T[len];
}

template<typename T>
T& BoundCheckTArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= arrlen)
	{
		cout << "배열의 범위를 벗어남." << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
T BoundCheckTArray<T>::operator[](int idx) const{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "배열의 범위를 벗어남." << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
int BoundCheckTArray<T>::getArrLen() {
	return arrlen;
}

template<typename T>
BoundCheckTArray<T>::~BoundCheckTArray() { delete[]arr; }