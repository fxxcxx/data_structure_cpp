#pragma once
#include <stdio.h>
#include <stdlib.h>

class BinaryNode{
    protected:
    int data;
    BinaryNode *left;
    BinaryNode *right;
    public:
    BinaryNode(int val=0, BinaryNode *l=NULL, BinaryNode *r=NULL):data(val),left(l),right(r){}
    //초기화 리스트, data = val left = l .. 뜻
    ~BinaryNode(){}
    
    void setData (int val) {data =val;}
    void setLeft(BinaryNode *l) {left = l;}
    void setRight(BinaryNode *r) {right =r;}
    int getData() {return data;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    bool isLeaf() {return left == NULL && right==NULL;}
};

#define MAX_QUEUE_SIZE 100
class CircularQueue{
    int front;
    int rear; //후방
    BinaryNode* data[MAX_QUEUE_SIZE];
    public:
    CircularQueue() {front = rear=0;}
    ~CircularQueue(){}
    bool isEmpty() {return front==rear;}
    bool isFull() {return (rear+1)%MAX_QUEUE_SIZE == front;} //큐 공부 ㄱ
    void enqueue(BinaryNode *n){
        if( isFull() ) perror(" Error: 큐가 포화상태입니다\n"); //error = perror 동일
        else{
            rear= (rear+1) % MAX_QUEUE_SIZE;
            data[rear]=n;
        }
    }
    BinaryNode* dequeue(){
        if (isEmpty()) perror("Error:큐가 공백상태입니다\n");
        else{
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
        return 0; //안 써주면 return 값 없어서 오류 생김.
    }

};

class BinaryTree{
    BinaryNode* root;
    public:
    BinaryTree():root(NULL){}
    ~BinaryTree(){}
    
    void setRoot(BinaryNode* node) {root=node;}
    BinaryNode* getRoot() {return root;}
    bool isEmpty() {return root ==NULL;}
    int getCount() {return isEmpty() ? 0 : getCount(root);}
    int getLeafCount() {return isEmpty() ? 0: getLeafCount(root);}
    int getHeight() {return isEmpty() ? 0 :getHeight(root);}
    void inorder() {printf("\n   inorder: "); inorder(root);}
    void preorder() {printf("\n  preorder: "); preorder(root);}
  void postorder() {printf("\n postorder: "); postorder(root);}
    void levelorder(){
        printf("\nlevelorder: ");
        if( !isEmpty() ) {
            CircularQueue q;
            q.enqueue( root );
            while (!q.isEmpty()){
                BinaryNode* n = q.dequeue();
                if(n!=NULL) {
                    printf(" [%c] ", n->getData());
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        printf("\n");
    }
    int getCount(BinaryNode *node) { //순환호출, 전체 노드 계산
        if(node == NULL) return 0;
        return 1 + getCount(node-> getLeft()) + getCount(node->getRight());
    }
    int getLeafCount(BinaryNode *node) { //단말노드 계산
        if( node ==NULL) return 0;
        if (node->isLeaf()) return 1;
        else return getLeafCount(node->getLeft())+getLeafCount(node-> getRight());
    }
    int getHeight(BinaryNode *node) { //높이, 서브트리의 높이 +1
        if(node == NULL) return 0;
      int hLeft = getHeight(node->getLeft());
      int hRight = getHeight(node->getRight());
      return (hLeft>hRight) ? hLeft+1 : hRight+1;
    }
    int calcSize() {return calcSize(root);} //폴더 용량, 후위 순회
    int calcSize (BinaryNode *node) {
        if (node == NULL) return 0;
        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
        
    }
    
    int evaluate() {return evaluate(root);} // 수식계산 함수
    int evaluate(BinaryNode *node) {
        if(node==NULL) return 0;

        if(node->isLeaf()) return node->getData();
        else{
            int op1=evaluate(node->getLeft());
            int op2= evaluate(node->getRight());
            switch(node->getData()){
                case '+': return op1+op2;
                case '-': return op1-op2;
                case'*': return op1*op2;
                case'/': return op1/op2;
            }
            return 0;
        }
    }
    private:
    void inorder(BinaryNode *node){
        if(node !=NULL) {
            if(node->getLeft() !=NULL) inorder(node->getLeft());
            printf(" [%c] ", node->getData());
            if(node->getRight()!= NULL) inorder(node->getRight());
        }
    }
    void preorder(BinaryNode *node) {
        if(node != NULL) {
            printf(" [%c] ", node ->getData());
            if(node->getLeft()!=NULL) preorder(node->getLeft());
            if(node->getRight()!= NULL) preorder(node->getRight());
        }
    }
    void postorder(BinaryNode * node) {
        if(node !=NULL){
            if(node->getLeft() != NULL) postorder(node->getLeft());
            if(node->getRight()!=NULL) postorder(node->getRight());
            printf(" [%c] ", node->getData());
        }
    }

};


int main()
{
    BinaryTree tree;
    //          A
     //      B    C
     //     D E  F
    BinaryNode *d= new BinaryNode('D', NULL, NULL);
    BinaryNode *e= new BinaryNode('E', NULL, NULL);
    BinaryNode *b = new BinaryNode('B', d,e);
    BinaryNode *f = new BinaryNode('F', NULL, NULL);
    BinaryNode *c = new BinaryNode('C', f, NULL);
    BinaryNode *a =new BinaryNode('A', b,c);
    
    
    tree.setRoot(a);

    printf(" 노드의 개수 = %d\n", tree.getCount());
    printf(" 단말의 개수 = %d\n", tree.getLeafCount());
    printf(" 트리의 높이 = %d\n", tree.getHeight());
    
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    
    
    
    
    
    
    BinaryTree tree2; //수식트리 ㅡㅡ
    //           +
    //       *       -
    //     3       2   5   6
    BinaryNode *n1 = new BinaryNode(3, NULL,NULL);
    BinaryNode *n2 = new BinaryNode(2,NULL, NULL);
    BinaryNode *n3 = new BinaryNode('*', n1,n2);
    BinaryNode *n4 = new BinaryNode(5, NULL, NULL);
    BinaryNode *n5 = new BinaryNode(6,NULL, NULL);
    BinaryNode *n6 = new BinaryNode('-', n4, n5);
    BinaryNode *n7 = new BinaryNode('+', n3,n6);

    tree2.setRoot(n7);
    printf(" 계산 결과 = %d\n",tree2.evaluate());


    BinaryTree tree3;
    BinaryNode *m4 = new BinaryNode (200, NULL, NULL);
    BinaryNode *m5 = new BinaryNode(500, NULL, NULL);
    BinaryNode *m3 = new BinaryNode(100, m4, m5);
    BinaryNode *m2 = new BinaryNode(50, NULL, NULL);
    BinaryNode *m1 = new BinaryNode(0, m2, m3);
    tree3.setRoot(m1);
    
    
    printf(" 디렉토리 용량 계산 결과 = %d KB\n",tree3.calcSize());
    
    return 0;
}
