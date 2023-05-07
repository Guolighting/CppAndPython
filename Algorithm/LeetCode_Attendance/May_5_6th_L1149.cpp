#include<iostream>
using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {

    }
};

int main(){

    return 0;
}

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if (time.size() == 0U) {
            return 0;
        }

        vector<int> idx{};
        for (int i = 0U; i < time.size(); i++) {
            if (time[i] % 60 == 0U) {
                idx.emplace_back(i);
            } else {
                time[i] = time[i] % 60;
            }
        }

        int cnt = idx.size();
        for (auto &id: idx) {
            time.erase(id);
        }

        
    }