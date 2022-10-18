//2261. K Divisible Elements Subarrays

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;
        
        for(int i=0;i<nums.size();i++){
            vector<int> tt;
            int count = 0;
            for(int j=i;j<nums.size();j++){
                tt.push_back(nums[j]);
                if(nums[j]%p==0){
                    count++;
                }
                if(count>k)break;
                ans.insert(tt);
            }
        }
            return ans.size();
        }
};