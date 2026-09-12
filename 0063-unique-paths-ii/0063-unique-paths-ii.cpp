using ll = long long;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<ll> prev(n,0);
        if(grid[0][0] || grid[m-1][n-1]) return 0;
        prev[0]=1;
        for(int i=0;i<m;i++){
            vector<ll> temp(n,0);
            for(int j=0;j<n;j++){
                ll up = 0, left = 0;
                if(grid[i][j]!=1) up = prev[j];
                if(j>0 && grid[i][j]!=1) left = temp[j-1];
                temp[j] = up+left;
            }
            prev = temp;
        }
        return prev[n-1];
    }
};