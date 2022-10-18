/*103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        deque<TreeNode *> visited{root};
        vector<vector<int>> zz;
        bool leftToRight = true;
        while(!visited.empty()){
            vector<int> row;
            int count = visited.size();
            while(count -- >0){
                TreeNode * curr = NULL;
                if(leftToRight){
                    curr = visited.front();
                    visited.pop_front();
                    if(curr->left){
                        visited.push_back(curr->left);
                    }
                    if(curr->right){
                        visited.push_back(curr->right);
                    }
                }
                else{
                    curr = visited.back();
                    visited.pop_back();
                    if(curr->right){
                        visited.push_front(curr->right);
                    }
                    if(curr->left){
                        visited.push_front(curr->left);
                    }
                 }
                row.push_back(curr->val);
            }
            zz.push_back(row);
            leftToRight = !leftToRight;
        }
        return zz;
    }
};

class Solution:
    def zigzagLevelOrder(self, root):
        if not root: return []
        queue = deque([root])
        result, direction = [], 1
        
        while queue:
            level = []
            for i in range(len(queue)):
                node = queue.popleft()
                level.append(node.val)
                if node.left:  queue.append(node.left)
                if node.right: queue.append(node.right)
            result.append(level[::direction])
            direction *= (-1)
        return result

/*In this problem we need to traverse binary tree level by level. When we see levels in binary tree, we need to think about bfs, 
because it is its logic: it first traverse all neighbors, before we go deeper. Here we also need to change direction on each level 
as well. So, algorithm is the following:

We create queue, where we first put our root.
result is to keep final result and direction, equal to 1 or -1 is direction of traverse.
Then we start to traverse level by level: if we have k elements in queue currently, we remove them all and put their children instead.
 We continue to do this until our queue is empty. Meanwile we form level list and then add it to result, using correct direction and 
 change direction after.
Complexity: time complexity is O(n), where n is number of nodes in our binary tree. Space complexity is also O(n), because our result
 has this size in the end. If we do not count output as additional space, then it will be O(w), where w is width of tree. It can be
  reduces to O(1) I think if we traverse levels in different order directly, but it is just not worth it.*/