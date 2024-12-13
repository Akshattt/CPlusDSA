#include<iostream>

using namespace std;

class Node{
	public:
	int value;
	Node* next;
	
	Node (int value) {
		this->value = value;
		next = nullptr;
	}
};

class LinkedList{
	private:
	Node* head;
	Node* tail;
	int length;
	public:
	LinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length=1;
	}
	~LinkedList() {
		Node* temp = head;
		while(temp!=nullptr)
		{
		head=head->next;
		delete temp;
		temp=head;
		}
		}
	void printlist(){
		Node* temp = head;
		while(temp!= nullptr) {
			cout<<temp->value<<endl;
			temp = temp->next;
			}
		
		}
	void getHead() {
		if (head == nullptr) {
			cout<<"head: nullptr"<<endl;
			}
		else
		{cout<<"Head : "<< head->value<<endl;
			}
		}
	
	void getlength() {
		cout<<"Length: "<<length<<endl;
		}
	
	void append(int value) {
		Node* newNode = new Node(value);
		if(length == 0) {
			head = newNode;
			tail = newNode;
			}
		else {
			tail->next = newNode;
			tail = newNode;
			}
			length++;
			}
			
	void deleteLast() {
		if(length == 0) return;
		Node* temp = head;
		Node *pre = head;
		while(temp->next) {
			pre= temp;
			temp = temp->next;
			}
			tail = pre;
			tail->next = nullptr;
			length--;
			
			if(length == 0) {
				head = nullptr;
				tail = nullptr;
				}
			delete temp;
		}
			
	};
	
	int main() {
		LinkedList* myLinkedList = new LinkedList(3);
		myLinkedList->append(2);
		myLinkedList->append(1);
		myLinkedList->append(4);
		
		
		cout<<"LL before deleteLast(): "<<endl;
		myLinkedList->printlist();
		
		myLinkedList->deleteLast();
		
		cout<<endl<<endl<<"LL after first deletion"<<endl;
		myLinkedList->printlist();
		
		myLinkedList->deleteLast();
		
		cout<<endl<<endl<<"Linked list after the 2nd deletion"<<endl;
		
		myLinkedList->printlist();
		myLinkedList->deleteLast();
		
		cout<<endl<<endl<<"Linked List after the 3rd deletion"<<endl;
		
		myLinkedList->printlist();
		
	}
		
		
		
		
	
	