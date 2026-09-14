int m,n;
class Solution {
public:
    bool isValid(int i, int j){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(k+1,0)));
        queue<vector<int>> q;
        q.push({0,0,0,grid[0][0]});
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vis[0][0][grid[0][0]] = 1;
        while(!q.empty()){
            auto x=q.front();
            int r=x[0], c=x[1], mvs=x[2], ed=x[3]; 
            q.pop();
            if(ed>k) continue;
            if(r==m-1 && c==n-1) return mvs; 
            for(int d=0;d<4;d++){
                int nr=r+dir[d][0], nc=c+dir[d][1];
                if(isValid(nr,nc) && !vis[nr][nc][ed]){
                    vis[nr][nc][ed]=1;
                    q.push({nr,nc,mvs+1,ed+grid[nr][nc]});
                }
            }
        }
        return -1;
    }
};