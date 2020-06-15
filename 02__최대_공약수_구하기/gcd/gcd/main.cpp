#include <iostream>
using namespace std;


int find_gcd(int, int);

int main() {
    
    int a,b;
    cout <<"a=";
    cin>>a;
    
    cout <<"b=";
    cin>>b;
    
    cout<<"GCD="<<find_gcd(a,b);
    
    return 0;
    
}
// 아래에 필요함 함수를 작성하시오.

int find_gcd(int a, int b)
{
    if (a==0 || b==0)
        return 0;
    else if (a==b)
        return a;
    else if (a>b)
        return find_gcd(a-b, b);
    else return find_gcd(a, b-a) ;
}
