class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                grid[i][0]=0;
                q.push({i,0});
            }
            if(grid[i][n-1]==1){
                grid[i][n-1]=0;
                q.push({i,n-1});
            }
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                grid[0][j]=0;
                q.push({0,j});
            }
            if(grid[m-1][j]==1){
                grid[m-1][j]=0;
                q.push({m-1,j});
            }
        }
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nr = r+dir[d][0], nc = c+dir[d][1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]){
                    q.push({nr,nc});
                    grid[nr][nc]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) ans += (grid[i][j]);
        return ans;
    }
};