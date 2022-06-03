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
    vector<int>bigtree;
    vector<int>smalltree;
    int salt,sub_root_val;
    void dfs_tour(TreeNode* current,char side,vector<int>&tree){
        salt = (side == 'l') ? 100000 : 0 ;
        if(current->val == sub_root_val)salt=0;
        tree.push_back(current->val + salt);
        if(current->left != nullptr)dfs_tour(current->left,'l',tree);
        if(current->right != nullptr)dfs_tour(current->right,'r',tree);
        tree.push_back(current->val + salt);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        sub_root_val = subRoot->val;
        dfs_tour(root,'m',bigtree);
        dfs_tour(subRoot,'m',smalltree);
        if(bigtree.size() < smalltree.size())return false;
        bool flag;
        for(int i=0;i<=bigtree.size()-smalltree.size();i++){
            flag = true;
            for(int j=0;j<smalltree.size();j++){
                if(bigtree[i+j] != smalltree[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true)break;
        }
        return flag;
    }
};