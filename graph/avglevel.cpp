/*637. Average of Levels in Binary Tree*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long temp = 0;
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* t = q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                temp +=t->val;
            }
            ans.push_back((double)temp /s);
        }
        return ans;
    }
};