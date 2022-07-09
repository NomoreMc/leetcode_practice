#include <iostream>
#include <vector>
using namespace std;

#define MAX_TREE_NODE 1000

/*
    Query接口：返回[lBound, rBound]之间所有元素之和
              需要遍历线段树，累加所有该范围内的叶子结点的值
*/
int QuerySegmentTree(vector<int> &arr, vector<int> &tree, int currNode, int start, int end, int lBound, int rBound) {
    /* 若当前结点对应的数组下标范围已和[lBound, rBound]没有交集，那么直接返回 0 */
    if (end < lBound || start > rBound) {
        return 0;
    /* 若到达合法叶子节点，则直接返回相应叶子节点的值 */
    } else if (start == end) {
        return arr[start];
    /* 若当前节点对应的下标范围和[lBound, rBound]一毛一样，则可以直接返回该非叶子结点的值，不必再向下递归 */
    } else if (lBound == start && rBound == end) {
        return tree[currNode];
    } else {    
        int mid = (start + end) / 2;
        int leftNode = currNode * 2 + 1;
        int rightNode = currNode * 2 + 2;
        int leftSum = QuerySegmentTree(arr, tree, leftNode, start, mid, lBound, rBound);
        int rightSum = QuerySegmentTree(arr, tree, rightNode, mid+1, end, lBound, rBound);
        return leftSum + rightSum;
    }
}

/*
    Update接口：更新arr数组中下标为index的值为val
               首先是要向下找到index对应的叶子结点，更新叶子结点后，向上更新其父节点的值
*/
void UpdateSegmentTree(vector<int> &arr, vector<int> &tree, int currNode, int start, int end, int index, int val) {
    /* 到达叶子结点 */
    if (start == end) {
        /* 更新数组中下标为index的值以及更新线段树对应的叶子结点的值 */
        arr[start] = val;
        tree[currNode] = val;
    } else {
        int mid = (start + end) / 2;
        int leftNode = currNode * 2 + 1;
        int rightNode = currNode * 2 + 2;

        /* 根据index在mid左边或者右边进行向下递归搜索 */
        /* 同时需要更新当前结点的值 */
        if (index <= mid) {
            UpdateSegmentTree(arr, tree, leftNode, start, mid, index, val);
            tree[currNode] = tree[leftNode] + tree[rightNode];
        } else {
            UpdateSegmentTree(arr, tree, rightNode, mid+1, end, index, val);
            tree[currNode] = tree[leftNode] + tree[rightNode];
        }
    }
}

/* 递归建树 */
void BuildSegmentTree(vector<int> &arr, vector<int> &tree, int currNode, int start, int end) {
    if (start == end) {
        tree[currNode] = arr[start];
    } else {
        /* 
            node结点的左右子结点下标：
                left = node * 2 + 1;
                right = node * 2 + 2;
        */
        int leftNode = currNode * 2 + 1;
        int rightNode = currNode * 2 + 2;
        int mid = (start + end) / 2;

        /* 当前结点的和为 leftNode + rightNode，所以需要先计算出子结点的和 */
        BuildSegmentTree(arr, tree, leftNode, start, mid);
        BuildSegmentTree(arr, tree, rightNode, mid+1, end);
        /* 结算当前结点的和 */
        tree[currNode] = tree[leftNode] + tree[rightNode];
    }
}

int main(int argc, char **argv) {

    vector<int> array = {1, 3, 5, 7, 9, 11};
    vector<int> tree(MAX_TREE_NODE, 0);
    BuildSegmentTree(array, tree, 0, 0, array.size()-1);
    
    for (int i=0; i<15; ++i) {
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    UpdateSegmentTree(array, tree, 0, 0, array.size()-1, 4, 6);
    for (int i=0; i<15; ++i) {
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    cout<<"Query: "<<QuerySegmentTree(array, tree, 0, 0, array.size()-1, 2, 5)<<endl;
    return 0;
}