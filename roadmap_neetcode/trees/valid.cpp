//Problem: Given a binary tree, check if it is valid.
//Sol: Traverse the tree with dfs and check if node's values are inside the valid range.

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
    bool isValidBST(TreeNode* root) {
        int mini = INT_MIN;
        int maxi = INT_MAX;

        return dfs(root, mini, maxi);
    }

private:
    bool dfs(TreeNode* node, int mini, int maxi) {
        if (!node) return true;

        if (!(mini < node->val &&  node->val < maxi)) 
            return false;

        return dfs(node->right, node->val, maxi) && dfs(node->left, mini, node->val);
    }
};
