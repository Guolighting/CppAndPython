#include<bits/stdc++.h>
using namespace std;
int countMaxOrSubsets(vector<int>&nums){
	int cnt = 0, maxVal = 0, n = (int)nums.size();
	for(int i =0 ;i < (1 << n); ++i){
		int _max = 0;
		for (int j = 0; j<n; ++j){
			if((1<<j) & i) _max|= nums[j];
		}

		if ( maxVal < _max){
			cnt = 1;
			maxVal = _max;
		}else if( maxVal == _max) ++cnt;
	}
	return cnt;
}
int main(){
	vector<int>nums{3,2,1,5};
	cout<<countMaxOrSubsets(nums)<<endl;
	system("pause");
	return 0;
}