#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
    给定一个长度为 n 的整数数组 nums 。
    假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
        F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
    返回 F(0), F(1), ..., F(n-1)中的最大值 。
    生成的测试用例让答案符合 32 位 整数。

    示例 1:
    输入: nums = [4,3,2,6]
    输出: 26
    解释:
        F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
        F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
        F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
        F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
    所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。

    示例 2:
    输入: nums = [100]
    输出: 0

    提示:

        n == nums.length
        1 <= n <= 105
        -100 <= nums[i] <= 100
*/

/*
    思路：
        F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6)
        F(1) = (3 * 4) + (0 * 3) + (1 * 2) + (2 * 6)
        F(2) = (2 * 4) + (3 * 3) + (0 * 2) + (1 * 6)
        F(3) = (1 * 4) + (2 * 3) + (3 * 2) + (0 * 6)

        令 N = nums.size()
    规律：
        F(1) = F(0) - (totalSum - nums[0]) + (N - 1) * nums[0];
        F(2) = F(1) - (totalSum - nums[1]) + (N - 1) * nums[1];
        .
        .
        .
        F(I) = F(I - 1) - (totalSum - nums[I - 1]) + (N - 1) * nums[I-1];
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxSum = 0;
        int totalSum = 0;
        int currSum = 0;
        int N = nums.size();

        for (int i=0; i<N; ++i) {
            totalSum += nums[i];
            currSum += i * nums[i];
        }
        
        maxSum = currSum;
        for (int i=0; i<N; ++i) {
            currSum = currSum - totalSum + N * nums[i];
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};

void test() {
    Solution a;
    vector<int> input1({4,3,2,6});
    cout<<"ans: "<<a.maxRotateFunction(input1)<<endl;

    vector<int> input2({100});
    cout<<"ans: "<<a.maxRotateFunction(input2)<<endl;    
}

int main(int argc, char **argv) {
    test();
    return 0;
}