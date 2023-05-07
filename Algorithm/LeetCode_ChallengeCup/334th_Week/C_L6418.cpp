#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
        vector<int> ans(queries.size(), 0);
        vector<int> arr(n + 2, 0);
        int cnt{};
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0] + 1;
            int color = queries[i][1];
            if (arr[idx]) {
                cnt -= (arr[idx] == arr[idx - 1]) + (arr[idx] == arr[idx + 1]);
            }

            arr[idx] = color;
            cnt += (arr[idx] == arr[idx - 1]) + (arr[idx] == arr[idx + 1]);
            ans[i] = cnt;
        }
        return ans;
    }
};