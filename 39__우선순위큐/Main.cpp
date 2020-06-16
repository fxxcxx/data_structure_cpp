#include <stdlib.h>
#include <cstdio>
#define MAX_ELEMENT	200
using namespace std;

class HeapNode //공간 틀
{
	int key;
	
	public:
	HeapNode(int key=0) : key(key) {} //이름똑같으니까 생성자, defalut para = 0
	~HeapNode(void) {}
	void setKey(int k) {key = k;}
	int getKey() {return key;}
	void display() {printf("\t%d", key);}
};

class MaxHeap //MaxHeap h, h라는 객체가 노드ㅡ를 갖고 있다.
{
	HeapNode node[MAX_ELEMENT]; //힙노드 배열을 가짐 node[0] node[1] ...
	int size;
	public:
	MaxHeap(): size(0) {}
	bool isEmpty() {return size ==0;}
	bool isFull() {return size == MAX_ELEMENT-1;}
	
	HeapNode& getParent(int i){return node[i/2];} //heapnode의 reference, node[0]가져오지 못함(private이라)
	HeapNode& getLeft(int i) {return node[i*2];}
	HeapNode& getRight(int i) {return node[i*2+1];}
	
	//삽입 함수 중요
	void insert(int key){ //upheap : 삽이 노드에서 루트까지으 경로에 있는 노드들 k와(새로운 key)와 비교, k가 부모노드보 작거나 같으면 upheap break
		if(isFull()) return;
		
		int i = ++size; //제일 두 indext서 하나 늘림
		
		while(i!=1 && key>getParent(i).getKey()) {
			node[i] = getParent(i);
			i/=2;
		}
		node[i].setKey(key);
	}
	
	//delete func 중요 , 가장 큰 값 삭제 : 무조거 root 삭제 -> 가장 말단 노드 삽입 (DownHeap)
	HeapNode remove() {
		if(isEmpty()) return NULL;
		
		HeapNode root = node[1]; //루트노드(꺼낼 요소)
		HeapNode last = node[size--]; //힙의 마지막노드
		
		int parent = 1; //마지막 노드의 위치를 루틀 생각 
		int child = 2; //루트의 왼쪽 자시 위치
		
		while(child <=size){ //힙 트리를 벗어나지 않는 동안 현 노드의 자식 노드 중 더 큰 자식노드를 찾음
			if(child < size && getLeft(parent).getKey() < getRight(parent).getKey())
				child++; //child :  더 큰 자식 노드의 인덱스
			//마지막 노드가 더 큰 자식보다 크면, 이동 완료
			if(last.getKey() >= node[child].getKey()) break;
			
			//아니며 한단ㄱ 아래로
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		
		node[parent] = last; //마지마 노드를 최종 위치에..
		return root; //루트 노드 반환
	}
	HeapNode find() {return node[1];}
	
	void display() {
		for(int i=1, level=1; i<=size; i++){
			if(i==level){
				printf("\n");
				level*=2;
			}
			node[i].display();
		}
		printf("\n-------------------------------------------");
	}
};

inline void heapSort(int a[], int n)
{
	MaxHeap h;
	for(int i=0; i<n ; i++)
		h.insert(a[i]);
	
	for(int i = n-1; i>=0; i--)
		a[i] = h.remove().getKey();
}

// 주함수 
int main()
{
	MaxHeap	heap;

	// 삽입
	heap.insert( 10 );
	heap.insert( 5 );
	heap.insert( 30 );
	heap.insert( 8 );
	heap.insert( 9 );
	heap.insert( 3 );
	heap.insert( 7 );
	heap.display();

	// 삭제
	heap.remove();
	heap.display();
	heap.remove();
	heap.display();

	// 정렬
	int data[10];
	for( int i=0 ; i<10 ; i++ )
		data[i] = rand() % 100;

	printf("\n정렬전: ");
	for( int i=0 ; i<10 ; i++ )
		printf( "%3d", data[i]);

	heapSort(data,10);

	printf("\n정렬후: ");
	for( int i=0 ; i<10 ; i++ )
		printf( "%3d", data[i]);
	printf("\n");
}

