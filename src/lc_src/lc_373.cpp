#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include "lc_373.h"
using namespace std;

vector<vector<int>> Solution_373::kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> ans;

    if (m && n == 0) {
        return {};
    }

    /* 使用set<tuple>来存储候选结点，因为set对相同结点只会存一次 */
    set<tuple<int, int, int>> st;
    st.insert({nums1[0] + nums2[0], 0, 0});
    while (ans.size() < k && st.size()) {
        auto curr = st.begin();
        int currIndex1 = get<1>(*curr);
        int currIndex2 = get<2>(*curr);
        ans.push_back({nums1[currIndex1], nums2[currIndex2]});
        st.erase(curr);
        if (currIndex1 + 1 < m) {
            st.insert({nums1[currIndex1 + 1] + nums2[currIndex2], currIndex1 + 1, currIndex2});
        }
        if (currIndex2 + 1 < n) {
            st.insert({nums1[currIndex1] + nums2[currIndex2 + 1], currIndex1, currIndex2 + 1});
        }
    }
    return ans;
}

vector<vector<int>> Solution_373::kSmallestPairs2(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    bool flag = true;
    vector<vector<int>> ans;

    if (m && n == 0) {
        return {};
    }

    if (m > n) {
        swap(nums1, nums2);
        swap(m, n);
        flag = false;
    }

    auto cmp = [&](const pair<int, int> &lhs, const pair<int, int> &rhs){
        return (nums1[lhs.first] + nums2[lhs.second]) > (nums1[rhs.first] + nums2[rhs.second]);
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    for (int i=0; i<min(k, m); ++i) {
        pq.push(make_pair(i, 0));
    }

    while (ans.size() < k && pq.size()) {
        auto curr = pq.top();
        pq.pop();
        flag ? ans.push_back({nums1[curr.first], nums2[curr.second]}): ans.push_back({nums2[curr.second], nums1[curr.first]});
        if (curr.second + 1 < n) {
            pq.push(make_pair(curr.first, curr.second + 1));
        }
    }
    return ans;
}

// void test1() {
//     Solution1 a;
//     vector<int> nums1({1,1,2});
//     vector<int> nums2({1,2,3});

//     cout<<"case1: \n";
//     vector<vector<int>> ans = a.kSmallestPairs(nums1, nums2, 10);
//     for (auto vec: ans) {
//         cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
//     }
//     cout<<endl;
// }

// void test2() {
//     Solution1 a;
//     vector<int> nums1({1,2});
//     vector<int> nums2({3});

//     cout<<"\ncase2: \n";
//     vector<vector<int>> ans = a.kSmallestPairs(nums1, nums2, 3);
//     for (auto vec: ans) {
//         cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
//     }
//     cout<<endl;
// }

// void test3() {
//     Solution2 a;
//     vector<int> nums1({1,1,2});
//     vector<int> nums2({1,2,3});

//     cout<<"\ncase3: \n";
//     vector<vector<int>> ans = a.kSmallestPairs(nums1, nums2, 10);
//     for (auto vec: ans) {
//         cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
//     }
//     cout<<endl;
// }

// void test4() {
//     Solution2 a;
//     vector<int> nums1({1,2});
//     vector<int> nums2({3});

//     cout<<"\ncase4: \n";
//     vector<vector<int>> ans = a.kSmallestPairs(nums1, nums2, 3);
//     for (auto vec: ans) {
//         cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
//     }
//     cout<<endl;
// }

// int main(int argc, char **argv) {
//     test1();
//     test2();
//     test3();
//     test4();
//     return 0;
// }