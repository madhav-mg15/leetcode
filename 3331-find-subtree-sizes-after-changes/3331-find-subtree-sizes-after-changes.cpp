class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<vector<int>>& m, string& s, vector<int>& ca){
        if(!m[s[i]-'a'].empty()) ca[i] = m[s[i]-'a'].back();
        m[s[i]-'a'].push_back(i);
        for(int &x:adj[i]) dfs(x,adj,m,s,ca);
        m[s[i]-'a'].pop_back();
    }
    int f(int i, vector<vector<int>>& adj, vector<int>& ans){
        if(adj[i].empty()) return ans[i] = 1;
        int c=1;
        for(int &x:adj[i]) c += f(x,adj,ans);
        return ans[i] = c;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> ans(n,1), ca = parent;
        vector<vector<int>> v(26);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<parent.size();i++) if(parent[i]!=-1) adj[parent[i]].push_back(i);
        dfs(0,adj,v,s,ca);
        adj = vector<vector<int>>(n+1);
        for(int i=0;i<ca.size();i++) if(ca[i]!=-1) adj[ca[i]].push_back(i);
        f(0,adj,ans);
        return ans;
    }
};