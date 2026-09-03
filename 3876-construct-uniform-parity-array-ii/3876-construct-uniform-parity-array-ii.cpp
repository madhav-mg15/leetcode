class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = 1e9, ce = 0, n = nums.size();
        for(int &x: nums){
            if(x%2==0) ce++;
            mn=min(mn,x);
        }
        if(mn%2 == 0) return ce == n;
        return true;
        
    }
};