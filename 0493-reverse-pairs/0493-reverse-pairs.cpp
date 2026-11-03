using ll = long long;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> mul_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> llpbds;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>,rb_tree_tag, tree_order_statistics_node_update> llmul_pbds;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans=0, n=nums.size();
        llmul_pbds s;
        for(int i=n-1;i>=0;i--){
            ans+=s.order_of_key({nums[i],-1});
            s.insert({(ll)nums[i]*2,i});
        }
        return ans;
    }
};