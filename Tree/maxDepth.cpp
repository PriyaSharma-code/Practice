//104. Maximum Depth of Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
};

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
    
        queue = [(root, 1)]
        self.res = 0
    
        while queue:
            root, nums = queue.pop(0)
        
            if not root.left and not root.right:
                self.res = max(self.res, nums)
            
            if root.left:
                queue.append((root.left, nums + 1))
            
            if root.right:
                queue.append((root.right, nums + 1))
            
        return self.res