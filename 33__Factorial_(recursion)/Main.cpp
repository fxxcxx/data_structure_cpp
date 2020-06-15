#include <iostream>
using namespace std;

int factorial(int a){
	int sum = 1;
	
	for(int i=1 ; i<=a ; i++){
			sum = sum*i;
	}
	return sum;
}

int main()
{
    cout << "10!=" << factorial(10) << endl;
	
    return 0;
}