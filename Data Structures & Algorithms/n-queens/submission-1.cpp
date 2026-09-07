class Solution {
public:
    vector<vector<string>>ans;
    void solve( vector<string> &temp, int i,vector<int> &row,vector<int> &col,
    vector<int> &rd,vector<int> &ld){

        int n=temp.size();

        if(i==n){
           ans.push_back(temp);
           return;
        }
        for(int d=0;d<n;d++){

            if(col[d]==0 && rd[n+(i-d)]==0 && ld[i+d]==0){

                temp[i][d]='Q';
                rd[n+(i-d)]=1;
                col[d]=1;
                ld[i+d]=1;
                solve(temp,i+1,row,col,rd,ld);
                temp[i][d]='.';
                rd[n+(i-d)]=0;
                col[d]=0;
                ld[i+d]=0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        string s=string(n,'.');
        vector<string>temp(n,s);
        vector<int>row(n,0),col(n,0),rd(2*n,0),ld(2*n,0);

        solve(temp,0,row,col,rd,ld);

        return ans;


        
    }
};
