int m,n;
vector<vector<vector<int>>> dp;
vector<vector<int>> grid;
class Solution {
public:
    int f(int i, int j1, int j2){
        if(j1<0 || j2<0 || j1>=n || j2>=n) return -1e8;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1e8) return dp[i][j1][j2];
        int a=0;
        for(int c1=-1;c1<=1;c1++){
            for(int c2=-1;c2<=1;c2++){
                int nc1=j1+c1, nc2=j2+c2;
                if(j1!=j2) a= max(a,f(i+1,nc1,nc2)+grid[i][j1]+grid[i][j2]);
                else a= max(a,f(i+1,nc1,nc2)+grid[i][j1]);
            }
        }
        return dp[i][j1][j2]=a;
    }
    int cherryPickup(vector<vector<int>>& grid1) {
        grid=grid1;
        m=grid.size(), n=grid[0].size();
        dp = vector<vector<vector<int>>> (m, vector<vector<int>>(n, vector<int>(n,-1e8)));
        return f(0,0,n-1);
    }
};