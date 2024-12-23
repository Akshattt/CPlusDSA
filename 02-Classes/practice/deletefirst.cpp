#include<iostream>
using namespace std;

class node{
	public:
	int value;
	node* next;
	
	node(int value){
		this->value=value;
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
		 length= 1;
	 }
	 
	 ~linkedlist() {
		 node* temp = head;
		 while(head) {
			 head = head->next;
			 delete temp;
			 temp = head;
		 }
	 }
	 void printlist() {
		 node* temp = head;
		 if(temp==nullptr) {
			 cout<<"Head : null pointer"<<endl;
		 }
		 
		 while(temp!=nullptr)
		 {
			cout<<temp->value<<endl;
			temp=temp->next;
			
		 }
	 }
	 
	 void gethead(){
		 if(head==nullptr) {
			 cout<<"Head : nullptr"<<endl;
		 }
		 else {
			 cout<<"Head : "<<head->value<<endl;
		 }
	 }
	 void gettail() {
		 if(tail == nullptr) {
			 cout<<"Head: nullptr"<<endl;
		 }
		 else {
			 cout<<"tail :"<<tail->value<<endl;
		 }
	 }
	 
	 void append(int value) {
		 node* newnode = new node(value);
		 if(length==0){
			 head = newnode;
			 tail= newnode;
		 }
		 else{
			 tail->next= newnode;
			 tail= newnode;
		 }
		 length++;
	 }
	
	void deletefirst(){
		node* temp = head;
		head= head->next;
		delete temp;
		length--;
	}
	 
};

int main(){
	linkedlist* mylinkedlist = new linkedlist(1);
	mylinkedlist->printlist();
	mylinkedlist->append(2);
	mylinkedlist->append(4);
	mylinkedlist->append(3);
	mylinkedlist->printlist();
	cout<<"After deleting the first element: "<<endl;
	mylinkedlist->deletefirst();
	mylinkedlist->printlist();
	delete mylinkedlist;
	return 0;
}
	

	