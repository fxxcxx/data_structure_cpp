#include<iostream>
using namespace std;

class Node{
public:
    char m; //node가 받는 형태
    Node *link; //node와 link
    
    Node(char a=0){
        m=a;
        link = NULL;
    } //생성자 ㅡㅡ 역할 제대로
    
    void insertNext(Node *nextNode){
        nextNode->link = link;
        link = nextNode;
    }
    
    void insertFront(Node *frontNode){
        frontNode->link = link;
        link = frontNode;
    }
    
    void removeNext(){
        if(link != NULL)
            link = link->link;
    }
    
    void display(){
        Node *p=link;
        while (p!=NULL){
            cout << p->m <<" "; //공백
            p= p->link; //p는 p의 링크로
        }
        cout<<endl; //엔터
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
    
    head.link->link->insertNext(new Node('g')); //e d "g" a b c
    head.link->link->insertFront(new Node('h')); //e d "h" g a b c
    head.display(); //edhgabc, g들가고 그 다음에 h또 들어감
    
    return 0;
}
