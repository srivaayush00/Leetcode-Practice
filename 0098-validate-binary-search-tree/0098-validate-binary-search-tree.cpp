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
    typedef long long ll;
private:
    bool check(TreeNode* node, ll minVal, ll maxVal){
        if(node==NULL){
            return true;
        }
        
        if(node->val <= minVal || node->val >= maxVal)
            return false;

        return check(node->left, minVal, node->val) &&
               check(node->right, node->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};