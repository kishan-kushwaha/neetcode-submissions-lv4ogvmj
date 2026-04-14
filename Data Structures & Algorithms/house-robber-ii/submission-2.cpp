class Solution {
public:
    int robbery(vector<int>&arr){
        int m=arr.size();
        if(m == 0) return 0;
        if(m == 1) return arr[0];
        vector<int>dp(m,0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i=2;i<m;i++){
            dp[i] =  max(arr[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[m-1];

    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];
        
        vector<int>arr1(n-1);
        vector<int>arr2(n-1);
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        
        for(int i=0;i<n-1;i++){
            arr1[i] = nums[i];
        }
        for(int i=1;i<n; i++){
            arr2[i-1] = nums[i];
        }
        
        int curr1 = robbery(arr1);
        int curr2 = robbery(arr2);

        return max(curr1,curr2);
    }
};
