class Solution {
private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == NULL)
                return root->right;
            if (root->right == NULL)
                return root->left;

            TreeNode* succ = findMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};
