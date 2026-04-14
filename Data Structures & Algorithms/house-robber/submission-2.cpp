class Solution {
public:
    int robbery(int index, vector<int>& nums, vector<int>&dp){
        if(index == 0) return nums[0];
        if(index == 1) return max(nums[0], nums[1]);
        if(dp[index] != -1) return dp[index];
        return dp[index] = max(nums[index] + robbery(index-2, nums,dp), robbery(index-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return robbery(n-1,nums,dp);
    }
};
