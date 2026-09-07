class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), mn=1e9;
        if(n==1) return grid[0][0]==0 ? 1:-1;
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> vis(n, vector<bool> (n,false));
        q.push({1,{0,0}});
        vis[0][0]=1;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int len=x.first, r=x.second.first, c=x.second.second;
            if(r==n-1 && c==n-1){
                mn=min(mn,len);
                continue;
            }
            for(int d=0;d<8;d++){
                int nr=r+dir[d][0], nc=c+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !grid[nr][nc] && !vis[nr][nc]){
                    q.push({len+1,{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        return mn==1e9?-1:mn;
    }
};