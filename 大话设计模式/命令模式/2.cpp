//��һ�������װΪһ�����󣬴Ӷ�ʹ����ò�ͬ������
//�Կͻ����в��������������Ŷӻ��߼�¼������־���Լ�֧�ֿɳ���������





#include<iostream>
#include <string>
using namespace std;

class Receiver
{
public:
	void action()
	{
		cout<<"ִ������"<<endl;
		//�������ִ��������
	}
};

class Command
{
protected:
	Receiver *receiver;
public:
	Command(Receiver *receiver)
	{
		this->receiver=receiver;
	}
	virtual void execute()=0;
};

class ConcreteCommand:public Command
{
public:
	ConcreteCommand(Receiver *receiver):Command(receiver)
	{}
	void execute()
	{
		receiver->action();
	}
};

class Invoker
{
private:
	Command *command;
public:
	void setCommand(Command *command)
	{
		this->command=command;
	}
	void executeCommand()
	{
		command->execute();
	}
};

int main()
{
	Receiver *r=new Receiver();
	Command *c=new ConcreteCommand(r);
	Invoker *i=new Invoker();

	i->setCommand(c);
	i->executeCommand();
	return 0;
}







 