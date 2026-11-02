class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[nums.size()/2], ans=0;
        for(int &x:nums) ans+=abs(x-a);
        return ans;
    }
};