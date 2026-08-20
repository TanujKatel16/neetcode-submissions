class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {

        int n=nums.size();

        sort(nums.begin(),nums.end());

        int maxr=nums[0][1];
        int count=0;

        for(int i=1;i<n;i++){

            int l=nums[i][0];
            int r=nums[i][1];

            if(l<maxr){
                count++;
                maxr=min(maxr,r);
            }
            else{
                maxr=r;
            }
        }

        return count;
    }
};