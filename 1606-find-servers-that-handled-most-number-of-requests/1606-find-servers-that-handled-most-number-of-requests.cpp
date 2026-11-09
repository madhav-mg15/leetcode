using ll = long long;
using pii = pair<ll,int>;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> s;
        unordered_map<int,int> m;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<k;i++) s.insert(i);
        int mx = 0, n = arrival.size(), t = 0;
        for(int i=0;i<n;i++){
            t = max(t,arrival[i]);
            while(!pq.empty() && pq.top().first<=t){
                s.insert(pq.top().second);
                pq.pop();
            }
            if(s.empty()) continue;
            auto it = s.lower_bound(i%k);
            if(it==s.end()) it = s.begin();
            pq.push({t+load[i],*it});
            m[*it]++;
            mx = max(mx,m[*it]);
            s.erase(it);
        }
        vector<int> ans;
        for(auto &x:m) if(x.second==mx) ans.push_back(x.first);
        return ans;
    }
};