#include <iostream>
using namespace std;

double power(double x, int n)
{	
	if(n==0) //x가 아닌 n을 조건으로 두어야 함
		return 1;
	
	else 
		if(n%2 == 0) return power(x*x , n/2);
	
	else 
		return x*power(x*x, (n-1)/2);
}

//iteration 방식보다 빠름

int main()
{
    cout << "1.5^20=" << power(1.5,20) << endl;

}