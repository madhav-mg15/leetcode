class Solution {
public:
    int minMoves(vector<int>& nums) {
        int d = *max_element(nums.begin(),nums.end()), ans = 0;
        for(int &x:nums) ans+=d-x;
        return ans;
    }
};