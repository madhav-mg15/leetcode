#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ll = long long;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> mul_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> llpbds;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>,rb_tree_tag, tree_order_statistics_node_update> llmul_pbds;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        mul_pbds s;
        int n=nums.size();
        vector<double> ans;
        for(int i=0;i<k;i++) s.insert({nums[i],i});
        for(int i=0;i<=n-k;i++){
            if(k%2==0){
                ll m1=s.find_by_order(k/2-1)->first;
                ll m2=s.find_by_order(k/2)->first;
                m1+=m2;
                ans.push_back(m1/2.0);
            }
            else{
                ll m1=s.find_by_order(k/2)->first;
                ans.push_back(m1);
            }
            if(i+k<n){
                s.erase({nums[i],i});
                s.insert({nums[i+k],i+k});
            }
        }
        return ans;
    }
};