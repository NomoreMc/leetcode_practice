#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include "lc_310.h"
using namespace std;

/* 拓扑排序  */
vector<int> Solution_310::findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> degrees(n);
    vector<int> ans;
    queue<int> que;
    unordered_map<int, vector<int>> umpGraph;
    
    /* 统计各个结点的度，以及生成图 */
    for (auto &edge: edges) {
        degrees[edge[0]]++;
        degrees[edge[1]]++;
        umpGraph[edge[0]].push_back(edge[1]);
        umpGraph[edge[1]].push_back(edge[0]);
    }
    
    for (int i=0; i<n; ++i) {
        if (degrees[i] == 1) {
            que.push(i);
        }
    }
    
    while (!que.empty()) {
        ans.clear();
        int queSize = que.size();
        while (queSize--) {
            int currNode = que.front();
            ans.push_back(currNode);
            que.pop();
            --degrees[currNode];
            for (auto &node: umpGraph[currNode]) {
                if ((--degrees[node]) == 1) {
                    que.push(node);
                }
            }
        }
    }
    return ans;
}

// int main(int argc, char **argv) {
//     Solution a;
//     /*
//         输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
//         输出：[3,4]
//     */
//     vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
//     vector<int> temp1 = a.findMinHeightTrees(6, edges);
//     for (auto num: temp1) {
//         cout<<num<<" ";
//     }
//     cout<<endl;

//     /*
//         输入：n = 4, edges = [[1,0],[1,2],[1,3]]
//         输出：[1]
//     */

//     vector<vector<int>> edges2 = {{1,0},{1,2},{1,3}};
//     vector<int> temp2 = a.findMinHeightTrees(4, edges2);
//     for (auto num: temp2) {
//         cout<<num<<" ";
//     }
//     cout<<endl;
//     return 0;
// }