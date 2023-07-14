/* std header */
#include <iostream>
#include <memory>
#include <gtest/gtest.h>

/* project header */
#include "leetcode.h"
using namespace std;

/* utils begin */
void PrintVec(vector<int>& vec) {
    for (auto num: vec) {
        cout<<num<<" ";
    }
    cout<<endl;
}
/* utils end */

void test_unknown_1() {
    Solution_Unknown_1 a;
    vector<vector<int>> discount1 = {
        {2,4,3},
        {3,3,2},
        {4,2,1}
    };
    vector<vector<int>> discount2 = {
        {2,4,3},
        {3,3,2},
        {4,2,1},
        {5,3,3},
        {6,4,4},
        {7,2,2},
        {8,3,1},
    };
    vector<vector<int>> discount3 = {
        {2,4,3},
        {3,3,2},
        {4,2,1},
        {5,3,3},
        {6,4,4},
        {7,2,2},
        {8,3,1},
        {9,2,1},
        {10,2,1},
        {11,2,1},
    };

    cout<<"ans: "<<a.Discount1(4, 5, 18, discount1)<<endl;
    cout<<"ans: "<<a.Discount1(6, 5, 20, discount1)<<endl;
    cout<<"ans: "<<a.Discount1(8, 5, 21, discount2)<<endl;
    cout<<"ans: "<<a.Discount1(6, 5, 12, discount3)<<endl;
    cout<<"ans: "<<a.Discount2(4, 5, 18, discount1)<<endl;
    cout<<"ans: "<<a.Discount2(6, 5, 20, discount1)<<endl;
    cout<<"ans: "<<a.Discount2(8, 5, 21, discount2)<<endl;
    cout<<"ans: "<<a.Discount2(6, 5, 12, discount3)<<endl;
}

void test_307() {
    vector<int> input = {0,9,5,7,3};
    Solution_307 a(input);

    cout<<"\nsum 4 4:\n";
    cout<<a.sumRange(4,4)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nsum 2 4:\n";
    cout<<a.sumRange(2,4)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nsum 3 3:\n";
    cout<<a.sumRange(3,3)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nupdate 4 5:\n";
    a.update(4,5);
    a.printArr();
    a.printTree();

    cout<<"\nupdate 1 7:\n";
    a.update(1,7);
    a.printArr();
    a.printTree();

    cout<<"\nupdate 0 8:\n";
    a.update(0,8);
    a.printArr();
    a.printTree();

    cout<<"\nsum 1 2:\n";
    cout<<a.sumRange(1,2)<<endl;
    a.printArr();
    a.printTree();

    cout<<"\nsum 1 2:\n";
    cout<<a.sumRange(3,4)<<endl;
    a.printArr();
    a.printTree();
}

void test_310() {
    Solution_310 a;
    /*
        输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
        输出：[3,4]
    */
    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    vector<int> temp1 = a.findMinHeightTrees(6, edges);
    PrintVec(temp1);
    /*
        输入：n = 4, edges = [[1,0],[1,2],[1,3]]
        输出：[1]
    */

    vector<vector<int>> edges2 = {{1,0},{1,2},{1,3}};
    vector<int> temp2 = a.findMinHeightTrees(4, edges2);
    PrintVec(temp2);
}

void test_373() {
    Solution_373 a;
    vector<vector<int>> ans;
    vector<int> nums1({1,1,2});
    vector<int> nums2({1,2,3});

    cout<<"case1: \n";
    ans = a.kSmallestPairs1(nums1, nums2, 10);
    for (auto vec: ans) {
        cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
    }
    cout<<endl;

    vector<int> nums3({1,2});
    vector<int> nums4({3});

    cout<<"\ncase2: \n";
    ans = a.kSmallestPairs1(nums1, nums2, 3);
    for (auto vec: ans) {
        cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
    }
    cout<<endl;

    vector<int> nums5({1,1,2});
    vector<int> nums6({1,2,3});

    cout<<"\ncase3: \n";
    ans = a.kSmallestPairs2(nums1, nums2, 10);
    for (auto vec: ans) {
        cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
    }
    cout<<endl;

    vector<int> nums7({1,2});
    vector<int> nums8({3});

    cout<<"\ncase4: \n";
    ans = a.kSmallestPairs2(nums1, nums2, 3);
    for (auto vec: ans) {
        cout<<"["<<vec[0]<<", "<<vec[1]<<"] ";
    }
    cout<<endl;
}

void test_380() {
    Solution_380 a;
    cout<<"insert 1: "<<a.insert(1)<<endl;
    cout<<"remove 2: "<<a.remove(2)<<endl;
    cout<<"insert 2: "<<a.insert(2)<<endl;
    cout<<"getRandom: "<<a.getRandom()<<endl;
    cout<<"remove 1: "<<a.remove(1)<<endl;
    cout<<"insert 2: "<<a.insert(2)<<endl;
    cout<<"getRandom: "<<a.getRandom()<<endl;
}

