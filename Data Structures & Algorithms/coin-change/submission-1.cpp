class Solution {
public:

    vector<vector<int>>dp;

    int solve(vector<int>& nums, int amount,int i){
        

        if(amount==0) return 0;
        if(i>=nums.size()) return 1e9;
        if(dp[amount][i]!=-1) return dp[amount][i];
        
        int take=1e9;
        int skip=solve(nums,amount,i+1);
        if(amount-nums[i]>=0)take=1+solve(nums,amount-nums[i],i);
        return dp[amount][i] = min(take,skip);

    }
    int coinChange(vector<int>& nums, int amount) {
        
        dp.assign(amount+1, vector<int>(nums.size(), -1));
        int val=solve(nums,amount,0);
        if(val==1e9) return -1;
        return val;
        
    }
};
