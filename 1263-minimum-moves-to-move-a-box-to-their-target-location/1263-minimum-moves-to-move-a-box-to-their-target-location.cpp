vector<vector<char>> grid;
int m,n;
vector<vector<int>> dir;
class Solution {
public:
    bool isValid(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    bool isReachable(int sr, int sc, int tr, int tc, int br, int bc){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        set<pair<int,int>> vis;
        vis.insert({sr,sc});
        while(!q.empty()){
            sr=q.front().first, sc=q.front().second;
            q.pop();
            if(sr==tr && sc==tc) return true;
            for(int d=0;d<4;d++){
                int nr=sr+dir[d][0], nc=sc+dir[d][1];
                if(isValid(nr,nc) && grid[nr][nc]=='.' && !vis.count({nr,nc}) && (nr!=br || nc!=bc)){
                    q.push({nr,nc});
                    vis.insert({nr,nc});
                }
            }
        }
        return false;
    }
    int minPushBox(vector<vector<char>>& grid1) {
        grid=grid1;
        n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        int tr=-1, tc=-1;
        int sr=-1, sc=-1;
        int br=-1, bc=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='B'){
                    grid[i][j]='.';
                    br=i;
                    bc=j;
                }
                if(grid[i][j]=='S'){
                    grid[i][j]='.';
                    sr=i;
                    sc=j;
                }
                if(grid[i][j]=='T'){
                    grid[i][j]='.';
                    tr=i;
                    tc=j;
                }
            }
        }
        q.push({br,bc,sr,sc,0});
        set<vector<int>> vis;
        vis.insert({br,bc,sr,sc});
        dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int st=x[4];
            br = x[0], bc = x[1], sr = x[2], sc = x[3];
            if(br==tr && bc==tc) return st;
            for(int d=0;d<4;d++){
                int nr=br+dir[d][0], nc=bc+dir[d][1];
                int xr=br-dir[d][0], yc=bc-dir[d][1];
                if(isValid(nr,nc) && grid[nr][nc]=='.' && !vis.count({nr,nc,xr,yc}) && isReachable(sr,sc,xr,yc,br,bc)){
                    q.push({nr,nc,xr,yc,st+1});
                    vis.insert({nr,nc,xr,yc});
                }
            }
        }
        return -1;
    }
};