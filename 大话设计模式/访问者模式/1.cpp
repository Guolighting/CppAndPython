#include <iostream>
#include <list>
#include <string>
using namespace std;
 
 
class Person
{
public:
	string action;
	virtual void getConclusion()=0;
};


class Man:public Person
{
public:
	void getConclusion()
	{
		if(action=="�ɹ�")
		{
			cout<<"���˳ɹ�ʱ����������һ��ΰ���Ů�ˡ�"<<endl;
		}
		else if(action=="����")
		{
			cout<<"��������ʱ�����²���װ����"<<endl;
		}		
	}
};

class Woman:public Person
{
public:
	void getConclusion()
	{
		if(action=="�ɹ�")
		{
			cout<<"Ů�˳ɹ�ʱ����������ʧ�ܵ����ˡ�"<<endl;
		}
		else if(action=="����")
		{
			cout<<"��������ʱ�������¶�Ҳװ������"<<endl;
		}		
	}
};

int main()
{
	list<Person*> persons;

	Person *man1=new Man();
	man1->action="�ɹ�";
	persons.push_back(man1);

	Person *woman1=new Woman();
	woman1->action="�ɹ�";
	persons.push_back(woman1);

	Person *man2=new Man();
	man2->action="����";
	persons.push_back(man2);

	Person *woman2=new Woman();
	woman2->action="����";
	persons.push_back(woman2);

	list<Person*>::iterator iter=persons.begin();
	while(iter!=persons.end())
	{
		(*iter)->getConclusion();
		++iter;
	}
	return 0;
}