//Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        if(n==0){ return 0;}
        if(n==1) { return 1;}
        int currentconsequtive =1;
        int longestconsequtive = 0;


        for(int i=1;i<n;i++){

            if(nums[i] !=nums[i-1]){
                if(nums[i] == nums[i-1] +1){
                    currentconsequtive++;
                }
                else{
                    longestconsequtive = max(longestconsequtive,currentconsequtive);
                    currentconsequtive = 1;
                }
            }
        }
        return max(longestconsequtive,currentconsequtive);
    }
};