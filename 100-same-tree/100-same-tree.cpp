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
    vector<int>ptree;
    vector<int>qtree;
    int salt;
    void dfs_tour(TreeNode* current,char side,vector<int>&tree){
        salt = (side == 'l') ? 100000 : 0 ;
        tree.push_back(current->val + salt);
        if(current->left != nullptr)dfs_tour(current->left,'l',tree);
        if(current->right != nullptr)dfs_tour(current->right,'r',tree);
        tree.push_back(current->val + salt);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q ==nullptr)return true;
        if( (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) )return false;
        dfs_tour(p,'m',ptree);
        dfs_tour(q,'m',qtree);
        if(ptree.size() != qtree.size())return false;
        return ptree == qtree;
    }
};