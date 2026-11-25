using ll = long long;
const int MOD = 1e9+7;
class Solution {
public:
    bool f(vector<int>& nums, int k){
        unordered_map<ll,int> m;
        int n = nums.size();
        ll s = 0, b = 100005, p = 1;
        for(int i=0;i<k;i++) s = ((s*b)%MOD + nums[i])%MOD;
        for(int i=0;i<k-1;i++) p = (p*b)%MOD;
        m[s]++;
        for(int i=0;i<n-k;i++){
            s = (s - (nums[i]*p)%MOD + MOD)%MOD;
            if(i+k==n) break;
            s = ((s*b)%MOD + nums[i+k])%MOD;
            m[s]++;
        }
        for(auto x:m) if(x.second==1) return true;
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int lo = 1, hi = n, ans = n;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(f(nums, mid)){
                ans = mid;
                hi = mid-1;
            } 
            else lo = mid+1;
        }
        return ans;
    }
};