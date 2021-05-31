#include "Node.h"

template<class T>
Node<T>::Node() {
	value = 0;
}

template<class T>
Node<T>::Node(T value) {
	this->value = value;
}

template<class T>
Node<T>::~Node() {
	delete right;
	delete left;
}