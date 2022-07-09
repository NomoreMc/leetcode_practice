#include <iostream>
#include <vector>
using namespace std;

/* leetcode solution */
class NumArray {
public:
    NumArray(vector<int>& nums) : arr(nums) {
        int count = 1;
        int numsSize = nums.size();
        while (count < numsSize) {
            count *= 2;
        }
        tree.resize(count * 2);
        BuildSegmentTree(0, 0, arr.size()-1);
    }
    
    void update(int index, int val) {
        UpdateSegmentTree(0, 0, arr.size()-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if (left == right) {
            return arr[left];
        }
        return QuerySegmentTree(0, 0, arr.size()-1, left, right);
    }

    void printArr() {
        cout<<"array: ";
        for (auto num: arr) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    void printTree() {
        cout<<"tree: ";
        for (int i=0; i<9; ++i) {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
private:
    /* 实现线段树 */
    vector<int> arr;
    vector<int> tree;
    
    /* 建树 */
    void BuildSegmentTree(int currNode, int start, int end) {
        if (start == end) {
            tree[currNode] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftNode = currNode * 2 + 1;
            int rightNode = currNode *2 + 2;

            BuildSegmentTree(leftNode, start, mid);
            BuildSegmentTree(rightNode, mid+1, end);
            tree[currNode] = tree[leftNode] + tree[rightNode];
        }
    }

    /* 更新array中下标为index的值为val，同时更新tree中的值 */
    void UpdateSegmentTree(int currNode, int start, int end, int index, int val) {
        if (start == end) {
            arr[start] = val;
            tree[currNode] = val;
        } else {
            int mid = (start + end) / 2;
            int leftNode = currNode * 2 + 1;
            int rightNode = currNode *2 + 2;

            if (index >= start && index <= mid) {
                UpdateSegmentTree(leftNode, start, mid, index, val);
                tree[currNode] = tree[leftNode] + tree[rightNode];
            } else {
                UpdateSegmentTree(rightNode, mid+1, end, index, val);
                tree[currNode] = tree[leftNode] + tree[rightNode];
            }
        }
    }

    /* 查询array中的[lBound, rBound]之间元素的和 */
    int QuerySegmentTree(int currNode, int start, int end, int lBound, int rBound) {
        if (rBound < start || lBound > end) {
            return 0;
        } else if (start >= lBound && end <= rBound) {
            return tree[currNode];
        } else {
            int mid = (start + end) / 2;
            int leftNode = currNode * 2 + 1;
            int rightNode = currNode *2 + 2;

            int leftSum = QuerySegmentTree(leftNode, start, mid, lBound, rBound);
            int rightSum = QuerySegmentTree(rightNode, mid+1, end, lBound, rBound);
            return leftSum + rightSum;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/*
    ["NumArray","sumRange","sumRange","sumRange","update","update","update","sumRange","update","sumRange","update"]
    [[[0,9,5,7,3]],[4,4],[2,4],[3,3],[4,5],[1,7],[0,8],[1,2],[1,9],[4,4],[3,4]]
*/

int main() {
    vector<int> input = {0,9,5,7,3};
    NumArray a(input);

    cout<<"\nsum 4 4:\n";
    cout<<a.sumRange(4,4)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nsum 2 4:\n";
    cout<<a.sumRange(2,4)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nsum 3 3:\n";
    cout<<a.sumRange(3,3)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nupdate 4 5:\n";
    a.update(4,5);
    a.printArr();
    a.printTree();

    cout<<"\nupdate 1 7:\n";
    a.update(1,7);
    a.printArr();
    a.printTree();

    cout<<"\nupdate 0 8:\n";
    a.update(0,8);
    a.printArr();
    a.printTree();

    cout<<"\nsum 1 2:\n";
    cout<<a.sumRange(1,2)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nsum 1 2:\n";
    cout<<a.sumRange(3,4)<<endl;
    a.printArr();
    a.printTree();
    return 0;
}