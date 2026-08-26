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
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL) return {};

        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        int lev=0;
        q.push({root,0});

        while(!q.empty()){

            auto [node,l]=q.front();
            q.pop();

            mp[l]=node->val;

            if(node->left) q.push({node->left,l+1});
            if(node->right) q.push({node->right,l+1});

        }

        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;

        
    }
};
