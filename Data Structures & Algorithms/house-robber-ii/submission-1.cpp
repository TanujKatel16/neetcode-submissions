class Solution {
public:

    vector<int>dp;

    int solve(int end,vector<int> &nums,int i){

        if(i>end) return 0;

        if(dp[i]!=-1) return dp[i];

        int skip=solve(end,nums,i+1);
        int take=nums[i]+solve(end,nums,i+2);

        return dp[i]=max(take,skip);
    }

    int rob(vector<int>& nums){

        int n=nums.size();

        if(n==1) return nums[0];

        dp.resize(n,-1);

        int case1=solve(n-1,nums,1);

        fill(dp.begin(),dp.end(),-1);

        int case2=solve(n-2,nums,0);

        return max(case1,case2);
    }
};