#include<iostream>

using namespace std;

class node{
	public: 
	int value;
	node* next;
	
	node(int value) {
		this->value = value;
		next= nullptr;
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
		length = 1;
	}
	~linkedlist() {
		node* temp = head;
		while(head){
			head = head->next;
			delete temp;
			temp = head;
		}
	}
	
	void printlist() {
		node* temp = head;
		while(temp!=nullptr) {
			cout<<temp->value<<endl;
			temp = temp->next;
		}
	}
	
	void gethead() {
		if(head==nullptr) {
			cout<<"Head is null pointer"<<endl;
		}
		else {
			cout<<"Head :"<<head->value<<endl;
		}
	}
	
	void gettail() {
		if(tail==nullptr) {
			cout<<"tail is nullpointer"<<endl;
		}
		else
		{
			cout<<"tail :"<<tail->value<<endl;
		}
	}
	
	void getlength() {
		cout<<"Length :"<<length<<endl;
	}
	
	void append(int value) {
		node* newnode = new node(value);
		if(length==0) {
			head = newnode;
			tail=newnode;
		}
		else
		{
			tail->next = newnode;
			tail=newnode;
		}
		length++;
	}
	
	void deletelast() {
		if (length==0) return;
		node* temp = head;
		if(length==1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			node* pre = head;
			while(temp->next) {
				pre=temp;
				temp=temp->next;
			}
			tail=pre;
			tail->next=nullptr;
		}
		delete temp;
		length--;
	}
	
	void prepend(int value) {
		node* newnode = new node(value);
		if (length=0) {
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->next=head;
			head = newnode;
		}
		length++;
	}
	
	void deletefirst(){
		if(length==0) return;
		node* temp = head;
		if(length==1) {
			head = nullptr;
			tail = nullptr;
		}
		else{
			head = head->next;
		}
		delete temp;
		length--;
	}
	
	node* get(int index) {
		if(index<0 || index >= length) return 0;
		node* temp = head;
		for(int i=0; i<index; i++)
		{temp= temp->next;
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
		
};

int main()
{
	linkedlist* mylinkedlist = new linkedlist(0);
	mylinkedlist->append(1);
	mylinkedlist->append(2);
	mylinkedlist->append(3);
	
	cout<<"LL before set:"<<endl;
	mylinkedlist->printlist();
	
	mylinkedlist->set(2,99);
	cout<<endl<<"LL after setting a value in a given index:"<<endl;
	mylinkedlist->printlist();
}

		
				
	