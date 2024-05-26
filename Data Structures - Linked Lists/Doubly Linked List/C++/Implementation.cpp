#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	Node(int v, Node* n, Node* p): value(v), next(n), prev(p) {}
	int value;
	Node* next;
	Node* prev;
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
		Node* node = new Node(value, nullptr, nullptr);
		if (this->length == 0) {
			this->head = node;
		} else {
			node->prev = tail;
			this->tail->next = node;
		}
		this->tail = node;
		this->length++;
	}

	void prepend(int value) {
		Node* node = new Node(value, head, nullptr);
		this->head->prev = node;
		this->head = node;
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
		Node* target = this->get(index);
		Node* parent = target->prev;
		Node* node = new Node(value, target, parent);	
		parent->next = node;
		target->prev = node;
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

		if (this->length == 0)
			return;

		if (this->length == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			this->length--;
			return;
		}

		if (index < 0 || index > this->length-1)
			return;

		Node* parent = nullptr;
		Node* target = nullptr;
		Node* replace = nullptr;
		if (index == 0) {
			target = this->head;
			replace = target->next;
			replace->prev = nullptr;
			this->head = target->next;
		} else {
			target = get(index);
			parent = target->prev;
			replace = target->next;
			parent->next = replace;
			replace->prev = parent;
		}
		delete target;
		this->length--;
	}

	void reverse() {
		Node* current = this->head;
		Node* temp = nullptr;

		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr) {
			this->tail = this->head;
			this->head = temp->prev;
		}
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

	for (unsigned int i = 0; i < 5; ++i) 
		linked_list.append(i+1);

	if (linked_list.length == 0) {
		cout << "The linked list is empty" << endl;
		return 0;
	}

	cout << "FORWARD: " << linked_list << endl;
	linked_list.reverse();
	cout << "REVERSE: " << linked_list << endl;
	return 0;
}

