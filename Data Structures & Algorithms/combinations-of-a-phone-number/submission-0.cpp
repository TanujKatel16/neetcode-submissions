class Solution {
public:
    vector<string>ans;
    void solve(int idx,vector<string>&v,string digits, string temp){

        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        int num=digits[idx]-'0';
        string s=v[num];
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            solve(idx+1,v,digits,temp);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {

        vector<string>v(10);
        if(digits.size()==0) return {};
        v[2]="abc";
        v[3]="def";
        v[4]="ghi";
        v[5]="jkl";
        v[6]="mno";
        v[7]="pqrs";
        v[8]="tuv";
        v[9]="wxyz";

        solve(0,v,digits,"");
        return ans;

        
    }
};
