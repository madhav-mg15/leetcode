using ll = long long;
const int MOD = 1000000007;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> v(30,0);
        for(int &x:nums) for(int i=0;i<30;i++) v[i]+= ((x>>i)&1);
        ll ans = 0;
        while(k--){
            ll n=0;
            for(int i=0;i<30;i++){
                if(v[i]!=0){
                    n|=(1LL<<i);
                    v[i]--;
                }
            }
            ans = (ans + (n*n)%MOD)%MOD;
        }
        return ans;
    }
};