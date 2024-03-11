#include<bits/stdc++.h>
using namespace std;

class FrequencyTracker {
public:
    unordered_map<int, int>cntNum{};// number 的出现次数
    unordered_map<int, int> fre{};// number 的出现次数的出现次数
    FrequencyTracker() {
    }
    
    void add(int number) {
        --fre[cntNum[number]];// 只有当 frequency 为0的时候， 才有可能为负数， 但是真实的frequency不可能为0
        ++fre[++cntNum[number]];
    }
    
    void deleteOne(int number) {
        if (!cntNum[number]) {
            return;
        }

        --fre[cntNum[number]];
        ++fre[--cntNum[number]];
    }
    
    bool hasFrequency(int frequency) {
        return fre[frequency];
    }
};