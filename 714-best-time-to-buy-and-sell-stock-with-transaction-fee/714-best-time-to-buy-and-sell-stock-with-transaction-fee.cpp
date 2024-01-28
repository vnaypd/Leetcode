class Solution {
public:
   int dp[50001][2];
    int dfs(vector<int> &prices, int fee, int idx, bool buying){
        if(idx > prices.size()-1) return 0;
        
        if(dp[idx][buying] != -1) return dp[idx][buying];
        
        if(buying){
            int buy = dfs(prices, fee, idx+1, !buying) - prices[idx];
            int cooldown = dfs(prices, fee, idx+1, buying);
            return dp[idx][buying] = max(buy, cooldown);
        }else{
            int sell = dfs(prices ,fee, idx+1, !buying) + prices[idx] - fee;
            int cooldown = dfs(prices, fee, idx+1, buying);
            return dp[idx][buying] = max(sell, cooldown);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return dfs(prices, fee, 0, 1);
    }
};