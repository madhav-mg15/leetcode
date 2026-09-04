class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(), mx=-1e9;
        vector<int> suf(n);
        suf[n-1] = nums.back();
        for(int i=n-2;i>=0;i--) suf[i] = min(nums[i],suf[i+1]);
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            if(mx-suf[i]<=k) return i;
        }
        return -1;
    }
};