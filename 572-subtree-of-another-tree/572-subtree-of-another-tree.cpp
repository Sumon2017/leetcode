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
    TreeNode* sub_root = nullptr;
    bool flag = false;
    void dfs(TreeNode* current){
        if(isSame(current,sub_root)){
            flag=true;
            return;
        }
        if(current->left != nullptr)dfs(current->left);
        if(current->right != nullptr)dfs(current->right);
    }
    bool isSame(TreeNode* a,TreeNode* b){
        if(a == nullptr || b== nullptr){
            return (a == nullptr && b == nullptr);
        }
        return ( a->val == b->val && isSame(a->left,b->left) && isSame(a->right,b->right) );
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        sub_root = subRoot;
        dfs(root);
        return flag;
    }
};