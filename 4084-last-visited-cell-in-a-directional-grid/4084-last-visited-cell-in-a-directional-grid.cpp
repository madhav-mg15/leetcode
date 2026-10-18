class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        unordered_map<char,pair<int,int>> mp;
        int m = grid.size(), n = grid[0].size();
        mp['U'] = {-1,0};
        mp['D'] = {1,0};
        mp['R'] = {0,1};
        mp['L'] = {0,-1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();
            int nr = r + mp[grid[r][c]].first, nc = c + mp[grid[r][c]].second;
            if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc]) return {r,c};
            q.push({nr,nc});
            vis[nr][nc] = true;
        }
        return {};
    }
};