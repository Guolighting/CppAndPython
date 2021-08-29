#include <iostream>
#include <string>
using namespace std;

class LeiFeng
{
public:
	void sweep()
	{
		cout<<"ɨ��"<<endl;
	}

	void wash()
	{
		cout<<"ϴ�·�"<<endl;
	}
}; 

class Student:public LeiFeng
{};

class Volunteer:public LeiFeng
{};


class SimpleFactory
{
public:
	static LeiFeng *createLeiFeng(string str)
	{
		LeiFeng *lf;
		lf=NULL;
		if(str=="ѧ��")
		{
			lf=new Student();
		}
		if(str=="��Ը��")
		{
			lf=new Volunteer();
		}
		return lf;
	}
};


class IFactory
{
public:
	virtual LeiFeng *createLeiFeng()=0;
};

class StuFactory:public IFactory
{
	static LeiFeng *createLeiFeng()
	{
		return new Student();
	}
};

class VolFactory:public IFactory
{
	static LeiFeng *createLeiFeng()
	{
		return new Volunteer();
	}
};

int main()
{
 
	return 0;
}