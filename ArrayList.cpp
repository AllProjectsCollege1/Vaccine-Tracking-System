#include "ArrayList.h"
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
ArrayList<T>::ArrayList(int size)
{
	Size = size;
	count = 0;
	array = new T[size];
}
template <class T>
ArrayList<T>::ArrayList()
{
	count = 0;
	Size = 5;
	array = new T[Size];
}
template <class T >
void ArrayList <T>::RemoveElement(int position)
{
	if (IsEmpty())
	{
		cout << "no elements to remove" << endl;
	}
	else {
		if (position >= 0 && position < count)
			for (int i = position; i < count; i++) {
				array[i] = array[i + 1];
			}

		count--;
	}
}
template <class T>
void ArrayList<T>::insert(int position, T value)
{
	if (IsFull()) {
		Expand();
	}
	else {
		if (position >= 0 && position < count)
			for (int i = count; i > position; i--) {
				array[i] = array[i - 1];
			}
		array[position] = value;
		count++;
	}
}
template <class T >

void ArrayList<T>::append(T value)
{
	if (IsFull())
		Expand();
	array[count] = value;
	count++;
}
template <class T >
T ArrayList<T>::getElementAtposition(int position)
{
	assert(position < count);
	return array[position];
}
template <class T >
int ArrayList<T>::getSize()
{
	if (count == 0)
		return 0;
	else
		return Size;
}
template <class T >
int ArrayList<T>::getcount()
{
	return count;
}
template <class T >
T ArrayList<T>::getarrayList()
{
	return *array;
}
template <class T >
bool ArrayList<T>::IsFull()
{
	return(Size == count);
}
template <class T >
bool ArrayList<T>::IsEmpty()
{
	return (count == 0);
}
template <class T >
void ArrayList<T>::Expand()
{
	int newsize = Size * 2;
	T* newArray = new T[newsize];
	for (int i = 0; i < count; i++) {
		newArray[i] = array[i];
	}
	Size = newsize;
	delete[]array;
	array = newArray;

}
template <class T >
ArrayList<T>::~ArrayList()
{
	delete[]array;
}