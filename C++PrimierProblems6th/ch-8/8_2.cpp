#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
struct CandyBar{
	string brand;
	float weight;
	int calorie;
};

void create_candy(CandyBar &candy,string s="Millennumu Munch",float w=2.85,int c=350){
	candy.brand=s;
	candy.weight=w;
	candy.calorie=c;
}

void show_candy(const CandyBar &candy){
	cout<<"The candybar is made by"<<candy.brand;
	cout<<"and its weight"<<candy.weight<<", ";
	cout<<candy.calorie<<"calorie"<<endl;
}

int main(){
	CandyBar cb;
	create_candy(cb);
	show_candy(cb);
	system("pause");
	return 0;
}