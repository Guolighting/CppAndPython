#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	bool makesquare(std::vector<int>&nums){
		if(nums.size()<4){//数量小于4时返回假
			return false;
		}
		int sum=0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];//累加求和
		}
		if(sum%4!=0){//总数不为4的整数倍时返回假
			return false;
		}//从大到小排序
		sort(nums.rbegin(),nums.rend());
		int bucket[4]={0};
		return generate(0,nums,sum/4,bucket);
	}
private:
	bool generate(int i,vector<int>&nums,int target,int bucket[]){
		if(i>=nums.size()){
			return bucket[0]==target&&bucket[1]==target
					&&bucket[2]==target&&bucket[3]==target;
		}
		for(int j=0;j<4;j++){//4个桶中分别尝试
			if(bucket[j]+nums[i]>target){//尝试j桶
				continue;
			}
			bucket[j]+=nums[i];//如果可以，则放进去
			if(generate(i+1,nums,target,bucket)){//如果放进去全部合适
				return true;
			}
			bucket[j]-=nums[i];//如果不合适则回退
		}
		return false;
	}

}