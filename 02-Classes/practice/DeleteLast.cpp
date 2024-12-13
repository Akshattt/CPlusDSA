#include<iostream>
using namespace std;

class Node{
	public:
	int value;
	Node* next;
	
	Node(int value) {
		this->value = value;
		next = nullptr;
	}
};

class Linkedlist {
	private:
		Node* head;
		Node* tail;
		int length;
		
	public:
		Linkedlist(int value) {
			Node* newNode = new Node(value);
			head = newNode;
			tail = newNode;
			length =1;
		}
		
		~Linkedlist() {
			Node* temp = head;
			while (head) {
				head = head->next;
				delete temp;
				temp= head;
			}
		}
		void printList() {
			Node* temp = head;
			while(temp!= nullptr) {
				cout<<temp->value<< endl;
				temp = temp->next;
			}
		}
		
		void getHead() {
			if(head == nullptr) {
				cout<<"Head: Nullptr"<< endl;
			}
			else{
				cout<<"Head: "<<head->value<<endl;
			}
		}
		
		void getTail() {
			if(tail == nullptr) {
				cout<<"Head: Nullptr"<<endl;
			}
			else {
				cout<<"Tail :"<<tail->value<<endl;
			}
			
		}
		
		void getLength(){
			cout<<"Length: "<<length<<endl;
		}
		
		void append(int value){
			Node* newNode = new Node(value);
			if(length==0) {
				head = newNode;
				tail= newNode;
			}
			else {
				tail->next = newNode;
				tail= newNode;
			}
			length++;
			
		}
};
		
	int main() {
		Linkedlist* mylinkedlist = new Linkedlist(1);
		mylinkedlist->printList();
		mylinkedlist->append(2);
		mylinkedlist->append(7);
        mylinkedlist->printList();

        delete mylinkedlist;

        return 0;

		
    }