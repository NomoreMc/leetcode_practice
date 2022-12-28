#include "lc_1094.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
    给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi]
    表示第 i 次旅行有 numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。
    这些位置是从汽车的初始位置向东的公里数。
    当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。
    
    示例 1：
    输入：trips = [[2,1,5],[3,3,7]], capacity = 4
    输出：false

    示例 2：
    输入：trips = [[2,1,5],[3,3,7]], capacity = 5
    输出：true
*/

bool Solution_1094::carPooling(vector<vector<int>>& trips, int capacity) {
    auto cmp = [](const vector<int> &lhs, const vector<int> &rhs){
        return lhs[2] > rhs[2];
    };

    /* 将原数组按照 from 从小到大排列 */
    sort(trips.begin(), trips.end(), [](const vector<int> &lhs, const vector<int> &rhs){
        return lhs[1] < rhs[1];
    });

    /* 优先队列，规则：to 较大的排前 */
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    int begin = 0;
    int currCapacity = capacity;
    for (int i=0; i<trips.size(); ++i) {
        vector<int> curr = trips[i];
        int currNum = curr[0];
        int currStart = curr[1];
        int currEnd = curr[2];
        while (!pq.empty() && pq.top()[2] <= currStart) {
            currCapacity += pq.top()[0];
            pq.pop();
        }
        if (currCapacity < currNum) {
            return false;
        }
        pq.push(trips[i]);
        currCapacity -= currNum;
    }
    return true;
}

/*
    使用一个priority_queue来保存团体，
*/