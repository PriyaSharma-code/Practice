///332. Reconstruct Itinerary

/*You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the 
departure and the arrival airports of one flight. Reconstruct the itinerary in order and 
return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin
 with "JFK". If there are multiple valid itineraries, you should return the itinerary that 
 has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets 
once and only once.*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        vector<string> ans;
        int n = tickets.size();
        
        for(int i=0;i<n;i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> stack;
        stack.push("JFK");
        while(!stack.empty()){
            string src =  stack.top();
            if(adj[src].size()==0){
                ans.push_back(src);
                stack.pop();
            }
            else{
                auto dst = adj[src].begin();
                stack.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};