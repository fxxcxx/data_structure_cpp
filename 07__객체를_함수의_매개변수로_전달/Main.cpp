#include <iostream>
using namespace std;

class Pizza {
public:
	Pizza(int s) : size(s) { } //멤버변수 size를 s로 초기화. 생성자
	int size;			// 단위: 인치
};

	void makeDouble(Pizza& p) //일반적인 함수, 복사해서 넘어간다 
		//참조자를 사용하여 객체를 변경하면 원 객체도 변경 된다. 기호는 &
{
	p.size *= 2;
}

int main()
{
	Pizza pizza(10); //객체
	makeDouble(pizza); //객체 피자가 메이크더블 함수의 매개 변수 P로 복사
	cout << pizza.size << "인치 피자" << endl; //P의 사이즈는 바뀌지만 객체 피자의 사이즈는 X 
	return 0;
}