class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size(), ogc = grid[row][col];
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<vector<bool>> vis(m, vector<bool>(n,0));
        vector<pair<int,int>> v;
        vis[row][col]=1;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nr = r+dir[d][0], nc = c+dir[d][1];
                if(!isValid(nr,nc,m,n) || grid[nr][nc]!=ogc){
                    v.push_back({r,c});
                    continue;
                }
                if(!vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        for(auto x:v) grid[x.first][x.second] = color;
        return grid;
    }
};