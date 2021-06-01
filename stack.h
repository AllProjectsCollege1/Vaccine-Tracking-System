#pragma once
template <class T>
class stack
{
	T* Stack;
	int capacity;
	int elements;
	void expend();
public:
	stack(void);
	stack(int size);
	void push(T newvalue);
	int pop();
	bool isEmpty();
	~stack(void);
};

