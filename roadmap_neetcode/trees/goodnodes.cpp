//Problem: Count the "good" nodes in a binary tree (all nodes x in which the path from the root has no values greater than x's value)
//Sol: Use dfs to traverse the graph while comparing node's values to the maximum value in the path so far.

class Solution {
    public: 
        int goodNodes(TreeNode* root) {
            int res = 1;
            int max = root->val;
            dfs(root, max, res);
            return res;
        }
    private:
        void dfs(TreeNode* node, int& max, int& res) {
            if (!node) return;     
            
            int aux;
            if (node->val >= max) res++;

            aux = max;
            max = max(node->val, max);

            dfs(node->right, max, res);
            dfs(node->left, max, res);

            max = aux;
            return;
        }
}