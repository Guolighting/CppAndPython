#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m_sum = 0;
		for(int i = 0;i < rolls.size();i++){
			m_sum += rolls[i];
		}

		int sum = mean*(rolls.size() + n);
		int n_sum = sum - m_sum;
		int n_avg = n_sum / n;
		int n_rem = n_sum % n;
		vector<int>n_rolls;
		for(int i = 0;i< n;i++){
			int n_roll = 6 - n_avg;
			if(n_rem - n_roll > 0){
				n_rem -= n_roll;
				n_rolls.push_back(n_avg + n_roll);
			}else{
				n_rolls.push_back(n_avg + n_rem);
				n_rem = 0;
			}
		}
		return n_rolls;
    }

};