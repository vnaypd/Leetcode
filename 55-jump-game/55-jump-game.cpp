class Solution {
public:
    bool helper(vector<int> &nums, int si, int ei, vector<int> &dp){
        if(si == ei) return true;
        if(dp[si] != -1) return dp[si];
        
        for(int i=1; i<=nums[si]; i++){
           if(helper(nums, si+i, ei, dp)) return dp[si] = true;
        }
        
        return dp[si]=false;
        
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, nums.size()-1, dp);
    }
};