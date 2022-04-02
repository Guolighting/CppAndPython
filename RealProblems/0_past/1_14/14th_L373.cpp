#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	struct Node{
		int idxX,idxY;
		int valX,valY;
		bool operator<(const Node & other)const{
			return (valX + valY) > (other.valX +other.valY);
		}
	};

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<Node>pQ;
		for(auto i = 0; (i < nums2.size()) && (i < k); ++i){
			Node aNode{};
			aNode.idxX = 0;
			aNode.idxY = i;
			aNode.valX = nums1[aNode.idxX];
			aNode.valY = nums2[aNode.idxY]; 
			pQ.emplace(aNode);
		}

		vector<vector<int>> res{};
		while(!pQ.empty() && --k){
			Node tmpNode = pQ.top();
			pQ.pop();

			res.emplace_back(vector<int,int>{tmpNode.valX, tmpNode.valY});
			if(tmpNode.idxX < (nums2.size() - 1)){
				tmpNode.valX = nums1[++tmpNode.idxX];
				pQ.emplace(tmpNode);
			}
		}
		return res;
    }
};