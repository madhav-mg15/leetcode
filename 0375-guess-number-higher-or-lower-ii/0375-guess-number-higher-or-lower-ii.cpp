vector<vector<int>> dp;
class Solution {
public:
    int f(int l, int r){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 1e8;
        for(int p=l;p<=r;p++) ans = min(ans, p+max(f(l,p-1),f(p+1,r)));
        return dp[l][r] = ans;
    }
    int getMoneyAmount(int n) {
        dp = vector<vector<int>>(n+2, vector<int>(n+2,-1));
        return f(1,n);
    }
};