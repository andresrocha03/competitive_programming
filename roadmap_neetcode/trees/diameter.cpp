//Problem: GIven a binary tree, find the diameter of the tree (longest path between any two nodes).
//Sol: Use dfs to compute the depth of each node while keeping track of the maximum diameter found so far (the sum of the depths of the left and right subtrees).

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
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left+right);

        return 1+max(left, right);

    }
};
