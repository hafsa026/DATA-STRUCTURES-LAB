// task3_evaluate_postfix.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <map>
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
    int size() const { return topIndex + 1; }

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
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// ---------- Evaluate Postfix ----------
double evaluatePostfix(const string& postfix,
                       const map<string, double>& values) {
    DynamicStack<double> stack;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size() < 2)
                throw runtime_error("Insufficient operands");
            double b = stack.pop();
            double a = stack.pop();
            double result = 0;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) throw runtime_error("Division by zero");
                    result = a / b; break;
                case '%':
                    result = (int)a % (int)b; break;
                case '^': {
                    result = 1;
                    int exp = (int)b;
                    for (int i = 0; i < exp; i++) result *= a;
                    break;
                }
            }
            stack.push(result);
        }
        else {
            // Try as variable first, then as number
            auto it = values.find(token);
            if (it != values.end()) {
                stack.push(it->second);
            } else {
                try {
                    stack.push(stod(token));
                } catch (...) {
                    throw runtime_error("Unknown operand: " + token);
                }
            }
        }
    }

    if (stack.size() != 1)
        throw runtime_error("Invalid postfix expression");
    return stack.pop();
}

// ---------- Main ----------
int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    getline(cin, postfix);

    // Collect values for any variables
    map<string, double> values;
    stringstream ss(postfix);
    string token;
    while (ss >> token) {
        if (token.size() == 1 && isOperator(token[0])) continue;
        try { stod(token); continue; } catch (...) {}
        if (values.find(token) == values.end()) {
            double val;
            cout << "Value for " << token << ": ";
            cin >> val;
            values[token] = val;
        }
    }

    try {
        double result = evaluatePostfix(postfix, values);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}