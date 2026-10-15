using pi = pair<int,int>;
vector<int> nums;
map<pi,int> dp;
class Solution {
public:
    int f(int l, int r){
        if(l+1==r) return 0;
        if(dp.find({l,r}) != dp.end()) return dp[{l,r}];
        int ans=1e8;
        for(int p=l+1;p<r;p++) ans = min(ans,nums[r]-nums[l]+f(l,p)+f(p,r));
        return dp[{l,r}] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        dp = map<pi,int> ();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        nums = cuts;
        return f(0,nums.size()-1);
    }
};