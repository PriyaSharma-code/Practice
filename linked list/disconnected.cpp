#include<iostream>
#include<vector.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n), pre(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pre.append((a,b));
    }
        vector<int> degree(n, 0), bfs;
        for (auto& e : pre)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i){
             if (!degree[i]) bfs.push_back(i);
        }
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size();
}