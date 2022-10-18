//1. Two Sum

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, n in enumerate(nums):    
            m = target - n
            if m in d:
                return [d[m], i]
            else:
                d[n] = i
    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> x;
        for(int i =0;i<nums.size();i++){
            if(x.find(target - nums[i])!= x.end()){
                return {i,x[target-nums[i]]};
            }
            x[nums[i]] = i;
        }
        return {};
    }
};