// /997. Find the Town Judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_count(n + 1, 0); // How many people trust this person
        vector<int> trusted_by_count(n + 1, 0); // How many people this person trusts
        
        // Process the trust relationships
        for (const auto& t : trust) {
            int a = t[0];
            int b = t[1];
            trusted_by_count[a]++;
            trust_count[b]++;
        }
        
        // Find the town judge
        for (int i = 1; i <= n; ++i) {
            if (trust_count[i] == n - 1 && trusted_by_count[i] == 0) {
                return i;
            }
        }
        
        return -1; // If no judge found
    }
};