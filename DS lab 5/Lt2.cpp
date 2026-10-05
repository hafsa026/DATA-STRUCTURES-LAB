// task2_infix_to_postfix.cpp
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
using namespace std;

// ---------- Dynamic Stack ----------
template <typename T>
class DynamicStack {
    T* data;
    int topIndex;
    int capacity;

    void resize(int newCap) {
        T* newData = new T[newCap];
        for (int i = 0; i <= topIndex; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    DynamicStack(int initCap = 4) : topIndex(-1), capacity(initCap) {
        data = new T[capacity];
    }
    ~DynamicStack() { delete[] data; }

    bool isEmpty() const { return topIndex == -1; }

    void push(const T& value) {
        if (topIndex + 1 == capacity) resize(capacity * 2);
        data[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) throw runtime_error("Stack underflow");
        return data[topIndex--];
    }

    T top() const {
        if (isEmpty()) throw runtime_error("Stack empty");
        return data[topIndex];
    }
};

// ---------- Helpers ----------
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) { return op == '^'; }

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// ---------- Infix to Postfix ----------
string infixToPostfix(const string& infix) {
    DynamicStack<char> stack;
    string postfix;

    for (size_t i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isspace(c)) continue;

        // Operand (multi-digit support)
        if (isalnum(c)) {
            while (i < infix.length() && (isalnum(infix[i]) || infix[i] == '.')) {
                postfix += infix[i++];
            }
            postfix += ' ';
            i--;
        }
        // Opening bracket
        else if (c == '(') {
            stack.push(c);
        }
        // Closing bracket
        else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfix += stack.pop();
                postfix += ' ';
            }
            if (stack.isEmpty())
                throw runtime_error("Mismatched parentheses");
            stack.pop(); // remove '('
        }
        // Operator
        else if (isOperator(c)) {
            while (!stack.isEmpty() && stack.top() != '(' &&
                   (precedence(stack.top()) > precedence(c) ||
                   (precedence(stack.top()) == precedence(c) && !isRightAssociative(c)))) {
                postfix += stack.pop();
                postfix += ' ';
            }
            stack.push(c);
        }
        else {
            throw runtime_error(string("Invalid character: ") + c);
        }
    }

    while (!stack.isEmpty()) {
        char op = stack.pop();
        if (op == '(') throw runtime_error("Mismatched parentheses");
        postfix += op;
        postfix += ' ';
    }

    return postfix;
}

// ---------- Main ----------
int main() {
    string input;
    cout << "Enter infix expression: ";
    getline(cin, input);

    try {
        cout << "Postfix: " << infixToPostfix(input) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}