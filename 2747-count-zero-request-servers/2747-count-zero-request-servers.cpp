bool cmp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),cmp);
        int sz = queries.size(), cnt = 0;
        vector<int> ans(sz);
        int freq[1000001] = {0};
        vector<pair<int,int>> q;
        for(int i=0;i<sz;i++) q.push_back({queries[i],i});
        sort(q.begin(), q.end());
        int l=0,r=0;
        for(int i=0;i<sz;i++){
            int idx = q[i].second, t=q[i].first;
            while(r<logs.size() && logs[r][1]<=t){
                if(freq[logs[r][0]]==0) cnt++;
                freq[logs[r][0]]++;
                r++;
            }
            while(l<r && logs[l][1]<t-x){
                if(freq[logs[l][0]]==1) cnt--;
                freq[logs[l][0]]--;
                l++;
            }
            ans[idx] = n-cnt;
        }
        return ans;
    }
};