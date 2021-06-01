#include "Queues.h"
#include<assert.h>
template<class T>
Queues<T>::Queues()
{
	elements = 0;
	a = new T[capacity];
	capacity = 10;
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
	return elements == 0;
}
template<class T>
void Queues<T>::Expand()
{
	capacity = capacity + 5;
	int* tmp = new int[capacity];
	for (int i = 0; i < elements; i++)
		tmp[i] = a[i];
	delete[]a;
	a = tmp;
	elements++;
}
template<class T>
void Queues<T>::enqueue(T val)
{
	if (elements == capacity)
		void Expand();
	back = (back + 1) % capacity;
	a[back] = val;
	elements++;

}
template<class T>
void Queues<T>::dequeue() {
	assert(elements == 0);
	front = (front + 1) % capacity;
	elements--;
	if (elements == 0)
	{
		front = back = -1;
	}


}
