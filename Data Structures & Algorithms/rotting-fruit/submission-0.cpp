class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        queue< tuple<int,int,int> >q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        int ans=0;

        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};

        while(!q.empty()){

            auto [i,j,d]=q.front();
            q.pop();

            for(int k=0;k<4;k++){

                int x=i+dx[k];
                int y=j+dy[k];

                if(x<0 || y<0 || x>m-1 || y>n-1) continue;

                if(grid[x][y]==1){

                    grid[x][y]=2;
                    q.push({x,y,d+1});
                    ans=max(ans,d+1);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   return -1; 
                }
            }
        }

        return ans;
        
    }
};
