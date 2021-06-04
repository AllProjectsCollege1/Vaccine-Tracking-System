#pragma once
template<class T>
class Queues
{

	T* a;
	int elements;
	int capacity;
	int front, back;
public:
	Queues(int size);
	int lenght();
	T Front();
	bool empty();
	bool isFull();
	void enqueue(T);
	void dequeue();
	~Queues(void);

};

