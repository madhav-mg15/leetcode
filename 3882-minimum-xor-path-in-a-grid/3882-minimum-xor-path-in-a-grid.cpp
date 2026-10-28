vector<vector<int>> grid;
vector<vector<vector<int>>> dp;
int m,n;
class Solution {
public:
    int f(int i, int j, int x){
        if(i==m-1 && j==n-1) return x;
        if(dp[i][j][x]!=-1) return dp[i][j][x];
        int ans = 1e8;
        if(i+1<m) ans = min(ans, f(i+1,j,x^grid[i+1][j]));
        if(j+1<n) ans = min(ans, f(i,j+1,x^grid[i][j+1]));
        return dp[i][j][x] = ans;
    }
    int minCost(vector<vector<int>>& grid1) {
        grid = grid1;
        m = grid.size(), n = grid[0].size();
        dp = vector<vector<vector<int>>> (m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return f(0,0,grid[0][0]);
    }
};