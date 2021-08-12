#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int>mv={10,20,30};
	auto it =mv.emplace(mv.begin()+1,100);
	mv.emplace(it,200);
	mv.emplace(mv.end(),300);
	for(auto &x:mv){
		cout<<" "<<x;
	}
	system("pause");
	return 0;
}