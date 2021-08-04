#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	bool makesquare(vector<int>&nums){
		if(nums.size()<4){
			return false;
		}
		int sum=0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
		}
		if(sum%4){
			return false;
		}
		int target=sum/4;
		vector<int>ok_subset;
		vector<int>ok_half;
		int all=;//1<<nums.size()
		for(int i=0;i<all;i++){
			int sum=0;
			for(int j=0;j<nums.size();j++){
				if(i&(1<<j)){
					sum+=nums[j];
				}
			}
			if(sum==target){
				ok_subset.push_back(i);
			}
		}
		for(int i=0;i<ok_half.size)
	}
}