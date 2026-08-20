class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        int l=intervals[0][0];
        int r=intervals[0][1];
        
        for(int i=1;i<n;i++){

            int f=intervals[i][0];
            int s=intervals[i][1];

            if(f<=r){
                r=max(r,s);
            }
            else{

                ans.push_back({l,r});
                l=f;
                r=s;
            }

        }
        ans.push_back({l,r});
        return ans;
        
    }
};
