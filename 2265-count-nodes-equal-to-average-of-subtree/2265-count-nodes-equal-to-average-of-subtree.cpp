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
    int count = 0;
    pair<int,int> solve(TreeNode* root ){     // {sun, n};
        if(!root) return {0,0};

        auto [leftsum , leftnodes] = solve(root->left);
        auto [rightsum , rightnodes] = solve(root->right);

        int n = rightnodes+leftnodes+1;
        int sum = leftsum+rightsum+root->val;
        if(sum/n==root->val) count++;

        return {sum, n};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};