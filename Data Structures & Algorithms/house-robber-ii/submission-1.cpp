class Solution {
public:
    int robbery(int index, vector<int>&arr, vector<int>&dp){
        int n=arr.size();
        if(index < 0) return 0;
        if(index == 0) return arr[0];
        if(dp[index] != -1) return dp[index];
        return dp[index] = max(arr[index] + robbery(index-2, arr, dp), robbery(index-1,arr, dp));

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr1(n-1);
        vector<int>arr2(n-1);
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        for(int i=0;i<n-1;i++){
            arr1[i] = nums[i];
        }
        for(int i=1;i<n; i++){
            arr2[i-1] = nums[i];
        }
        
        int curr1 = robbery(n-2,arr1,dp1);
        int curr2 = robbery(n-2,arr2,dp2);

        return max(curr1,curr2);
    }
};
