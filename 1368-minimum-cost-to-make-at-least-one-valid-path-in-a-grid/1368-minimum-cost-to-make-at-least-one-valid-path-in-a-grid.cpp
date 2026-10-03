class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    int minCost(vector<vector<int>>& grid) {
        deque<pair<int,pair<int,int>>> q;
        q.push_back({0,{0,0}});
        int m=grid.size(), n=grid[0].size(), ans=1e8;
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(5,false)));
        vis[0][0][grid[0][0]]=true;
        while(!q.empty()){
            auto a = q.front();
            q.pop_front();
            int cost = a.first;
            int r=a.second.first, c=a.second.second;
            if(r==m-1 && c==n-1){
                ans=min(ans,cost);
                continue;
            }
            if(isValid(r,c+1,m,n) && !vis[r][c+1][1]){
                if(grid[r][c]==1) q.push_front({cost,{r,c+1}});
                else q.push_back({cost+1,{r,c+1}});
                vis[r][c+1][1]=true;
            }
            if(isValid(r,c-1,m,n) && !vis[r][c-1][2]){
                if(grid[r][c]==2) q.push_front({cost,{r,c-1}});
                else q.push_back({cost+1,{r,c-1}});
                vis[r][c-1][2]=true;
            }
            if(isValid(r+1,c,m,n) && !vis[r+1][c][3]){
                if(grid[r][c]==3) q.push_front({cost,{r+1,c}});
                else q.push_back({cost+1,{r+1,c}});
                vis[r+1][c][3]=true;
            }
            if(isValid(r-1,c,m,n) && !vis[r-1][c][4]){
                if(grid[r][c]==4) q.push_front({cost,{r-1,c}});
                else q.push_back({cost+1,{r-1,c}});
                vis[r-1][c][4]=true;
            }
        }   
        return ans;
    }
};