class Solution {
public:
    vector<string>ans;
    void solve(int n,string &temp, int open,int closed){

        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            temp.push_back('(');
            solve(n,temp,open+1,closed);
            temp.pop_back();
        }
        if(open>closed){
            temp.push_back(')');
            solve(n,temp,open,closed+1);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {

        string temp="";
        solve(n,temp,0,0);
        return ans;
        
    }
};
