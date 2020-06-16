#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

// class Node 구현
class Node{ //data와 link구분
	Node* link; //다음 노드를 가리키는 포인터 변수
	int data;
	public:
	Node(int val=0) : data(val), link(NULL) {}
	Node* getLink() {return link;} //넘어거
	void setLink(Node* next) {link=next;} //넘어가
	void display() {printf(" <%2d>", data);}
	bool hasData(int val) {return data == val; }
	
	void inseretNext(Node *n){
		if(n != NULL ) {
			n->link = link; //node insertnext(link)-  n(link)
			link = n; //연결됨
		}
	}
	Node* removeNext() {
		Node* removed = link; //새로운 포인터 만들 링크로 놔라.
		if(removed != NULL)
			link = removed->link; //링크를 removed의 링클 바꿔라(따라해라 정도..?)
		return removed;
	}
};

class LinkedList {
	Node org; //헤드노드, 실제노드(포인터 아님) org->link(안돼!) org.link 로 접근.(도 안돼 privateㅣㅇ라) 따랏 org.getLink()
	public:
	LinkedList() : org(0) {} //생성자
	~LinkedList() {clear();} //소멸자
	void clear() {while(!isEmpty()) delete remove(0); }
	Node* getHead() {return org.getLink();} 
	//헤드노드의 포인터, org.getLink() org는 접근 노드... 값이 있는 맨처음 리스트노드는 head 노드
	
	bool isEmpty() {return getHead()==NULL; }
	
	Node* getEntry(int pos) {
		Node* n = &org; //노드를 가리키는 포인터 n생성, 처음에 org의 주소르 가리킴
		for(int i=-1; i<pos; i++, n=n->getLink()) //i=0일때, n의 get link = 맨 처으 데이터 노드
			if(n==NULL) break;
		return n;
	}
	
	void insert(int pos, Node *n){
		Node* prev = getEntry(pos-1); //prev : 추가해야할 위치으 바로 앞 노드
		if(prev != NULL)
			prev->inseretNext(n);
	}
	
	Node* remove(int pos) {
		Node* prev = getEntry(pos-1);
		return prev->removeNext();
	}
	void replace(int pos, Node *n){
		Node* prev = getEntry(pos - 1);
		if (prev != NULL){
			delete prev->removeNext();
			prev->inseretNext(n);
		}
	}
	
	int size() {
		int count = 0;
		for(Node* p = getHead(); p!=NULL; p=p->getLink())
			count++;
		return count;
	}
	
	void display() {
		printf("[ the size of the linked list = %2d] : ",size());
		for(Node *p = getHead(); p!=NULL;p=p->getLink()) //gethead : 맨처음 , p=gethead, p의 getlink : p 다음 값
			p->display();
		printf("\n");
	}
};



int main()
{
	LinkedList	list;				

	list.insert( 0, new Node(10) );	
	list.insert( 0, new Node(20) );	
	list.insert( 1, new Node(30) );	
	list.insert( list.size(), new Node(40) );
	list.insert( 2, new Node(50) );	
	list.display();			
	list.replace(1,new Node(80)) ;
	list.display();			

	list.remove( 2 );		
	list.remove(list.size()-1);		
	list.remove(0);					
	list.replace(1, new Node(90));	
	list.display();					

	list.clear();					
	list.display();					
	
	return 0;
}


