using ll = long long;
class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    ll sum = grid[i][j]%k;
                    vis[i][j] = true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int r = q.front().first, c = q.front().second;
                        q.pop();
                        for(int d=0;d<4;d++){
                            int nr = r+dir[d][0], nc = c+dir[d][1];
                            if(isValid(nr,nc,m,n) && grid[nr][nc] && !vis[nr][nc]){
                                sum = (sum%k + grid[nr][nc]%k)%k;
                                vis[nr][nc] = true;
                                q.push({nr,nc});
                            }
                        }
                    }
                    if(sum == 0) ans++;
                }
            }
        }
        return ans;
    }
};