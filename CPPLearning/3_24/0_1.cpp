#include<bits/stdc++.h>
using namespace std;

class Base{
public:
	virtual void Display()const{
		cout<<"Base::Display()"<<endl;
	}
};

class Derived:public Base{
public:
	virtual void Display(){
		cout<<"Derived::Display()"<<endl;
	}
};

int main(){
	Base *p =new Derived();
	p->Display();//Base::Display()
	Derived *p2 = new Derived();
	p2->Display();//Derived::Display()
	delete p;
	delete p2;

	system("pause");
	return 0;
}