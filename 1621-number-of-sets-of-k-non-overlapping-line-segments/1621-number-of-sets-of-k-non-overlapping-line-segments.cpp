using ll = long long;
vector<vector<vector<ll>>> dp;
int n,k; 
const ll MOD = 1000000007;
class Solution {
public:
    ll f(int i, int j, int t){
        if(i==n) return j==k && t==0;
        if(dp[i][j][t]!=-1) return dp[i][j][t];
        ll ans=f(i+1,j,t)%MOD;
        if(t==0) ans = (ans%MOD + f(i+1,j,1)%MOD);
        else{
            if(j<k) ans = (ans%MOD + f(i+1,j+1,0)%MOD + f(i+1,j+1,1)%MOD)%MOD;
        }
        return dp[i][j][t]=ans%MOD;
    }
    int numberOfSets(int n1, int k1) {
        n=n1, k=k1;
        dp = vector<vector<vector<ll>>> (n+1, vector<vector<ll>>(k+1, vector<ll>(2,-1)));
        return f(0,0,0)%MOD;
    }
};