#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class CashSuper
{
public:
	virtual double acceptMoney(double money)=0;
};

class CashNormal:public CashSuper
{
public:
	double acceptMoney(double money)
	{
		return money;
	}
};

class CashRebate:public CashSuper
{
private:
	double discount;
public:
	CashRebate(double dis)
	{
		discount=dis;
	}
	double acceptMoney(double money)
	{
		return money*discount;
	}
};


class CashReturn:public CashSuper
{
private:
	double moneyCondition;
	double moneyReturn;
public:
	CashReturn(double mc,double mr)
	{
		moneyCondition=mc;
		moneyReturn=mr;
	}
	double acceptMoney(double money)
	{
		double result=money;
		if(money>=moneyCondition)
		{
			result=money-floor(money/moneyCondition)*moneyReturn;
		}
		return result;
	}
};

class CashFactory
{
public:
	static CashSuper *createCashAccept(string str)
	{
		CashSuper *cs=NULL;
		if(str=="�����շ�")
		{
			return new CashNormal();
		}
		else if(str=="��9��")
		{
			return new CashRebate(0.9);
		}
		else if(str=="��300��200")
		{
			return new CashReturn(300,200);
		}
		return cs;
	}
};


int main()
{
	CashSuper *cs;
	
	cs=CashFactory::createCashAccept("��9��");
	cout<<cs->acceptMoney(1000)<<endl;

	cs=CashFactory::createCashAccept("�����շ�");
	cout<<cs->acceptMoney(1000)<<endl;

	return 0;
}