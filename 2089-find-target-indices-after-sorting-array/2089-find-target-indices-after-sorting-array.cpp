class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int c1=0,c2=0;
        for(int& x:nums){
            if(x<target) c1++;
            if(x>target) c2++;
        }
        c2=nums.size()-c2;
        nums = vector<int>();
        for(int i=c1;i<c2;i++) nums.push_back(i);
        return nums;
    }
};