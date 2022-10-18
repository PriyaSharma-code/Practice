//101. Symmetric Tree

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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return helper(p->left,q->right) && helper(p->right, q->left); 
    }
};


//iterative solution:
bool isSymmetric(TreeNode* root) {
         if (root == NULL) return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty())
        {
            TreeNode *left = q1.front(); q1.pop();
            TreeNode *right = q2.front(); q2.pop();
            
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        
        return true;
    }