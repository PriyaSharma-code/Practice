/*
572. Subtree of Another Tree
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root
 with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this 
node's descendants. 
The tree tree could also be considered as a subtree of itself.

*/
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
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }
        if(root == NULL  || subRoot == NULL){
            return false;
        }
        if(root->val == subRoot->val){
            return isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL){
            return true;   //null is present in all trees
        }
        if(root == NULL){
            return false;   //root is null but subroot is  not null
        }
        if(isIdentical(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot);
    }
};