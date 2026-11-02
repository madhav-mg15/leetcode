#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> mul_pbds;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        mul_pbds s;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            s.insert({nums[i],i});
            ans[i] = s.order_of_key({nums[i],-1});
        }
        return ans;
    }
};