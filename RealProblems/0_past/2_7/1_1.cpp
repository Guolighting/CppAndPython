#include<bits/stdc++.h>
using namespace std;
void f1(){
	static int a = 1;
	a++;
	cout<<a<<endl;
}

int main(){
	f1();
	f1();
	system("pause");
	return 0;
}