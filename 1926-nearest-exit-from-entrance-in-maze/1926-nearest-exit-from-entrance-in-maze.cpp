class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& etr) {
        int m=maze.size(), n=maze[0].size();
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{etr[0],etr[1]}});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vis[etr[0]][etr[1]] = true;
        while(!q.empty()){
            int r = q.front().second.first, c = q.front().second.second, cnt = q.front().first;
            q.pop();
            if(!(r==etr[0] && c==etr[1]) && (r==0 || r==m-1 || c==0 || c==n-1)) return cnt;
            for(int d=0;d<4;d++){
                int nr = r+dir[d][0], nc = c+dir[d][1];
                if(isValid(nr,nc,m,n) && maze[nr][nc]=='.' && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({cnt+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};