#include <iostream>
#include <stdexcept>
#include <vector>

class StackFullException : public std::runtime_error {
public:
    StackFullException() : std::runtime_error("Stack is full") {}
};

class StackEmptyException : public std::runtime_error {
public:
    StackEmptyException() : std::runtime_error("Stack is empty") {}
};

// Template général pour la classe Stack
template<typename T>
class Stack {
private:
    std::vector<T> data;
    int max_size;

public:
    Stack(int size) : max_size(size) {}

    void push(T value) {
        if (data.size() >= max_size) {
            throw StackFullException();
        }
        data.push_back(value);
    }

    T pop() {
        if (data.empty()) {
            throw StackEmptyException();
        }
        T value = data.back();
        data.pop_back();
        return value;
    }

    int size() const {
        return data.size();
    }
};

// Spécialisation pour les entiers
template<>
class Stack<int> {
private:
    std::vector<int> data;
    int max_size;

public:
    Stack(int size) : max_size(size) {}

    void push(int value) {
        if (data.size() >= max_size) {
            throw StackFullException();
        }
        data.push_back(value);
    }

    int pop() {
        if (data.empty()) {
            throw StackEmptyException();
        }
        int value = data.back();
        data.pop_back();
        return value;
    }

    int size() const {
        return data.size();
    }
};

// Spécialisation pour les doubles
template<>
class Stack<double> {
private:
    std::vector<double> data;
    int max_size;

public:
    Stack(int size) : max_size(size) {}

    void push(double value) {
        if (data.size() >= max_size) {
            throw StackFullException();
        }
        data.push_back(value);
    }

    double pop() {
        if (data.empty()) {
            throw StackEmptyException();
        }
        double value = data.back();
        data.pop_back();
        return value;
    }

    int size() const {
        return data.size();
    }
};

void func_c(Stack<int>& stack) {
    std::cout << "In func_c" << std::endl;
    stack.push(4);  // Cette opération va lancer une exception
    std::cout << "This line won't be executed" << std::endl;
}

void func_b(Stack<int>& stack) {
    std::cout << "In func_b" << std::endl;
    func_c(stack);
    std::cout << "This line won't be executed" << std::endl;
}

void func_a(Stack<int>& stack) {
    std::cout << "In func_a" << std::endl;
    func_b(stack);
    std::cout << "This line won't be executed" << std::endl;
}

int main() {
    try {
        Stack<int> stack(2);
        stack.push(1);
        stack.push(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        func_a(stack);
    }
    catch (const StackFullException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    try {
        Stack<int> stack(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.pop();
    }
    catch (const StackEmptyException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    // Test avec la spécialisation pour les doubles
    try {
        Stack<double> doubleStack(3);
        doubleStack.push(1.5);
        doubleStack.push(2.7);
        std::cout << "Double stack size: " << doubleStack.size() << std::endl;
        double value = doubleStack.pop();
        std::cout << "Popped value: " << value << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error with double stack: " << ex.what() << std::endl;
    }

    std::cout << "Program completed" << std::endl;
    return 0;
} 