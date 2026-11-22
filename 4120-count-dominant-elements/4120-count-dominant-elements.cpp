class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i=0;i<n;i++){
            if(i==0){
                if(n==1 || nums[i]>=nums[i+1]) ans++;
            }
            else if(i==n-1){
                if(nums[n-1]>=nums[n-2]) ans++;
            }
            else{
                if(2*nums[i]>=nums[i-1]+nums[i+1]) ans++;
            }
        }
        return ans;
    }
};