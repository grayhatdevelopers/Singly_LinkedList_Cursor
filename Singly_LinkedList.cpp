// Singly_LinkedList.cpp with cursor pointer, by Saad Bazaz
// main.cpp

#include <iostream>
#include "List.h"
using namespace std;
int main()
{
    cout << "Hello World!\n";
	List <int> a;
	cout<<a.isEmpty()<<endl;
	int num = 3;
	int option;
	int position;
	do {
		cout << "Enter 1 to insert at end, or 2 to insert at your desired position." << endl;
		cout << "Or, enter 3 to sort the list, and 4 clear the List." << endl;
		cin >> option;

		if (option == 1) {
			cout << "Enter the number you'd like to insert at end." << endl;
			cin >> num;
			a.insert(num);
		}
		else if (option == 2) {
			cout << "Enter the number you'd like to insert, then the position." << endl;
			cin >> num;
			cin >> position;
			a.insertAt(num, position);
		}
		else if (option == 3) {
			a.sort();
		}
		else if (option == 3) {
			a.clear();
		}
		cout << "is Empty? "<<a.isEmpty() << endl;
		a.Display();
	} while (option);
	return 0;
}

