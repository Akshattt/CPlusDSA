#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
}

void deletelast() {
    if (length == 0) return;
    node* temp = head;
    node* pre = head;
    while(temp->next) {
        pre = temp;
        temp = temp->next;
    }
    tail = pre;
    tail->next = nullptr;
    length --;
    if (length ==0) {
        head = nullptr;
        tail = nullptr;

    }
    delete temp;   
}