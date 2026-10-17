using pi = pair<int,pair<int,int>>;
bool cmp(pi &a, pi &b){
    return a.second.first == b.second.first ? (a.first<b.first) : (a.second.first < b.second.first);
}
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<pi> v(n);
        for(int i=0;i<n;i++){
            int a = nums[i], s = 0;
            while(a){
                s += a%10;
                a/=10;
            }
            v[i] = {nums[i],{s,i}};
        }
        sort(v.begin(),v.end(),cmp);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            cnt++;
            int k=i;
            while(!vis[k]){
                vis[k] = true;
                k = v[k].second.second;
            }
        }
        return n-cnt;
    }
};