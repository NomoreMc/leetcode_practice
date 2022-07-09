#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 暴力搜索 */
class Solution1 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
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
};

/* 使用hash table存储相同和的数组个数 */
class Solution2 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
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
};

void test1() {
    Solution1 a;
    vector<int> nums({1,0,1,0,1});

    cout<<"ans: "<<a.numSubarraysWithSum(nums, 2)<<endl;
}

void test2() {
    Solution2 a;
    vector<int> nums({1,0,1,0,1});

    cout<<"ans: "<<a.numSubarraysWithSum(nums, 2)<<endl;
}

int main(int argc, char **argv) {
    test1();
    test2();
    return 0;
}