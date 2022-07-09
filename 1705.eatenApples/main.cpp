#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    有一棵特殊的苹果树，一连 n 天，每天都可以长出若干个苹果。在第 i 天，树上会长出
    apples[i] 个苹果，这些苹果将会在 days[i] 天后（也就是说，第 i + days[i] 天时）
    腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 apples[i] == 0 
    且 days[i] == 0 表示。

    你打算每天最多吃一个苹果来保证营养均衡。注意，你可以在这 n 天之后继续吃苹果。

    给你两个长度为 n 的整数数组 days 和 apples ，返回你可以吃掉的苹果的最大数目。

    示例 1：

    输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
    输出：7
    解释：你可以吃掉 7 个苹果：
    - 第一天，你吃掉第一天长出来的苹果。
    - 第二天，你吃掉一个第二天长出来的苹果。
    - 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
    - 第四天到第七天，你吃的都是第四天长出来的苹果。

    示例 2：

    输入：apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
    输出：5
    解释：你可以吃掉 5 个苹果：
    - 第一天到第三天，你吃的都是第一天长出来的苹果。
    - 第四天和第五天不吃苹果。
    - 第六天和第七天，你吃的都是第六天长出来的苹果。

*/

/*
    解读题意：
        1）每一天 i，都会有一批苹果产出，并且附带这些苹果的有效日期。
        2）每天只消耗一颗苹果
        3）若某一批苹果数量为 0，或者已经过期，则不能食用
    
    解题方法：
        使用一个优先队列来保存每一个批次的苹果，队列元素为pair<appleNum, validDay>，
        按照pair中的保质期validDay从短到长来排序，优先吃掉保质期短的苹果。

        迭代过程中，若pair<appleNum, validDay>中的appleNum为0了，或者validDay到期了，
        那么直接将其出列。直到队列中不存在任何元素。
*/

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int i = 0;
        /* 按照每一天的顺序将所有批次的苹果入队 */
        while (!pq.empty() || i < apples.size()) {
            if (i < apples.size() && apples[i] > 0) {
                pq.push(make_pair(days[i] + i - 1, apples[i]));
            }
            /* 将所有保质期超过今天的apple全部扔掉 */
            while (!pq.empty() && pq.top().first < i) {
                pq.pop();
            }
            /* 取出最优先要吃的一批苹果 */
            if (!pq.empty()) {
                auto iter = pq.top();
                pq.pop();
                iter.second--;
                ++ans;
                if (iter.second > 0) {
                    pq.push(iter);
                }
            }
            ++i;
        }

        return ans;
    }
};

void test1() {
    Solution a;
    vector<int> apples({3,0,0,0,0,2});
    vector<int> days({3,0,0,0,0,2});

    cout<<"ans: "<<a.eatenApples(apples, days)<<endl;
}

void test2() {
    Solution a;
    vector<int> apples({1,2,3,5,2});
    vector<int> days({3,2,1,4,2});

    cout<<"ans: "<<a.eatenApples(apples, days)<<endl;
}

int main(int argc, char **argv) {
    test1();
    test2();
    return 0;
}