class Solution {
public:
   
   vector<vector<string>>ans;

    bool isPalindrome(string &s,int i,int j){
      
      string s_new=s.substr(i,j-i+1);
      string sr=s_new;
      reverse(sr.begin(),sr.end());
      return (s_new==sr);
    }
    
    void solve(int idx,string &s,vector<string> &temp){

        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<string>temp;
        solve(0,s,temp);
        return ans;
       
    }
};
