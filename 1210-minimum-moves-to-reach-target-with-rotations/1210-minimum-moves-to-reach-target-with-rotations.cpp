class Solution {
public:
    bool isValid(int i, int j, int n){
        return i>=0 && j>=0 && i<n && j<n;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size();
        q.push({0,1,0,0,0,0});
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(n, vector<bool>(2,0)));
        vis[0][1][0]=1;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int hr=x[0], hc=x[1], tr=x[2], tc=x[3], mvs=x[4], dcn=x[5];
            if(hr==n-1 && hc==n-1 && tr==n-1 && tc==n-2) return mvs;
            if(dcn==0){
                if(isValid(hr,hc+1,n) && !grid[hr][hc+1] && !vis[hr][hc+1][0]){
                    q.push({hr,hc+1,hr,hc,mvs+1,0});
                    vis[hr][hc+1][0]=1;
                }
                if(isValid(hr+1,hc,n) && !grid[hr+1][hc] && !vis[hr+1][hc][0] && isValid(tr+1,tc,n) && !grid[tr+1][tc]){
                    q.push({hr+1,hc,tr+1,tc,mvs+1,0});
                    vis[hr+1][hc][0]=1;
                }
                if(isValid(tr+1,tc,n) && !grid[tr+1][tc] && !vis[tr+1][tc][1] && isValid(hr+1,hc,n) && !grid[hr+1][hc]){
                    q.push({tr+1,tc,tr,tc,mvs+1,1});
                    vis[tr+1][tc][1]=1;
                }
            }
            else{
                if(isValid(hr+1,hc,n) && !grid[hr+1][hc] && !vis[hr+1][hc][1]){
                    q.push({hr+1,hc,hr,hc,mvs+1,1});
                    vis[hr+1][hc][1]=1;
                }
                if(isValid(hr,hc+1,n) && !grid[hr][hc+1] && !vis[hr][hc+1][1] && isValid(tr,tc+1,n) && !grid[tr][tc+1]){
                    q.push({hr,hc+1,tr,tc+1,mvs+1,1});
                    vis[hr][hc+1][1]=1;
                }
                if(isValid(tr,tc+1,n) && !grid[tr][tc+1] && !vis[tr][tc+1][0] && isValid(hr,hc+1,n) && !grid[hr][hc+1]){
                    q.push({tr,tc+1,tr,tc,mvs+1,0});
                    vis[tr][tc+1][0]=1;
                }
            }
        }
        return -1;
    }
};