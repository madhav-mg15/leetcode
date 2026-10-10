using pi = pair<int,pair<int,int>>;
class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dis(m, vector<int>(n,1e8));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int ans = x.first, r = x.second.first, c = x.second.second;
            if(r==m-1 && c==n-1) return ans;
            for(int d=0;d<4;d++){
                int nr = r+dir[d][0], nc = c+dir[d][1];
                if(isValid(nr,nc,m,n)){
                    int y = max(abs(heights[nr][nc]-heights[r][c]),ans);
                    if(y<dis[nr][nc]){
                        pq.push({y,{nr,nc}});
                        dis[nr][nc] = y;
                    }
                }
            }
        }
        return -1;
    }
};