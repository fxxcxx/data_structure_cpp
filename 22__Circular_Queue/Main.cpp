// 코딩하시오.
#include<stdio.h>
#include<stdlib.h>

inline void error(char* str){
		fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue
{
	protected:
	int front; //첫번째 요 앞의 위치
	int rear; //마지막 요소 위치
	int data[MAX_QUEUE_SIZE];
	
	public:
		CircularQueue() {front=rear=0;}
		~CircularQueue() {} 
		bool isEmpty() {return front ==rear;}
		bool isFull() {return (rear+1)%MAX_QUEUE_SIZE == front;} //한자리 비워두었다+1
		
	void enqueue(int val){
		if(isFull())
			error(" error:큐가 포화상태입니다\n");
			else{
				rear = (rear+1) % MAX_QUEUE_SIZE;
				data[rear] = val;
			}
	}
	
	int dequeue() {
		if(isEmpty())
			error("Error:큐가 공백상태입니다.\n");
		else{
			front = (front+1) % MAX_QUEUE_SIZE;
			return data[front]; //실제로 없어지지 않지만 front 다음이 원소락 약속해서 ㅇㅇ
			
		}
	}
	
	int peek(){
		if(isEmpty())
			error(" Error:큐가 공백상태입니다\n");
		else
			return data[(front+1)%MAX_QUEUE_SIZE];
	}
	
	void display(){
		printf("큐 내용 : ");
		int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE; //front가 더 크면 한바쿠 돈거라 size만큼 플러스
		for(int i=front+1; i<=maxi; i++)
			printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
		printf("\n");
	}
};

int main()
{
	
	CircularQueue que;
	for(int i=1; i<10; i++)
		que.enqueue(i);
	
	que.display();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.display();
	
	return 0;
}
