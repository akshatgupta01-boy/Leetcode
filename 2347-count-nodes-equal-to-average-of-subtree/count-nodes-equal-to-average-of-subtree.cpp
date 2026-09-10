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
    pair<int, int> traversal(TreeNode* root, int& count){
        if(root == NULL) return {0, 0};
        auto[leftSum, leftCount] = traversal(root -> left, count);
        auto[rightSum, rightCount] = traversal(root -> right, count);
        int totalSum = leftSum + rightSum + root -> val;
        int totalCount = leftCount + rightCount + 1;
        if(totalSum / totalCount == root -> val) count++;
        return {totalSum, totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0; 
        traversal(root, count);
        return count;
    }
};