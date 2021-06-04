#pragma once
template <class T>
class ArrayList
{
	int Size;
	int count;
	T* array;
	void Expand();
public:
	ArrayList();
	ArrayList(int size);
	void deleteAllElements();
	void RemoveElement(int position);
	void insert(int position, T value);
	void append(T value);
	T getElementAtposition(int pos);
	int getSize();
	int getcount();
	T getarrayList();
	bool IsFull();
	bool IsEmpty();
	~ArrayList();
};