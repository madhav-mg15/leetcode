vector<vector<int>> dir;
int m,n;
vector<vector<int>> grid;
queue<pair<int,int>> q;
class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void bfs(){
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nr = r+dir[d][0], nc = c+dir[d][1];
                if(isValid(nr,nc,m,n) && !grid[nr][nc]){
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid1) {
        grid=grid1;
        m = grid.size(), n = grid[0].size();
        q = queue<pair<int,int>> ();
        dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int j=0;j<n;j++){
            if(!grid[0][j]){
                q.push({0,j});
                grid[0][j]=1;
            }
            if(!grid[m-1][j]){
                q.push({m-1,j});
                grid[m-1][j]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(!grid[i][0]){
                q.push({i,0});
                grid[i][0]=1;
            }
            if(!grid[i][n-1]){
                q.push({i,n-1});
                grid[i][n-1]=1;
            }
        }
        bfs();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){
                    cnt++;
                    q.push({i,j});
                    grid[i][j]=1;
                    bfs();
                }
            }
        }
        return cnt;
    }
};