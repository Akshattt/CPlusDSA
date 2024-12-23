#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newnode = new Node(value);
        head = newnode;
        tail = newnode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printlist() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void gethead() {
        if (head == nullptr) {
            cout << "head: null pointer" << endl;
        } else {
            cout << "head: " << head->value << endl;
        }
    }

    void append(int value) {
        Node* newnode = new Node(value);
        if (length == 0) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        length++;
    }

    void deletelast() {
        if (length == 0) return;

        Node* temp = head;
        Node* pre = head;
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
        length--;

        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
    }

    void prepend(int value) {
        Node* newnode = new Node(value);
        newnode->next = head;
        head = newnode;
        if (length == 0) {
            tail = newnode;
        }
        length++;
    }
};

int main() {
    LinkedList* mylinkedlist = new LinkedList(1);
    mylinkedlist->append(2);
    mylinkedlist->append(3);
    mylinkedlist->printlist();

    mylinkedlist->prepend(4);
    cout << "New Linked List:" << endl;
    mylinkedlist->printlist();

    delete mylinkedlist;
    return 0;
}
