#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_LIST_SIZE 100
using namespace std;

inline void error(char* str){
	fprintf(stderr, "%s\n", str);
	exit(1);
};

class ArrayList
{
	int data[MAX_LIST_SIZE] ; //실제 항목 값
	int length;
	
	public:
	ArrayList(void){length=0;} //생성자, void 대신 int a / length = a;
	
	void insert(int pos, int e){ //우리 추가해..? void insert(int, int); 파라미터타입, 개수  뒤에가서 다시 선언 
		//void ArrayLise :: insert(int pos, int data){,,,
		
		if(!isFull()&&pos>=0&&pos<=length){
			for(int i=length; i>pos; i--) //끝에 있는것붙 없애야함
				data[i] = data[i-1]; //for문은 여기서 끝남
			data[pos] = e;
			length++;
		}
		else error("포화상태 오류 또는 삽입 위치 오류");
	}
	
	void remove(int pos){ //응..?
		if(!isFull()&&0<=pos&&pos<length){
			for(int i=pos+1; i<length; i++) //ㅁㅁ3ㅁㅁ , 3으 뺀다고 생각
				data[i-1]=data[i];
			length--;
		}
		else error("공백상태 오류 또는 삭제 위치 오류");
	}
	
	int getEntry(int pos){return data[pos];} //pos번ㅉ 항모 변환
	
	bool isEmpty(){return length==0;}
	bool isFull(){return length==MAX_LIST_SIZE;}
	
	bool find(int item){ //int find(int ~~)
		for(int i=0; i<length; i++)
			if(data[i] == item) return true; //return i도 ㅇㅇ
		return false;
	}
	void replace(int pos, int e){
		data[pos] = e;
	}
	
	int size() {return length;}
	void display(){
		printf("[# of elements in the list = %2d] : ", length);
		for(int i=0; i<length;i++)
			printf("[%2d] ", data[i]);
		printf("\n");
	}
	
	void clear(){length=0;}
};





int main()
{
	ArrayList list;					

	list.insert( 0, 10 );			
	list.insert( 0, 20 );			
	list.insert( 1, 30 );			
	list.insert(list.size(),40 );	
	list.insert( 2, 50 );			
	list.display();					
	cout<<"the value of index 2 : "<< list.getEntry(2) <<endl;
	list.replace(0,100);
	list.display();					
	

	list.remove( 2 );				
	list.remove(list.size()-1);		
	list.remove(0);					
	list.replace(1, 90);			
	list.display();					

	list.clear();					
	list.display();					
	
	return 0;
}
