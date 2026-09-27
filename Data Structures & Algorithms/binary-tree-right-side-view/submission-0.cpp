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
        vector<int> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n= q.size();
            for(int i=0;i<n;i++){
                TreeNode* p= q.front();
                q.pop();
                level.push_back(p->val);
                if(p->left != NULL) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            result.push_back(level[level.size()-1]);
        }
        return result;
    }
};
