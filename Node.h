#pragma once
template <class T>
class Node
{
	T value;
	Node<T>* right;
	Node<T>* left;
public:
	Node();
	Node(T val);
	~Node();
};