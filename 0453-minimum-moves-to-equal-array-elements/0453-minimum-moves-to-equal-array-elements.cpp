class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0, k=0;
        for(int i=1;i<nums.size();i++){
            ans+=k+nums[i]-nums[i-1];
            k+=nums[i]-nums[i-1];
        }
        return ans;
    }
};