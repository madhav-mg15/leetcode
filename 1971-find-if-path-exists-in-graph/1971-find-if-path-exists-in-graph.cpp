class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        vector<int> vis(n, false);
        if(src==dst) return true;
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            src = q.front();
            q.pop();
            if(src == dst) return true;
            for(auto x:adj[src]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        return false;
    }
};