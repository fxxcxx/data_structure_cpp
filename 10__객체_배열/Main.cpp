#include<iostream>
using namespace std;

class Circle
{
	
	public:
		int x,y;
		int radius;
		Circle() :x{0}, y{0}, radius{0}{ } //배열이라 대괄호 셈미콜론 없어
		Circle(int x, int y, int r):x{x}, y{y}, radius{r}{ }
	//r을 radius로 받는다...ㅁ
	void print(){
		cout<<"반지름:"<<radius<<"@("<<x<<y<<","<<y<<")"<<endl;
}
};

int main(void)
{
	Circle objArray[10];//배열
	
	for(Circle& c: objArray){ //class circle 이용, objArray서 받아와
		c.x = rand()%500;//랜덤함수자나 ㅡㅡ
		c.y = rand()%300;
		c.radius = rand()%100;
	}
	for(Circle c: objArray)
		c.print();
	
	return 0;
}
