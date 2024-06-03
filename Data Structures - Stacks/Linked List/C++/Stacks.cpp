#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
	Node(T value, Node* next): value(value), next(next) {}
	T value;
	Node* next;
};

template <typename T>
class Stack {
public:
	Stack(): top(nullptr), bottom(nullptr), length(0) {}
	void push(T value) {
		Node<T>* node = new Node<T>(value, nullptr);
		if (length == 0)
			bottom = node;
		node->next = top;
		top = node;
		length++;
	}
	Node<T>* pop() {
		if (this->isEmpty())
			return nullptr;
		length--;
		Node<T>* tmp = top;
		top = top->next;
		return top;
	}
	Node<T>* peek() {
		if (this->isEmpty())
			return nullptr;
		return top;	
	}
	bool isEmpty() {
		return length == 0;
	}
private:
	Node<T>* top;
	Node<T>* bottom;
	int length;
};

// Main function
int main(int argc, char* argv[]) {
	Stack<string> stack;
	stack.push("Udemy");
	stack.push("Discord");
	stack.push("Google");
	stack.pop();
	stack.pop();
	Node<string>* node = stack.peek();
	if (node != nullptr)
		cout << node->value << endl;
	else
		cout << "null" << endl;
	return 0;
}
