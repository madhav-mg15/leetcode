class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, n = nums.size();
        for(int i=0;i<n;i++){
            int a = 1, b = 1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]) a++;
                else break;
            }
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[j-1]) b++;
                else break;
            }
            ans = max({ans,a,b});
        }
        return ans;
    }
};