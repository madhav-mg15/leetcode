using ll = long long;
using pi = pair<int,int>;
using pii = pair<ll,pair<int,int>>;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        ll t = 0;
        vector<int> ans(m,0);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        priority_queue<pii,vector<pii>,greater<pii>> pq1;
        for(int i=0;i<n;i++) pq.push({servers[i],i});
        for(int i=0;i<m;i++){
            t=max(t,(ll)i);
            while(!pq1.empty() && (ll)pq1.top().first<=t){
                pq.push({pq1.top().second.first,pq1.top().second.second});
                pq1.pop();
            }
            if(pq.empty()){
                t=pq1.top().first;
                while(!pq1.empty() && pq1.top().first <= t){
                    pq.push({pq1.top().second.first,pq1.top().second.second});
                    pq1.pop();
                }
            }
            ans[i] = pq.top().second;
            pq1.push({tasks[i]+t,{pq.top().first,pq.top().second}});
            pq.pop();
        }
        return ans;
    }
};