#pragma once

#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
class List {
	Node<T>* head;
	Node<T>* cursor;



public:
	List() {
		head = nullptr;
		cursor = nullptr;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void insertAtHead(const T& newDataItem) {
		Node<T>* newNode = new Node <T>(newDataItem);
		newNode->next = head;
		head = newNode;
		cout << "Pointing cursor to head!" << endl;
		cursor = head;
	}

	void insert(const T& newDataItem) {

		if (isEmpty()) {
			insertAtHead(newDataItem);
			return;
		}
		else {
			Node<T>* newNode = new Node <T>(newDataItem);
			if (!cursor) {
				cout << "The cursor was NULLPTR, so moving to head." << endl;
				cursor = head;
			}
			moveCursorToEnd();
			cursor->next = newNode;
		}
	}

	void insertAt(const T& newDataItem, int index) {
		if (isEmpty() and index != 0) {
			cout << "The List is empty!" << endl;
			return;
		}
		else {
			if (index == 0) {
				insertAtHead(newDataItem);
				return;
			}
			else {
				Node<T>* newNode = new Node <T>(newDataItem);
				int i = index;
				cursor = head;
				while (i > 1) {

					if ((cursor == nullptr) and i != 1) {
						cout << "Index is out of range!" << endl;
						break;
					}
					cursor = cursor->next;
					i--;
				}

				if (i == 1) {
					newNode->next = cursor->next;
					cursor->next = newNode;
					return;
				}
				else {
					return;
				}
			}
		}

	}

	T getCursor() {
		return cursor->data;
	}
	bool goToNext() {
		if (!cursor->next) return false;
		cursor = cursor->next;
		return true;
	}
	bool moveCursorToEnd() {
		if (!isEmpty()) {
			while (cursor->next != nullptr) {
				cursor = cursor->next;
			}
			return true;
		}
		return false;
	}

	void remove() {
		if (cursor->next == nullptr) {
			delete cursor;
			cursor = head;
			return;
		}
		cursor->data = cursor->next->data;
		Node <T> tmp;
		Node <T>* tmpptr;
		tmpptr = cursor;
		cursor = cursor->next;
		tmpptr->next = cursor->next;
		delete cursor;
		cursor = tmpptr->next;
	}

	void removeAt(int index) {
		int i = index;
		cursor = head;
		while (i > 1) {

			if ((cursor == nullptr) and i != 1) {
				cout << "Index is out of range!" << endl;
				break;
			}
			cursor = cursor->next;
			i--;
		}

		if (i == 1) {
			remove();
			return;
		}
		else {
			return;
		}
	}

	void replace(const T& newDataItem) {
		if (!isEmpty()) {
			cursor->data = newDataItem;
			return;
		}
	}

	void replaceAt(const T& newDataItem, int index) {
		int i = index;
		cursor = head;
		while (i > 1) {

			if ((cursor == nullptr) and i != 1) {
				cout << "Index is out of range!" << endl;
				break;
			}
			cursor = cursor->next;
			i--;
		}

		if (i == 1) {
			replace(newDataItem);
			return;
		}
		else {
			return;
		}
	}

	void sort() {
		if (isEmpty()) return;
		//cursor = head;
		Node<T>* tmp = head;
		T tempvar;
		while (tmp->next) {
			cursor = tmp;
			while (cursor->next) {
				if (cursor->data > cursor->next->data) {
					tempvar = cursor->data;
					cursor->data = cursor->next->data;
					cursor->next->data = tempvar;
				}
				cursor = cursor->next;
			}

			tmp=tmp->next;
		}
	}

	bool duplicate() {
		if (isEmpty()) return false;

		Node<T>* tmp = head;
		T tempvar;
		while (tmp) {
			cursor = tmp->next;
			while (cursor) {
				if (cursor->data == tmp->data) {
					return true;
				}
				cursor = cursor->next;
			}

			tmp = tmp->next;
		}
		return false;
	}

	void splitList(int index) {
		if (isEmpty() or head->next->next==nullptr) return;

		int i = index;
		cursor = head;
		while (i > 1) {

			if ((cursor == nullptr) and i != 1) {
				cout << "Index is out of range!" << endl;
				break;
			}
			cursor = cursor->next;
			i--;
		}
		if (i == 1 and cursor->next) {
			List <T>* newList = new List;
			while (cursor) {
				newList.insert(cursor.data);
				remove();
			}
			cout << "The splitted List is...";
			newList->Display();
			cout << endl;
		}
		else {
			return;
		}

	}

	void Display(){
		Node <T>* displaycursor = head;
		//cursor = head;
		cout << "The Linked List is..." << endl;
		cout << "{ ";
		while (displaycursor) {
			cout << displaycursor->data;
			displaycursor = displaycursor->next;
			if (displaycursor != nullptr) {
				cout << ", ";
			}
		}
		cout << " }" << endl;
	}

	bool clear() {
		if (isEmpty()) {
			return false;
		}
		Node<T>* nextNode = nullptr; 
		cursor = head;
		while (cursor != nullptr)
		{
			nextNode = cursor->next;
			// destroy the current node
			delete cursor;
			cursor = nextNode;
		}
		head = nullptr;
		return true;
	}

	~List(){
		clear();
		delete head;
		delete cursor;
	}
};
