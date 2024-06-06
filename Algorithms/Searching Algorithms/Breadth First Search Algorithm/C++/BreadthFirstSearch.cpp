#include <iostream>
#include <functional>
#include <vector>
#include <queue>

// Thanks to this guide: https://youtu.be/gcULXE7ViZw?si=SgKq5_jTs-s7gm23

using namespace std;

template <typename T>
class Node {
public:
	Node(T value, Node<T>* left, Node<T>* right): value(value), left(left), right(right) {}
	T value;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
void print(vector<Node<T>*> arr) {
	for (int i = 0; i < arr.size(); ++i)
		cout << (arr[i])->value << ((i != arr.size()-1)? ", ": "");	
	cout << endl;
}

template <typename T>
class BinarySearchTree {
public:
	BinarySearchTree() {}

	void insert(T value) {
		Node<T>* node = new Node<T>(value, nullptr, nullptr);
		if (this->root == nullptr) {
			this->root = node;
		} else {
			Node<T>* currentNode = this->root;
			while (true) {
				if (value <= currentNode->value) {
					if (currentNode->left == nullptr) {
						currentNode->left = node;
						break;
					} 
					currentNode = currentNode->left;
				} else if (value > currentNode->value) {
					if (currentNode->right == nullptr) {
						currentNode->right = node;	
						break;
					}
					currentNode = currentNode->right;
				}
			}
		}
	}

	Node<T>* lookup(T value) {
		if (this->root == nullptr)
			return nullptr;
		Node<T>* currentNode = this->root;
		while (currentNode) {
			if (value < currentNode->value)
				currentNode = currentNode->left;
			else if (value > currentNode->value)
				currentNode = currentNode->right;
			else
				break;
		}
		return currentNode;
	}

	void remove(T value) {

		auto findMin = [](Node<T>* node) -> Node<T>* {
			if (node == nullptr) return nullptr;
			Node<T>* current = node;
			while (current->left != nullptr)
				current = current->left;
			return current;
		};

		std::function<Node<T>*(Node<T>*, T)> removeNode;
		removeNode = [&removeNode, findMin](Node<T>* node, T target) -> Node<T>* {
			if (node == nullptr) return nullptr;
			else if (target < node->value) {
				cout << "traversing to right node" << endl;
				node->left = removeNode(node->left, target);
			} else if (target > node->value) {
				cout << "traversing to right node" << endl;
				node->right = removeNode(node->right, target);
			} else {
				cout << "found: " << node->value << endl;
				// Case 1: No child
				if (node->left == nullptr && node->right == nullptr) {
					cout << "replacing with leaf node" << endl;
					delete node;
					node = nullptr;
				}
				// Case 2: One child
				else if (node->left == nullptr) {
					cout << "replacing with right node" << endl;
					Node<T>* tmp = node;
					node = node->right;
					delete tmp;
				}
				else if (node->right == nullptr) {
					cout << "replacing with left node" << endl;
					Node<T>* tmp = node;
					node = node->left;
					delete tmp;
				}
				// Case 3: Two Children
				else {
					cout << "replacing with the minimum value in the subtree" << endl;
					Node<T>* minimum_value = findMin(node->right);
					node->value = minimum_value->value;
					node->right = removeNode(node->right, minimum_value->value);
				}
			}
			return node;
		};

		// Remove the node
		this->root = removeNode(this->root, value);
	}
	vector<Node<T>*> breadthFirstSearch(bool iterative = true) {
		vector<Node<T>*> result;
		queue<Node<T>*> _queue;
		_queue.push(this->root);
		if (iterative)
			this->breadthFirstSearchIterative(result, _queue);
		else
			this->breadthFirstSearchRecursive(result, _queue);
		return result;
	}
	vector<Node<T>*> breadthFirstSearchIterative(vector<Node<T>*>& result, queue<Node<T>*>& _queue) {
		while (_queue.size() != 0) {
			Node<T>* currentNode = _queue.front();
			_queue.pop();
			result.push_back(currentNode);
			if (currentNode->left)
				_queue.push(currentNode->left);
			if (currentNode->right)
				_queue.push(currentNode->right);
		}
		return result;
	}
	vector<Node<T>*> breadthFirstSearchRecursive(vector<Node<T>*>& result, queue<Node<T>*>& _queue) {
		// Base Case
		if (_queue.size() == 0)
			return result;
		Node<T>* currentNode = _queue.front();
		_queue.pop();
		result.push_back(currentNode);
		if (currentNode->left)
			_queue.push(currentNode->left);
		if (currentNode->right)
			_queue.push(currentNode->right);
		return breadthFirstSearchRecursive(result, _queue);
	}
	void printInOrder() {
		inOrderTraversal(this->root);
		cout << endl;
	}
private:
	Node<T>* root;
	// Recursive function for in-order traversal
	void inOrderTraversal(Node<T>* node) {
		if (node != nullptr) {
		    // Traverse left subtree
		    inOrderTraversal(node->left);

		    // Print current node's value
		    cout << node->value << " ";

		    // Traverse right subtree
		    inOrderTraversal(node->right);
		}
	}
};


// Main function
int main() {
	BinarySearchTree<int> bst;

	bst.insert(12);
	bst.insert(5);
	bst.insert(15);
	bst.insert(3);
	bst.insert(7);
	bst.insert(1);
	bst.insert(9);
	bst.insert(13);
	bst.insert(17);

	/*

	Binary Search Tree (BST)

	          12
	         /  \
	        /    \
	       5      15
	      / \    /  \
	     3   7  13  17
	    /     \
	   1       9

	*/

	vector<Node<int>*> result;
	
	// Iterative Approach
	result = bst.breadthFirstSearch(true);
	print(result);

	// Recursive Approach
	result = bst.breadthFirstSearch(false);
	print(result);
	
	return 0;
}
