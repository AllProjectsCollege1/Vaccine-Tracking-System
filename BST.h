#pragma once
//#include "Node.h"
#include"Node.cpp"
template <class T>
class BST
{
	Node<T>* root;
	Node<T>* findNode(T value);
	void inOrder(Node<T>* start);
	void preOrder(Node<T>* start);
	void postOrder(Node<T>* start);
public:
	BST(void);
	bool contains(T value);
	void insert(T value);
	void traverse(int order);

	~BST();
};

