#include<iostream>
using namespace std;

class Node{
    public:
        char m;
        Node *link; //node를 가르키는 ponter link
    
        Node(char a=0){
            m=a; //class public에 선언한 m에 넣는거, clas 기본과 똑같쥬?
            link=NULL;
        }
    void insertNext(Node *nextNode){ // 내 뒤에 노드 추가
        nextNode->link=link;
        link=nextNode;
    }
    
    void insertFront(Node *frontNode){ //앞에 삽입
        frontNode->link=link; //프론트의 링크를 링크로 바꿔줌(붙여)
        link=frontNode; //링크를 프론트노드로
    }
    
    void removeNext(){ //넥스트 지움
        if(link!=NULL) link=link->link;
        //앞의 링크를 링크의 링크(뛰어 넘어가)
    }
    
    void display(){
        Node *p=link; //헤드의 링크를...
        while(p!=NULL){ //n개
            cout<< p->m <<" ";
            p=p->link; //p 를 p의 링크로 바꾸래
        }
        cout<<endl;
    }
};

int main()
{
    //앞의 예제 : 포인터로 했으나 여긴 head라는 객체를 만듦
    Node head; //head라는 노드 맹긂(맹그로브 아님 ㅎ)
    head.insertNext(new Node('a'));
    head.link->insertNext(new Node('b'));
    head.link->link->insertNext(new Node('c')); //a링크 다음에 b 다음에 c
    
    head.insertFront(new Node('d'));
    head.insertNext(new Node('e'));
    head.insertFront(new Node('f'));
    head.display(); //fedabc
    
    head.removeNext();
    head.display(); //edabc
    
    head.link->link->insertNext(new Node('g'));
    head.link->link->insertFront(new Node('h'));
    head.display(); //edhgabc, g들가고 그 다음에 h또 들어감
    
    return 0;
}
