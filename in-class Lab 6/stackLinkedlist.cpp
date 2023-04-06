#include <iostream>
#include <chrono>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    void push(int n) {
        Node* newNode = new Node;
        newNode->data = n;
        newNode->next = top;
        top = newNode;
        cout << n << " pushed to stack" << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Error: Stack underflow!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        int x = temp->data;
        delete temp;
        cout << x << " popped from stack" << endl;
    }

    int stackTop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Elements in the stack: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int stackSize;
    cout << "Enter stack size: ";
    cin >> stackSize;

    Stack s;
    
    auto start = chrono::high_resolution_clock::now(); // start timer

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();

    for (int i = 0; i < 5; i++)
        s.pop();
    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto end = chrono::high_resolution_clock::now(); // end timer
    double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Execution time: " << time_taken << " microseconds." << endl;

    return 0;
}
