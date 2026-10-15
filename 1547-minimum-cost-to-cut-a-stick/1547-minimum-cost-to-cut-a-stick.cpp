using pi = pair<int,int>;
class Solution {
public:
    int f(int l, int r, map<pi,int>& dp, vector<int>& cuts){
        if(l+1==r) return 0;
        if(dp.find({l,r}) != dp.end()) return dp[{l,r}];
        int ans=1e8;
        for(int p=l+1;p<r;p++) ans = min(ans,cuts[r]-cuts[l]+f(l,p,dp,cuts)+f(p,r,dp,cuts));
        return dp[{l,r}] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        map<pi,int> dp;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return f(0,cuts.size()-1,dp,cuts);
    }
};