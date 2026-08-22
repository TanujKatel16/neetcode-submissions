class Solution {
public:

   vector<vector<int>>ans;
    
    void solve(int target,vector<int>& candidates,vector<int> &temp,int i){

        if( target==0 ){
            ans.push_back(temp);
            return;
        }
        if( target<0 || i>=candidates.size() ) return;
        temp.push_back(candidates[i]);
        solve(target-candidates[i], candidates, temp,i);
        temp.pop_back();
        solve(target, candidates, temp,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        solve(target,candidates,temp,0);
        return ans;
        
    }
};