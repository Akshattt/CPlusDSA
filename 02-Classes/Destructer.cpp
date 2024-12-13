#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
}

class LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;

}

~LinkedList() {
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }

}
Linkedlist* mylinkedlist = new LinkedList(4);

delete mylinkedlist;
