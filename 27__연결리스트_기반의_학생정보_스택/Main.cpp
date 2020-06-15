#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STRING	100

class Student
{
	int id;
	char name[MAX_STRING];
	char dept[MAX_STRING];
	public:
	Student(int i=0, char* nam="", char* dep=""){
		set(i, nam, dep);
	}
	void set(int i, char* nam, char* dep){
		id = i;
		strcpy(name, nam);
		strcpy(dept, dep);
	}
	void display(){
		printf("ID:%-15d Name:%-10s Major:%-20s\n", id, name, dept);
	}


};

class Node : public Student
{
	Node* link;
	public:
		Node(int id=0, char* name="", char* dept="")
			: Student(id, name, dept) {link = NULL;}
	~Node(void) {}
	Node* getLink() {return link;}
	void setLink(Node *p) {link = p;}
};



class LinkedStack
{
	Node* top;
	public:
	LinkedStack() {top=NULL;}
	~LinkedStack() {while(!isEmpty()) delete pop();}
	bool isEmpty() {return top==NULL;}
	void push(Node *n){
		if(isEmpty()) top = n;
		else {
			n->setLink(top);
			top = n;
		}
	}
	Node* pop() {
		if(isEmpty()) return NULL;
		Node *n = top;
			top = top->getLink();
		return n;
	}
	Node* peek() {return top;}
	void display() {
		printf("[LinkedStack]\n");
		for(Node *p = top; p != NULL; p=p->getLink())
			p->display();
		printf("\n");
	}	
	
};

int main()
{
	LinkedStack stack;
	stack.push(new Node(2015130007, "Jack", "CS"));
	stack.push(new Node(2015130100, "Paul", "ME"));
	stack.push(new Node(2015130135, "Tim", "EE"));
	stack.display();

	Node* node = stack.pop();
	printf("[Pop]\n");
	node->display();
	printf("\n");
	delete node;
	stack.display();
	
	return 0;
}
