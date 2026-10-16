int dp[201][201];
class Solution {
public:
    void generate(){
        static bool done = false;
        if(done) return;
        done = true;
        memset(dp,-1,sizeof dp);
    }
    int f(int l, int r){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 1e8;
        for(int p=l;p<=r;p++) ans = min(ans, p+max(f(l,p-1),f(p+1,r)));
        return dp[l][r] = ans;
    }
    int getMoneyAmount(int n) {
        generate();
        return f(1,n);
    }
};