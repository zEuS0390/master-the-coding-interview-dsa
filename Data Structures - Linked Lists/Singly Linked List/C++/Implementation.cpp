#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	Node(int v, Node* n): value(v), next(n) {}
	int value;
	Node* next;
};

class LinkedList {
public:
	Node* head;
	Node* tail;
	int length;

	LinkedList(int value) {
		this->append(value);	
		this->length = 1;
	}

	LinkedList(): head(nullptr), tail(nullptr), length(0) {}

	void append(int value) {
		Node* node = new Node(value, nullptr);
		if (this->length == 0) {
			head = node;
			tail = node;
		}
		tail->next = node;
		tail = node;
		this->length++;
	}

	void prepend(int value) {
		Node* node = new Node(value, head);
		head = node;
		this->length++;
	}

	void insert(int index, int value) {
		if (index <= 0) {
			this->prepend(value); 
			return;
		} else if (index >= this->length) {
			this->append(value);
			return;
		}
		Node* node = new Node(value, nullptr);	
		Node* parent = this->get(index-1);
		node->next = parent->next;
		parent->next = node;
		this->length++;
	}

	Node* get(unsigned int index) {
		if (index < 0 || index > this->length-1)
			return nullptr;
		Node* current = this->head;
		unsigned int i = 0;
		while (current != nullptr) {
			if (i == index)
				return current;
			current = current->next;
			++i;
		}
		return nullptr;
	}

	void remove(int index) {
		if (index < 0 || index > this->length-1)
			return;
		Node* target;
		if (index == 0) {
			target = this->head;	
			this->head = target->next;
		} else {
			Node* parent = get(index-1);	
			target = parent->next;
			parent->next = target->next;
		}
		delete target;
		this->length--;
	}

	friend ostream& operator<<(ostream& os, const LinkedList& linked_list) {
		Node* tmp = linked_list.head;
		while (tmp != nullptr) {
			os << tmp->value << " --> " << ((tmp->next != nullptr)? "": "nullptr");
			tmp = tmp->next;
		}
		return os;
	}
};

// Main function
int main(int argc, char* argv[]) {
	LinkedList linked_list = LinkedList();
	for (unsigned int i = 0; i < 10; ++i) 
		linked_list.append(i+1);
	cout << linked_list << endl;
	return 0;
}
