//121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int right = INT_MAX;
        int maxP=0;
        int profit =0;
        for(int i=0;i<prices.size();i++){
            right = min(right, prices[i]);
            profit = prices[i] - right;
            maxP = max(maxP, profit);

        }
        return maxP;

    }
};