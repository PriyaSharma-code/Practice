//108. Convert Sorted Array to Binary Search Tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums, 0, nums.size()-1);
    }
    
    TreeNode* sorted(vector<int>& nums, int left, int right){
        if(left>right){return NULL;}
        
        int mid = (left+right)/2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = sorted(nums, left, mid-1);
        head->right = sorted(nums, mid+1, right);
        return head;
    }
};