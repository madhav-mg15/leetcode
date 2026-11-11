using ll = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll a = (ll)cost1*(ll)need1 + (ll)cost2*(ll)need2;
        ll b = (ll)costBoth*(ll)(min(need1,need2)) + ((need1>=need2) ? ((ll)min(costBoth,cost1)*(ll)(need1-need2)) : ((ll)min(costBoth,cost2)*(ll)(need2-need1)));
        return min(a,b);
    }
};