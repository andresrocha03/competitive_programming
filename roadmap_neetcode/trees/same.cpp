//Problem: Given two binary trees, check if they are equivalent (same structure and node values).
//Sol: Use dfs to traverse both trees simultaneously and check values while doing it.


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (!p && !q) return true;
        else if (p && q) {
            bool equi;
            equi = (p->val == q->val);
            return equi && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        //all the other possibilities lead to non-equivalence and we return false;
        return false;
    }
};
