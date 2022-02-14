/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 1* };
 */
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* subRoot)
    {
        if(subRoot == nullptr)
        {
            return (root == nullptr);
        }
        if(root == nullptr)//subroot not nullptr but root is
        {
            return false;
        }
        if(root->val == subRoot->val)
            return(helper(root->left,subRoot->left) && helper(root->right,subRoot->right));
        else
            return false;
    }
        
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr)
        {
            return false;
        }
        return (helper(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        
    }
};