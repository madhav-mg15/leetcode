class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=1 && c>=1 && r<=m && c<=n;
    }
    bool bfs(int k, int row, int col, vector<vector<int>>& cells){
        set<pair<int,int>> st;
        for(int i=0;i<k;i++) st.insert({cells[i][0],cells[i][1]});
        vector<vector<bool>> vis(row+1, vector<bool>(col+1, false));
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=1;i<=col;i++){
            if(st.find({1,i}) == st.end()){
                q.push({1,i});
                vis[1][i] = true;
            }
        } 
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            if(r==row) return true;
            for(int d=0;d<4;d++){
                int nr = r+dir[d][0], nc = c+dir[d][1];
                if(isValid(nr,nc,row,col) && st.find({nr,nc}) == st.end() && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc] = true;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int m = cells.size(), n = cells[0].size();
        int lo = 1, hi = m;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(bfs(mid,row,col,cells)) lo = mid+1;
            else hi = mid-1;
        }
        return hi;
    }
};