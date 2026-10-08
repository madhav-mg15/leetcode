using ll = long long;
vector<vector<vector<vector<ll>>>> dp;
vector<int> nums;
int n;
class Solution {
public:
    ll f(int i, int d, int s, int k){
        if(i==n){
            return k==0 ? -1e18 : 0;
        }
        if(dp[i][d][s][k]!=-1e18) return dp[i][d][s][k];
        ll ans=0;
        if(k==0) ans = f(i+1,0,0,0);
        if(d==0){
            if(k==1) ans = max(ans,f(i+1,1,s,1));
            ans = max(ans,f(i+1,0,1-s,1) + (s==0 ? nums[i] : -nums[i]));
        }
        else ans = max(ans,f(i+1,1,1-s,1) + (s==0 ? nums[i] : -nums[i]));
        return dp[i][d][s][k] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums1) {
        nums = nums1;
        n = nums.size();
        dp = vector<vector<vector<vector<ll>>>>(n, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2,vector<ll>(2,-1e18))));
        return f(0,0,0,0);
    }
};