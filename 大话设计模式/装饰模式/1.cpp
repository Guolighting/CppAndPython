#include <string>
#include <iostream>
using namespace std;





class Person
{
private:
	string m_strName;
public:
	Person(string strName)
	{
		m_strName=strName;
	}
	Person(){}
	virtual void show()
	{
		cout<<"װ�����:"<<m_strName<<endl;
	}
};	

class Finery:public Person
{
protected:
	Person *m_component;
public:
	void decorate(Person* component)
	{
		m_component=component;
	}
	virtual void show()
	{
		m_component->show();
	}
};

class TShirts:public Finery
{
public:
	virtual void show()
	{
		m_component->show();
		cout<<"T shirts"<<endl;
	}
};

class BigTrouser:public Finery
{
public:
	virtual void show()
	{
		m_component->show();
		cout<<"Big Trouser"<<endl;
	}
};

int main()
{
	Person *p=new Person("С��");
	BigTrouser *bt=new BigTrouser();
	TShirts *ts=new TShirts();
		
	bt->decorate(p);
	ts->decorate(bt);
	ts->show();

	return 0;
}
 /*

//�ͻ���
int main()
{
	bt->Decorate(p);
	ts->Decorate(bt);
	ts->Show();
	return 0;
}
*/