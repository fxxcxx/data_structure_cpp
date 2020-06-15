#include <iostream>
using namespace std;
//Complex 클래스를 구현해라.
class Complex{
	
	int real;
	int imag;
	
	public:
	Complex(){}	//생성자, 얜 지우면 에러남
	  ~Complex() {}; //소멸자, 안넣어도 에러는 안남
	
	Complex(int r, int i){
		real = r; 
		imag = i;
	}
	void add(Complex a, Complex b)
	{
		real = a.real + b.real; //겁먹지마 다른것들 덧셈이라 Complex로 받아야된다..!
		imag = a.imag + b.imag;
	}
	
	void print()
	{
		if(imag>0) //!!class public과 동일하게
		cout<<"("<<real<<"+"<<imag<<"i"<<")"<<endl;	
		else
		cout<<"("<<real<<imag<<"i"<<")"<<endl;
		}
		
};

		

int main()
{
    Complex a(7, 8);
    a.print();
    cout << "+";
    Complex b(2, 9);
    b.print();
    cout << "=";
    Complex c;
    c.add(a, b);
    c.print();
    cout << endl;

    Complex d(5, 3);
    d.print();
    cout << "+";
    Complex e(3, -4);
    e.print();
    cout << "=";
    Complex f;
    f.add(d, e);
    f.print();
    cout << endl;


    return 0;
}
