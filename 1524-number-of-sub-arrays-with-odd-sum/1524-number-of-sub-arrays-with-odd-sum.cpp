const int MOD = (int)1e9 +7;
// vector<vector<int>> dp;
class Solution {
public:
    // int f(int i, int s, vector<int>& arr){
    //     if(i==arr.size()) return 0;
    //     if(dp[i][s]!=-1) return dp[i][s];
    //     int ans = 0;
    //     if(arr[i]%2==0) ans += (f(i+1,s,arr) + (s%2))%MOD;
    //     else ans += (f(i+1,(s+1)%2,arr) + ((s+1)%2))%MOD;
    //     return dp[i][s] = ans%MOD;
    // }
    int numOfSubarrays(vector<int>& arr) {
        long long sum = 0, odd=0, even=1, ans=0;
        for(int &x:arr){
            sum+=(x&1);
            if(sum&1){
                ans = (ans + even);
                odd++;
            }
            else{
                ans = (ans + odd);
                even++;
            }
        }
        return ans%MOD;
    }
};