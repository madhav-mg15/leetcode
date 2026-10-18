class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt=0, n=nums.size(), i=0;
        while(i<n){
            int j=i+1;
            while(j<n && nums[i]==nums[j]) j++;
            cnt += (j-i-1);
            i=j;
            cout<<cnt<<" ";
        }
        return cnt;
    }
};