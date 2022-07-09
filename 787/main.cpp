#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
/*
    有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，
    表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
    现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，
    使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。

    1 <= n <= 100
    0 <= flights.length <= (n * (n - 1) / 2)
    flights[i].length == 3
    0 <= fromi, toi < n
    fromi != toi
    1 <= pricei <= 10^4
    航班没有重复，且不存在自环
    0 <= src, dst, k < n
    src != dst
*/

/* 回溯 + 剪枝 */
class Solution1 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        this->minPrice = INT_MAX;
        this->target = dst;
        this->targetHop = k;
        for (int i=0; i<flights.size(); ++i) {
            auto currFlight = flights[i];
            umpGraph[currFlight[0]].push_back(make_pair(currFlight[1], currFlight[2]));
        }

        dfs(src, 0, 0);
        return minPrice == INT_MAX ? -1 : minPrice;
    }
private:
    /* 邻接表存图 */
    unordered_map<int, vector<pair<int, int>>> umpGraph;
    /* 最小开销 */
    int minPrice;
    int targetHop;
    int target;

    void dfs(int currPos, int currCost, int currHop) {
        if (currPos == target && targetHop >= currHop - 1) {
            if (currCost < minPrice) {
                minPrice = currCost;
            }
        }
        if (currHop > targetHop || currCost > minPrice) {
            return;
        }
        /* 遍历该结点所有的邻接结点 */
        auto edges = umpGraph[currPos];
        for (auto edge: edges) {
            dfs(edge.first, edge.second + currCost, currHop + 1);
        }
    }
};

/* dijkstra */
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> visited(n, 0);
        vector<int> cost(n, INT_MAX);
        vector<int> parent(n, 0);
        vector<int> hop(n, 0);
        unordered_map<int, vector<pair<int, int>>> umpGraph;
        for (int i=0; i<flights.size(); ++i) {
            auto currFlight = flights[i];
            umpGraph[currFlight[0]].push_back(make_pair(currFlight[1], currFlight[2]));
        }

        visited[src] = src;
        cost[src] = 0;
        queue<int> que;
        que.push(src);
        while (!que.empty()) {
            auto currPos = que.front();
            que.pop();
            auto edges = umpGraph[currPos];
            for (auto edge: edges) {
                if (hop[currPos] <= k && cost[edge.first] > cost[currPos] + edge.second) {
                    cost[edge.first] = cost[currPos] + edge.second;
                    hop[edge.first] += 1;
                    parent[edge.first] = currPos;
                    que.push(edge.first);
                }
            }
        }
        return cost[dst];
    }
};

/* dijkstra */
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> visited(n, 0);
        vector<int> cost(n, INT_MAX);
        vector<int> parent(n, 0);
        vector<int> hop(n, 0);
        unordered_map<int, vector<pair<int, int>>> umpGraph;
        for (int i=0; i<flights.size(); ++i) {
            auto currFlight = flights[i];
            umpGraph[currFlight[0]].push_back(make_pair(currFlight[1], currFlight[2]));
        }

        visited[src] = src;
        cost[src] = 0;
        queue<int> que;
        que.push(src);
        while (!que.empty()) {
            auto currPos = que.front();
            que.pop();
            auto edges = umpGraph[currPos];
            for (auto edge: edges) {
                if (hop[currPos] <= k && cost[edge.first] > cost[currPos] + edge.second) {
                    cost[edge.first] = cost[currPos] + edge.second;
                    hop[edge.first] += 1;
                    parent[edge.first] = currPos;
                    que.push(edge.first);
                }
            }
        }
        return cost[dst];
    }
};

/*
    示例 1：
    输入: 
    n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0, dst = 2, k = 1
    输出: 200
    解释: 
    城市航班图如下
    从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。

    示例 2：
    输入: 
    n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0, dst = 2, k = 0
    输出: 500
    解释: 
    城市航班图如下
    从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
*/
void test1() {
    Solution1 a;
    vector<vector<int>> edges1 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    cout<<"case1: "<<a.findCheapestPrice(3, edges1, 0, 2, 1)<<endl;

    vector<vector<int>> edges2 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    cout<<"case1: "<<a.findCheapestPrice(3, edges1, 0, 2, 0)<<endl;
}

void test2() {
    Solution2 a;
    vector<vector<int>> edges1 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    cout<<"case1: "<<a.findCheapestPrice(3, edges1, 0, 2, 1)<<endl;

    vector<vector<int>> edges2 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    cout<<"case1: "<<a.findCheapestPrice(3, edges1, 0, 2, 0)<<endl;
}

int main(int argc, char **argv) {
    test1();
    test2();
    return 0;
}