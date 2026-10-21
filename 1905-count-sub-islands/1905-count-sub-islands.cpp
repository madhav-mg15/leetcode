class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j] && !vis[i][j]){
                    queue<pair<int,int>> q;
                    q.push({i,j}); 
                    vis[i][j] = true;
                    int f = grid1[i][j]==0;
                    while(!q.empty()){
                        int r = q.front().first, c = q.front().second;
                        q.pop();
                        for(int d=0;d<4;d++){
                            int nr = r+dir[d][0], nc = c+dir[d][1];
                            if(isValid(nr,nc,m,n) && grid2[nr][nc] && !vis[nr][nc]){
                                if(!grid1[nr][nc]) f=1;
                                vis[nr][nc] = true;
                                q.push({nr,nc});
                            }
                            if(nr==m-1 && nc==n-1) cout<<nr<<" "<<nc<<" "<<f<<" "<<grid1[nr][nc]<<endl;
                        }
                    }
                    if(!f) ans++;
                }
            }
        }
        return ans;
    }
};