#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Stack {
public:
    Stack() : length(0), top(nullptr), bottom(nullptr) {}

    void push(T value) {
        this->arr.push_back(value);
        if (this->length == 0) {
		this->bottom = this->arr.data();
        }
        this->top = this->arr.data() + length++;
    }

    void pop() {
        if (this->isEmpty()) {
            return;
        }
        this->arr.pop_back();
        this->length--;
        if (this->isEmpty()) {
            this->bottom = nullptr;
            this->top = nullptr;
        } else {
            this->top = &arr[this->length - 1];
        }
    }

    T* peek() {
        if (this->isEmpty())
            return nullptr;
        return top;
    }

    bool isEmpty() {
        return this->length == 0;
    }

private:
    T* top;
    T* bottom;
    vector<T> arr;
    int length;
};

// Main function
int main(int argc, char* argv[]) {
    Stack<string> stack;
    stack.push("Udemy");
    stack.push("Discord");
    stack.push("Google");
    return 0;
}
