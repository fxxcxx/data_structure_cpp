#include<iostream>
using namespace std;

class Circle{
	public:
		int radius; //반지름
		string color; //색상
	
		double calcArea(){
			return 3.14*radius*radius;
		}
};

int main(){
	Circle obj;
	
	obj.radius = 100;
	obj.color = "blue";
	
	cout<<"원의 면적 ="<<obj.calcArea()<<"\n";
	return 0;
}