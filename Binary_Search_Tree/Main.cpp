#pragma once
#include <stdio.h>

class BinaryNode
{
protected:
	int			data;
	BinaryNode	*left;
	BinaryNode	*right;
public:
	BinaryNode( int val=0, BinaryNode *l=NULL, BinaryNode *r=NULL)
			: data(val), left(l), right(r) { }
	~BinaryNode()	{ }

	void		setData ( int val )		{ data	= val; }
	void		setLeft (BinaryNode *l)	{ left	= l; }
	void		setRight(BinaryNode *r)	{ right	= r; }
	int			getData ()				{ return data; }	
	BinaryNode*	getLeft ()				{ return left; }	
	BinaryNode*	getRight()				{ return right; }	
	bool		isLeaf()	{ return left==NULL && right==NULL; }
};

class BinaryTree
{
protected:
	BinaryNode*	root;
public:

	BinaryTree(): root(NULL) { }
	~BinaryTree()	{ }

	void setRoot(BinaryNode* node)	{ root = node; }
	BinaryNode* getRoot()			{ return root; }
	bool isEmpty()	{ return root==NULL; }

	int	getCount()	{ return isEmpty() ? 0 : getCount(root); }
	int	getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root); }
	int	getHeight()	{ return isEmpty() ? 0 : getHeight(root); }
	void inorder()	{ printf("\n   inorder: "); inorder(root); }
	void preorder()	{ printf("\n  preorder: "); preorder(root); }
	void postorder(){ printf("\n postorder: "); postorder(root); }
	

	int getCount(BinaryNode *node) {
		if( node == NULL ) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	int getLeafCount(BinaryNode *node) {
		if( node == NULL ) return 0;
		if( node->isLeaf() ) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	int getHeight(BinaryNode *node)	{
		if( node == NULL ) return 0;
		int	hLeft  = getHeight(node->getLeft());
		int	hRight = getHeight(node->getRight());
		return (hLeft>hRight) ? hLeft+1 : hRight+1;
	}
	int	calcSize()	{ return calcSize(root); }
	int calcSize(BinaryNode *node)	{
		if( node == NULL ) return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}	


private:
	// 트리의 순회
	void inorder(BinaryNode *node) {
		if( node != NULL ) {
			if( node->getLeft() != NULL ) inorder(node->getLeft());
			printf( " [%2d]", node->getData());
			if( node->getRight()!= NULL ) inorder(node->getRight());
		}
	}
	void preorder(BinaryNode *node) {
		if( node != NULL ) {
			printf( " [%2d]", node->getData());
			if( node->getLeft() != NULL ) preorder(node->getLeft());
			if( node->getRight()!= NULL ) preorder(node->getRight());
		}
	}
	void postorder(BinaryNode *node) {
		if( node != NULL ) {
			if( node->getLeft() != NULL ) postorder(node->getLeft());
			if( node->getRight()!= NULL ) postorder(node->getRight());
			printf( " [%2d]", node->getData());
		}
	}
};
class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void){}
	~BinSrchTree(void){}
	
	BinaryNode* search(int key){
	BinaryNode* node = search(root, key);
	
	if(node != NULL)
	printf("\n탐색 성공: 키값이 %d인 노드 있음\n", node->getData());
	else
	printf("\n탐색 실패: 키값이 %d인 노드 없음\n", key);
	return node;
	}
BinaryNode* search(BinaryNode *n, int key){
if(n==NULL) return NULL;

	if(key==n->getData())
		return n;
	else if(key <n->getData())
		return search(n->getLeft(),key);
	else
		return search(n->getRight(),key);
}

void insert(BinaryNode* n){
if(n==NULL) return;
if(isEmpty())
root = n;
else insert(root, n);
}
void insert(BinaryNode* r, BinaryNode* n){
	if(n->getData() == r->getData())
	 return;
	 else if(n->getData() < r ->getData()){
	 if(r->getLeft() == NULL)
	 r->setLeft(n);
	 else 
	 insert(r->getLeft(),n);
	 }
	 else{
	 if(r->getRight() == NULL)
	 r->setRight(n);
	 else 
	 insert(r->getRight(), n);
	 }
}
void remove(int data){
if(isEmpty()) return;

BinaryNode *parent=NULL;
BinaryNode *node = root;
while(node != NULL && node->getData() != data){
parent=node;
node=(data<node->getData())
?node->getLeft()
:node->getRight();
}

if(node==NULL){
	printf("Error:key is not in the tree!\n");
	return;
}
else remove(parent, node);
}
void remove (BinaryNode *parent, BinaryNode *node){

	if(node->isLeaf()){
	if(parent == NULL) root = NULL;
	else{
	if(parent->getLeft() ==node )
	parent->setLeft(NULL);
	else
	parent->setRight(NULL);
	}
}

else if(node->getLeft()==NULL||node->getRight()==NULL){
BinaryNode *child = (node->getLeft() != NULL)
?node->getLeft()
:node -> getRight();

if(node == root)
	root = child;
	else{
	if(parent->getLeft() == node)
	parent -> setLeft(child);
	else
	parent->setRight(child);
	}
}

else{
BinaryNode* succp = node;
BinaryNode* succ = node->getRight();
while(succ->getLeft() != NULL){
succp = succ;
succ = succ->getLeft();
}

if(succp->getLeft() == succ)
succp->setLeft(succ->getRight());
else
succp->setRight(succ->getRight());

node->setData(succ->getData());

node=succ;
}

delete node;
}

};//class BinSrchTree




int main()
{
	BinSrchTree tree;

	// 삽입 연산 테스트
	tree.insert( new BinaryNode(35) );
	tree.insert( new BinaryNode(18) );
	tree.insert( new BinaryNode(7 ) );
	tree.insert( new BinaryNode(26) );
	tree.insert( new BinaryNode(12) );
	tree.insert( new BinaryNode(3 ) );
	tree.insert( new BinaryNode(68) );
	tree.insert( new BinaryNode(22) );
	tree.insert( new BinaryNode(30) );
	tree.insert( new BinaryNode(99) );

	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d", tree.getHeight());

	tree.inorder();
	tree.preorder();
	tree.postorder();
	
	tree.search(26);
	tree.search(25);

	// 삭제 연산 테스트
	printf("\n 삭제: case 1 ==> 노드  3 삭제");
	tree.remove( 3 );
	tree.inorder();
	printf("\n 삭제: case 2 ==> 노드 68 삭제");
	tree.remove( 68 );
	tree.inorder();
	printf("\n 삭제: case 3 ==> 노드 18 삭제");
	tree.remove( 18 );
	tree.inorder();
	printf("\n 삭제: case 3 ==> 노드 35 삭제 (루트 노드 삭제)");
	tree.remove( 35 );
	tree.inorder();

	// 최종 트리 정보 출력
	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
}