void test_396() {
    Solution_396 a;
    vector<int> input1({4,3,2,6});
    cout<<"ans: "<<a.maxRotateFunction(input1)<<endl;

    vector<int> input2({100});
    cout<<"ans: "<<a.maxRotateFunction(input2)<<endl;
}

void test_728() {
    Solution_728 a;
    vector<int> ans;
    ans = a.selfDividingNumbers1(1, 22);
    PrintVec(ans);
    ans = a.selfDividingNumbers2(1, 22);
    PrintVec(ans);
    ans = a.selfDividingNumbers1(47, 85);
    PrintVec(ans);
    ans = a.selfDividingNumbers2(47, 85);
    PrintVec(ans);
    cout<<endl;
}

void test_787() {
    Solution_787 a;
    vector<vector<int>> edges1 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    cout<<"case1: "<<a.findCheapestPrice1(3, edges1, 0, 2, 1)<<endl;
    cout<<"case1: "<<a.findCheapestPrice2(3, edges1, 0, 2, 1)<<endl;

    vector<vector<int>> edges2 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    cout<<"case1: "<<a.findCheapestPrice1(3, edges1, 0, 2, 0)<<endl;
    cout<<"case2: "<<a.findCheapestPrice2(3, edges1, 0, 2, 0)<<endl;
}

void test_930() {
    Solution_930 a;
    vector<int> nums({1,0,1,0,1});

    cout<<"ans: "<<a.numSubarraysWithSum1(nums, 2)<<endl;

    cout<<"ans: "<<a.numSubarraysWithSum2(nums, 2)<<endl;
}

void test_954(void) {
    Solution_954 a;
    cout<<"case 1:\n";
    vector<int> input1 = {3, 1, 3, 6};
    PrintVec(input1);
    cout<<a.canReorderDoubled(input1)<<endl;

    cout<<"case 2:\n";
    vector<int> input2 = {2, 1, 2, 6};
    PrintVec(input2);
    cout<<a.canReorderDoubled(input2)<<endl;

    cout<<"case 3:\n";
    vector<int> input3 = {2, 4, -2, -4};
    PrintVec(input3);
    cout<<a.canReorderDoubled(input3)<<endl;

    cout<<"case 4:\n";
    vector<int> input4 = {1, 2, 4, 16, 8, 4};
    PrintVec(input4);
    cout<<a.canReorderDoubled(input4)<<endl;
}

void test_1094(void) {
    Solution_1094 a;

    /* Flase */
    vector<vector<int>> trips1 = {
        {2,1,5},
        {3,3,7}
    };
    int capacity1 = 4;
    if (a.carPooling(trips1, capacity1)) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    /* True */
    vector<vector<int>> trips2 = {
        {2,1,5},
        {3,3,7}
    };
    int capacity2 = 5;
    if (a.carPooling(trips2, capacity2)) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    /* False */
    vector<vector<int>> trips3 = {
        {7,5,6},
        {6,7,8},
        {10,1,6}
    };
    int capacity3 = 16;
    if (a.carPooling(trips3, capacity3)) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
}

void test_1606(void) {
    Solution_1606 a;
    int k = 3;
    vector<int> arrival1 = {1,2,3,4,5};
    vector<int> load1 = {5,2,3,3,3};
    vector<int> ans;
    ans = a.busiestServers(1, arrival1, load1);
    PrintVec(ans);

    k = 3;
    vector<int> arrival2 = {1,2,3,4};
    vector<int> load2 = {1,2,1,2};
    ans = a.busiestServers(1, arrival2, load2);
    PrintVec(ans);

    k = 3;
    vector<int> arrival3 = {1,2,3};
    vector<int> load3 = {10,12,11};
    ans = a.busiestServers(1, arrival3, load3);
    PrintVec(ans);

    k = 3;
    vector<int> arrival4 = {1,2,3,4,8,9,10};
    vector<int> load4 = {5,2,10,3,1,2,2};
    ans = a.busiestServers(1, arrival4, load4);
    PrintVec(ans);

    k = 1;
    vector<int> arrival5 = {1};
    vector<int> load5 = {1};
    ans = a.busiestServers(1, arrival5, load5);
    PrintVec(ans);
}

void test_1705(void) {
    Solution_1705 a;
    vector<int> apples({3,0,0,0,0,2});
    vector<int> days({3,0,0,0,0,2});

    cout<<"ans: "<<a.eatenApples(apples, days)<<endl;
}

int main(int argc, char **argv) {
    int ret = 0;
    // test_unknown_1();
    // test_307();
    // test_310();
    // test_373();
    // test_380();
    // test_396();
    // test_728();
    // test_787();
    // test_930();
    // test_954();
    // test_1094();
    // test_1606();
    // test_1705();

    ::testing::InitGoogleTest(&argc, argv);
    ret = RUN_ALL_TESTS();
    cout<<"Test End!"<<endl;
    return 0;
}