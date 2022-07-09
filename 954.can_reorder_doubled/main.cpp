#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
题目要点：
    （1）数组长度为偶数
    （2）"重组数组"，使其满足每个0 <= i < len(arr) / 2，都有:
        arr[2*i + 1] = 2 * arr[2*i];
        
index   0  1  2  3         0  1  2  3
        4 -2  2 -4  --->  -2 -4  2  4
        
即：两两分组，奇数下标上的元素其值为偶数下标上的元素的两倍

思路：使用哈希表对每个数出现的次数进行存储，从小到大遍历arr中的每个元素
    若哈希表中能找到值为该元素两倍的元素（2*arr[index]），则说明该元
    素能找到匹配的，相应的，减少a[i]以及2*arr[i]的哈希值。若遇到哈希
    值为 0 的，则说明该元素不存在，直接返回false。
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<double, double> mp;

        /* 统计每个元素出现的次数 */
        for (auto &num: arr) {
            mp[num]++;
        }

        /* 由于map底层是红黑树实现，进行遍历时，会按照从iter->first从小到大进行遍历 */
        /* 所以无需对arr再进行排序再进行遍历，可以对map直接进行遍历，其顺序就是从小 */
        /* 到大的顺序。 */
        for (auto iter: mp) {
            /* 若当前的iter->second < 0，说明该元素被超支匹配了，返回false */
            if (iter.second < 0) {
                return false;
            }
            /* 若当前的iter->second == 0，即表示当前元素已经被先前的匹配完了 */
            if (iter.second == 0) {
                continue;
            }
            /* 根据元素的正负进行分类处理，若 > 0，则找2倍；若 < 0，则找1/2 */
            if (iter.first > 0) {
                if (!mp.count(iter.first * 2)) {
                    return false;
                }
                mp[iter.first * 2] -= iter.second;
            } else {
                if (!mp.count(iter.first / 2.0)) {
                    return false;
                }
                mp[iter.first / 2.0] -= iter.second;
            }
        }
        return true;
    }
};

void Test(vector<int> &input) {
    Solution a;
    bool ans = a.canReorderDoubled(input);
    if (ans) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
}

void PrintVec(vector<int> &vec) {
    for (auto num: vec) {
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(int argc, char **argv) {
    cout<<"case 1:\n";
    vector<int> input1 = {3, 1, 3, 6};
    PrintVec(input1);
    Test(input1);
    cout<<endl;

    cout<<"case 2:\n";
    vector<int> input2 = {2, 1, 2, 6};
    PrintVec(input2);
    Test(input2);
    cout<<endl;

    cout<<"case 3:\n";
    vector<int> input3 = {2, 4, -2, -4};
    PrintVec(input3);
    Test(input3);
    cout<<endl;

    cout<<"case 4:\n";
    vector<int> input4 = {1, 2, 4, 16, 8, 4};
    PrintVec(input4);
    Test(input4);
    cout<<endl;

    return 0;
}