class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        vector<int> dp(nums.size(), 0);
        
        for(int i=1; i<nums.size()-1; i++){
            int a = nums[i] - nums[i-1];
            int b = nums[i+1] - nums[i];
            
            if(a == b){
                dp[i] = 1 + dp[i-1];
                count += dp[i];
            }
        }
        
        return count;
    }
};