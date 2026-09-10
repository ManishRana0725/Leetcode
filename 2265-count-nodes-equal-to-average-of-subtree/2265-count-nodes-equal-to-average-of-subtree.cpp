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
    // sum , subtreelen
    pair<int , int> solve(TreeNode* root ){
        if(root == nullptr){
            return {0 , 0};
        }

        pair<int ,int > left = solve(root->left);
        pair<int ,int > right = solve(root->right);

        pair<int , int> ans;
        ans.first = left.first + right.first + root->val;
        ans.second = left.second + right.second + 1;

        if(ans.first / ans.second == root->val){
            count++;
        }
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int , int> a = solve(root);

        return count;
    }
};