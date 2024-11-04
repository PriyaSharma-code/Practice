//169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = int(nums.size()/2);
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>majority){
                    return nums[i];
                
            }
        }
        return 0; // This line will never be reached as per problem constraints
    }
};