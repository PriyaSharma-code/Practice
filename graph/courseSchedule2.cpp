/*210. Course Schedule II
Return the ordering of courses you should take to finish all courses. If there are many valid
 answers, return any of them. If it is impossible to finish all courses, return an empty array.*/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites){
            G[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        if(bfs.size() == n){
            return bfs;
        }
        else{
            return {};
        }
    }
};