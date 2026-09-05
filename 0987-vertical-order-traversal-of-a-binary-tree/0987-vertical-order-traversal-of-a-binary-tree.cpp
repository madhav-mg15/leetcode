/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int r = q.front().second.first, c = q.front().second.second;
            q.pop();
            m[c].push_back({r,temp->val});
            if(temp->left) q.push({temp->left,{r+1,c-1}});
            if(temp->right) q.push({temp->right,{r+1,c+1}});
        }
        vector<vector<int>> ans;
        for(auto x:m){
            int c = x.first;
            vector<pair<int,int>> v = x.second;
            sort(v.begin(),v.end());
            vector<int> a;
            for(auto ele:v) a.push_back(ele.second);
            ans.push_back(a);
        }
        return ans;
    }
};