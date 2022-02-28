#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* back;
private:

};

class Stack {
public:
	Stack() {
		info = NULL;
	}
	~Stack() {
		Node* temp;
		while (info != NULL) {
			temp = info;
			info = info->back;
			delete temp;
		}
	}
	void add(int x) {
		Node* temp = new Node();
		Node* previous;
		previous = info;
		temp->data = x;
		temp->next = NULL;
		temp->back = NULL;

		if (info == NULL) {
			info = temp;
		}
		else {
			info->next = temp;
			info = info->next;
			info->back = previous;
		}
	}
	void remove() {
		Node* temp;
		if (info != NULL) {
			temp = info;
			info = info->back;
			delete temp;
		}
	}
	int get() {
		return info->data;
	}
private:
	Node* info;
};

int main() {

	Stack stack;
	cout << "+" << endl;
	stack.add(10);
	cout << "+" << endl;
	stack.add(8);
	cout << "+" << endl;
	stack.add(3);
	cout << "+" << endl;
	stack.add(88);

	cout << stack.get() << endl;

	cout << "-" << endl;
	stack.remove();
	cout << "-" << endl;
	stack.remove();
	cout << "-" << endl;
	stack.remove();

	cout << stack.get() << endl;

	cout << "+" << endl;
	stack.add(50);

	cout << stack.get() << endl;

	stack.~Stack();

	cout << stack.get() << endl;

	return 0;
}