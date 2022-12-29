#ifndef __LEETCODE_307_H__
#define __LEETCODE_307_H__
#include <vector>

class Solution_307 {
public:
    Solution_307(std::vector<int>& nums) : arr(nums) {
        int count = 1;
        int numsSize = nums.size();
        while (count < numsSize) {
            count *= 2;
        }
        tree.resize(count * 2);
        BuildSegmentTree(0, 0, arr.size()-1);
    }
    void update(int index, int val);
    int sumRange(int left, int right);
    void printArr();
    void printTree();
private:
/* 实现线段树 */
    std::vector<int> arr;
    std::vector<int> tree;
    void BuildSegmentTree(int currNode, int start, int end);
    void UpdateSegmentTree(int currNode, int start, int end, int index, int val);
    int QuerySegmentTree(int currNode, int start, int end, int lBound, int rBound);
};

#endif