/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void build(TreeNode* root, string& s){
        if(root==nullptr){
            s+="#,";
            return;
        }
        s+=to_string(root->val)+",";
        build(root->left,s);
        build(root->right,s);

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        build(root,s);
        return s;
    }
    TreeNode* makeTree(stringstream& ss){
        string x;
        getline(ss,x,',');
        if (x=="#"){
            return nullptr;
        }
        TreeNode* root= new TreeNode(stoi(x));
        root->left= makeTree(ss);
        root->right= makeTree(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return makeTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));