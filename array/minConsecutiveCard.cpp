//2260. Minimum Consecutive Cards to Pick Up

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int ans = INT_MAX;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(cards[i])!=m.end()){
                ans = min(ans,i-m[cards[i]]+1);
            }
            m[cards[i]] = i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        minPick = float('inf')
        seen = {}
        for i, n in enumerate(cards):
            if n in seen:
                if i - seen[n] + 1 < minPick:
                    minPick = i - seen[n] + 1
            seen[n] = i
        if minPick == float('inf'):
            return -1
        return minPick
        