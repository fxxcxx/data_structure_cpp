#include<iostream>
using namespace std;

class Dog{
	private:
		string name;
		int age;
	
	public:
	Dog(){
		age = 1;
		name = "바둑이";
	}
	~Dog(){ }
	int getAge(){return age;}
	void setAge(int dog_age){age = dog_age;}	
};

int main()
{
	Dog * pDog=new Dog; //pDog 포인터 생성
	cout << "강아지의 나이:"<<pDog->getAge()<<endl; //괄 호
	
	pDog->setAge(5); //pointer는 화살표로 움직입니다.
	cout<<"강아지의 나이:"<<pDog->getAge()<<endl;
	
	delete pDog;
	return 0;
}
