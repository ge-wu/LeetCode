class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) 
            return 0;
        
        vector<vector<int>>dp(n, {0, 0});
        dp[0][0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] += nums[i] + dp[i - 1][1];
            dp[i][1] += max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
