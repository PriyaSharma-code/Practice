//122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int profit =0;
        for(int i=1;i<prices.size();i++){
            profit = prices[i] - prices[i-1];
            maxP = max(maxP, profit + maxP);

        }
        return maxP;
    }
};