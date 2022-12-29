#include <iostream>
#include <vector>
#include "lc_728.h"
using namespace std;

vector<int> Solution_728::selfDividingNumbers1(int left, int right) {
    vector<int> ans;
    for (int i=left; i<=right; ++i) {
        int curr = i;
        // bool flag = false;
        while (curr != 0) {
            int divisor = curr % 10;
            curr /= 10;
            if (!divisor) {
                break;
            }
            if ((i % divisor) != 0) {
                break;
            }
            if (curr == 0) {
                ans.push_back(i);
            }
        }
    }
    for (auto num: ans) {
        cout<<num<<" ";
    }
    return ans;
}

vector<int> Solution_728::selfDividingNumbers2(int left, int right) {
    vector<int> ans;
    for (int i=left; i<=right; ++i) {
        string curr = to_string(i);
        int j = 0;
        for (; j<curr.size(); ++j) {
            if (curr[j] == '0') {
                break;
            }
            if ((i % (curr[j] - '0')) != 0) {
                break;
            }
        }
        if (j == curr.size()) {
            ans.push_back(i);
        }
    }
    for (auto num: ans) {
        cout<<num<<" ";
    }
    return ans;
}

// void test(int left, int right) {
//     Solution2 a;
//     a.selfDividingNumbers(left, right);
//     cout<<endl;
// }

// int main(int argc, char **argv) {
//     cout<<"case 1:\n";
//     test(1, 22);

//     cout<<"case 2:\n";
//     test(47, 85);
//     return 0;
// }