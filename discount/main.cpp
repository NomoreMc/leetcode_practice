#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>

using namespace std;

/*
    已知某种产品需要采购的数量为n，每个产品原价为price，够买的预算budget。
    给出一个discount数组，数组存储的是在某天的折扣价格即最大折扣的数量，用(day, dis, num)表示。
    任何一天都能采购原价为price的产品，不收数量限制。
    (1)day严格递增;
    (2)discount < price
    (3)num <= 10
    (4)给出折扣价的长度小于3*10^4，price<10^5，budget<10^9。
    求最早哪天可以完成采购。

    例：
    n = 4, price = 5, budget = 18, discount = [[2,4,3],[3,3,2],[4,2,1]];
    第一天：没有折扣，购买4个产品需要20，大于预算，不能完成
    第二天：采购单价4的数量3个，需要12，加上第一天采购单价5的数量1个，总价17，小于预算，返回2。
*/

/*
    只要满足在预算内，即可作为答案，但是要求是最早的一天。在遍历时，我们只需要找到第一个满足预算内
    的购买方案即可。
*/

/*
    组合问题，将discount数组按照day进行拆分，例如：discount = [[2,4,3],[3,3,2],[4,2,1]]，
    对该数组进行拆分得到：
        [4][4][4][3][3][2]
*/

class Solution1 {
public:
    int Discount(int n, int price, int budget, vector<vector<int>> discount) {
        /* 如果预算已够原价买入要求数量的产品，则直接返回1 */
        if (n * price <= budget) {
            return 1;
        }

        discountProductDay.clear();
        productPriceArray.clear();
        /* 构造两个数组，一个是每个折扣商品的售卖时间，一个是每个商品的售卖价格，一一对应 */
        for (int i=0; i<discount.size(); ++i) {
            auto today = discount[i];
            for (int j=0; j<today[2]; ++j) {
                discountProductDay.push_back(today[0]);
                productPriceArray.push_back(today[1]);
            }
        }

        /* 初始化结束标志位、答案、原价 */
        this->ansFound = false;
        this->earlestDay = INT_MAX;
        this->oriPrice = price;
        for (int i=0; i<productPriceArray.size(); ++i) {
            /* 对于每个折扣商品，有“买”与“不买”两种选择 */
            DiscountCore(productPriceArray, discountProductDay, i, budget - productPriceArray[i], n - 1);
            DiscountCore(productPriceArray, discountProductDay, i, budget, n);
        }
        return earlestDay;
    }
private:
    /* 存储每个折扣产品售卖的日期 */
    vector<int> discountProductDay;
    /* 按序存储产品 */
    vector<int> productPriceArray;
    bool ansFound;
    int earlestDay;
    int oriPrice;
private:
    void DiscountCore(vector<int> &discountPrice, vector<int> &saleDay, int currProduct, int budget, int remainToBuy) {
        if (ansFound) {
            return;
        }
        if (budget <= 0 && remainToBuy > 0) {
            return;
        }
        if ((budget >= 0 && remainToBuy == 0) || (budget >= remainToBuy * oriPrice)) {
            ansFound = true;
            earlestDay = saleDay[currProduct];
            return;
        }

        for (int i=currProduct+1; i<discountPrice.size(); ++i) {
            /* 对于每个折扣商品，有“买”与“不买”两种选择 */
            /* 买的话要看预算够不够 */
            if (budget - productPriceArray[i] >= 0) {
                DiscountCore(productPriceArray, discountProductDay, i, budget - productPriceArray[i], remainToBuy - 1);
            }
            DiscountCore(productPriceArray, discountProductDay, i, budget, remainToBuy);
        }
    }
};

class Solution2 {
public:
    int Discount(int n, int price, int budget, vector<vector<int>> discount) {
        int ans = 0;
        /* 存放当前计入购买总价的商品价格以及数量，key-价格，value-购买数量 */
        unordered_map<int, int> umpPriceNum;
        /* 从大到小存放当前已计入购买总价的商品价格 */
        queue<int> que;
        /* 存放"截止今天购买折扣商品的数量" */
        int currNum = 0;
        /* 存放"截止今天购买折扣商品的总价" */
        int currPriceTotal = 0;

        for (int i=0; i<discount.size(); ++i) {
            auto currDiscount = discount[i];
            if (umpPriceNum[currDiscount[1]] == 0) {
                que.push(currDiscount[1]);
            }
            umpPriceNum[currDiscount[1]] += currDiscount[2];
            currNum += currDiscount[2];
            currPriceTotal += currDiscount[1] * currDiscount[2];
            while (currNum > n) {
                /* 多的购买数量 */
                int gap = currNum - n;
                /* 当前已购商品的最贵价格 */
                int currHighestPrice = que.front();
                /* 如果当前最贵商品的购买量大于等于"多的购买数量"，将其退回，不要了 */
                 if (umpPriceNum[currHighestPrice] >= gap) {
                    currPriceTotal -= gap * currHighestPrice;
                    currNum -= gap;
                    umpPriceNum[currHighestPrice] -= gap;
                /* 否则，当前最贵商品的购买量小于"多的购买数量"，将当前最贵商品全数退回，都不要了 */
                } else {
                    currPriceTotal -= umpPriceNum[currHighestPrice] * currHighestPrice;
                    currNum -= umpPriceNum[currHighestPrice];
                    /* 将当前已购队列中价格最高的商品吐出 */
                    que.pop();
                    /* 同时将商品包中对应的进行清空 */
                    umpPriceNum[currHighestPrice] = 0;
                }
            }

            /* 计算：总价 = 已购折扣商品总价 + 购买原价商品总价 */
            int currTotal = currPriceTotal + (n - currNum) * price;
            /* 若总价小于等于预算，则今天就可以采购完毕了 */
            if (currTotal <= budget) {
                ans = currDiscount[0];
                break;
            }
        }

        return ans;
    }
};

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

void test1() {
    Solution1 a;

    cout<<"ans: "<<a.Discount(4,5,18,discount1)<<endl;

    cout<<"ans: "<<a.Discount(6,5,20,discount1)<<endl;

    cout<<"ans: "<<a.Discount(8,5,21,discount2)<<endl;

    cout<<"ans: "<<a.Discount(6,5,12,discount3)<<endl;
}

void test2() {
    Solution2 a;

    cout<<"ans: "<<a.Discount(4,5,18,discount1)<<endl;

    cout<<"ans: "<<a.Discount(6,5,20,discount1)<<endl;

    cout<<"ans: "<<a.Discount(8,5,21,discount2)<<endl;

    cout<<"ans: "<<a.Discount(6,5,12,discount3)<<endl;
}

int main(int argc, char **argv) {
    test1();
    cout<<endl;
    test2();
    return 0;
}