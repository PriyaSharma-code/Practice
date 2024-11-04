//399. Evaluate Division

class Solution {
public:
    unordered_map<string, vector<pair<string,double>> >neighborMap;

    void dfs( const string &source, const string &target, double & ans, double temp,unordered_set<string>& visited){
        if(visited.find(source) != visited.end()){
            return;
        }
        visited.insert(source);

        if(source == target){
            ans = temp;
            return;
        }

        vector<pair<string,double>> neighbors = neighborMap[source];

        for(const pair<string, double> &neighbor : neighbors){
            dfs(neighbor.first, target, ans, temp* neighbor.second, visited);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i< equations.size();i++){
            const vector<string>& names = equations[i];
            const double val = values[i];
            neighborMap[names[0]].push_back({names[1],val});
            neighborMap[names[1]].push_back({names[0],1.0f/val});
        }

        vector<double> ans;

        for( const vector<string>& query: queries){
            if(neighborMap.find(query[0]) == neighborMap.end() || neighborMap.find(query[1]) == neighborMap.end()){
                ans.push_back(-1);
                continue;
            }

            unordered_set<string> visited;
            double currAns = -1,temp = 1.0;
            dfs(query[0],query[1],currAns,temp, visited);
            ans.push_back(currAns);
        }
        return ans;
    }
};