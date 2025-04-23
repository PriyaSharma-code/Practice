class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n < 2){
            return n; // base case: only 0 or 1 fruit, return it directly
        }

        unordered_map<int, int> fruitCount; // keeps count of each fruit type in current window
        int maxFruits = 0; // tracks the max number of fruits collected
        int left = 0; // left pointer of the sliding window

        for(int right = 0 ; right < n; right++){
            fruitCount[fruits[right]]++; // add current fruit to map

            // if we have more than 2 types, shrink window from the left
            while(fruitCount.size() > 2){
                fruitCount[fruits[left]]--; // remove one fruit of that type
                if(fruitCount[fruits[left]] == 0){
                    fruitCount.erase(fruits[left]); // erase type if count is 0
                }
                left++; // move left pointer right
            }

            // update maxFruits with the current window size
            maxFruits = max(maxFruits, right - left + 1); 
        }

        return maxFruits; // return the best window length
    }
};
