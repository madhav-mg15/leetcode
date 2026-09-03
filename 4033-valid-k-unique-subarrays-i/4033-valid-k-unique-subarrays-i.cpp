struct query{
    int l, r, id;
};
vector<int> nums;
vector<query> q;
int freq[100001];
int len, d, x;
bool cmp(const query& a, const query& b) {
    int x = a.l/len, y = b.l/len;
    if (x != y) return x<y;
    return (x & 1)?(a.r<b.r):(a.r>b.r);
}
class Solution {
public:
    void add(int i){
        int ele = nums[i];
        freq[ele]++;
        if(freq[ele]==1) d++;
        if(freq[ele]%2 != 0) x++;
        else x--;
    }
    void rem(int i){
        int ele = nums[i];
        freq[ele]--;
        if(freq[ele]==0) d--;
        if(freq[ele]%2 != 0) x++;
        else x--;
    }
    vector<bool> validSubarrays(vector<int>& num, int k, vector<vector<int>>& queries) {
        int n = nums.size(), t = queries.size();
        nums = num;
        len = sqrt(n)+1;
        d=0, x=0;
        q = vector<query> (t);
        vector<bool> ans(t);
        for(int i=0;i<t;i++){
            q[i].l=queries[i][0];
            q[i].r=queries[i][1];
            q[i].id=i;
        }
        sort(q.begin(), q.end(), cmp);
        memset(freq,0,sizeof freq);
        int ml=0, mr=-1;
        for(int i=0;i<t;i++){
            int le=q[i].l, ri=q[i].r, idx=q[i].id;
            while(le<ml) add(--ml);
            while(le>ml) rem(ml++);
            while(ri<mr) rem(mr--);
            while(ri>mr) add(++mr);
            ans[idx] = (d==k && x==0);
        }
        return ans;
    }
};