using ll = long long;
vector<ll> fact; 
const ll MOD = 1000000007;
class Solution {
public:
    void generate(){
        static bool flg=false;
        if(flg) return;
        flg=true;
        fact.push_back(1);
        fact.push_back(1);
        for(int i=2;i<=2000;i++) fact.push_back((i%MOD * fact[i-1]%MOD)%MOD);
        return;
    }
    ll power(ll x, ll n){
        if(n==0) return 1;
        if(n==1) return x%MOD;
        ll ans=power(x,n/2)%MOD;
        if(n%2==0) return (ans%MOD * ans%MOD)%MOD;
        else return (x%MOD * ans%MOD * ans%MOD)%MOD;
    }
    int numberOfSets(int n, int k) {
        generate();
        ll a=fact[n+k-1];
        ll b=fact[2*k];
        ll c=fact[n-k-1];
        ll d=(b%MOD * c%MOD)%MOD;
        return (a%MOD * (power(d,MOD-2)%MOD))%MOD;
    }
};