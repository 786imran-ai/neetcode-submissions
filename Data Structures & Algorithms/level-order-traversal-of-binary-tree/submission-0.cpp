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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n= que.size();
            vector<int> levels;
            for(int i=0;i<n;i++){
                TreeNode* p= que.front();
                que.pop();
                levels.push_back(p->val);
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);

            }
            result.push_back(levels);
        }
        return result;



    }
};
