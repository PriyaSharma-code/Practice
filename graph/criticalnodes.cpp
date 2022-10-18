//1192. Critical Connections in a Network


//easy to understand sol
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto conn : connections) {  //undirected graph
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time++;
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {  //dfs for unvisited node
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev)
                low[curr] = min(low[curr], disc[next]);
            if (low[next] > disc[curr]) //we've found a loop
                ans.push_back({curr, next});
        }
    }
private:
    vector<int> disc{0}, low{0};
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
};


//faster sol

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> vi(n, false);
        vector<int> disc(n, 0), low(n, 0), parent(n, -1);
        vector<vector<int>> g(n, vector<int>()), res;
        for (auto& p : connections) {
            g[p.front()].push_back(p.back());
            g[p.back()].push_back(p.front());
        }
        for (int i = 0; i < n; ++i) {
            if (vi[i]) continue;
            h(i, vi, disc, low, parent, g, res);
        }
        return res;
    }

    void h(int u, vector<bool>& vi, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& g, vector<vector<int>>& res) {
        static int time = 0;
        vi[u] = true;
        disc[u] = low[u] = ++time;
        for (int v : g[u]) {
            if (!vi[v]) {
                parent[v] = u;
                h(v, vi, disc, low, parent, g, res);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    res.push_back({u, v});
                }

            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }

        }
    }

};

/*If we think of the network and its connections like an undirected graph and its edges, then a 
critical connection, as defined by this problem, is the same as a bridge in the graph. To find 
out which edges are bridges, we can employ Tarjan's Bridge-Finding Algorithm (TBFA).

TBFA is a bit like a combination of a depth-first search (DFS) approach with recursion and a 
union-find. IN TBFA, we do a recursive DFS on our graph and for each node we keep track of the 
earliest node that we can circle back around to reach. By doing this, we can identify whether a
 given edge is a bridge because the far node doesn't lead back to any other earlier node.

To implement our TBFA, the first thing we have to do is to construct an edge map (edgeMap) from 
the connections list. Each key in our edge map should correspond to a specific node, and its
 value should be an array of each adjacent node to the key node.

We'll also need separate arrays to store the discovery time (disc) and the lowest future node
 (low) for each node, as well as a time counter to use with disc.

For our recursive DFS helper (dfs), each newly-visited node should set its initial value for 
both disc and low to the current value of time before time is incremented. (Note: If we start
 time at 1 instead of 0, we can use either disc or low as a visited array, rather than having 
 to keep a separate array for the purpose. Any non-zero value in the chosen array will then 
 represent a visited state for the given node.)

Then we recursively call dfs on each of the unvisited adjacent nodes (next) of the current
 node (curr). If one of the possible next nodes is an earlier node (disc[next] < curr[low]), 
 then we've found a loop and we should update the low value for the current node. As each layer 
 of the recursive function backtracks, it will propagate this value of low back down the chain.

If, after backtracking, the value of low[next] is still higher than disc[curr], then there is 
no looped connection, meaning that the edge between curr and next is a bridge, so we should add
 it to our answer array (ans).

Once the dfs helper function has completed its traversal, we can return ans.*/