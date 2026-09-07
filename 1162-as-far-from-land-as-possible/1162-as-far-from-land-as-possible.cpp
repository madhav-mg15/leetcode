class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), mx = -1;
        vector<vector<bool>> vis(n, vector<bool>(n,0));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    vis[i][j]=1;
                    q.push({i,j,i,j});
                }
            }
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int r = x[0], c = x[1], r1 = x[2], c1 = x[3];
            if(!grid[r][c]) mx = max(mx, (abs(r1-r)+abs(c1-c)));
            for(int d=0;d<4;d++){
                int nr = r+dir[d][0], nc = c+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !grid[nr][nc] && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc,r1,c1});
                }
            }
        }
        return mx;
    }
};