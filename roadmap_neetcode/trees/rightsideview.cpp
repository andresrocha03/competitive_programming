//Problem: Given a binary tree, return the nodes visible from the right side
//Sol: Use dfs prioritizing right nodes then the left ones. Keep track of the levels already visited and mark as visible the first visited node of a certain level.

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
    vector<int> rightSideView(TreeNode* root) {
        unordered_set<int> levels;
        vector<int> res;
        
        dfs(root, levels, res, 0);
        
        return res;
    }
private:
    void dfs(TreeNode* node, unordered_set<int>& levels, vector<int>& res, int curr_level) {
        if (!node) return;

        if (levels.count(curr_level) == 0){
            levels.insert(curr_level);
            res.push_back(node->val);
        }

        dfs(node->right, levels, res, curr_level+1);
        dfs(node->left, levels, res, curr_level+1);
    }
};
