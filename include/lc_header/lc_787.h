#ifndef __LEETCODE_787_H__
#define __LEETCODE_787_H__
#include <vector>
#include <unordered_map>

class Solution_787 {
public:
    int findCheapestPrice1(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k);
    int findCheapestPrice2(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k);

private:
    void dfs(int currPos, int currCost, int currHop);

private:
    /* struct for solution 1 */
    /* 邻接表存图 */
    std::unordered_map<int, std::vector<std::pair<int, int>>> umpGraph;
    /* 最小开销 */
    int minPrice;
    int targetHop;
    int target;
};

#endif