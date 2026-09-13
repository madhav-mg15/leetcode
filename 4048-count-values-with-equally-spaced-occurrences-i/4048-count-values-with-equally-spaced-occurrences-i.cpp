class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        int ans=0;
        for(auto x:m){
            vector<int> v = x.second;
            if(v.size()!=3) continue;
            int diff=v[1]-v[0], f=0;
            for(int i=1;i<v.size();i++){
                if(v[i]-v[i-1]!=diff){
                    f=1;
                    break;
                }
            }
            ans += (f==0);
        }
        return ans;
    }
};