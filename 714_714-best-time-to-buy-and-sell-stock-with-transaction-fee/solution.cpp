// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description
// Description
// You are given an array
// prices
// where
// prices[i]
// is the price of a given stock on the
// i
// th
// day, and an integer
// fee
// representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
// Note:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.
// Example 1:
// Input:
// prices = [1,3,2,8,4,9], fee = 2
// Output:
// 8
// Explanation:
// The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:
// Input:
// prices = [1,3,7,5,10,3], fee = 3
// Output:
// 6
// Constraints:
// 1 <= prices.length <= 5 * 10
// 4
// 1 <= prices[i] < 5 * 10
// 4
// 0 <= fee < 5 * 10
// 4

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n, 0), sell(n,0);
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++){
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee);
        }
        return *(sell.end()-1);
    }
};
