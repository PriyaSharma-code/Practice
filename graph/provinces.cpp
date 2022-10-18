/*8547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities 
outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city 
and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()){
            return 0;
        }
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int groups = 0;
        for(int i = 0; i< visited.size(); i++){
            groups += !visited[i] ? dfs(i,isConnected, visited), 1 : 0;
        }
        return groups;
    }
private:
    void dfs(int i, vector<vector<int>> &M, vector<bool> & visited){
        visited[i] = true;
        for(int j=0; j<visited.size(); j++){
            if(i!=j && M[i][j] && !visited[j]){
                dfs(j, M, visited);
            }
        }
    }
};