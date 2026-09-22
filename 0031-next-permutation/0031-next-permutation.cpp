class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pindx = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pindx = i;
                break;
            }
        }
        if(pindx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin()+pindx+1, nums.end());
        int nindx = -1;
        for(int i=pindx+1;i<n;i++){
            if(nums[i] > nums[pindx]){
                swap(nums[i],nums[pindx]);
                break;
            }
        }
        return;
    }
};