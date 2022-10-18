//98. Validate Binary Search Tree

class Solution {
public:
    bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) {
    if (root == NULL) return true;
    if (root->val <= min || root->val >= max) return false;
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
  }
};

class Solution:
    def isValidBST(self, root, s=-inf, e=inf):
        if not root:
            return True
        if s >= root.val or e <= root.val:
            return False
        return self.isValidBST(root.left, s, root.val) and self.isValidBST(root.right, root.val, e)
        