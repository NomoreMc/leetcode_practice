#ifndef __LEETCODE_380_H__
#define __LEETCODE_380_H__
#include <vector>
#include <unordered_map>

class Solution_380 {
public:
    Solution_380() {

    }
    bool insert(int val);
    bool remove(int val);
    int getRandom();

private:
    std::unordered_map<int, int> ump;
    std::vector<int> array;
};

#endif