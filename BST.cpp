#include "BST.h"
#include<assert.h>
#include<iostream>

using namespace std;

template <class T>
BST<T>::BST() {
	root = 0;
}

template <class T>
bool BST<T>::contains(T value) {

	Node<T>* temp = findNode(value);
	return(temp != 0);
}

template <class T>
Node<T>* BST<T>::findNode(T value) {
	Node<T>* temp = root;
	while (temp != 0 && value != temp->value) {
		if (value < temp->value)
			temp = temp->left;
		else
			temp = temp->right;
	}

	return temp;
}

template <class T>
void BST<T>::insert(T value) {

	assert(!contains(value));
	Node<T>* n = new Node<T>(value);
	if (root == 0)
		root = n;
	else {
		Node<T>* temp = root;
		while (true) {
			if (value < temp->value) {
				if (temp->left == 0) {
					temp->left = n;
					break;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (value > temp->value) {
					if (temp->right == 0) {
						temp->right = n;
						break;
					}
					else {
						temp = temp->right;
					}
				}
			}

		}

	}
}

template <class T>
void BST<T>::traverse(int order) {

	switch (order)
	{
	case 1:
		inOrder(root);
		break;
	case 2:
		preOrder(root);
		break;
	case 3:
		postOrder(root);
		break;
	default:
		cout << "Wrong Choice" << endl;
		break;
	}

}

template <class T>
void BST<T>::inOrder(Node<T>* start) {

	if (start != NULL) {
		inOrder(start->left);
		cout << start->value << " ";
		inOrder(start->right);
	}

}

template <class T>
void BST<T>::preOrder(Node<T>* start) {

	if (start != NULL) {
		cout << start->value << " ";
		preOrder(start->left);
		preOrder(start->right);
	}
}
template <class T>
void BST<T>::postOrder(Node<T>* start) {

	if (start != NULL) {
		postOrder(start->left);
		postOrder(start->right);
		cout << start->value << " ";

	}

}

template <class T>
BST<T>::~BST() {
	delete root;
}