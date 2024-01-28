class Solution {
public:
//     int helper(vector<int> &dp, string s, int i){
//         if(i >= s.length()) return 1;
//         if(dp[i] != 0) return dp[i];
//         if(s[i] == '0') return 0;
        
//         int res = helper(dp, s, i+1);
        
//         if(i+1 < s.length()){
//             if(s[i] == '1') res += helper(dp, s, i+2);
//             else if(s[i] == '2'){
//                 if(s[i+1] == '0' || s[i+1] == '1' || s[i+1] == '2' || s[i+1] == '3' || s[i+1] == '4' || s[i+1] == '5' || s[i+1] == '6' ){
//                     res += helper(dp, s, i+2);
//                 }
//             }
//         }
//         dp[i] = res;
//         return res;
//     }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size()+1, 1);
        for(int i=s.size()-1; i >= 0; i--){
            if(s[i] == '0') dp[i] = 0;
            else{dp[i] = dp[i+1];
            if(i+1 < s.length()){
            if(s[i] == '1') dp[i] += dp[i+2];
            else if(s[i] == '2'){
                if(s[i+1] == '0' || s[i+1] == '1' || s[i+1] == '2' || s[i+1] == '3' || s[i+1] == '4' || s[i+1] == '5' || s[i+1] == '6'){
                    dp[i] += dp[i+2];
                }
        }}}}
        return dp[0];
        }
};