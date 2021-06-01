#include "stack.h"

template<class T>
stack<T>::stack(void)
{
	elements = 0;
	capacity = 10;
	stack = new T[capacity];

}
template<class T>
stack<T>::stack(int size)
{
	elements = 0;
	capacity = size;
	stack = new T[capacity];
}
template<class T>
void stack <T>::push(T newvalue)
{
	if (capacity == elements)
	{
		expend();
	}
	stack[elements] = newvalue;
	elements++;
}

template<class T>
int stack <T>::pop()
{
	elements--;
	int temp = stack[elements];
	return temp;
}

template<class T>
void stack <T>::expend()
{
	int* newstack = new int[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		newstack[i] = stack[i];
	}
	capacity *= 2;
	delete[] stack;
	stack = newstack;
}