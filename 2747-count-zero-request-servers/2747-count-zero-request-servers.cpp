int freq[1000001];
struct query{
    int l,r,id;
};
int len, cnt;
bool cmp(const query& a, const query& b) {
    int x = a.l/len, y = b.l/len;
    if (x != y) return x<y;
    return (x & 1)?(a.r<b.r):(a.r>b.r);
}
bool cmp1(vector<int>& a, vector<int>& b){
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
class Solution {
public:
    void add(int i, vector<vector<int>>& logs){
        if(freq[logs[i][0]]==0) cnt++;
        freq[logs[i][0]]++;
    }
    void remove(int i, vector<vector<int>>& logs){
        if(freq[logs[i][0]]==1) cnt--;
        freq[logs[i][0]]--;
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int sz = queries.size();
        len = sqrt(logs.size());
        cnt = 0;
        vector<query> q(sz);
        memset(freq,0,sizeof freq);
        sort(logs.begin(),logs.end(),cmp1);
        vector<int> times;
        for(auto &v:logs) times.push_back(v[1]);
        sort(times.begin(),times.end());
        for(int i=0;i<sz;i++){
            q[i].l = lower_bound(times.begin(),times.end(),queries[i]-x)-times.begin();
            q[i].r = upper_bound(times.begin(),times.end(),queries[i])-times.begin()-1;
            q[i].id = i;
        }
        sort(q.begin(),q.end(),cmp);
        vector<int> ans(sz,0);
        int pl=0, pr=-1;
        for(int i=0;i<sz;i++){
            int le=q[i].l, ri=q[i].r, idx=q[i].id;
            while(pl<le) remove(pl++, logs);
            while(pl>le) add(--pl, logs);
            while(pr<ri) add(++pr, logs);
            while(pr>ri) remove(pr--, logs);
            ans[idx] = n-cnt;
        }
        return ans;
    }
};