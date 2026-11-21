vector<int> ca;
class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, unordered_map<char,vector<int>>& m, string& s){
        if(!m[s[i]].empty()) ca[i] = m[s[i]].back();
        m[s[i]].push_back(i);
        for(int &x:adj[i]) dfs(x,adj,m,s);
        m[s[i]].pop_back();
    }
    int f(int i, vector<vector<int>>& adj, vector<int>& ans){
        if(adj[i].empty()) return ans[i] = 1;
        int c=1;
        for(int &x:adj[i]) c += f(x,adj,ans);
        return ans[i] = c;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> ans(n,1);
        unordered_map<char,vector<int>> m;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<parent.size();i++) if(parent[i]!=-1) adj[parent[i]].push_back(i);
        ca = parent;
        dfs(0,adj,m,s);
        adj = vector<vector<int>>(n+1);
        for(int i=0;i<ca.size();i++) if(ca[i]!=-1) adj[ca[i]].push_back(i);
        f(0,adj,ans);
        return ans;
    }
};