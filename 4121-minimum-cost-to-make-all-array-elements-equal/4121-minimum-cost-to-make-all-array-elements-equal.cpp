using ll = long long;
class Solution {
public:
    long long minCost(vector<int>& nums) {
        ll ans = 1e18;
        int n = nums.size();
        vector<ll> pre(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) pre[i] = (ll)nums[i]*(ll)i;
            else pre[i] = pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=nums[i+1]) pre[i] += (ll)nums[i]*(ll)(n-i-1);
            else pre[i] = pre[i+1];
        }
        for(int i=1;i<n-1;i++) ans = min(ans,pre[i]);
        return ans;
    }
};