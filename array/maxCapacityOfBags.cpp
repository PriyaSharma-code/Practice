//2279. Maximum Bags With Full Capacity of Rocks

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // init the missingRocks array(stored in capacity)
        for(int i = 0; i < capacity.size(); i++)
            capacity[i]-=rocks[i];
        
        // sorts the array
        sort(capacity.begin(),capacity.end());

        // find how many bags we can fill using additionalRocks.
        // note that the cases :bag = 0, additionalRocks = 0 is handled 
        int j = 0;
        for (int bag:capacity){
            additionalRocks -= bag;
            if (additionalRocks >= 0) j++;
            else break;
        } 

        return j;
    }
};