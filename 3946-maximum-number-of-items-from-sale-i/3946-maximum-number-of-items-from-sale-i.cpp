vector<int> v;
vector<vector<int>> dp;
class Solution {
public:
    int f(int i, int budget, int mn, vector<vector<int>>& items){
        int n = items.size();
        if(i==n){
            if(budget<=0) return 0;
            return budget/mn;
        }
        if(dp[i][budget]!=-1) return dp[i][budget];
        int ans = f(i+1,budget,mn,items);
        if(items[i][1]<=budget) ans = max(ans, f(i+1,budget-items[i][1],mn,items) + v[i]);
        return dp[i][budget] = ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = 1e8;
        v = vector<int>(n,1);
        for(int i=0;i<n;i++){
            mn = min(mn, items[i][1]);
            for(int j=0;j<n;j++) if(i!=j && items[j][0]%items[i][0] == 0) v[i]++;
        }
        dp = vector<vector<int>> (n, vector<int>(budget+1,-1));
        return f(0,budget,mn,items);
    }
};