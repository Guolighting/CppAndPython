class Solution {
public:
    static bool cmp(vector<int>fir, vector<int>sec){
        if(fir[0] + fir[1] < sec[0] + sec[1]){
            return true;
        }
        return false;
    }
// 用堆
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>all{};
          vector<int>row{};
        for(const auto &i:nums1){
            for(const auto &j:nums2){
                row.emplace_back(i);
                row.emplace_back(j);
                all.emplace_back(row);
                row.clear();    
            }
        }

        sort(all.begin(), all.end(), cmp);       
        vector<vector<int>>res{};
        int tmpK = 0;
        for(const auto &it : all){
            if(tmpK < k){
                res.emplace_back(it);
            }

            if(tmpK >= k){
                break;
            }

            ++tmpK;
        }
        return res;
    }
};