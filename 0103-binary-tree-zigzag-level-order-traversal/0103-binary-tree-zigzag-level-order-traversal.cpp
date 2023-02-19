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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        bool r=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                temp.push_back(node->val);
            }
            if(!r)reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            // else{
            //     ans.push_back({temp.rbegin(),temp.rend()});
            // }
            r=!r;
            temp.clear();
        }
        return ans;
    }
};