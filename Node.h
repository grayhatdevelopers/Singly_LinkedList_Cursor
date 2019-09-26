#pragma once

template <typename T>
class Node {
public:	
	Node<T>*  next;
	T data;
	Node() {
		next = nullptr;
		data = 0;
	}

	Node(T Data) : data(Data) {
		next = nullptr;
	}
	~Node() {

	}
};