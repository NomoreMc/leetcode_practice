/* std header */
#include <iostream>
#include <memory>

/* project header */
#include "leetcode.h"
using namespace std;

void test1() {
    Solution_1705 a;
    vector<int> apples({3,0,0,0,0,2});
    vector<int> days({3,0,0,0,0,2});

    cout<<"ans: "<<a.eatenApples(apples, days)<<endl;
}

int main(int argc, char **argv) {
    int *p = new int(1);
    test1();
    cout<<"hello world!"<<endl;
    return 0;
}