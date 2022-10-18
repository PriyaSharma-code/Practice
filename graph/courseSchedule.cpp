/* 207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you 
must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

class Solution {
public:
      
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == n;
    }
};

class Solution:
    def canFinish(self, n: int, prerequisites: List[List[int]]) -> bool:
        G = [[] for i in range(n)]
        degree = [0] * n
        for j, i in prerequisites:
            G[i].append(j)
            degree[j] += 1
        bfs = [i for i in range(n) if degree[i] == 0]
        for i in bfs:
            for j in G[i]:
                degree[j] -= 1
                if degree[j] == 0:
                    bfs.append(j)
        return len(bfs) == n