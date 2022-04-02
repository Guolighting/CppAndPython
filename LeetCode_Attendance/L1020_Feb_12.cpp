class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_map<int, int> evens{};
        unordered_map<int, int> odds{};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i % 2 == 0)
            {
                evens[nums[i]]++;
            }
            else (i % 2)
            {
                odds[nums[i]]++;
            }
        }

        int maxEvensNum1{};
        int maxEvensValue1{};
        for (const auto &it : evens)
        {
            if (maxEvensNum1 < it.second)
            {
                maxEvensValue1 = it.first;
                maxEvensNum1 = it.second;
            }
        }

        int maxOddsNum1{};
        for (const auto &it : odds)
        {
            if ((it.first != maxEvensValue1) && (maxOddsNum1 < it.second))
            {
                maxOddsNum1 = it.second;
            }
        }
        return nums.size() - maxEvensNum1 - maxOddsNum1;
    }
};