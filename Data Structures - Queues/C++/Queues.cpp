#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
	Node(T value, Node<T>* next): value(value), next(next) {
	}
	T value;
	Node<T>* next;
};

template <typename T>
class Queue {
public:
	Queue(): front(nullptr), back(nullptr), length(0) {}
	~Queue() {
		while (!this->isEmpty()) 
			this->dequeue();
	}
	bool isEmpty() {
		return this->length == 0;
	}
	void enqueue(T value) {
		Node<T>* node = new Node<T>(value, nullptr);	
		if (this->isEmpty()) {
			back = front = node;
		} else {
			back->next = node;
			back = node;
		}
		++length;
	}
	void dequeue() {
		if (this->isEmpty())
			return;	
		Node<T>* tmp = front;
		front = front->next;
		delete tmp;
		--length;
	}
	friend ostream& operator<<(ostream& os, Queue<T>& queue) {
		Node<T>* tmp = queue.front;
		while (tmp != nullptr) {
			os << tmp->value << ((tmp->next != nullptr)? ", ": "");
			tmp = tmp->next;
		}
		return os;
	}
private:
	Node<T>* front;
	Node<T>* back;
	int length;
};

// Main function
int main(int argc, char* argv[]) {
	Queue<string> queue;
	queue.enqueue("Law");
	queue.enqueue("Yamato");
	queue.enqueue("Luffy");
	queue.enqueue("Zoro");
	queue.enqueue("Nami");
	queue.enqueue("Usopp");
	queue.enqueue("Sanji");
	queue.enqueue("Chopper");
	queue.enqueue("Robin");
	queue.enqueue("Franky");
	queue.enqueue("Brook");
	queue.enqueue("Jinbei");
	cout << queue << endl;
	queue.dequeue();
	cout << queue << endl;
	return 0;
}
