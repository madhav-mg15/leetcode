class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), ans = 1e8;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(j-i+1>=l && j-i+1<=r && sum>0) ans=min(ans,sum);
            }
        }
        return ans==1e8 ? -1 : ans;
    }
};