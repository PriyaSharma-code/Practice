//leetcode:518. Coin Change 2

/*You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money 
cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = coins.size();
        //DP TABLE OF COINS X AMOUNT
        vector<vector<int>> dp(n+1,vector<int>(amount+1));
        
        //first row is 0 as 0 can be formed with 0 coins
        for(int i = 1; i<=amount;i++){
            dp[0][i] = 0;
        }
        //first col is 1 as 0 can be formed in 1 way, by exclusing all coins
        for(int i = 0; i<=n;i++){
            dp[i][0] = 1;
        }
        
        
        for(int i = 1; i<= n; i++){
            for(int j =1; j<=amount; j++){
                
                if(amount>=coins[i-1]){//include+exclude
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else{//only exclude
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
      int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        vector<vector<int>> dp;
        dp.resize(n+2,vector<int>(amount+2,-1));
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=0;i<amount+1;i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};


public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;        
        for (int j = 0; j < coins.length; j++) {
            for (int i = 1; i <= amount; i++) {
                if (i - coins[j] >= 0) {
                    dp[i] += dp[i - coins[j]];
                }
            }
        }
        return dp[amount];
    }