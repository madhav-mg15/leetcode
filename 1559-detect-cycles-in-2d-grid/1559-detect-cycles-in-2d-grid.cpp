class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    vis[i][j] = true;
                    q.push({i,j,-1,-1});
                    while(!q.empty()){
                        auto x = q.front();
                        int r = x[0], c = x[1], pr = x[2], pc = x[3];
                        q.pop();
                        for(int d=0;d<4;d++){
                            int nr = r+dir[d][0], nc = c+dir[d][1];
                            if(isValid(nr,nc,m,n) && grid[nr][nc] == grid[i][j] && !(nr==pr && nc==pc)){
                                if(vis[nr][nc]) return true;
                                vis[nr][nc] = true;
                                q.push({nr,nc,r,c});
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};