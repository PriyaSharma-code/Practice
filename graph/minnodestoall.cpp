//Minimum Number Of Vertices To Reach All Nodes

#include <bits/stdc++.h> 
vector<int> getSmallestSetOfVertices(int n, vector<vector<int>>& edges)
{
	// Write your code here.
        vector<int> degree(n, 0), nodeset;
        for (auto& e : edges)
            degree[e[1]]++;
        for (int i = 0; i < n; ++i) {
            if(degree[i]==0){
                nodeset.push_back(i);
            }
        }
        return nodeset;
}

