class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, ans = 2;
        unsigned long long pro = 1;
        while(r<n){
            if(gcd(nums[r],pro) != 1){
                ans = max(ans, r-l);
                while(l<n && gcd(nums[r],pro) != 1) pro /= nums[l++];
            }
            pro *= nums[r++];
        }
        ans = max(ans, r-l);
        return ans;
    }
};