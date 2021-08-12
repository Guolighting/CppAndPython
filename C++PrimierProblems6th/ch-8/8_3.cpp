#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void uppercase(string &s){
	for(int i=0;i<s.size();i++){
		s[i]=toupper(s[i]);
	}
}
int main(){
	string st;
	cout<<"Enter a string (q to quit)";
	getline(cin,st);
	while(st!="q"){
		uppercase(st);
		cout<<st<<endl;
		cout<<"Next string(q to quit):";
		getline(cin,st);
	}
	cout<<"Bye."<<endl;
	return 0;
}