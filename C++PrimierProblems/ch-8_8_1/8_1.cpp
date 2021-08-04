#include<bits/stdc++.h>
using namespace std;
class Pro_8_1{
public:
	void loop_print(const char *str,int n=0){
		static int func_count=0;
		func_count++;
		if(n==0){
			cout<<"Arguments=0;\n";
			cout<<str<<endl;
		}else{
			cout<<"Arguments!=0;\n";
			for(int i=0;i<func_count;i++){
				cout<<str<<endl;
			}
		}
	}
};

int main(){
	Pro_8_1 pro_8_1;
	pro_8_1.loop_print("Hello World!");
	pro_8_1.loop_print("Hello World!");
	pro_8_1.loop_print("Hello World!",5);
	Pro_8_2 pro_8_2;
	pro_8_2.create_candy()
	//system("pause");
	return 0;
}