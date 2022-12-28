#include "lc_1606.h"
#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

/*
    k个服务器，编号0~k-1
    
    若所有服务器都正忙，则抛弃请求
    
    若第(i % k)个服务器空闲，那么对应的服务器(i % k)会处理该请求
    
    若第(i % k)个服务器正忙，那么线性查看其下一个服务器，一直到找到空闲服务器
    
    给定一个递增的正整数数组arrival，arrival[i]表示第i个任务的到达事件，load[i]表示第i个请求的工作量（服务器完成它所需要的事件）。任务：找到最繁忙的服务器，即，处理请求数最多的服务器。
    
    返回所有最繁忙服务器序号的列表
*/

vector<int> Solution_1606::busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    map<int, int> server_tasks;
    map<int, int> task_complete_count;
    int maxTask = INT_MIN;
    
    for (int i=0; i<k; ++i) {
        server_tasks[i] = 0;
    }
    
    for (int index=0; index<arrival.size(); ++index) {
        /* 若第index个服务器的空闲时间结点小于等于当前到达的时间，则分配给它 */
        if (server_tasks[index % k] <= arrival[index]) {
            server_tasks[index % k] = arrival[index] + load[index];
            task_complete_count[index % k]++;
        /* 否则查询它的下家*/
        } else {
            int curr = index % k + 1;
            /* 线性探查：需要查询 n-1 */
            for (int i=0; i<k-1; ++i) {
                /* 判断curr不越界 */
                if (curr >= k) {
                    curr %= k;
                }
                if (server_tasks[curr] <= arrival[index]) {
                    server_tasks[curr] = arrival[index] + load[index];
                    task_complete_count[curr]++;
                    break;
                }
                ++curr;
            }
        }
    }
    vector<int> ans;
    for (auto iter=task_complete_count.begin(); iter!=task_complete_count.end(); ++iter) {
        if (iter->second > maxTask) {
            maxTask = iter->second;
            ans.clear();
            ans.push_back(iter->first);
        } else if (maxTask == iter->second) {
            ans.push_back(iter->first);
        }
        cout<<"server "<<iter->first<<" has "<<iter->second<<" tasks\n";
    }
    return ans;
}

// int main(int argc, char **argv) {
//     cout<<"case1:\n";
//     vector<int> arrival1 = {1,2,3,4,5};
//     vector<int> load1 = {5,2,3,3,3};
//     test1(3, arrival1, load1);

//     cout<<"case2:\n";
//     vector<int> arrival2 = {1,2,3,4};
//     vector<int> load2 = {1,2,1,2};
//     test1(3, arrival2, load2);

//     cout<<"case3:\n";
//     vector<int> arrival3 = {1,2,3};
//     vector<int> load3 = {10,12,11};
//     test1(3, arrival3, load3);

//     cout<<"case4:\n";
//     vector<int> arrival4 = {1,2,3,4,8,9,10};
//     vector<int> load4 = {5,2,10,3,1,2,2};
//     test1(3, arrival4, load4);

//     cout<<"case5:\n";
//     vector<int> arrival5 = {1};
//     vector<int> load5 = {1};
//     test1(1, arrival5, load5);

//     return 0;
// }