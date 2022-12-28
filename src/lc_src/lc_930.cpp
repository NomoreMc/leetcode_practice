#include "lc_930.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 暴力搜索 */
int Solution_930::numSubarraysWithSum1(vector<int>& nums, int goal) {
    vector<int> prefixSum(nums);
    
    for (int i=1; i<prefixSum.size(); ++i) {
        prefixSum[i] += prefixSum[i-1];
    }

    int ans = 0;
    for (int i=0; i<prefixSum.size(); ++i) {
        if (prefixSum[i] == goal) {
            ++ans;
        }
        for (int j=0; j<i; ++j) {
            if (prefixSum[i] - prefixSum[j] < goal) {
                break;
            } else if (prefixSum[i] - prefixSum[j] == goal) {
                ++ans;
            }
        }
    }
    return ans;
}


/* 使用hash table存储相同和的数组个数 */
int Solution_930::numSubarraysWithSum2(vector<int>& nums, int goal) {
    int currSum = 0;
    int ans = 0;
    unordered_map<int, int> ump;

    for (int i=0; i<nums.size(); ++i) {
        currSum += nums[i];
        if (currSum == goal) {
            ++ans;
        }
        int gap = currSum - goal;
        if (gap >= 0 && ump.find(gap) != ump.end()) {
            ans += ump[gap];
        }
        ump[currSum]++;
    }
    return ans;
}