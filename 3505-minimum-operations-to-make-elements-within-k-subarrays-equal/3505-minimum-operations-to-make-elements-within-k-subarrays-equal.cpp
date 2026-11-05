using ll = long long;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> mul_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> llpbds;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>,rb_tree_tag, tree_order_statistics_node_update> llmul_pbds;
vector<vector<ll>> dp;
vector<ll> cost;
class Solution {
public:
    void generate(vector<int>& nums, int x){
        int n = nums.size();
        llmul_pbds lo,hi;
        multiset<pair<ll,ll>> s;
        ll sumLo=0, sumHi=0;
        for(int i=0;i<x;i++) s.insert({nums[i],i});
        for(auto ele:s){
            if(lo.size()<((x+1)/2)){
                lo.insert(ele);
                sumLo+=ele.first;
            }
            else{
                hi.insert(ele);
                sumHi+=ele.first;
            }
        }
        for(int i=0;i<=n-x;i++){
            ll median = lo.find_by_order({lo.size()-1})->first;
            ll a = ((ll)lo.size()*median-sumLo) +(sumHi-median*(ll)hi.size());
            cost.push_back(a);
            pair<ll,ll> p = {nums[i],i};
            if(lo.find(p)!=lo.end()){
                sumLo-=nums[i];
                lo.erase({nums[i],i});
            }
            else{
                sumHi-=nums[i];
                hi.erase({nums[i],i});
            }
            if(i==n-x) break;
            ll ele=nums[i+x];
            if(lo.empty() || ele<=lo.find_by_order(lo.size()-1)->first){
                sumLo+=nums[i+x];
                lo.insert({ele,i+x});
            }
            else{
                sumHi+=ele;
                hi.insert({ele,i+x});
            }
            while(lo.size()<((x+1)/2)){
                auto pl=hi.find_by_order(0);
                lo.insert(*pl);
                sumHi-=pl->first;
                sumLo+=pl->first;
                hi.erase(pl);
            }
            while(lo.size()>((x+1)/2)){
                auto pl=lo.find_by_order(lo.size()-1);
                hi.insert(*pl);
                sumHi+=pl->first;
                sumLo-=pl->first;
                lo.erase(pl);
            }
            if(!lo.empty() && !hi.empty() && lo.find_by_order(lo.size()-1)->first>hi.find_by_order(0)->first){
                auto a=*lo.find_by_order(lo.size()-1);
                auto b=*hi.find_by_order(0);
                sumLo+=b.first-a.first;
                sumHi+=a.first-b.first;
                lo.erase(a);
                lo.insert(b);
                hi.erase(b);
                hi.insert(a);
            }
        }
    }
    ll f(int i, int k, int x, vector<int>& nums){
        if(k==0) return 0;
        if(i>nums.size()-x) return k==0 ? 0 : 1e18;
        if(dp[i][k]!=-1) return dp[i][k];
        return dp[i][k] = min(f(i+1,k,x,nums), cost[i]+f(i+x,k-1,x,nums));
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        dp = vector<vector<ll>>(n+1, vector<ll>(k+1,-1));
        cost = vector<ll>();
        generate(nums,x);
        return f(0,k,x,nums);
    }
};