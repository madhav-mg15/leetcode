using ll = long long;
using pii = pair<ll,int>;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> s;
        vector<int> v(k,0);
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
            v[*it]++;
            mx = max(mx,v[*it]);
            s.erase(it);
        }
        vector<int> ans;
        for(int i=0;i<k;i++) if(mx==v[i]) ans.push_back(i);
        return ans;
    }
};