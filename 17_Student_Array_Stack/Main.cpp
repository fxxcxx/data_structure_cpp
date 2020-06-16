//여기에 코딩해라.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

class Student
{
    int id; //학번
    char name[MAX_STRING]; //이름
    char dept[MAX_STRING]; //소속 학과
    
    public:
        Student(int i=0, char* nam="", char* dep=""){
            set(i, nam, dep); //set으로 넘어가
        }
    
    //set함수
    void set(int i, char* nam, char* dep){
        id = i;
        strcpy(name, nam);
        strcpy(dept, dep);
    }
    void display(){
        printf("학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
    }
};


inline void error(char* str){
    printf("%s\n",str);
    exit(0);
};

//Studentstack : 학생정보 스택 클래스
class StudentStack{
    
    int top;
    Student data[MAX_STACK_SIZE];
    
public:
    StudentStack() {top = -1;} //위에 있는걸 초기값을 해줘 ㅡㅡ
    ~StudentStack () {}
    bool isEmpty() {return top == -1;}
    bool isFull() {return top == MAX_STACK_SIZE-1;}
    
    void push(Student e){ //student class..
        if(isFull()) error("스택포화에러");//push, pop은 무조건 bool조건 체킹
        else{
            data[++top] = e;
        }
        
    }
        
        Student pop(){ //return 값이 student라서 ㅎ ㅎ
            if(isEmpty()) error("스택 공백 에러");
            else{
                return data[top--]; //pop이나 dequeue나 return은 똑같넹
            }
            return 0;
        }
        
        Student peek(){
            if(isEmpty()) error("스택 공백 에러");
            return data[top];
        }
        
        void display(){
            printf("전체 학생의 수 = %2d", top+1);
            for(int i=0; i<=top; i++)
                data[i].display(); //꼴 외우기
            printf("\n");
        }
};

int main()
{
    StudentStack stack;
    stack.push(Student(1, "김아무개","전정공"));
    stack.push(Student(2, "박아무개","전정공"));
    stack.push(Student(3, "이아무개", "컴공"));
    
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    stack.peek();
    
    return 0;
}
