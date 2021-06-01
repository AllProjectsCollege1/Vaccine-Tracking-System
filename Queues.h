#pragma once
template<class T>
class Queues
{

	T* a;
	int elements;
	int capacity;
	int front, back;
public:
	Queues(void);
	int lenght();
	T Front();
	bool empty();
	void Expand();
	void enqueue(T);
	void dequeue();
	~Queues(void);

};

