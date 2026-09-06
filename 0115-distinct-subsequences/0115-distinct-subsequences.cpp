using ll = long long;
ll dp[1005][1005];
string s,t;
int n,m;
class Solution {
public:
    ll f(int i, int j){
        if(j==m) return 1;
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans = f(i+1,j);
        if(s[i]==t[j]) ans += f(i+1,j+1);
        return dp[i][j]=ans;
    }
    int numDistinct(string s1, string t1) {
        s=s1;
        t=t1;
        n=s.length(), m=t.length();
        memset(dp,-1,sizeof dp);
        return f(0,0);
    }
};