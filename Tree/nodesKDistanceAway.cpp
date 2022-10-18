//863. All Nodes Distance K in Binary Tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parents = {}
        def dfs(this,parent):
            parents[this] = parent
            if this.left:
                dfs(this.left, this)
            if(this.right):
                dfs(this.right, this)
        dfs(root,None)
        
        q = deque([(target,0)])
        seen = {target}
        while q:
            this, dist = q.popleft()
            if(dist ==k):
                return [this.val] + [node.val for node, d in q]
            for node in (this.left, this.right, parents[this]):
                if node and node not in seen:
                    seen.add(node)
                    q.append((node, dist+1))
        return []


class Solution {
public:
    vector<int> ans;   
    map<TreeNode*, TreeNode*> parent;  // son=>parent  
    set<TreeNode*> visit;    //record visied node
    
    void findParent(TreeNode* node){
        if(!node ) return;
        if( node->left ){
            parent[node->left] = node;
            findParent(node->left);
        }
        if( node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if( !root ) return {};
        
        findParent(root);
        dfs(target, K );
        return ans;
    }

    void dfs( TreeNode* node, int K){
        if (!node) return;
        if (visited.count(node) > 0) return;
         visited.insert(node);
       if (K == 0) {
          ans.push_back(node->val);
          return;
        }
    dfs(node->left, K - 1);
    dfs(node->right, K - 1);
    dfs(parent[node], K - 1);
    }
};

/*Self Notes:
🍋 Mark each node to its parent to traverse upwards
🍋 We will do a BFS traversal starting from the target node
🍋 As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
🍋 when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result*/