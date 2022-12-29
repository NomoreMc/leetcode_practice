#ifndef __LEETCODE_UNKNOWN_1_H__
#define __LEETCODE_UNKNOWN_1_H__
#include <vector>

class Solution_Unknown_1 {
public:
    int Discount1(int n, int price, int budget, std::vector<std::vector<int>> discount);
    int Discount2(int n, int price, int budget, std::vector<std::vector<int>> discount);

private:
    void DiscountCore(std::vector<int> &discountPrice, std::vector<int> &saleDay, int currProduct, int budget, int remainToBuy);

private:
    /* 存储每个折扣产品售卖的日期 */
    std::vector<int> discountProductDay;
    /* 按序存储产品 */
    std::vector<int> productPriceArray;
    bool ansFound;
    int earlestDay;
    int oriPrice;
};

#endif