// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
//
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// If you were only permitted to complete at most one transaction (ie, buy one and sell 
// one share of the stock), design an algorithm to find the maximum profit.

namespace BestTimeToBuyAndSellStock {
    class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            
            int min = INT_MAX;
            int max = INT_MIN;
            int maxProfit = 0;
            for (int i = 0; i < prices.size(); i++) {
                if (prices[i] < min) {
                    min = prices[i];
                    max = min; // when update min price, always reset max price
                }
                
                if (prices[i] > max) {
                    max = prices[i];
                }
                
                int profit = max - min;
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
                    
            }
            
            return maxProfit;
            
        }
    };
}
