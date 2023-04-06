#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

struct Stack {
    int top;
    int* arr;
    int stackSize;
};

void push(Stack& s, int n) {
    if (s.top == s.stackSize - 1) {
        cout << "Error: Stack overflow!" << endl;
        return;
    }
    s.arr[++s.top] = n;
    cout << n << " pushed to stack" << endl;
}

void pop(Stack& s) {
    if (s.top == -1) {
        cout << "Error: Stack underflow!" << endl;
        return;
    }
    int x = s.arr[s.top--];
    cout << x << " popped from stack" << endl;
}

int StackTop(Stack& s) {
    if (s.top == -1) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return s.arr[s.top];
}

bool isEmpty(Stack& s) {
    return s.top == -1;
}

bool isFull(Stack& s) {
    return s.top == s.stackSize -1 ;
}

void display(Stack& s) {
    if (s.top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Elements in the stack: ";
    for (int i = s.top; i >= 0; i--)
        cout << s.arr[i] << " ";
    cout << endl;
}

int main() {
    Stack s;
    s.top = -1;

    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;
    s.stackSize = stackSize;
    s.arr = new int[stackSize];

    auto start = chrono::high_resolution_clock::now();

    push(s, 8);
    push(s, 10);
    push(s, 5);
    push(s, 11);
    push(s, 15);
    push(s, 23);
    push(s, 6);
    push(s, 18);
    push(s, 20);
    push(s, 17);
    display(s);

    for (int i = 0; i < 5; i++)
        pop(s);
    display(s);

    push(s, 4);
    push(s, 30);
    push(s, 3);
    push(s, 1);
    display(s);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Execution time: " << setprecision(5) << time_taken << " microseconds." << endl;

    delete[] s.arr;

    return 0;
}
