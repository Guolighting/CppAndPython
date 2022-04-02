#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int ans = 0;
	bool check(string &s){
		int l = 0, r = s.size() - 1;
		while(l < r){
			if(s[l++] != s[r--]){
				return false;
			}
		}
		return true;
	}

	void dfs(string s, string s1, string s2, int index){
		if(check(s1) && check(s2)){
			ans = max(ans, int(s1.size() * s2.size()));
		}
		if(index == s.size()) return;
		dfs(s, s1 + s[index], s2, index + 1);
		dfs(s, s1, s2 + s[index], index + 1);
		dfs(s, s1, s2, index + 1);
	}

    int maxProduct(string s) {
        string s1, s2;
		dfs(s, s1, s2, 0);
		return ans;
    }
};	
int main(){
	Solution s;
	cout<< s.maxProduct("leetcodecom") <<endl;
	system("pause");
	return 0;
}