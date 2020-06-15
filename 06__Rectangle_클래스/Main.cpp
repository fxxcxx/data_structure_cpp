#include <iostream>
using namespace std;
//필요한 코드를 작성해라.

class Rectangle{
	
	int width, height;
	
	public:
	
		Rectangle(int w, int h);
		int calcArea();
};

//class내 외부 선언 -> ::

Rectangle::Rectangle(int w, int h){ //생성자 외부 선언
	width = w;
	height = h; //class 안의 함수형태로 바꿔줌
}

int Rectangle::calcArea(){ //클래스 외부에서 멤버함수 정의
	return width*height;
}

int main()
{
	Rectangle r{ 3, 4 };

	cout << "사각형의 넓이 : " << r.calcArea() << '\n';
	return 0;
}
