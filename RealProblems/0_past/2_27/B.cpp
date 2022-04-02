#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
	int minSteps(string s, string t)
	{
		map<char, int> char_nums;
		map<char, int> char_numt;
        map<char,int>char_tot;
		for (const auto &ch : s)
		{
			char_nums[ch]++;
            char_tot[ch]++;
		}
        
		for (const auto &ch : t)
		{
			char_numt[ch]++;
		}

		for (const auto &ch : t)
		{
			if (char_nums[ch] < char_numt[ch])
			{
                char_tot[ch] = char_numt[ch] - char_nums[ch];
			}
		}
        
        int totNum{0};
        for(const auto &it :char_tot){
            totNum += it.second - char_nums[it.first];
        }
        
        for(const auto &it : char_tot){
            totNum += it.second - char_numt[it.first];
        }
        return totNum;
	}
};
