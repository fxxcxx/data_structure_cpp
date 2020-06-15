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
    void insertNext(Node *nextNode){ //넥스트에 삽입
        nextNode->link=link;
        link=nextNode;
    }
    
    void insertFront(Node *frontNode){ //앞에 삽입
        frontNode->link=link;
        link=frontNode;
    }
    
    void removeNext(){ //넥스트 지움
        if(link!=NULL) link=link->link;
    }
    
    void display(){
        Node *p=link;
        while(p!=NULL){
            cout<< p->m <<" ";
            p=p->link;
        }
        cout<<endl;
    }
};

int main()
{
    
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
