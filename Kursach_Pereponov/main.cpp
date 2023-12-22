//
//  main.cpp
//  Kursach_Pereponov
//
//  Created by Роман Перепонов on 22.12.2023.
//

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node() : key(0), next(nullptr) {}

    Node(int k) : key(k), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int k) {
        Node* newNode = new Node(k);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->key << endl;
        delete temp;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void remove() {
        while (!isEmpty()) {
            pop();
        }
    }

    int size() {
        int count = 0;
        Node* temp = top;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Stack copy() {
        Stack newStack;
        vector<int> elements;

        Node* temp = top;
        while (temp) {
            elements.push_back(temp->key);
            temp = temp->next;
        }

        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            newStack.push(*it);
        }

        return newStack;
    }
};

void stackOperations() {
    Stack stack;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Print\n4. Size\n5. Remove\n6. Copy\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.print();
                break;
            case 4:
                cout << "Size of stack: " << stack.size() << endl;
                break;
            case 5:
                stack.remove();
                break;
            case 6: {
                Stack copiedStack = stack.copy();
                cout << "Copied stack: ";
                copiedStack.print();
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}

int main() {
    stackOperations();
    return 0;
}
