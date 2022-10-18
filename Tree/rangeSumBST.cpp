//938. Range Sum of BST

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> nodes ;
        int sum = 0;
        while(root){
            if(root->left){
            TreeNode* pre = root->left;
            while(pre->right && pre->right!= root){
                pre = pre->right;
            }
            if(!pre->right){
                pre->right = root;
                root= root->left;
            }
            else{
                pre->right= NULL;
                nodes.push_back(root->val);
                if(root->val >=low && root-> val<= high){
                sum +=root->val;
                }
                root=root->right;
            }
            }
            else{
                nodes.push_back(root->val);
                 if(root->val >=low && root-> val<= high){
                sum +=root->val;
                 }
                root= root->right;
            }
            
        }
        return sum;
    }
};

//using threaded binary tree:

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        int ans = 0;
        while(root) 
            if(root -> left && root -> val >= L) {
                auto pre = root -> left;  
                // finding predecessor of root
                while(pre -> right && pre -> val <= H) pre = pre -> right;
                // make root as right child of predecessor (temporary link)
                pre -> right = root;        // adding temporary link
                auto tmp = root;
                root = root -> left;                    
                tmp -> left = nullptr;      // avoiding inifinte loop
            }
			else {
                if(root -> val >= L && root -> val <= H) ans += root -> val;
                if(root -> val < H) root = root -> right;
                else break;
            }
        
        return ans;
    }
};

