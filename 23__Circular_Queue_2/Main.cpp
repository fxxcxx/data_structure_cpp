#pragma once
#include <stdio.h>
#include <stdlib.h>

inline void error(const char* str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
};

#define MAX_QUEUE_SIZE    10

class CircularQueue
{
protected:
    int    front;
    int    rear;
    int    data[MAX_QUEUE_SIZE];
    int lastOp;

//CircularQueue의 필요한 부분을 작성해라.
public:
    CircularQueue() {front=rear=lastOp=0;}
    ~CircularQueue() {}
    
    bool isFull(){
        return lastOp== (MAX_QUEUE_SIZE);
    }
    bool isEmpty(){
        return lastOp == 0;
    }

    void enqueue(int val){ //enqueue dequeue isfull isempty 주의
        if(isFull()){}
        else{
            data[rear] = val;
            rear = (rear+1)%(MAX_QUEUE_SIZE);
            lastOp ++;}
    }
    
    int dequeue(){
    
        int fr = 0;
        
        if(isEmpty()){
            printf("queue is empty");
            return fr;
        }
        else{
            fr = data[front]; //4개절차, dequeue 밑에 선언한  fr에 data
            //return은 fr
            front = (front+1)%MAX_QUEUE_SIZE;
            lastOp --;
            return fr;}
    }
    
    int peek(){ //int peek 까먹지 말기!
        if(isEmpty())
            error("error");
        else
            return data[(front+1) % (MAX_QUEUE_SIZE)];
        return 0;
    }
    
    void display(){
        printf("큐 내용 : ");
        int maxi = (rear>front) ? rear : rear+MAX_QUEUE_SIZE; //rear가 큰게 정상.
        for(int i=front; i<maxi; i++) //i=0이 아니고 front!!!! 기본 queue는 front+1
            printf("%2d", data[i%MAX_QUEUE_SIZE]); //여기도 ㅠㅠ 무조건 data는 front 느낌이댜
        printf("\n");
    }

};

int main()
{
    CircularQueue que;
    for (int i = 1; i < 15; i++)
        que.enqueue(i);
    que.display();
    for (int i = 1; i < 6; i++)
        que.dequeue();
    que.display();
    for (int i = 1; i < 15; i++)
        que.enqueue(i);
    que.display();

    return 0;
}
