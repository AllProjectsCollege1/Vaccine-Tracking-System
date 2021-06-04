#include "Queues.h"
#include<assert.h>
template<class T>
Queues<T>::Queues(int size)
{
	elements = 0;
	capacity = size;
	a = new T[capacity];
	front = -1;
	back = -1;
}
template<class T>
int Queues<T>::lenght()
{
	return elements;
}
template<class T>
bool Queues<T>::empty()
{
	return (elements == 0);
}

template<class T>
void Queues<T>::enqueue(T val)
{
	assert(!isFull());
	if (elements == 0)
		front = 0;
	back = (back + 1) % capacity;
	a[back] = val;
	elements++;

}
template<class T>
void Queues<T>::dequeue() {
	assert(!empty());
	if (elements == 1)
		front = back = -1;
	else
		front = (front + 1) % capacity;
	elements--;
}
template<class T>
T Queues<T>::Front() {
	assert(!empty());
	return a[front];
}

template<class T>
bool Queues<T>::isFull() {
	return (elements == capacity);
}

template<class T>
Queues<T>::~Queues() {
	delete[]a;
}
