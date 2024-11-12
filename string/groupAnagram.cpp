//49. Group Anagrams

class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> anagrams;
        for(string s: strs){
            string key = s;
            sort(key.begin(),key.end());
            anagrams[key].push_back(s);
        }
        for(auto& pair: anagrams ){
            answer.push_back(pair.second);
        }
        return answer;
    }
};