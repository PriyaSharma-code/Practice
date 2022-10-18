/*300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/

class Solution { // 256 ms, faster than 42.84%
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution { // 10 ms, faster than 93.16%
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i= 0; i<nums.size();i++){
            auto it = std::lower_bound(res.begin(),res.end(),nums[i]);
            if(it == res.end()){
                res.push_back(nums[i]);
            }
            else{
                *it= nums[i];
            }
        }
        return res.size();
    }
};