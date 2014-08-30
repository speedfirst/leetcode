// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
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
