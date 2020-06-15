#include<iostream>
using namespace std;

class Dog{
    private:
    int*pWeight;
    int*pAge;
    
    public:
        Dog(){
            pAge = new int(1);
            pWeight=new int(10);
        }
    
    ~Dog(){
        delete pAge;
        delete pWeight;
    }
    
    int getAge(){return*pAge;}
    void setAge(int age){*pAge = age;}
    int getWeight(){return*pWeight;}
    void setWeight(int weight) {*pWeight=weight;}
};

int main()
{
        Dog*pDog=new Dog;
        cout<<"강아지의 나이:"<<pDog->getAge()<<endl;
        cout<<"갱얼쥐 몸무게:"<<pDog->getWeight()<<endl;
    
        pDog->setAge(5);
        cout<<"강아지의 나이:"<<pDog->getAge()<<endl;
    pDog->setWeight(20);
    cout<<"갱얼쥐 살찜:"<<pDog->getWeight()<<endl;
    
    delete pDog;
    return 0;
}
