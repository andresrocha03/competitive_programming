//Problem: Check if a binary tree is height-balanced;
//Sol: Use dfs to traverse tree and use a global variable to sign if we found some imbalance.


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
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        dfs(root, balance);
        return balance;
    }

private:
    int dfs(TreeNode* root, bool& balance) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        if (abs(left - right) > 1) balance = false;

        return 1 + max(left, right);

    }
};
