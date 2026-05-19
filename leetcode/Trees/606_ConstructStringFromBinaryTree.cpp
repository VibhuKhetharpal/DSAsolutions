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
        string dfs(TreeNode* root){
            if (root==nullptr)return "";
    
            string res = to_string(root->val);
            if(!root->left&&!root->right){
                return res;
    
            }else if (!root->left&&root->right){
                res+="()("+dfs(root->right)+")";
            }
            else if(root->left && !root->right) {
            res += "(" + dfs(root->left) + ")";
    }
            else{
                res+="("+dfs(root->left)+")"+"("+dfs(root->right)+")";
            }
    
            return res;
        }
        string tree2str(TreeNode* root) {
            return dfs(root);
        }
    };