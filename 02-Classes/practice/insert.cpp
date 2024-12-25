#include<iostream>

using namespace std;

class node{
	public:
	int value;
	node* next;
	
	node(int value){
		this->value = value;
		next=nullptr;
	}
};

class linkedlist{
	private:
	node* head;
	node* tail;
	int length;
	
	public:
	linkedlist(int value) {
		node* newnode = new node(value);
		head = newnode;
		tail = newnode;
		length=1;
	}
	
	~linkedlist(){
		node* temp= head;
		while(head) {
			head=head->next;
			delete temp;
			temp=head;
	}
	}
	
	void printlist() {
		node* temp = head;
		while(temp!=nullptr){
			cout<<temp->value<<endl;
			temp=temp->next;
		}
	}
	
	void append(int value) {
		node* newnode = new node(value);
		if(length==0){
			head=newnode;
			tail=newnode;
		}
		else
		{tail->next= newnode;
		tail=newnode;
		}
		length++;
	}
	
	void deletelast() {
		if(length==0) return;
		node* temp= head;
		if(length==1) {
			head=nullptr;
			tail=nullptr;
		}
		else
		{
			node* pre = head;
			while(temp->next) {
				pre=temp;
				temp=temp->next;
			}
			tail = pre;
			tail->next=nullptr;
		}
		delete temp;
		length--;
	}
	
	void prepend(int value) {
		node* newnode = new node(value);
		if(length==0) {
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->next = head;
			head=newnode;
		}
		length++;
	}
	
	void deletefirst() {
		if(length==0) return;
		node* temp=head;
		if(length==1) {
			head=nullptr;
			tail=nullptr;
		}
		else
		{ head=head->next;
		}
		delete temp;
		length--;
	}
	
	node* get(int index){
		if(index < 0 || index >= length) return nullptr;
		node* temp=head;
		for(int i=0;i<index;i++){
			temp = temp->next;
		}
		return temp;
	}
	
	bool set(int index, int value) {
		node* temp = get(index);
		if(temp) {
			temp->value = value;
			return true;
		}
		return false;
	}
	
	bool insert(int index, int value) {
		if(index<0 || index>length) return false;
		
		if(index==0) {prepend(value);
		return true;
		}
		if(index==length)
		{append(value);
		return true;
		}
		node* newnode = new node(value);
		node* temp = get(index-1);
		newnode->next = temp->next;
		temp->next = newnode;
		length++;
		return true;
	}
};
	int main() {
		linkedlist* mylinkedlist = new linkedlist(1);
		mylinkedlist->append(3);
		cout<<"Linkedlist before insert"<<endl;
		mylinkedlist->printlist();
		
		mylinkedlist->insert(1,2);
		
		cout<<"LL after insert 2 in the middle"<<endl;
		mylinkedlist->printlist();
		mylinkedlist->insert(0,0);
		cout<<"Linkedlist after insert at 0 at beginning"<<endl;
		mylinkedlist->printlist();
		mylinkedlist->insert(4,4);
		cout<<"Insert after 4 at the end"<<endl;
		mylinkedlist->printlist();
	}
		
	
		
			