/* std header */
#include <iostream>
#include <memory>

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
    vector<int> arrival = {1,2,3,4,5};
    vector<int> load = {5,2,3,3,3};

    // k = 3;
    // vector<int> arrival2 = {1,2,3,4};
    // vector<int> load2 = {1,2,1,2};

    // k = 3;
    // vector<int> arrival3 = {1,2,3};
    // vector<int> load3 = {10,12,11};

    // k = 3;
    // vector<int> arrival4 = {1,2,3,4,8,9,10};
    // vector<int> load4 = {5,2,10,3,1,2,2};

    // k = 1;
    // vector<int> arrival5 = {1};
    // vector<int> load5 = {1};

    vector<int> temp = a.busiestServers(3, arrival, load);
    for (auto num: temp) {
        cout<<num<<" ";
    }
    cout<<endl;
}

void test_1705(void) {
    Solution_1705 a;
    vector<int> apples({3,0,0,0,0,2});
    vector<int> days({3,0,0,0,0,2});

    cout<<"ans: "<<a.eatenApples(apples, days)<<endl;
}

int main(int argc, char **argv) {
    test_930();
    test_954();
    test_1094();
    test_1606();
    test_1705();

    cout<<"Test End!"<<endl;
    return 0;
}