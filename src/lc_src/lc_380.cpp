#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <algorithm>
#include "lc_380.h"
using namespace  std;
    
bool Solution_380::insert(int val) {
    if (ump.count(val)) {
        return false;
    }
    array.push_back(val);
    ump[val] = array.size()-1;
    return true;
}

bool Solution_380::remove(int val) {
    if (!ump.count(val)) {
        return false;
    }
    
    /* 如果该元素在数组的最末，直接删除并返回 */
    if (ump[val] == (array.size()-1)) {
        ump.erase(val);
        array.pop_back();
        return true;
    }
    
    /* 更新当前对位在ump中的val */
    ump[array[array.size()-1]] = ump[val];
    swap(array[ump[val]], array[array.size()-1]);
    array.pop_back();
    ump.erase(val);
    return true;
}

int Solution_380::getRandom() {
    size_t size = array.size();
    if (size == 1) {
        return array[0];
    }
    size_t random = (rand() % (size - 0)) + 0;
    return array[random];
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// void test() {
//     RandomizedSet a;
//     cout<<"insert 1: "<<a.insert(1)<<endl;
//     cout<<"remove 2: "<<a.remove(2)<<endl;
//     cout<<"insert 2: "<<a.insert(2)<<endl;
//     cout<<"getRandom: "<<a.getRandom()<<endl;
//     cout<<"remove 1: "<<a.remove(1)<<endl;
//     cout<<"insert 2: "<<a.insert(2)<<endl;
//     cout<<"getRandom: "<<a.getRandom()<<endl;
// }

// int main(int argc, char **argv) {
//     test();
//     return 0;
// }