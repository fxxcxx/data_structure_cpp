#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STRING    100

class Student
{
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];
    //private
    
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

class Node : public Student //상속, 노드가 스튜던트 클래스를 상속, 멤버함수 다 쓸 수 있다.
{
    Node* link; //다음 노드를 가리키는 포인터 변수 n.link ㄴㄴ / n.getlink ㅇㅇ 퍼블릭으로 접근
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
    //top을 포인터로 지정
    
    public:
    LinkedStack() {top=NULL;} //-1대신 null(연결리스트니겐) //생성자
    ~LinkedStack() {while(!isEmpty()) delete pop();} //소멸자 종료될때 계속 지움
    bool isEmpty() {return top==NULL;}
    
    void push(Node *n){
        if(isEmpty()) top = n;
        else {
            n->setLink(top); //n이 가리키는 링크 셋링크(밑에 탑)
            top = n; //탑이 가리키는 링크는 n이 됨
        } //data[++top} = e;와 동일
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
        for(Node *p = top; p != NULL; p=p->getLink()) //p=p->link; 동일, public 멤버함수로 변경
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
