using ll = long long;
using pll = pair<ll,ll>;
class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        vector<ll> frq(n,0), ans(n,-1);
        vector<vector<pll>> adj(n);
        ans[0] = 0;
        for(auto x:edges) adj[x[0]].push_back({x[1],x[2]});
        pq.push({0,0});
        while(!pq.empty()){
            ll t = pq.top().first, node = pq.top().second;
            frq[node]++;
            pq.pop();
            if(node!=0 && ans[node]!=-1) continue;
            if(frq[node]>=requiredSignals[node] && ans[node]==-1) ans[node] = t;
            if(node==0 || frq[node]>=requiredSignals[node]){
                for(auto &x:adj[node]){
                    if(ans[x.first]!=-1) continue;
                    pq.push({t+x.second,x.first});
                }
            }
        }
        return ans;
    }
};