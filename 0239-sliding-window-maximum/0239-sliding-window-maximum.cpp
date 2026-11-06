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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        mul_pbds s;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++) s.insert({nums[i],i});
        for(int i=0;i<=n-k;i++){
            ans.push_back(s.find_by_order(s.size()-1)->first);
            s.erase({nums[i],i});
            if(i==n-k) break;
            s.insert({nums[i+k],i+k});
        }
        return ans;
    }
};