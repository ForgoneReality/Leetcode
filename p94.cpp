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
    
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> answer;
        if (!root) return answer;
        stack<TreeNode *> vertical;
        vertical.push(root);
        while (root->left) {
            vertical.push(root->left);
            root = root->left;
        }
        while (!vertical.empty()) {
            TreeNode *itr = vertical.top();
            vertical.pop();
            answer.push_back(itr->val);
            if (itr->right) { 
                TreeNode *right = itr->right;
                vertical.push(right);
                while (right->left)
                {
                    right = right->left;
                    vertical.push(right);
                }
            }
        }
        return answer;
    }
private:
};