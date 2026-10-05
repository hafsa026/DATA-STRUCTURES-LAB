// task1_balanced_brackets.cpp
#include <iostream>
#include <string>
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

// ---------- Balanced Bracket Check ----------
bool isBalanced(const string& expr) {
    DynamicStack<char> stack;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) return false;
            char open = stack.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{'))
                return false;
        }
    }
    return stack.isEmpty();
}

// ---------- Main ----------
int main() {
    string input;
    cout << "Enter a string with brackets: ";
    getline(cin, input);

    cout << (isBalanced(input) ? "BALANCED" : "NOT BALANCED") << endl;
    return 0;
}