//2415. Reverse Odd Levels of Binary Tree

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
    void reverse(TreeNode* rootleft, TreeNode* rootright, int level){
        if(rootleft== nullptr and rootright == nullptr){
            return ;
        }
        if(level%2 == 0){
            swap(rootleft->val, rootright->val);
        }
        reverse(rootleft->left, rootright->right, level+1 );
        reverse(rootleft->right, rootright->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root){
        reverse(root->left,root->right,0);
        return root;
    }
};



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = deque([root])
        level = 0
        while q:
            if(level%2!=0):
                l=0
                r = len(q)-1
                while(l<r):
                    q[l].val,q[r].val = q[r].val, q[l].val
                    l+=1
                    r-=1
            for _ in range(len(q)):
                cur = q.popleft()
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
            level+=1
        return root
    