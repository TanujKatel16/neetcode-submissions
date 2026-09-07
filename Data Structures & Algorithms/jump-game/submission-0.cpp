class Solution {
public:
    bool canJump(vector<int>& nums) {

        int currReach=0;
        int n=nums.size();

        for(int i=0;i<n;i++){

            if(i>currReach) return false;
            currReach=max(currReach,i+nums[i]);
        }
        return true;
        
    }
};
